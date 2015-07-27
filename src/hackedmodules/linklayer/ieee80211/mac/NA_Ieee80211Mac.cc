#include "NA_Ieee80211Mac.h"
#include "RadioState.h"
#include "IInterfaceTable.h"
#include "InterfaceTableAccess.h"
#include "PhyControlInfo_m.h"
#include "AirFrame_m.h"
#include "Radio80211aControlInfo_m.h"
#include "Ieee80211eClassifier.h"
#include "Ieee80211DataRate.h"
#include "NA_DroppingDetectorStandalone.h"
#include "IPv4Datagram.h"
#include "UDPPacket.h"
#include "UDPControlInfo.h"
#include "NA_aodv_msg_struct.h"
#include "ManetAddress.h"


using std::cout;

Define_Module(NA_Ieee80211Mac);

void NA_Ieee80211Mac::initialize(int stage) {

    if (stage == 0) {
        LOG << "NA_Ieee80211Mac: inizialize\n";
        restartDetectionCounters();
        droppingSADetectionIsActive = false;
        droppingDDetectionIsActive = false;
    }
    Ieee80211Mac::initialize(stage);

}

void NA_Ieee80211Mac::restartDetectionCounters() {
    LOG << "NA_Ieee80211Mac: Restarting detection counters\n";
    sentRTS = 0;
    auxSentRTS = 0;
    receivedCTS = 0;
    pMob = 0;
    validDetectionRTSFrame = false;
}

void NA_Ieee80211Mac::handleMessageFromDetectionController(cMessage *msg,
        NA_Detector *controller) {

    // It is necessary to call Enter_Method for doing context switching (4.10 of User Manual)
    Enter_Method
    ("NA_Ieee80211Mac: handle message from detection controller");

    LOG << "NA_Ieee80211Mac: Received message: " << msg->getFullName() << "\n";

    if (not strcmp(msg->getFullName(), "droppingSAActivate")) {
        restartDetectionCounters();
        droppingSADetectionIsActive = true;
    } else if (not strcmp(msg->getFullName(), "droppingSADeactivate")) {
        restartDetectionCounters();
        droppingSADetectionIsActive = false;
    } else if (not strcmp(msg->getFullName(), "droppingSAGetData")) {
        NA_DroppingDetectorStandaloneMessage *data =
                new NA_DroppingDetectorStandaloneMessage("droppingSAMACData");
        data->setReceivedCTS(receivedCTS);
        data->setSentRTS(sentRTS);
        data->setPMob(pMob);
        controller->handleDataMessage(data);
    } else if (not strcmp(msg->getFullName(), "droppingDActivate")) {
        droppingDDetectionIsActive = true;
        this->detectionDController = controller;
    } else if (not strcmp(msg->getFullName(), "droppingDDectivate")) {
        droppingDDetectionIsActive = false;
    }
    delete (msg);
}

void NA_Ieee80211Mac::sendRTSFrame(Ieee80211DataOrMgmtFrame *frameToSend) {
    if (droppingSADetectionIsActive && !strncmp(frameToSend->getName(), "UDP", 3)) {
        auxSentRTS++;
        validDetectionRTSFrame = true;
    }
    //cout << "[" << this->getFullPath() << "] Enviando RTS: " << frameToSend->getName()<< " [" << auxSentRTS << "] \n";
    //cout << this->getFullPath() << " at [" << simTime() << "] has sent a RTS frame. Total: " << sentRTS << "\n";
    Ieee80211Mac::sendRTSFrame(frameToSend);
}

