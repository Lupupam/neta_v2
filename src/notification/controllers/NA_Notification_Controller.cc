//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

#include "NA_Notification_Controller.h"


Define_Module (NA_Notification_Controller);

void NA_Notification_Controller::initialize()
{
    getDefenseModules();
    getNotificationModules();
}


void NA_Notification_Controller::getDefenseModules() {
    cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
    cTopology::Node *node;
    std::string nodeName;

    // extract all modules with the @attackType property set in the simulation
    topo.extractByProperty("defense");

    std::string prefix = this->getParentModule()->getFullPath(); // First we get the full path of the parent node
    int numModules = 0;
        for (int i = 0; i < topo.getNumNodes(); i++) {
            node = topo.getNode(i);
            nodeName = node->getModule()->getFullPath();
            if (not nodeName.compare(0, prefix.size(), prefix)) {
                modList.push_back(node->getModule());
                numModules++;
            }
        }
}

void NA_Notification_Controller::getNotificationModules()
{
    cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
    cTopology::Node *nodo;
    std::string nodeName;

    // extract all modules with the @attackType property set in the simulation
    topo.extractByProperty("notificador");

    std::string prefix = this->getParentModule()->getFullPath(); // First we get the full path of the parent node
    int numModules = 0;
    for (int i = 0; i < topo.getNumNodes(); i++) {
        nodo = topo.getNode(i);
        nodeName = nodo->getModule()->getFullPath();
        if (not nodeName.compare(0, prefix.size(), prefix)) {
            notificador = nodo->getModule();
            numModules++;
            //return;
        }
    }
}


void NA_Notification_Controller::sendMessageToDefenseModules(cPacket *msg)
{
    Enter_Method_Silent();
    take(msg);

    unsigned int i;
    NA_Notification_Module *modNotification;

    for (i = 0; i < modList.size(); i++) {
//Debe entrar aqui para reenviar
        if (modList[i]->isSimple()) { // Activation is only done in simple modules (implemented in C++ classes).
            modNotification = dynamic_cast<NA_Notification_Module *>(modList[i]);
            // Send the message to the specific hacked module
            modNotification->handleMessageFromNotificationController(msg);
        }
    }
}


void NA_Notification_Controller::sendMessageToNotificationModules(cPacket *msg) {

    Enter_Method_Silent();
    take(msg);

    NA_Notification *modNotification;
    if (notificador->isSimple())
    {
        modNotification = dynamic_cast<NA_Notification *>(notificador);
    }

    modNotification->handleMessageFromNotificationController(msg);

}
