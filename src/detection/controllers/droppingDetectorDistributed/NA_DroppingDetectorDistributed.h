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

#ifndef NA_DROPPINGDETECTOR_H_
#define NA_DROPPINGDETECTOR_H_

#include "NA_Detector.h"
#include "NA_DroppingDetectorDistributedMessage_m.h"
#include "IPv4Address.h"
#include "MACAddress.h"

typedef struct{
    char id[50];
    uint32_t ip;
    uint64_t mac;
    long sentRTS;
    long sentRTSaux;
    bool maxRTS;
    long receivedCTS;
    long receivedCTSaux;
    bool CTSwaitingNextFrame;
    long fordwardedCount;
    long receivedCount;
    long RREQcount;
    bool RREQWindowEnable;
    bool pMob;
}DistributedNodeInfo;

class NA_DroppingDetectorDistributed: public NA_Detector {

private:

    vector<DistributedNodeInfo> dNodes;
    simtime_t lastTimestamp;

    void restartNodeInfo(int i);

public:
    virtual void performDetection();
    virtual void handleDataMessage(cMessage *msg);

protected:

    static simsignal_t probDrop;

    /**
     * Overridden function
     */
    virtual cMessage *generateDetectionMessage(const char* name);
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
    virtual int numInitStages() const {return 3;}
    virtual void triggerResponse(double pDrop, int i);
};

#endif
