#include "NA_DefenseAdapter.h"
#include "control.h"


Define_Module(NA_DefenseAdapter);

void NA_DefenseAdapter::initialize(){
    getControlModule();

}

NA_DefenseAdapter::NA_DefenseAdapter(){

}

NA_DefenseAdapter::~NA_DefenseAdapter(){

}

void NA_DefenseAdapter::getControlModule(){

    cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
    cTopology::Node *node;
    std::string nodeName;

    topo.extractByProperty("control");

    std::string prefix = this->getParentModule()->getFullPath(); // First we get the full path of the parent node
    int numControl = 0;
    for (int i = 0; i < topo.getNumNodes(); i++) {
        node = topo.getNode(i);
        nodeName = node->getModule()->getFullPath();
        if (not nodeName.compare(0, prefix.size(), prefix)){
            moduloControl = node->getModule();
            numControl++;
        }
    }
}

void NA_DefenseAdapter::getNotificationControllerModules()
{
    cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
    cTopology::Node *node;
    std::string nodeName;

    topo.extractByProperty("controlador");

    std::string prefix = this->getParentModule()->getFullPath(); // First we get the full path of the parent node
    int numModules = 0;
    for (int i = 0; i < topo.getNumNodes(); i++) {
        node = topo.getNode(i);
        nodeName = node->getModule()->getFullPath();
        if (not nodeName.compare(0, prefix.size(), prefix)) {
            controlador = node->getModule();
            numModules++;
        }
    }
}

void NA_DefenseAdapter::handleMessage(cPacket *msg) { //cPacket *msg

    if (strcmp(msg->getName(),"AlertMsg")==0) {
        sendMessage(msg);
    }

}


void NA_DefenseAdapter::handleMessageFromNotificationController(cPacket *msg)
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
                    initializeControl();
                    disableModule((AlertMsgAdaptation *) msg);
                    break;
            }
        }

}

void NA_DefenseAdapter::disableModule(AlertMsgAdaptation *msg){

    std::string nodoMalicioso =msg->getMaliciousNode();
    delete msg;
    cTopology topo;
    cTopology::Node *nodo;
    std::string nodeName;
    cModule *modulo;

    topo.extractByProperty("Usuario");

    for (int i = 0; i < topo.getNumNodes(); i++) {
        nodo = topo.getNode(i);
        nodeName = nodo->getModule()->getFullPath();
        if (not nodoMalicioso.compare(0, nodeName.size(), nodeName)){
            modulo=nodo->getModule();
            if (!modulo)
                throw cRuntimeError("Modulo no encontrado");
            modulo->callFinish();
            modulo->deleteModule();
            EV << "--->Nodo eliminado: " << nodeName << "\n";
            getNodosUsuario();
        }

    }
}

//void NA_DefenseAdapter::compose_reply(REQMsg *msg)
//{
//    uint16_t nodos = msg->getNodos();
//    uint16_t variables = msg->getVariables();
//    uint32_t idNodo=0;
//    uint32_t idNodoInformado[nodos];
//    uint32_t idSolicitud = msg->getIdMensaje();
//    uint32_t idNodoSolicitante = msg->getIdSrc();
//    int aux=0;
//
//    unsigned int datosSize = msg->getReqExtensionArraySize();
//
//    REPMsg_extension datos[nodos*variables];
//
//    for ( unsigned int i = 0; i <datosSize; i++)
//    {
//        datos[i].idVariable = msg->getReqExtension(i).idVariable;
//        datos[i].idProtocolo = msg->getReqExtension(i).idProtocolo;
////        datos[i].valorVariable = calcular_variable(msg->getIdNodoSolicitado(idNodo), msg->getReqExtension(i));
//
//        aux++;
//        if (aux>=variables)
//        {
//            aux=0;
//            idNodo++;
//        }
//    }
//
//    for (unsigned int i = 0; i < nodos; i++ )
//    {
//        idNodoInformado[i] = msg->getIdNodoSolicitado(i);
//    }
//
//    REPMsg *msg2 = NA_Notification::repMsg_create(nodos, variables, idNodoSolicitante, idSolicitud, idNodoInformado, datos);
//
//    sendMessage(msg2);
//
//}

void NA_DefenseAdapter::initializeControl() {

    control *modControl;
    modControl = dynamic_cast<control *>(moduloControl);
    modControl->initializeDefense();
}

void NA_DefenseAdapter::getNodosUsuario() {

    control *modControl;
    modControl = dynamic_cast<control *>(moduloControl);
    modControl->getNodosUsuario();

}
