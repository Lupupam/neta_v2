//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

#include "Defense_Basic.h"


Define_Module(Defense_Basic);

void Defense_Basic::initialize()
{
    respuestas=0;
    tiempo=2;

    char* tipoNotificacion = (char*) par("notificationType").stringValue();

    getNotificationControlllerModules();

    if (strcmp(tipoNotificacion, "alerta")==0)
    {
        cMessage *msg = new cMessage("alerta");
        scheduleAt(2, msg);
    }

    if (strcmp(tipoNotificacion, "peticion")==0)
    {
        cMessage *msg = new cMessage("peticion");
        scheduleAt(2, msg);
    }

}

void Defense_Basic::getNotificationControlllerModules()
{
    cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
    cTopology::Node *node;
    std::string nodeName;

    // extract all modules with the @attackType property set in the simulation
    topo.extractByProperty("controlador");

    std::string prefix = this->getParentModule()->getFullPath(); // First we get the full path of the parent node
    int numModules = 0;
    for (int i = 0; i < topo.getNumNodes(); i++) {
        node = topo.getNode(i);
        nodeName = node->getModule()->getFullPath();
        if (not nodeName.compare(0, prefix.size(), prefix)) {
            controlador = node->getModule();
            numModules++;
            //return;
        }
    }
}

void Defense_Basic::handleMessage(cMessage *msg)
{

    if (msg->isSelfMessage() && strcmp(msg->getName(),"alerta")==0)
        {
            delete msg;
            AlertMsg *msg = NA_Notification::alertMsg_create(1, 1, 1, 167772165);

            sendMessage(msg);

            AlertMsg *msg2 = NA_Notification::alertMsg_create(3, 6, 9, 167772166);

            sendMessage(msg2);

            AlertMsg *msg3 = NA_Notification::alertMsg_create(3, 7, 10, 167772167);

            sendMessage(msg3);

        }

    if (msg->isSelfMessage() && strcmp(msg->getName(),"peticion")==0)
        {
            delete msg;
            uint32_t idNodoSolicitado[2];
            idNodoSolicitado[0]=167772165;
            idNodoSolicitado[1]=167772166;
            REQMsg_extension datos[4];
            datos[0].idProtocolo=1;
            datos[0].idVariable=1;
            datos[1].idProtocolo=2;
            datos[1].idVariable=2;
            datos[2].idProtocolo=3;
            datos[2].idVariable=3;
            datos[3].idProtocolo=4;
            datos[3].idVariable=4;

            REQMsg *msg = NA_Notification::reqMsg_create(2, 2, idNodoSolicitado, datos);
            msg->setTtl(2);

            sendMessage(msg);

//            tiempo=tiempo+2.857;
//
//            if(tiempo<105)
//            {
//                cMessage *msg2 = new cMessage("peticion");
//                scheduleAt(tiempo, msg2);
//            }

//            uint32_t idNodoSolicitado[1];
//            idNodoSolicitado[0]=167772165;
//            REQMsg_extension datos[1];
//            datos[0].idProtocolo=1;
//            datos[0].idVariable=1;
//
//            REQMsg *msg = NA_Notification::reqMsg_create(1, 1, idNodoSolicitado, datos);
//            msg->setTtl(2);
//
            sendMessage(msg);

        }
}

void Defense_Basic::handleMessageFromNotificationController(cPacket *msg)
{
    Enter_Method_Silent();
    take(msg);
    NotificationMsg *not_aux=NULL;

    if (dynamic_cast<NotificationMsg  *>(msg))
    {
        not_aux = check_and_cast<NotificationMsg*>(msg);
        int tipo = not_aux-> getTipoMensaje();

        switch ( tipo )
        {
            case ALERTMSG:
                newAlert((AlertMsg *) msg);
                break;
            case REQMSG:
                newREQ((REQMsg *) msg);
                break;
            case REPMSG:
                newREP((REPMsg *) msg);
                break;
        }
    }

}


void Defense_Basic::compose_reply(REQMsg *msg)
{
    uint16_t nodos = msg->getNodos();
    uint16_t variables = msg->getVariables();
    uint32_t idNodo=0;
    uint32_t idNodoInformado[nodos];
    uint32_t idSolicitud = msg->getIdMensaje();
    uint32_t idNodoSolicitante = msg->getIdSrc();
    int aux=0;

    unsigned int datosSize = msg->getReqExtensionArraySize();

    REPMsg_extension datos[nodos*variables];

    for ( unsigned int i = 0; i <datosSize; i++)
    {
        datos[i].idVariable = msg->getReqExtension(i).idVariable;
        datos[i].idProtocolo = msg->getReqExtension(i).idProtocolo;
        datos[i].valorVariable = calcular_variable(msg->getIdNodoSolicitado(idNodo), msg->getReqExtension(i));

        aux++;
        if (aux>=variables)
        {
            aux=0;
            idNodo++;
        }
    }

    for (unsigned int i = 0; i < nodos; i++ )
    {
        idNodoInformado[i] = msg->getIdNodoSolicitado(i);
    }

    REPMsg *msg2 = NA_Notification::repMsg_create(nodos, variables, idNodoSolicitante, idSolicitud, idNodoInformado, datos);

    sendMessage(msg2);

}

uint32_t Defense_Basic::calcular_variable(uint32_t idNodo, REQMsg_extension datos)
{
    return rand();
}

void Defense_Basic::sendMessage(cPacket *msg)
{
    NA_Notification_Controller *modNotification;
    modNotification = dynamic_cast<NA_Notification_Controller *>(controlador);
    modNotification->sendMessageToNotificationModules(msg);
}