void NA_Ieee80211Mac::promiscousFrame(cMessage *msg)
{
    if(droppingDDetectionIsActive && detectionDController != NULL){
        NA_DroppingDetectorDistributedMessage *data = new NA_DroppingDetectorDistributedMessage("droppingDMACData");
        data->setTimestamp(msg->getCreationTime());
        if(!strcmp(msg->getName(),"wlan-rts")){
            Ieee80211RTSFrame *rtsFrame = check_and_cast<Ieee80211RTSFrame*>(msg);
            data->setRTS(true);
            data->setSrcMACAdd(rtsFrame->getTransmitterAddress().getInt());
            data->setDstMACAdd(rtsFrame->getReceiverAddress().getInt());
            detectionDController->handleDataMessage(data);
        }else if(!strcmp(msg->getName(),"wlan-cts")){
            Ieee80211CTSFrame *ctsFrame = check_and_cast<Ieee80211CTSFrame*>(msg);
            data->setCTS(true);
            data->setDstMACAdd(ctsFrame->getReceiverAddress().getInt());
            detectionDController->handleDataMessage(data);
        }else if(!strncmp(msg->getName(),"UDP",3) && msg->getKind() == UDP_I_DATA){
            Ieee80211DataFrame *frame = check_and_cast<Ieee80211DataFrame *>(msg);
            IPv4Datagram *datagram = check_and_cast<IPv4Datagram *>(frame->decapsulate());
            data->setDATA(true);
            data->setSrcIPAdd(datagram->getSrcAddress().getInt());
            data->setDstIPAdd(datagram->getDestAddress().getInt());
            data->setSrcMACAdd(frame->getTransmitterAddress().getInt());
            data->setDstMACAdd(frame->getReceiverAddress().getInt());
            delete datagram;
            detectionDController->handleDataMessage(data);
        }else if(!strcmp(msg->getName(),"RouteReply") || !strcmp(msg->getName(),"RouteReplyAck")){
            Ieee80211DataFrame *frame = check_and_cast<Ieee80211DataFrame *>(msg->dup());
            IPv4Datagram *datagram = check_and_cast<IPv4Datagram *>(frame->decapsulate());

            data->setSrcIPAdd(datagram->getSrcAddress().getInt());
            data->setDstIPAdd(datagram->getDestAddress().getInt());
            data->setSrcMACAdd(frame->getTransmitterAddress().getInt());
            data->setDstMACAdd(frame->getReceiverAddress().getInt());

            delete datagram;
            delete frame;
            detectionDController->handleDataMessage(data);
        }
        delete data;

        //DEBUG ISSUES
        /*if (!strcmp(this->getFullPath().c_str(),"TresNodes.node[2].wlan[0].mac") || !strcmp(this->getFullPath().c_str(),"TresNodes.node[4].wlan[0].mac")){
            if(!strcmp(msg->getName(),"wlan-rts")){
                cout << this->getFullPath() << " at [" << simTime() << "] has listen a RTS frame\n";
                Ieee80211RTSFrame *rtsFrame = check_and_cast<Ieee80211RTSFrame*>(msg);
                cout << "Source MAC: " << rtsFrame->getTransmitterAddress() << "\n";
                cout << "Destination MAC: " << rtsFrame->getReceiverAddress() << "\n";
                cout << "Timestamp: " << msg->getCreationTime() << "\n";
            }else if(!strcmp(msg->getName(),"wlan-cts")){
                cout << this->getFullPath() << " at [" << simTime() << "] has listen a CTS frame\n";
                Ieee80211CTSFrame *ctsFrame = check_and_cast<Ieee80211CTSFrame*>(msg);
                cout << "Destination MAC: " << ctsFrame->getReceiverAddress() << "\n";
                cout << "Timestamp: " << msg->getCreationTime() << "\n";
            }else if(!strncmp(msg->getName(),"UDP",3) && msg->getKind() == UDP_I_DATA){
                cout << this->getFullPath() << " at [" << simTime() << "] has listen a UDP datagram\n";
                Ieee80211DataFrame *frame = check_and_cast<Ieee80211DataFrame *>(msg);
                IPv4Datagram *datagram = check_and_cast<IPv4Datagram *>(frame->decapsulate());
                cout << "Source IP: " << datagram->getSrcAddress() << "\n";
                cout << "Destination IP: " << datagram->getDestAddress() << "\n";
                cout << "Source MAC: " << frame->getTransmitterAddress() << "\n";
                cout << "Destination MAC: " << frame->getReceiverAddress() << "\n";
                cout << "Timestamp: " << msg->getCreationTime() << "\n";
                delete datagram;
            }else{
                cout << this->getFullPath() << " at [" << simTime() << "] has listen a " << msg->getName() << " frame\n";
            }*/
    }

    Ieee80211Mac::promiscousFrame(msg);
}

