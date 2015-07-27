//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
//
//

#include "NA_ModuleAdapter.h"
#include "control.h"
//#include "NA_ResponseMessage_m.h"
//#include "NA_Notification_omnet.h"



Define_Module(NA_ModuleAdapter);

void NA_ModuleAdapter::initialize(){
    getNotificationControllerModules();

}

NA_ModuleAdapter::NA_ModuleAdapter(){

}

NA_ModuleAdapter::~NA_ModuleAdapter(){

}

void NA_ModuleAdapter::getNotificationControllerModules()
{
    cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
    cTopology::Node *node;
    std::string nodeName;


    // extract all modules with the @attackType property set in the simulation
    topo.extractByProperty("controlador");
 //   topo.extractByModulePath(cStringTokenizer("**.node[*] **.attacker[*]").asVector());;

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

uint8_t NA_ModuleAdapter::convertirEnUint8_t(double dato, int max){
    uint8_t result=(dato*256)/max;
    return result;

}

void NA_ModuleAdapter::handleMessage(cPacket *msg) { //cPacket *msg

    if (strcmp(msg->getName(),"AlertMsgAdaptation")==0) {
        sendMessage(msg);
    }

}


void NA_ModuleAdapter::handleMessageFromNotificationController(cPacket *msg)
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
                newAlert((AlertMsgAdaptation *) msg);
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



void NA_ModuleAdapter::compose_reply(REQMsg *msg)
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
//        datos[i].valorVariable = calcular_variable(msg->getIdNodoSolicitado(idNodo), msg->getReqExtension(i));

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

void NA_ModuleAdapter::sendMessage(cPacket *msg) {

    NA_Notification_Controller *modNotification;
    modNotification = dynamic_cast<NA_Notification_Controller *>(controlador);
    modNotification->sendMessageToNotificationModules(msg);

}
