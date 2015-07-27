#ifndef NA_DEFENSE_ADAPTER_H_
#define NA_DEFENSE_ADAPTER_H_

#include <omnetpp.h>
#include "NA_Notification_Module.h"
#include "NodeOperations.h"
#include "NodeStatus.h"
//#include "LifecycleOperation.h"
//#include "NodeOperations.h"
//#include "LifecycleOperation.h"
#include "LifecycleController.h"

class NA_DefenseAdapter;

class NA_DefenseAdapter : public cSimpleModule, public NA_Notification_Module {

public:
    cModule * moduleAdapter;

    /**
     * Overridden function
     */
    void handleMessageFromNotificationController(cPacket *msg);
//    void handleMessageFromDetection(cMessage *msg);
    void handleMessage(cPacket *msg);

    void disableModule(AlertMsgAdaptation *msg);
//    IRoutingTable *routingTable;

    void initializeControl();
    void getNodosUsuario();

    ~NA_DefenseAdapter();
    NA_DefenseAdapter();

protected:
    cModule * controlador;
    cModule * moduloControl;


    /**
         * Overridden function
         */
    void getNotificationControllerModules();
    void getControlModule();
//    virtual void compose_reply(REQMsg *msg);


    virtual void initialize();


};

#endif /* SEND_ALARM_H_ */
