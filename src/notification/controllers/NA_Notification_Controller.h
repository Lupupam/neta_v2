//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

#ifndef NA_NOTIFICATION_CONTROLLER_H_
#define NA_NOTIFICATION_CONTROLLER_H_

#include "NA_Notification_omnet.h"
#include "NA_Notification_Module.h"
#include "NA_notification_msg_struct_m.h"



class NA_Notification_Controller: public cSimpleModule {

private:

    std::vector<cModule *> modList;
    cModule * notificador; //cambiado notificador

public:

    void sendMessageToDefenseModules(cPacket *msg);
    void sendMessageToNotificationModules(cPacket *msg);


protected:

    virtual void initialize();

    void getDefenseModules();
    void getNotificationModules();

};

#endif /* NA_NOTIFICATION_CONTROLLER_H_ */
