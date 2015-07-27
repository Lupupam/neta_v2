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

#include "NA_IPv4.h"
#include <iostream>
#include <string.h>
#include "IPv4Datagram.h"
#include "NA_Detector.h"
#include "InterfaceTableAccess.h"
#include "IPv4ControlInfo.h"

#include "NodeOperations.h"
#include "NodeStatus.h"
#include "NotificationBoard.h"
#include "Ieee802Ctrl_m.h"//Prueba

#include <AbstractQueue.h>


#include <IPv4Datagram.h>

using std::cout;

simsignal_t NA_IPv4::dropSignal = SIMSIGNAL_NULL;
simsignal_t NA_IPv4::rcvdPktSignal = SIMSIGNAL_NULL;
simsignal_t NA_IPv4::delaySignal = SIMSIGNAL_NULL;

Define_Module(NA_IPv4);

void NA_IPv4::initialize(int stage) {

    // Dropping attack initialization
    numDrops = 0;
    dropSignal = registerSignal("droppings");
    droppingAttackProbability = 0;
    droppingAttackIsActive = false;

    // Delay attack initialization
    delayAttackIsActive = false;
    delayAttackProbability = 0;
    numDelays = 0;
    delaySignal = registerSignal("delayed");
    totalDelayTime = 0;
    delayAttackValue = NULL;

    // Number of data packet received
    numRecvPacket = 0;
    rcvdPktSignal = registerSignal("rcvdPkt");

    //Detection restart
    restartDetectionCounters();
    droppingSADetectionIsActive = false;

        LOG << "NA_IPv4: inizialize\n";

    IPv4::initialize(stage);
}

void NA_IPv4::restartDetectionCounters() {
    LOG << "NA_IPv4: Restarting detection counters\n";
    fordwardedCount = 0;
    receivedCount = 0;
}

void NA_IPv4::handleMessageFromDetectionController(cMessage *msg, NA_Detector *controller) {

    // It is necessary to call Enter_Method for doing context switching (4.10 of User Manual)
    Enter_Method
    ("NA_IPv4: handle message from detection controller");

    LOG << "NA_IPv4: Received message: " << msg->getFullName() << "\n";

    if (not strcmp(msg->getFullName(), "droppingSAActivate")) {
        restartDetectionCounters();
        droppingSADetectionIsActive = true;
        NA_DroppingDetectorStandaloneMessage *msgDropping =
                dynamic_cast<NA_DroppingDetectorStandaloneMessage *>(msg);
        eventWindowSize = msgDropping->getEventWindowSize();
        this->detectionSAController = controller;
    } else if (not strcmp(msg->getFullName(), "droppingSADeactivate")) {
        restartDetectionCounters();
        droppingSADetectionIsActive = false;
    } else if (not strcmp(msg->getFullName(), "droppingSAGetData")) {
        NA_DroppingDetectorStandaloneMessage *data =
                new NA_DroppingDetectorStandaloneMessage("droppingSAIPData");
        data->setFordwardedCount(fordwardedCount);
        data->setReceivedCount(receivedCount);
        this->detectionSAController = controller;
        this->detectionSAController->handleDataMessage(data);
    }
    delete (msg);
}

void NA_IPv4::handleMessageFromAttackController(cMessage *msg) {

    // It is necessary to call Enter_Method for doing context switching (4.10 of User Manual)
    Enter_Method("NA_IPv4: handle message from attack controller");

    LOG << "NA_IPv4: Received message: " << msg->getFullName() << "\n";

    /*-------------------------- DROPPING ATTACK -------------------------*/
    if (not strcmp(msg->getFullName(), "droppingActivate")) {
        NA_DroppingMessage *dmsg;
        dmsg = check_and_cast<NA_DroppingMessage *>(msg);
        LOG << "--> Activating module NA_IPv4 for Dropping Attack...\n";
        LOG << "    Dropping Attack Probability received: "
                << dmsg->getDroppingAttackProbability() << "\n";
        //Now dropping attack is activated in this module
        droppingAttackIsActive = true;
        droppingAttackProbability = dmsg->getDroppingAttackProbability();
        delete (msg);

    } else if (not strcmp(msg->getFullName(), "droppingDeactivate")) {
        NA_DroppingMessage *dmsg;
        dmsg = check_and_cast<NA_DroppingMessage *>(msg);
        LOG << "Deactivating module NA_IPv4 for Dropping Attack...\n";
        //Now dropping attack is deactivated
        droppingAttackIsActive = false;
        delete (msg);

        /*-------------------------- DELAY ATTACK -------------------------*/

    } else if (not strcmp(msg->getFullName(), "delayActivate")) {
        NA_DelayMessage *dmsg;
        dmsg = check_and_cast<NA_DelayMessage *>(msg);
        LOG << "--> Activating module NA_IPv4 for Delay Attack...\n";
        LOG << "    Delay Attack Probability received: "
                << dmsg->getDelayAttackProbability() << "\n";
        LOG << "    Delay Attack Value received: "
                << dmsg->getDelayAttackValue() << "\n";
        delayAttackIsActive = true;
        delayAttackProbability = dmsg->getDelayAttackProbability();
        delayAttackValue = dmsg->getDelayAttackValue();
        delete (msg);

    } else if (not strcmp(msg->getFullName(), "delayDeactivate")) {
        NA_DelayMessage *dmsg;
        dmsg = check_and_cast<NA_DelayMessage *>(msg);
        LOG << "Deactivating module NA_IPv4 for Delay Attack...\n";
        delayAttackIsActive = false;
        delayAttackValue = NULL;
        delete (msg);

    } else {
        LOG
                << "ERROR: Message unknown in NA_IPv4::handleMessageFromAttackController. Msg: "
                << msg->getFullName() << "\n";
    }
}

