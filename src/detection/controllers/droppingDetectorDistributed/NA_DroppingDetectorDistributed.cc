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

#include "NA_DroppingDetectorDistributed.h"
#include "NA_DroppingDetectorDistributedMessage_m.h"
//#include "NA_ResponseMessage_m.h"
#include "IInterfaceTable.h"
#include "IPv4InterfaceData.h"
#include "NA_ModuleAdapter.h"


//QUITA ESTA SEÑAL QUE NO VALE PARA NADA
simsignal_t NA_DroppingDetectorDistributed::probDrop = SIMSIGNAL_NULL;

Define_Module(NA_DroppingDetectorDistributed);

void NA_DroppingDetectorDistributed::initialize(int stage) {
    if(stage == 0){
        NA_Detector::initialize();
    }
    if (stage == 2){
        cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
        DistributedNodeInfo nodeInfo;

        topo.extractByModulePath(cStringTokenizer("**.node[*] **.attacker[*]").asVector());

        int numModules = 0;
        for (int i = 0; i < topo.getNumNodes(); i++) {
            cTopology::Node *node = topo.getNode(i);
            string nodeName = node->getModule()->getFullPath();

            IInterfaceTable *it = check_and_cast<IInterfaceTable*>(node->getModule()->getSubmodule("interfaceTable",0));
            InterfaceEntry *ie = it->getInterface(1);
            if(ie != NULL && !ie->isLoopback()){
                strcpy(nodeInfo.id,nodeName.c_str());
                nodeInfo.ip = ie->ipv4Data()->getIPAddress().getInt();
                nodeInfo.mac = ie->getMacAddress().getInt();
                nodeInfo.RREQWindowEnable = false;

                dNodes.push_back(nodeInfo);
                numModules++;
            }
        }
        //cout << "Module Addresses: \n";
        for(uint32_t i = 0 ; i<dNodes.size() ; i++){
            //cout << dNodes.at(i).id << " MAC: " << MACAddress(dNodes.at(i).mac) << " IP: "<< IPv4Address(dNodes.at(i).ip) << "\n";
            restartNodeInfo(i);
        }

        lastTimestamp = 0;
        probDrop = registerSignal("probDrop");

    }
}

cMessage *NA_DroppingDetectorDistributed::generateDetectionMessage(
        const char *name) {

    LOG << "NA_DroppingDetectorDistributed: generateDetectionMessage\n";

    // Specific message for the specifics hacked modules.
    NA_DroppingDetectorDistributedMessage *msg =
            new NA_DroppingDetectorDistributedMessage(name);
    return msg;
}

void NA_DroppingDetectorDistributed::performDetection() {

    for(uint32_t i = 0 ; i<dNodes.size() ; i++){
        if (dNodes.at(i).receivedCount >= par("eventWindowSize").longValue()){
            if (dNodes.at(i).receivedCount != 0 && dNodes.at(i).sentRTS != 0) {
                long double nPfwd = ((long double) dNodes.at(i).fordwardedCount / (long double) dNodes.at(i).receivedCount);
                long double nPcol = ((long double) (dNodes.at(i).sentRTS - dNodes.at(i).receivedCTS) / (long double) dNodes.at(i).sentRTS);

                long double pDrop = 0;
                if (!(dNodes.at(i).pMob != 0 || nPcol == 1 || dNodes.at(i).RREQWindowEnable || dNodes.at(i).RREQcount != 0)) {
                    pDrop = 1 - (nPfwd / (1 - nPcol));
                    if (pDrop < 0){
                        pDrop = 0;
                    }
                }

                cout << dNodes.at(i).id << " " << simTime() << " " << pDrop << " " << dNodes.at(i).receivedCount << " " << dNodes.at(i).fordwardedCount << " " << dNodes.at(i).pMob << " " << dNodes.at(i).sentRTS << " " << dNodes.at(i).receivedCTS << " " << dNodes.at(i).RREQcount << " [Distributed]\n";
                emit(probDrop, pDrop);

                if (pDrop+1e-16 < par("threshold").doubleValue() || dNodes.at(i).RREQWindowEnable) {
                    emit(detectionResult, false);
                } else {
                    /*if (!strcmp(this->getFullPath().c_str(),"Dropping.attacker[0].droppingDetection")){
                            cout << "Malicious during the window\n\n";
                        }*/
                    emit(onceDetected,1);
                    emit(detectionResult, true);
                    triggerResponse(pDrop,i);
                }
            } else {
                /*if (!strcmp(this->getFullPath().c_str(),"Dropping.attacker[0].droppingDetection")){
                        cout << "Legitimate during the window\n\n";
                    }*/
                emit(detectionResult, false);
            }

            //Restart the counters in every node
            restartNodeInfo(i);
        }
    }


}

