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

#ifndef NA_IEEE80211MAC_H_
#define NA_IEEE80211MAC_H_

#include <Ieee80211Mac.h>
#include <omnetpp.h>
#include "common/log/NA_NesgLog.h"
#include "NA_HackedModule.h"
#include "NA_DroppingDetectorStandaloneMessage_m.h"
#include "NA_DroppingDetectorDistributedMessage_m.h"

class INET_API NA_Ieee80211Mac: public Ieee80211Mac, public NA_HackedModule{
private:
    NA_NesgLog log;

    //Detectition Distributed
    bool droppingDDetectionIsActive;

    //Detection Standalone counters
    long sentRTS;
    long auxSentRTS;
    long receivedCTS;
    bool droppingSADetectionIsActive;
    bool validDetectionRTSFrame;
    long pMob;

    //Restart counters fuction
    virtual void restartDetectionCounters();

    //Detection controller pointer, used for sniffed packet trigger callback
    NA_Detector *detectionDController;


public:
    void handleMessageFromDetectionController(cMessage *msg, NA_Detector *controller);

protected:
    virtual int numInitStages() const {return 2;}
    virtual void initialize(int stage);
    virtual void sendRTSFrame(Ieee80211DataOrMgmtFrame *frameToSend);
    virtual void handleWithFSM(cMessage *msg);
    virtual void promiscousFrame(cMessage *msg);
    virtual void handleLowerMsg(cPacket *msg);

};
#endif