void NA_IPv4::handleIncomingDatagram(IPv4Datagram *datagram, const InterfaceEntry *fromIE) {

    ASSERT(datagram);
    ASSERT(fromIE);

    //cout << simTime() << ": Incoming packet: " << datagram->getFullPath() << endl;
    //cout << simTime() << ": Source address: " << datagram->getSrcAddress().str() << endl;
    //cout << simTime() << ": Destination address: " << datagram->getDestAddress().str() << endl;

    // Count the number of total data packet received, for statistics.
    if (!strncmp(datagram->getName(), PING_DATA, 4)
            || !strncmp(datagram->getName(), UDP_DATA, 3)
            || !strncmp(datagram->getName(), TCP_DATA, 3)) {
        numRecvPacket++; // The number of packets is updated
        emit(rcvdPktSignal, numRecvPacket); // Sending of the signal indicating that we have received a new data packet.

        //Detection received counter
        if (droppingSADetectionIsActive) {

            IPv4Address &destAddr = datagram->getDestAddress();
            const IPv4Route *re = rt->findBestMatchingRoute(destAddr);
            if(!rt->isLocalAddress(destAddr) && re){ //Checking if this node is not the destination and it has a route to the destination
                //cout << this->getFullPath() << ": Reiceived a packet to: " << destAddr << " route: " << re << "\n";
                receivedCount++;
            }

            //Detection window trigger
            if (receivedCount >= eventWindowSize && detectionSAController != NULL) {
                LOG << "NA_IPv4: Event window size reached. Calling detection procedure.\n";
                detectionSAController->performDetection();
            }

        }
    }

    //Packet is a ping/UDP/TCP (data packet)
    if (droppingAttackIsActive) {
        LOG << "Received packet after activating dropping attack ... " << "\n";
        if (!strncmp(datagram->getName(), PING_DATA, 4)
                || !strncmp(datagram->getName(), UDP_DATA, 3)
                || !strncmp(datagram->getName(), TCP_DATA, 3)) {
            LOG << "Is a valid packet for dropping ..." << "\n";
            if (uniform(0, 1) < droppingAttackProbability) {
                numDrops++; // The number of droppings is updated
                emit(dropSignal, numDrops); // Sending of the signal indicating a drop
                LOG << "Discarding packet: " << datagram->getName() << ": "
                        << numDrops << " dropping times." << endl;
                cout << simTime() << ": Discarding packet: "
                        << datagram->getName() << endl;
                delete datagram; //Deletes the datagram thus calling its destructor
            } else {
                IPv4::handleIncomingDatagram(datagram, fromIE);
            }
        } else { //Packet is not a data packet --> normal behavior
            IPv4::handleIncomingDatagram(datagram, fromIE);

        }

    } else { // --> Normal behavior.
        IPv4::handleIncomingDatagram(datagram, fromIE);
    }
}

simtime_t NA_IPv4::startService(cPacket *msg) {

    // The value for the variable "delay" is obtained in QueueBase::initialize from the .ned parameter "procDelay".
    // Here, the delay attack add a new delay.

    double delayAttack = 0;

    if (delayAttackIsActive) {
        if (delayAttackValue != NULL) {
            if (!strncmp(msg->getName(), PING_DATA, 4)
                    || !strncmp(msg->getName(), UDP_DATA, 3)
                    || !strncmp(msg->getName(), TCP_DATA, 3)) {
                if (uniform(0, 1) < delayAttackProbability) {
                    delayAttack = delayAttackValue->doubleValue();
                    if (delayAttack < 0)
                        delayAttack = 0; //Avoid negative delays from a random distribution
                    numDelays++; // The number of packets delayed is updated
                    emit(delaySignal, numDelays); // Sending of the signal indicating a drop
                    LOG << "(NA_IPv4) Applied delay of: " << delayAttack
                            << "s. Packet name: " << msg->getFullName() << endl;
                    //cout << simTime() << ": (NA_IPv4) Applied delay of: " << delayAttack << "s. Packet name: " << msg->getFullName() << "\n";
                }
            }
        }
    }
    return delayAttack + delay;
}