void NA_DroppingDetectorDistributed::handleDataMessage(cMessage *msg) {
    Enter_Method("NA_DroppingDetectorDistributed: Receiving sniffed data");


    NA_DroppingDetectorDistributedMessage *data =
            dynamic_cast<NA_DroppingDetectorDistributedMessage *>(msg);
    if (not strcmp(msg->getFullName(), "droppingDMACData") && lastTimestamp != data->getTimestamp()) {
        //cout << "\nSniffed packet received at [" << data->getTimestamp() << "]: ";

        lastTimestamp = data->getTimestamp();

        if(data->getRTS()){
            //cout << "RTS\n";
            for(uint32_t i = 0 ; i<dNodes.size() ; i++){
                if(dNodes.at(i).mac == data->getSrcMACAdd()){
                    if(dNodes.at(i).maxRTS){
                        dNodes.at(i).maxRTS = false;
                        dNodes.at(i).sentRTSaux = 0;
                        dNodes.at(i).pMob = true;
                    }
                    dNodes.at(i).sentRTSaux++;
                    if(dNodes.at(i).sentRTSaux >= 7){
                        dNodes.at(i).maxRTS = true;
                    }
                }
            }
        }else if(data->getCTS()){
            //cout << "CTS\n";
            for(uint32_t i = 0 ; i<dNodes.size() ; i++){
                if(dNodes.at(i).mac == data->getDstMACAdd() && dNodes.at(i).sentRTSaux > 0){
                    dNodes.at(i).CTSwaitingNextFrame = true;
                    dNodes.at(i).maxRTS = false;
                    dNodes.at(i).receivedCTSaux++;
                }
            }
        }else if(data->getDATA()){
            //cout << "DATA\n";
            for(uint32_t i = 0 ; i<dNodes.size() ; i++){
                if(dNodes.at(i).mac == data->getSrcMACAdd() && dNodes.at(i).CTSwaitingNextFrame){
                    dNodes.at(i).receivedCTS += dNodes.at(i).receivedCTSaux;
                    dNodes.at(i).receivedCTSaux = 0;
                    dNodes.at(i).sentRTS += dNodes.at(i).sentRTSaux;
                    dNodes.at(i).sentRTSaux = 0;
                    dNodes.at(i).CTSwaitingNextFrame = false;
                }
                if(dNodes.at(i).mac == data->getSrcMACAdd() && dNodes.at(i).ip != data->getSrcIPAdd()){
                    dNodes.at(i).fordwardedCount++;
                }
                if(dNodes.at(i).mac == data->getDstMACAdd() && dNodes.at(i).ip != data->getDstIPAdd()){
                    dNodes.at(i).receivedCount++;
                    if (dNodes.at(i).receivedCount >= par("eventWindowSize").longValue()){
                        performDetection();
                    }
                }
            }
        }else if(data->getRREQ()){
            //cout << "RREQ\n";
            for(uint32_t i = 0 ; i<dNodes.size() ; i++){
                if(dNodes.at(i).ip == data->getOrgAdd() && dNodes.at(i).ip == data->getSrcIPAdd() && dNodes.at(i).mac == data->getSrcMACAdd() && dNodes.at(i).maxRTS){
                    dNodes.at(i).maxRTS = false;
                    dNodes.at(i).CTSwaitingNextFrame = false;
                    dNodes.at(i).sentRTSaux = 0;
                    dNodes.at(i).receivedCTSaux = 0;


                    dNodes.at(i).RREQcount++;
                    LOG << "NA_DroppingDetectorDistributed: handleDataMessage [sheduling legitimate period T for " << dNodes.at(i).id  << "]\n";
                    dNodes.at(i).RREQWindowEnable = true;
                    NA_DroppingDetectorDistributedMessage *RREQmsg = new NA_DroppingDetectorDistributedMessage("switchRREQWindow");
                    RREQmsg->setIndex(i);
                    scheduleAt(simTime()+par("legitimatePeriodT").doubleValue(),RREQmsg);
                }
            }
        }else if(!data->getRREQ() && !data->getDATA() && !data->getRTS() && !data->getCTS()){
            //cout << "RREP or RREPACK\n";
            for(uint32_t i = 0 ; i<dNodes.size() ; i++){
                if(dNodes.at(i).mac == data->getSrcMACAdd() && dNodes.at(i).CTSwaitingNextFrame){
                    dNodes.at(i).sentRTSaux = 0;
                    dNodes.at(i).receivedCTSaux = 0;
                    dNodes.at(i).CTSwaitingNextFrame = false;
                }
            }
        }
        //cout << "O: " << IPv4Address(data->getOrgAdd()) << " IPS: " << IPv4Address(data->getSrcIPAdd()) << " IPD: " << IPv4Address(data->getDstIPAdd()) << "\nMACS: " << MACAddress(data->getSrcMACAdd()) << " MACD: " << MACAddress(data->getDstMACAdd()) << "\n";
    }
}

