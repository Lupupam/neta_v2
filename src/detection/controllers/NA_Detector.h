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

#ifndef NA_DETECTOR_H_
#define NA_DETECTOR_H_

#include <omnetpp.h>
#include "common/log/NA_NesgLog.h"

/* --------------- CONSTANTS --------------------------------*/
/**
 * Constant for tag Activate in the detection controller message name
 */
#define NA_DETECTOR_ACTIVATE_TAG "Activate"

/**
 * Constant for tag Deactivate in the detection controller message name
 */
#define NA_DETECTOR_DEACTIVATE_TAG "Deactivate"

/**
 * Constant for tag GetData in the detection controller message name
 */
#define NA_DETECTOR_GET_DATA "GetData"

/**
 * Constant for the EndDetection message name
 */
#define NA_DETECTOR_END_MESSAGE "EndDetection"

/**
 * Constant for the StartDetection message name
 */
#define NA_DETECTOR_START_MESSAGE "StartDetection"

/* ---------------- NED MODULE ATTRIBUTES NAMES ------------------ */
/**
 * Constant for the type of the detection parameter
 */
#define NA_DETECTOR_TYPE "detectorType"

/**
 * Constant for the name of the active parameter
 */
#define NA_DETECTOR_ACTIVE "active"

/**
 * Constant for the name of the end time parameter
 */
#define NA_DETECTOR_END_TIME "endTime"

/**
 * Constant for the name of the start time parameter
 */
#define NA_DETECTOR_START_TIME "startTime"

/**
 * @brief Base class containing the base functionality for all detection controllers. This is in charge of
 * the communications between the detection controller and the hacked modules (modules that should be modified to build the detection)
 *
 *
 * @details Among others functionalities, this class is in charge of discover all modules that will be
 * modified (hacked modules) and activated for a specific detection implementation.
 * Each of this modules have the <i>detectorType</i> parameter to identify them.
 * Is also in charge of activate and deactivate the detection, scheduling it (from startime and stoptime parameters), among
 * other funcionalities.
 *
 *
 * @author Gabriel Maciá Fernández, gmacia@ugr.es
 * @date 01/22/2013
 *
 */
class NA_Detector: public cSimpleModule {

private:
    /**
     * String identifying the kind of detection to be striked
     */
    char* detectorType;

    /**
     * List of modules for activation of the detection
     */
    vector<cModule *> modList;

public:
    virtual void handleDataMessage(cMessage *msg);
    virtual void performDetection();


protected:

    /**
     * Log reference
     */
    NA_NesgLog log;


    /**
     * Signal for the detection decision
     */
    static simsignal_t detectionResult;
    static simsignal_t onceDetected;


    /**
     * Method from cSimpleModule class, to initialize the simple module.
     */
    virtual void initialize();

    /**
     * Get the modules (hacked modules) in which the detection should be activated (saved in modList)
     *
     */
    void getDetectorModules();

    /**
     * Schedule the activation/deactivation time of the detection
     */
    void scheduleDetection();

    /**
     * For send the corresponding message to the specifics hacked modules implied in the detection
     *
     * @param msg cMessage, the message of the specific detection and with its specific attributes.
     */
    void sendMessageToHackedModules(cMessage *msg);

    /**
     * Activate the detection in the hacked modules.
     */
    virtual void activateModules();

    /**
     * Deactivate the detection in the hacked modules
     */
    virtual void deactivateModules();

    /**
     * Get detection data from the hacked modules
     */
    virtual void getDataFromModules();
    
    /**
     * Trigger the response to the detected attack
     */
    virtual void triggerResponse();

    /**
     * Method from cSimpleModule that is listening all messages scheduling by the scheduleAt method.
     *
     * @param msg cMessage, the received message.
     */
    virtual void handleMessage(cMessage *msg);

    /**
     * Generate the specific message for an detection. This must be overridden by all detection controllers subclasses.
     * The name of the message, will be automatic generated by NA_detector in the following way:
     * @code
     *
     * <detectorType> + <Activate/Deactivate/GetData>
     *
     * @endcode
     *
     * @param name char, name of the message.
     * @return cMessage, the generated message.
     */
    virtual cMessage *generateDetectionMessage(const char* name);

};

#endif /* NA_DETECTOR_H_ */