void NA_IPv4::routeUnicastPacket(IPv4Datagram *datagram, const InterfaceEntry *fromIE, const InterfaceEntry *destIE, IPv4Address requestedNextHopAddress)
{
    IPv4Address destAddr = datagram->getDestAddress();

    EV << "Routing datagram `" << datagram->getName() << "' with dest=" << destAddr << ": ";

    IPv4Address nextHopAddr;
    // if output port was explicitly requested, use that, otherwise use IPv4 routing
    if (destIE)
    {
        EV << "using manually specified output interface " << destIE->getName() << "\n";
        // and nextHopAddr remains unspecified
        if (!requestedNextHopAddress.isUnspecified())
            nextHopAddr = requestedNextHopAddress;
         // special case ICMP reply
        else if (destIE->isBroadcast())
        {
            // if the interface is broadcast we must search the next hop
            const IPv4Route *re = rt->findBestMatchingRoute(destAddr);
            if (re && re->getInterface() == destIE)
                nextHopAddr = re->getGateway();
        }
    }
    else
    {
        // use IPv4 routing (lookup in routing table)
        const IPv4Route *re = rt->findBestMatchingRoute(destAddr);
        if (re)
        {
            destIE = re->getInterface();
            nextHopAddr = re->getGateway();
        }
    }

    if (!destIE) // no route found
    {
        EV << "unroutable, sending ICMP_DESTINATION_UNREACHABLE\n";
        numUnroutable++;
        icmpAccess.get()->sendErrorMessage(datagram, fromIE ? fromIE->getInterfaceId() : -1, ICMP_DESTINATION_UNREACHABLE, 0);

    }
    else // fragment and send
    {
        EV << "output interface is " << destIE->getName() << ", next-hop address: " << nextHopAddr << "\n";
        numForwarded++;

        if (droppingSADetectionIsActive) {
            if (!strncmp(datagram->getName(), PING_DATA, 4)
                    || !strncmp(datagram->getName(), UDP_DATA, 3)
                    || !strncmp(datagram->getName(), TCP_DATA, 3)) {

                //Detection forwarded counter
                if(!datagram->getSrcAddress().isUnspecified()){ //Unspecified source address seems to be from the own packets. Detection doesn't count them.
                    fordwardedCount++;
                }
            }
        }

        fragmentAndSend(datagram, destIE, nextHopAddr);
    }
}

void NA_IPv4::sendDatagramToOutput(IPv4Datagram *datagram, const InterfaceEntry *ie, IPv4Address nextHopAddr)
{
    {
        bool isIeee802Lan = ie->isBroadcast() && !ie->getMacAddress().isUnspecified(); // we only need/can do ARP on IEEE 802 LANs
        if (!isIeee802Lan) {
            sendPacketToNIC(datagram, ie);
        }
        else {
            if (nextHopAddr.isUnspecified()) {
                if (useProxyARP) {
                    nextHopAddr = datagram->getDestAddress();
                    EV << "no next-hop address, using destination address " << nextHopAddr << " (proxy ARP)\n";
                }
                else {
                    throw cRuntimeError(datagram, "Cannot send datagram on broadcast interface: no next-hop address and Proxy ARP is disabled");
                }
            }

            MACAddress nextHopMacAddr;  // unspecified
            nextHopMacAddr = resolveNextHopMacAddress(datagram, nextHopAddr, ie);

            if (nextHopMacAddr.isUnspecified())
            {
                if (arp->deletePacket(nextHopAddr))
                    delete datagram;
                else
                {
                    pendingPackets[nextHopAddr].insert(datagram);
                    arp->startAddressResolution(nextHopAddr, ie);
                }
            }
            else
            {
                ASSERT2(pendingPackets.find(nextHopAddr) == pendingPackets.end(), "IPv4-ARP error: nextHopAddr found in ARP table, but IPv4 queue for nextHopAddr not empty");
                sendPacketToIeee802NIC(datagram, ie, nextHopMacAddr, ETHERTYPE_IPv4);
            }
        }
    }
}





