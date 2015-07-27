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
#include "NA_DroppingDetectorStandaloneMessage_m.h"

class NA_DroppingDetectorStandalone: public NA_Detector {

private:
    //Local copy of module data
    long sentRTS;
    long receivedCTS;
    long fordwardedCount;
    long receivedCount;
    long RREQcount;
    long pMob;

    //Legitimate period T switch variable
    bool RREQWindowEnable;

public:
    virtual void performDetection();
    virtual void handleDataMessage(cMessage *msg);

protected:
    static simsignal_t probDrop;

    void sendMessage(cPacket *msg);
    void getModuleAdapter();
    cModule * moduleAdapter;

    /**
     * Overridden function
     */
    virtual cMessage *generateDetectionMessage(const char* name);
    virtual void handleMessage(cMessage *msg);
    virtual void initialize();
    virtual void triggerResponse(double pDrop);



};

#endif