void NA_Ieee80211Mac::handleLowerMsg(cPacket *msg){
    if(droppingDDetectionIsActive && detectionDController != NULL){
        NA_DroppingDetectorDistributedMessage *data = new NA_DroppingDetectorDistributedMessage("droppingDMACData");
        data->setTimestamp(msg->getCreationTime());
        if(!strcmp(msg->getName(),"RREQAodvMsg")){
            Ieee80211DataFrame *frame = check_and_cast<Ieee80211DataFrame *>(msg->dup());
            IPv4Datagram *datagram = check_and_cast<IPv4Datagram *>(frame->decapsulate());
            UDPPacket *udpPacket = check_and_cast<UDPPacket*>(datagram->decapsulate());
            RREQ *aodvMsg = check_and_cast  <RREQ *>(udpPacket->decapsulate());

            data->setRREQ(true);
            data->setOrgAdd(aodvMsg->getOrig_addr().getIPv4().getInt());
            data->setSrcIPAdd(datagram->getSrcAddress().getInt());
            data->setDstIPAdd(datagram->getDestAddress().getInt());
            data->setSrcMACAdd(frame->getTransmitterAddress().getInt());
            data->setDstMACAdd(frame->getReceiverAddress().getInt());

            delete datagram;
            delete udpPacket;
            delete frame;
            delete aodvMsg;
            detectionDController->handleDataMessage(data);
        }
        delete data;
        
        //DEBUG ISSUES
        /*if (!strcmp(this->getFullPath().c_str(),"TresNodes.node[2].wlan[0].mac") || !strcmp(this->getFullPath().c_str(),"TresNodes.node[4].wlan[0].mac")){
            if(!strcmp(msg->getName(),"RREQAodvMsg")){
                cout << this->getFullPath() << " at [" << simTime() << "] has listen a RREQ frame\n";
                Ieee80211DataFrame *frame = check_and_cast<Ieee80211DataFrame *>(msg->dup());
                IPv4Datagram *datagram = check_and_cast<IPv4Datagram *>(frame->decapsulate());
                UDPPacket *udpPacket = check_and_cast<UDPPacket*>(datagram->decapsulate());
                RREQ *aodvMsg = check_and_cast  <RREQ *>(udpPacket->decapsulate());

                cout << "Origin IP: " << aodvMsg->getOrig_addr().getIPv4() << "\n";
                cout << "Source IP: " << datagram->getSrcAddress() << "\n";
                cout << "Destination IP: " << datagram->getDestAddress() << "\n";
                cout << "Source MAC: " << frame->getTransmitterAddress() << "\n";
                cout << "Destination MAC: " << frame->getReceiverAddress() << "\n";
                cout << "Timestamp: " << msg->getCreationTime() << "\n";

                delete datagram;
                delete udpPacket;
                delete frame;
                delete aodvMsg;
            }
        }*/
    }
    Ieee80211Mac::handleLowerMsg(msg);
}



