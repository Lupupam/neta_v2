//
// Copyright (C) 2013 by NESG (Network Engineering and Security Group), http://nesg.ugr.es
// Dept. of Signal Theory, Telematics and Communications
// University of Granada
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "NA_DroppingDetectorStandalone.h"
#include "NA_DroppingDetectorStandaloneMessage_m.h"
#include "NA_ModuleAdapter.h"

simsignal_t NA_DroppingDetectorStandalone::probDrop = SIMSIGNAL_NULL;

Define_Module(NA_DroppingDetectorStandalone);

void NA_DroppingDetectorStandalone::initialize() {
    RREQWindowEnable = false;
    probDrop = registerSignal("probDrop");
    NA_Detector::initialize();
    getModuleAdapter(); //Busca el modulo adpater(send_alarm) topo.... como en defense_basic

}

cMessage *NA_DroppingDetectorStandalone::generateDetectionMessage(
        const char *name) {

    LOG << "NA_DroppingDetectorStandalone: generateDetectionMessage\n";

    // Specific message for the specifics hacked modules.
    NA_DroppingDetectorStandaloneMessage *msg =
            new NA_DroppingDetectorStandaloneMessage(name);
    msg->setEventWindowSize(par("eventWindowSize").longValue());

    return msg;
}

void NA_DroppingDetectorStandalone::performDetection() {
//    triggerResponse(0.5);
    Enter_Method("NA_DroppingDetectorStandAlone: Performing Detection");
    LOG << "NA_DroppingDetectorStandalone: performDetection [asking for data]\n";
    getDataFromModules();
    LOG << "NA_DroppingDetectorStandalone: performDetection [calculating dropping probability]\n";

    if (receivedCount != 0 && sentRTS != 0) {
        long double nPfwd = ((long double) fordwardedCount / (long double) receivedCount);
        long double nPcol = ((long double) (sentRTS - receivedCTS) / (long double) sentRTS);

        long double pDrop = 0;
        if (!(pMob != 0 || nPcol == 1 || RREQWindowEnable || RREQcount != 0)) {
            pDrop = 1 - (nPfwd / (1 - nPcol));
            if (pDrop < 0){
                pDrop = 0;
            }
        }

        cout << this->getFullPath() << " " << simTime() << " " << pDrop << " " << receivedCount << " " << fordwardedCount << " " << pMob << " " << sentRTS << " " << receivedCTS << " " << RREQcount << " [Standalone]\n";
        emit(probDrop, pDrop);
        /*if (!strcmp(this->getFullPath().c_str(),"Dropping.node[0].droppingDetection")){
        //Debug the collected data
        cout << this->getFullPath() << " at [" << simTime() << "]\n";
        cout << "DataRecv: " << receivedCount << " DataFwd: " << fordwardedCount << " pMob: " << pMob
                << " RTSsend: " << sentRTS << " CTSrecv: " << receivedCTS
                << " RREQ: " << RREQcount
                << "\n";
        //Debug the calculated data
        cout << "nPfwd: " << nPfwd << " nPcol: " << nPcol << " pMob: " << pMob
                << "\n" << "Pdrop: " << Pdrop << " Thr: " << par("threshold").doubleValue() << "\n";
        }*/

        if (pDrop+1e-16 < par("threshold").doubleValue() || RREQWindowEnable) {
            if (RREQcount == 0 || RREQWindowEnable) {
                /*if (!strcmp(this->getFullPath().c_str(),"Dropping.attacker[0].droppingDetection")){
                    if (RREQWindowEnable){
                        cout << "[Legitimate period] ";
                    }
                    cout << "Legitimate during the window\n\n";
                }*/
                emit(detectionResult, false);
            } else {
                /*if (!strcmp(this->getFullPath().c_str(),"Dropping.attacker[0].droppingDetection")){
                    cout << "Legitimate for every window during T period. Setting the T period until: " << simTime()+par("legitimatePeriodT").doubleValue() << "\n\n";
                }*/
                LOG << "NA_DroppingDetectorStandalone: handleDataMessage [sheduling legitimate period T]\n";
                RREQWindowEnable = true;
                cMessage *RREQmsg = new cMessage("switchRREQWindow");
                scheduleAt(simTime()+par("legitimatePeriodT").doubleValue(),RREQmsg);
                emit(detectionResult, false);
            }
        } else {
            /*if (!strcmp(this->getFullPath().c_str(),"Dropping.attacker[0].droppingDetection")){
                cout << "Malicious during the window\n\n";
            }*/
            emit(onceDetected,1);
            emit(detectionResult, true);
            triggerResponse(pDrop);
        }
    } else {
        /*if (!strcmp(this->getFullPath().c_str(),"Dropping.attacker[0].droppingDetection")){
            cout << "Legitimate during the window\n\n";
        }*/
        emit(detectionResult, false);
    }
    activateModules(); //Restart the counters in every node
}

