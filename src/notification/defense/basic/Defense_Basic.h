//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

#ifndef DEFENSE_BASIC_H_
#define DEFENSE_BASIC_H_

#include <omnetpp.h>
#include "NA_Notification_Module.h"

class Defense_Basic;


class Defense_Basic : public cSimpleModule, public NA_Notification_Module
{

public:

    /**
     * Overridden function
     */
    void handleMessageFromNotificationController(cPacket *msg);

protected:

    /**
     * Overridden function
     */
    void getNotificationControlllerModules();
    virtual void compose_reply(REQMsg *msg);
    virtual uint32_t calcular_variable(uint32_t idNodo, REQMsg_extension datos);
    virtual void sendMessage(cPacket *msg);

    virtual void initialize();

    virtual void handleMessage(cMessage *msg);

};

#endif /* DEFENSE_BASIC_H_ */
