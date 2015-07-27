#ifndef NA_MODULE_ADAPTER_H_
#define NA_MODULE_ADAPTER_H_

#include <omnetpp.h>
#include "NA_Notification_Module.h"

class NA_ModuleAdapter;

class NA_ModuleAdapter : public cSimpleModule, public NA_Notification_Module {

public:
    cModule * moduleAdapter;

    /**
     * Overridden function
     */
    void handleMessageFromNotificationController(cPacket *msg);
    void handleMessageFromDetection(cMessage *msg);
    void handleMessage(cPacket *msg);

    void sendMessage(cPacket *msg);
    uint8_t convertirEnUint8_t(double dato, int max);
//    virtual void handleMessage(cMessage *msg); //NA_ResponseMessage *data
    ~NA_ModuleAdapter();
    NA_ModuleAdapter();

protected:
    cModule * controlador;
    cModule * moduloControl;


    void getNotificationControllerModules();
    virtual void compose_reply(REQMsg *msg);



    virtual void initialize();


};

#endif /* SEND_ALARM_H_ */