void NA_DroppingDetectorDistributed::handleMessage(cMessage *msg) {
    if(not strcmp(msg->getFullName(), "switchRREQWindow")){
        NA_DroppingDetectorDistributedMessage *data =
                dynamic_cast<NA_DroppingDetectorDistributedMessage *>(msg);
        dNodes.at(data->getIndex()).RREQWindowEnable = false;
        LOG << "NA_DroppingDetectorStandalone: handleDataMessage [Legitimate period T turned off]\n";
    }
    NA_Detector::handleMessage(msg);
}

void NA_DroppingDetectorDistributed::restartNodeInfo(int i){
    dNodes.at(i).RREQcount = 0;
    dNodes.at(i).fordwardedCount = 0;
    dNodes.at(i).receivedCTS = 0;
    dNodes.at(i).sentRTS = 0;
    dNodes.at(i).sentRTSaux = 0;
    dNodes.at(i).maxRTS = false;
    dNodes.at(i).receivedCount = 0;
    dNodes.at(i).pMob = false;
    dNodes.at(i).CTSwaitingNextFrame = false;
    dNodes.at(i).receivedCTSaux = 0;

}

void NA_DroppingDetectorDistributed::triggerResponse(double pDrop, int i) {;
//    LOG << "--------------------Droping Distributed detectado--------------------\n";
//
//    cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
//    topo.extractByProperty("controlador");
////    topo.extractByModulePath(cStringTokenizer("**.node[*] **.attacker[*]").asVector());
//
//    if(topo.getNumNodes() != 0){
//        NA_ResponseMessage *data = new NA_ResponseMessage();
//
//        data->setEventType("DroppingAttackDistributed"); //"DroppingAttackDistributed"
//        data->setSeverity(pDrop);
//        data->setAccuracy((pDrop-par("threshold").doubleValue())/par("threshold").doubleValue());
//        data->setDetectorNode(this->getFullPath().c_str());
//        data->setMaliciousNode(dNodes.at(i).id);
//        data->setTimestamp(simTime());
//
//        LOG << "--------------------Droping Distributed enviado--------------------\n";
//
//        //Send data to the response module when implemented
////       topo.getNode(i).handleMessage(data);
////        NA_Send_Alarm *Alarm = new NA_Send_Alarm();
////        Alarm->handleMessage(data);
//
//        delete data;
//        delete Alarm;
//    }
}

