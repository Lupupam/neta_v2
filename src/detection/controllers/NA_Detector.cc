//
// Copyright (C) 2013, NESG (Network Engineering and Security Group), http://nesg.ugr.es,
// - Gabriel Maciá Fernández (gmacia@ugr.es)
// - Leovigildo Sánchez Casado (sancale@ugr.es)
// - Rafael A. Rodríguez Gómez (rodgom@ugr.es)
// - Roberto Magán Carrión (rmagan@ugr.es)
// - Pedro García Teodoro (pgteodor@ugr.es)
// - José Camacho Páez (josecamacho@ugr.es)
// - Jesús E. Díaz Verdejo (jedv@ugr.es)
//
// This file is part of NETA.
//
//    NETA is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    NETA is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with NETA.  If not, see <http://www.gnu.org/licenses/>.
//

#include "NA_Detector.h"
#include "NA_NesgLog.h"
#include "NA_HackedModule.h"
#include "NA_IPv4.h"

simsignal_t NA_Detector::detectionResult = SIMSIGNAL_NULL;
simsignal_t NA_Detector::onceDetected = SIMSIGNAL_NULL;


Define_Module(NA_Detector);

void NA_Detector::initialize() {

    detectionResult = registerSignal("detectionResult");
    onceDetected = registerSignal("onceDetected");

    // Get the type of detector type to be launched
    detectorType = (char*) par(NA_DETECTOR_TYPE).stringValue();

    // Activate the detection only if defined in the active parameter in module (.ned)
    if (par(NA_DETECTOR_ACTIVE).boolValue() == true) {
        getDetectorModules();
        scheduleDetection();
    }
}

void NA_Detector::getDetectorModules() {
    cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
    cTopology::Node *node;
    string nodeName;

    // extract all modules with the @detectorType property set in the simulation
    topo.extractByProperty(par(NA_DETECTOR_TYPE).stringValue());

    LOG << "------------------------------------\n";
    LOG << "Found " << topo.getNumNodes()
            << " possible modules for detection\n";
    LOG << "------------------------------------\n";

    // Now, only the modules contained in the parent module of this NA_Detector object are activated.
    string prefix = this->getParentModule()->getFullPath(); // First we get the full path of the parent node
    int numModules = 0;
    for (int i = 0; i < topo.getNumNodes(); i++) {
        node = topo.getNode(i);
        nodeName = node->getModule()->getFullPath();
        if (not nodeName.compare(0, prefix.size(), prefix)) {

            LOG << "--->Inserting module in list: " << nodeName << "\n";
            modList.push_back(node->getModule());
            numModules++;
        }
    }
    LOG << "-----------------------------------\n";
    LOG << "Inserted " << numModules << " modules in list\n";
    LOG << "-----------------------------------\n";
}

void NA_Detector::scheduleDetection() {
    cMessage *msg = new cMessage(NA_DETECTOR_START_MESSAGE);
    LOG << "Scheduling the detection\n";
    scheduleAt(par(NA_DETECTOR_START_TIME).doubleValue(), msg);
    if (par(NA_DETECTOR_END_TIME).doubleValue()) //When the value differs from 0
    {
        cMessage *msgEnd = new cMessage(NA_DETECTOR_END_MESSAGE);
        scheduleAt(par(NA_DETECTOR_END_TIME).doubleValue(), msgEnd);
    }
}

void NA_Detector::handleMessage(cMessage *msg) {
    LOG << "Message received: " << msg->getFullName() << "\n";
    if (not strcmp(msg->getFullName(), NA_DETECTOR_START_MESSAGE)) {
        activateModules();
    } else if (not strcmp(msg->getFullName(), NA_DETECTOR_END_MESSAGE)) {
        deactivateModules();
    }
    delete (msg);
}

void NA_Detector::activateModules() {
    char msgCaption[30];

    // Concatenate the <detectorType> + Activate
    opp_strcpy(msgCaption, detectorType);
    strcat(msgCaption, NA_DETECTOR_ACTIVATE_TAG);

    // Generate the specific detection controller message.
    // This method belongs to the specific detection controller.
    cMessage *msg = check_and_cast<cMessage *>(
            generateDetectionMessage(msgCaption));
    EV<< "\n\n";
    LOG << "-----------------------------------\n";
    LOG << "ACTIVATING HACKED MODULES\n";
    LOG << "-----------------------------------\n";

    sendMessageToHackedModules(msg);
}

void NA_Detector::deactivateModules() {

    char msgCaption[30];

    // Concatenate the <detectorType> + Activate
    opp_strcpy(msgCaption, detectorType);
    strcat(msgCaption, NA_DETECTOR_DEACTIVATE_TAG);

    // Generate the specific detection controller message.
    // This method belongs to the specific detection controller.
    cMessage *msg = check_and_cast<cMessage *>(
            generateDetectionMessage(msgCaption));

    EV<< "\n\n";
    LOG << "-----------------------------------\n";
    LOG << "DEACTIVATING HACKED MODULES\n";
    LOG << "-----------------------------------\n";

    sendMessageToHackedModules(msg);
}

void NA_Detector::getDataFromModules() {
    char msgCaption[30];

    // Concatenate the <detectorType> + GetData
    opp_strcpy(msgCaption, detectorType);
    strcat(msgCaption, NA_DETECTOR_GET_DATA);

    // Generate the specific detection controller message.
    // This method belongs to the specific detection controller.
    cMessage *msg = check_and_cast<cMessage *>(
            generateDetectionMessage(msgCaption));

    EV<< "\n\n";
    LOG << "-----------------------------------\n";
    LOG << "ASKING HACKED MODULES FOR DATA\n";
    LOG << "-----------------------------------\n";

    sendMessageToHackedModules(msg);
}

void NA_Detector::sendMessageToHackedModules(cMessage *msg) {

    unsigned int i;
    NA_HackedModule *modHacked;

    for (i = 0; i < modList.size(); i++) {
        LOG << "Module: " << modList[i]->getFullPath() << "\n";
        if (modList[i]->isSimple()) { // Activation is only done in simple modules (implemented in C++ classes).

            modHacked = dynamic_cast<NA_HackedModule *>(modList[i]);

            LOG << "--> Sending message: " << msg->getFullName() << "\n";
            // Send the message to the specific hacked module
            cMessage *msgCopy = msg->dup();
            modHacked->handleMessageFromDetectionController(msgCopy, this);
        } else {
            LOG << "--> Message not sent. Not a simple module.\n";
        }
    }
    delete (msg);
    LOG << "-----------------------------------\n";
}

cMessage *NA_Detector::generateDetectionMessage(const char *name) {

    LOG << "ERROR: IN NA_DETECTOR GENERATE DETECTION MESSAGE FUNCTION\n";
    cMessage *msg = new cMessage(name);
    return msg;
}

void NA_Detector::performDetection() {
    LOG << "ERROR: IN NA_DETECTION PERFORM DETECTION FUNCTION\n";
}

void NA_Detector::handleDataMessage(cMessage *msg) {
    LOG << "ERROR: IN NA_DETECTION HANDLE DATA MESSAGE FUNCTION\n";
}

void NA_Detector::triggerResponse() {
    LOG << "ERROR: IN NA_DETECTION TRIGGER RESPONSE FUNCTION\n";
}
