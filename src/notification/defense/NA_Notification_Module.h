//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

#ifndef NA_NOTIFICATION_MODULE_H_
#define NA_NOTIFICATION_MODULE_H_

#include <omnetpp.h>
#include "NA_Notification_Controller.h"
#include "NA_Notification_omnet.h"
#include "NA_notification_msg_struct_m.h"


class NA_Notification_Module {

private:

protected:

    cModule * controlador;
    int respuestas;
    double tiempo;

    virtual void getNotificationControlllerModules();

    virtual void newAlert(AlertMsg *msg);
    virtual void newAlert(AlertMsgAdaptation *msg);
    virtual void newREQ(REQMsg *msg);
    virtual void newREP(REPMsg *msg);

    virtual void compose_reply(REQMsg *msg);

    virtual uint32_t calcular_variable(uint32_t idNodo, REQMsg_extension datos);
    virtual void sendMessage(cPacket *msg);


public:

    virtual void handleMessageFromNotificationController(cPacket *msg);

};

#endif /* NA_NOTIFICATION_MODULE_H_ */