void NA_Ieee80211Mac::handleWithFSM(cMessage *msg) {
    removeOldTuplesFromDuplicateMap();
    // skip those cases where there's nothing to do, so the switch looks simpler
    if (isUpperMsg(msg) && fsm.getState() != IDLE) {
        if (fsm.getState() == WAITAIFS && endDIFS->isScheduled()) {
            // a difs was schedule because all queues ware empty
            // change difs for aifs
            simtime_t remaint = getAIFS(currentAC) - getDIFS();
            scheduleAt(endDIFS->getArrivalTime() + remaint, endAIFS(currentAC));
            cancelEvent(endDIFS);
        } else if (fsm.getState() == BACKOFF
                && endBackoff(numCategories() - 1)->isScheduled()
                && transmissionQueue(numCategories() - 1)->empty()) {
            // a backoff was schedule with all the queues empty
            // reschedule the backoff with the appropriate AC
            backoffPeriod(currentAC) = backoffPeriod(numCategories() - 1);
            backoff(currentAC) = backoff(numCategories() - 1);
            backoff(numCategories() - 1) = false;
            scheduleAt(endBackoff(numCategories() - 1)->getArrivalTime(),
                    endBackoff(currentAC));
            cancelEvent(endBackoff(numCategories() - 1));
        }
        EV<< "deferring upper message transmission in " << fsm.getStateName() << " state\n";
        return;
    }

    Ieee80211Frame *frame = dynamic_cast<Ieee80211Frame*>(msg);
    int frameType = frame ? frame->getType() : -1;
    int msgKind = msg->getKind();
    logState();
    stateVector.record(fsm.getState());

    if (frame && isLowerMsg(frame)) {
        lastReceiveFailed = (msgKind == COLLISION || msgKind == BITERROR);
        scheduleReservePeriod(frame);
    }

    // TODO: fix bug according to the message: [omnetpp] A possible bug in the Ieee80211's FSM.
    FSMA_Switch(fsm){
        FSMA_State(IDLE)
                                                                                                                                    {
            FSMA_Enter(sendDownPendingRadioConfigMsg());
            /*
         if (fixFSM)
         {
         FSMA_Event_Transition(Data-Ready,
         // isUpperMsg(msg),
         isUpperMsg(msg) && backoffPeriod[currentAC] > 0,
         DEFER,
         //ASSERT(isInvalidBackoffPeriod() || backoffPeriod == 0);
         //invalidateBackoffPeriod();
         ASSERT(false);

         );
         FSMA_No_Event_Transition(Immediate-Data-Ready,
         //!transmissionQueue.empty(),
         !transmissionQueueEmpty(),
         DEFER,
         //  invalidateBackoffPeriod();
         ASSERT(backoff[currentAC]);

         );
         }
             */
            FSMA_Event_Transition(Data-Ready,
                    isUpperMsg(msg),
                    DEFER,
                    ASSERT(isInvalidBackoffPeriod() || backoffPeriod() == 0);
            invalidateBackoffPeriod();
            );
            FSMA_No_Event_Transition(Immediate-Data-Ready,
                    !transmissionQueueEmpty(),
                    DEFER,
                    if (retryCounter() == 0) //  jesjones patch.  TODO: check this particular case, I haven't been sure about this particular case
                        invalidateBackoffPeriod();
            );
            FSMA_Event_Transition(Receive,
                    isLowerMsg(msg),
                    RECEIVE,
            );
                                                                                                                                    }
        FSMA_State(DEFER)
        {
            FSMA_Enter(sendDownPendingRadioConfigMsg());
            FSMA_Event_Transition(Wait-AIFS,
                    isMediumStateChange(msg) && isMediumFree(),
                    WAITAIFS,
                    ;);
            FSMA_No_Event_Transition(Immediate-Wait-AIFS,
                    isMediumFree() || (!isBackoffPending()),
                    WAITAIFS,
                    ;);
            FSMA_Event_Transition(Receive,
                    isLowerMsg(msg),
                    RECEIVE,
                    ;);
        }
        FSMA_State(WAITAIFS)
        {
            FSMA_Enter(scheduleAIFSPeriod());

            FSMA_Event_Transition(EDCAF-Do-Nothing,
                    isMsgAIFS(msg) && transmissionQueue()->empty(),
                    WAITAIFS,
                    ASSERT(0==1);
            ;);
            FSMA_Event_Transition(Immediate-Transmit-RTS,
                    isMsgAIFS(msg) && !transmissionQueue()->empty() && !isMulticast(getCurrentTransmission())
                    && getCurrentTransmission()->getByteLength() >= rtsThreshold && !backoff(),
                    WAITCTS,
                    sendRTSFrame(getCurrentTransmission());
            oldcurrentAC = currentAC;
            cancelAIFSPeriod();
            );
            FSMA_Event_Transition(Immediate-Transmit-Multicast,
                    isMsgAIFS(msg) && isMulticast(getCurrentTransmission()) && !backoff(),
                    WAITMULTICAST,
                    sendMulticastFrame(getCurrentTransmission());
            oldcurrentAC = currentAC;
            cancelAIFSPeriod();
            );
            FSMA_Event_Transition(Immediate-Transmit-Data,
                    isMsgAIFS(msg) && !isMulticast(getCurrentTransmission()) && !backoff(),
                    WAITACK,
                    sendDataFrame(getCurrentTransmission());
            oldcurrentAC = currentAC;
            cancelAIFSPeriod();
            );
            /*FSMA_Event_Transition(AIFS-Over,
         isMsgAIFS(msg) && backoff[currentAC],
         BACKOFF,
         if (isInvalidBackoffPeriod())
         generateBackoffPeriod();
         );*/
            FSMA_Event_Transition(AIFS-Over,
                    isMsgAIFS(msg),
                    BACKOFF,
                    if (isInvalidBackoffPeriod())
                        generateBackoffPeriod();
            );
            // end the difs and no other packet has been received
            FSMA_Event_Transition(DIFS-Over,
                    msg == endDIFS && transmissionQueueEmpty(),
                    BACKOFF,
                    currentAC = numCategories()-1;
            if (isInvalidBackoffPeriod())
                generateBackoffPeriod();
            );
            FSMA_Event_Transition(DIFS-Over,
                    msg == endDIFS,
                    BACKOFF,
                    for (int i=numCategories()-1; i>=0; i--)
                    {
                        if (!transmissionQueue(i)->empty())
                        {
                            currentAC = i;
                        }
                    }
            if (isInvalidBackoffPeriod())
                generateBackoffPeriod();
            );
            FSMA_Event_Transition(Busy,
                    isMediumStateChange(msg) && !isMediumFree(),
                    DEFER,
                    for (int i=0; i<numCategories(); i++)
                    {
                        if (endAIFS(i)->isScheduled())
                            backoff(i) = true;
                    }
            if (endDIFS->isScheduled()) backoff(numCategories()-1) = true;
            cancelAIFSPeriod();
            );
            FSMA_No_Event_Transition(Immediate-Busy,
                    !isMediumFree(),
                    DEFER,
                    for (int i=0; i<numCategories(); i++)
                    {
                        if (endAIFS(i)->isScheduled())
                            backoff(i) = true;
                    }
            if (endDIFS->isScheduled()) backoff(numCategories()-1) = true;
            cancelAIFSPeriod();

            );
            // radio state changes before we actually get the message, so this must be here
            FSMA_Event_Transition(Receive,
                    isLowerMsg(msg),
                    RECEIVE,
                    cancelAIFSPeriod();
            ;);
        }
        FSMA_State(BACKOFF)
        {
            FSMA_Enter(scheduleBackoffPeriod());
            if (getCurrentTransmission())
            {
                FSMA_Event_Transition(Transmit-RTS,
                        msg == endBackoff() && !isMulticast(getCurrentTransmission())
                        && getCurrentTransmission()->getByteLength() >= rtsThreshold,
                        WAITCTS,
                        sendRTSFrame(getCurrentTransmission());
                oldcurrentAC = currentAC;
                cancelAIFSPeriod();
                decreaseBackoffPeriod();
                cancelBackoffPeriod();
                );
                FSMA_Event_Transition(Transmit-Multicast,
                        msg == endBackoff() && isMulticast(getCurrentTransmission()),
                        WAITMULTICAST,
                        sendMulticastFrame(getCurrentTransmission());
                oldcurrentAC = currentAC;
                cancelAIFSPeriod();
                decreaseBackoffPeriod();
                cancelBackoffPeriod();
                );
                FSMA_Event_Transition(Transmit-Data,
                        msg == endBackoff() && !isMulticast(getCurrentTransmission()),
                        WAITACK,
                        sendDataFrame(getCurrentTransmission());
                oldcurrentAC = currentAC;
                cancelAIFSPeriod();
                decreaseBackoffPeriod();
                cancelBackoffPeriod();
                );
            }
            FSMA_Event_Transition(AIFS-Over-backoff,
                    isMsgAIFS(msg) && backoff(),
                    BACKOFF,
                    if (isInvalidBackoffPeriod())
                        generateBackoffPeriod();
            );
            FSMA_Event_Transition(AIFS-Immediate-Transmit-RTS,
                    isMsgAIFS(msg) && !transmissionQueue()->empty() && !isMulticast(getCurrentTransmission())
                    && getCurrentTransmission()->getByteLength() >= rtsThreshold && !backoff(),
                    WAITCTS,
                    sendRTSFrame(getCurrentTransmission());
            oldcurrentAC = currentAC;
            cancelAIFSPeriod();
            decreaseBackoffPeriod();
            cancelBackoffPeriod();
            );
            FSMA_Event_Transition(AIFS-Immediate-Transmit-Multicast,
                    isMsgAIFS(msg) && isMulticast(getCurrentTransmission()) && !backoff(),
                    WAITMULTICAST,
                    sendMulticastFrame(getCurrentTransmission());
            oldcurrentAC = currentAC;
            cancelAIFSPeriod();
            decreaseBackoffPeriod();
            cancelBackoffPeriod();
            );
            FSMA_Event_Transition(AIFS-Immediate-Transmit-Data,
                    isMsgAIFS(msg) && !isMulticast(getCurrentTransmission()) && !backoff(),
                    WAITACK,
                    sendDataFrame(getCurrentTransmission());
            oldcurrentAC = currentAC;
            cancelAIFSPeriod();
            decreaseBackoffPeriod();
            cancelBackoffPeriod();
            );
            FSMA_Event_Transition(Backoff-Idle,
                    isBackoffMsg(msg) && transmissionQueueEmpty(),
                    IDLE,
                    resetStateVariables();
            );
            FSMA_Event_Transition(Backoff-Busy,
                    isMediumStateChange(msg) && !isMediumFree(),
                    DEFER,
                    cancelAIFSPeriod();
            decreaseBackoffPeriod();
            cancelBackoffPeriod();
            );

        }
        FSMA_State(WAITACK)
        {
            FSMA_Enter(scheduleDataTimeoutPeriod(getCurrentTransmission()));
            FSMA_Event_Transition(Receive-ACK-TXOP,
                    isLowerMsg(msg) && isForUs(frame) && frameType == ST_ACK && txop,
                    WAITSIFS,
                    currentAC = oldcurrentAC;
            if (retryCounter() == 0) numSentWithoutRetry()++;
            numSent()++;
            fr = getCurrentTransmission();
            numBits += fr->getBitLength();
            bits() += fr->getBitLength();

            macDelay()->record(simTime() - fr->getMACArrive());
            if (maxJitter() == 0 || maxJitter() < (simTime() - fr->getMACArrive()))
                maxJitter() = simTime() - fr->getMACArrive();
            if (minJitter() == 0 || minJitter() > (simTime() - fr->getMACArrive()))
                minJitter() = simTime() - fr->getMACArrive();
            EV << "record macDelay AC" << currentAC << " value " << simTime() - fr->getMACArrive() <<endl;
            numSentTXOP++;
            cancelTimeoutPeriod();
            finishCurrentTransmission();
            );
            /*
         FSMA_Event_Transition(Receive-ACK,
         isLowerMsg(msg) && isForUs(frame) && frameType == ST_ACK,
         IDLE,
         currentAC=oldcurrentAC;
         if (retryCounter[currentAC] == 0) numSentWithoutRetry[currentAC]++;
         numSent[currentAC]++;
         fr=getCurrentTransmission();
         numBits += fr->getBitLength();
         bits[currentAC] += fr->getBitLength();

         macDelay[currentAC].record(simTime() - fr->getMACArrive());
         if (maxJitter[currentAC] == 0 || maxJitter[currentAC] < (simTime() - fr->getMACArrive())) maxJitter[currentAC]=simTime() - fr->getMACArrive();
         if (minJitter[currentAC] == 0 || minJitter[currentAC] > (simTime() - fr->getMACArrive())) minJitter[currentAC]=simTime() - fr->getMACArrive();
         EV << "record macDelay AC" << currentAC << " value " << simTime() - fr->getMACArrive() <<endl;

         cancelTimeoutPeriod();
         finishCurrentTransmission();
         );

             */
            /*Ieee 802.11 2007 9.9.1.2 EDCA TXOPs*/
            FSMA_Event_Transition(Receive-ACK,
                    isLowerMsg(msg) && isForUs(frame) && frameType == ST_ACK,
                    DEFER,
                    currentAC = oldcurrentAC;
            if (retryCounter() == 0)
                numSentWithoutRetry()++;
            numSent()++;
            fr = getCurrentTransmission();
            numBits += fr->getBitLength();
            bits() += fr->getBitLength();

            macDelay()->record(simTime() - fr->getMACArrive());
            if (maxJitter() == 0 || maxJitter() < (simTime() - fr->getMACArrive()))
                maxJitter() = simTime() - fr->getMACArrive();
            if (minJitter() == 0 || minJitter() > (simTime() - fr->getMACArrive()))
                minJitter() = simTime() - fr->getMACArrive();
            EV << "record macDelay AC" << currentAC << " value " << simTime() - fr->getMACArrive() <<endl;
            cancelTimeoutPeriod();
            finishCurrentTransmission();
            resetCurrentBackOff();
            );
            FSMA_Event_Transition(Transmit-Data-Failed,
                    msg == endTimeout && retryCounter(oldcurrentAC) == transmissionLimit - 1,
                    IDLE,
                    currentAC = oldcurrentAC;
            giveUpCurrentTransmission();
            txop = false;
            if (endTXOP->isScheduled()) cancelEvent(endTXOP);
            );
            FSMA_Event_Transition(Receive-ACK-Timeout,
                    msg == endTimeout,
                    DEFER,
                    currentAC = oldcurrentAC;
            retryCurrentTransmission();
            txop = false;
            if (endTXOP->isScheduled()) cancelEvent(endTXOP);
            );
            FSMA_Event_Transition(Interrupted-ACK-Failure,
                    isLowerMsg(msg) && retryCounter(oldcurrentAC) == transmissionLimit - 1,
                    RECEIVE,
                    currentAC=oldcurrentAC;
            giveUpCurrentTransmission();
            txop = false;
            if (endTXOP->isScheduled()) cancelEvent(endTXOP);
            );
            FSMA_Event_Transition(Retry-Interrupted-ACK,
                    isLowerMsg(msg),
                    RECEIVE,
                    currentAC=oldcurrentAC;
            retryCurrentTransmission();
            txop = false;
            if (endTXOP->isScheduled()) cancelEvent(endTXOP);
            );
        }
        // wait until multicast is sent
        FSMA_State(WAITMULTICAST)
        {
            FSMA_Enter(scheduleMulticastTimeoutPeriod(getCurrentTransmission()));
            /*
         FSMA_Event_Transition(Transmit-Multicast,
         msg == endTimeout,
         IDLE,
         currentAC=oldcurrentAC;
         finishCurrentTransmission();
         numSentMulticast++;
         );
             */
            ///changed
            FSMA_Event_Transition(Transmit-Multicast,
                    msg == endTimeout,
                    DEFER,
                    currentAC = oldcurrentAC;
            fr = getCurrentTransmission();
            numBits += fr->getBitLength();
            bits() += fr->getBitLength();
            finishCurrentTransmission();
            numSentMulticast++;
            resetCurrentBackOff();
            );
        }
        // accoriding to 9.2.5.7 CTS procedure
        FSMA_State(WAITCTS)
        {
            FSMA_Enter(scheduleCTSTimeoutPeriod());
            FSMA_Event_Transition(Receive-CTS,
                    isLowerMsg(msg) && isForUs(frame) && frameType == ST_CTS,
                    WAITSIFS,
                    //Incresing CTS received counter
                    if (droppingSADetectionIsActive) {
                        if (validDetectionRTSFrame){
                            receivedCTS++;
                            sentRTS += auxSentRTS;
                        }
                        validDetectionRTSFrame = false;
                        auxSentRTS = 0;
                        //cout << "[" << this->getFullPath() << "] Recibido CTS numero: "<< receivedCTS << " Total RTS validos: " << sentRTS << "\n";
                    };
            cancelTimeoutPeriod();
            );
            FSMA_Event_Transition(Transmit-RTS-Failed,
                    msg == endTimeout && retryCounter(oldcurrentAC) == transmissionLimit - 1,
                    IDLE,
                    //RTS sended for a frame has exceeded the SRL
                    if (droppingSADetectionIsActive) {
                        if (validDetectionRTSFrame){
                            pMob++;
                        }
                        validDetectionRTSFrame = false;
                        auxSentRTS = 0;
                    }
            currentAC = oldcurrentAC;
            giveUpCurrentTransmission();
            );
            FSMA_Event_Transition(Receive-CTS-Timeout,
                    msg == endTimeout,
                    DEFER,
                    currentAC = oldcurrentAC;
            retryCurrentTransmission();
            );
        }
        FSMA_State(WAITSIFS)
        {
            FSMA_Enter(scheduleSIFSPeriod(frame));
            FSMA_Event_Transition(Transmit-Data-TXOP,
                    msg == endSIFS && getFrameReceivedBeforeSIFS()->getType() == ST_ACK,
                    WAITACK,
                    sendDataFrame(getCurrentTransmission());
            oldcurrentAC = currentAC;
            );
            FSMA_Event_Transition(Transmit-CTS,
                    msg == endSIFS && getFrameReceivedBeforeSIFS()->getType() == ST_RTS,
                    IDLE,
                    sendCTSFrameOnEndSIFS();
                    finishReception();
            );
            FSMA_Event_Transition(Transmit-DATA,
                    msg == endSIFS && getFrameReceivedBeforeSIFS()->getType() == ST_CTS,
                    WAITACK,
                    sendDataFrameOnEndSIFS(getCurrentTransmission());
            oldcurrentAC = currentAC;
            );
            FSMA_Event_Transition(Transmit-ACK,
                    msg == endSIFS && isDataOrMgmtFrame(getFrameReceivedBeforeSIFS()),
                    IDLE,
                    sendACKFrameOnEndSIFS();
                    finishReception();
            );
        }
        // this is not a real state
        FSMA_State(RECEIVE)
        {
            FSMA_No_Event_Transition(Immediate-Receive-Error,
                    isLowerMsg(msg) && (msgKind == COLLISION || msgKind == BITERROR),
                    IDLE,
                    EV << "received frame contains bit errors or collision, next wait period is EIFS\n";
            numCollision++;
            finishReception();
            );
            FSMA_No_Event_Transition(Immediate-Receive-Multicast,
                    isLowerMsg(msg) && isMulticast(frame) && !isSentByUs(frame) && isDataOrMgmtFrame(frame),
                    IDLE,
                    sendUp(frame);
            numReceivedMulticast++;
            finishReception();
            );
            FSMA_No_Event_Transition(Immediate-Receive-Data,
                    isLowerMsg(msg) && isForUs(frame) && isDataOrMgmtFrame(frame),
                    WAITSIFS,
                    sendUp(frame);
            numReceived++;
            );
            FSMA_No_Event_Transition(Immediate-Receive-RTS,
                    isLowerMsg(msg) && isForUs(frame) && frameType == ST_RTS,
                    WAITSIFS,
            );
            FSMA_No_Event_Transition(Immediate-Receive-Other-backtobackoff,
                    isLowerMsg(msg) && isBackoffPending(), //(backoff[0] || backoff[1] || backoff[2] || backoff[3]),
                    DEFER,
            );

            FSMA_No_Event_Transition(Immediate-Promiscuous-Data,
                    //isLowerMsg(msg) && !isForUs(frame) && isDataOrMgmtFrame(frame), [Removed in order to sniff all kind of frames]
                    isLowerMsg(msg) && !isForUs(frame),
                    IDLE,
                    promiscousFrame(frame);
                    finishReception();
                    numReceivedOther++;
            );
            FSMA_No_Event_Transition(Immediate-Receive-Other,
                    isLowerMsg(msg),
                    IDLE,
                    finishReception();
                    numReceivedOther++;
            );
        }
    }
    EV<<"leaving handleWithFSM\n\t";
    logState();
    stateVector.record(fsm.getState());
    if (simTime() - last > 0.1) {
        for (int i = 0; i < numCategories(); i++) {
            throughput(i)->record(bits(i) / (simTime() - last));
            bits(i) = 0;
            if (maxJitter(i) > 0 && minJitter(i) > 0) {
                jitter(i)->record(maxJitter(i) - minJitter(i));
                maxJitter(i) = 0;
                minJitter(i) = 0;
            }
        }
        last = simTime();
    }
}