void NA_DroppingDetectorStandalone::handleDataMessage(cMessage *msg) {
    NA_DroppingDetectorStandaloneMessage *data = dynamic_cast<NA_DroppingDetectorStandaloneMessage *>(msg);

    if (not strcmp(msg->getFullName(), "droppingSAMACData")) {
        receivedCTS = data->getReceivedCTS();
        sentRTS = data->getSentRTS();
        pMob = data->getPMob();
        LOG << "NA_DroppingDetectorStandalone: handleDataMessage [obtaining MAC data]\n";
    } else if (not strcmp(msg->getFullName(), "droppingSAIPData")) {
        fordwardedCount = data->getFordwardedCount();
        receivedCount = data-> getReceivedCount();
        LOG << "NA_DroppingDetectorStandalone: handleDataMessage [obtaining IP data]\n";
    } else if (not strcmp(msg->getFullName(), "droppingSAAODVUUData")) {
        RREQcount = data->getRREQCount();
        LOG << "NA_DroppingDetectorStandalone: handleDataMessage [obtaining AAODVUU data]\n";
    }
    delete (msg);
}

void NA_DroppingDetectorStandalone::handleMessage(cMessage *msg) {
    if(not strcmp(msg->getFullName(), "switchRREQWindow")){
        RREQWindowEnable = false;
        LOG << "NA_DroppingDetectorStandalone: handleDataMessage [Legitimate period T turned off]\n";
    }
    NA_Detector::handleMessage(msg);
}

void NA_DroppingDetectorStandalone::getModuleAdapter(){

    cTopology topo;
    cTopology::Node *node;
    std::string nodeName;

    topo.extractByProperty("moduleAdapter");

    std::string prefix = this->getParentModule()->getFullPath(); // First we get the full path of the parent node
    int numModules = 0;
    for (int i = 0; i < topo.getNumNodes(); i++) {
        node = topo.getNode(i);
        nodeName = node->getModule()->getFullPath();
        if (not nodeName.compare(0, prefix.size(), prefix)) {
            moduleAdapter = node->getModule();
            numModules++;
        }
     }


}

void NA_DroppingDetectorStandalone::triggerResponse(double pDrop) {
    LOG << "--------------------Droping Standalone detectado--------------------\n";
    cTopology topo;
    topo.extractByProperty("moduleAdapter");

    if(topo.getNumNodes() != 0){

        double accuracy_var= ((pDrop-par("threshold").doubleValue())/par("threshold").doubleValue());
        const char* detectorNode = (this->getFullPath().c_str());
        const char* maliciousNode = (this->getFullPath().c_str());

        LOG << "--------------------Droping Standalone avisado--------------------\n";


        NA_ModuleAdapter *modAdapter;
        modAdapter = dynamic_cast<NA_ModuleAdapter *>(moduleAdapter);

        uint8_t event =1 ;
        uint8_t severity=modAdapter->convertirEnUint8_t(pDrop,1);;
        uint8_t accuracy=modAdapter->convertirEnUint8_t(accuracy_var,9);  //Maxima accuracy (pDrop-trh)/trh


        AlertMsgAdaptation *msg = NA_Notification::alertMsg_createAdaptation(event,severity,accuracy, maliciousNode);

        sendMessage(msg);
    }
}
void NA_DroppingDetectorStandalone::sendMessage(cPacket *msg){
    NA_ModuleAdapter *modAdapter;
    modAdapter = dynamic_cast<NA_ModuleAdapter *>(moduleAdapter);
    modAdapter->handleMessage(msg);
}



