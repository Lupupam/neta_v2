//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

#ifndef NA_NOTIFICATION_H_
#define NA_NOTIFICATION_H_

#include "IInterfaceTable.h"
#include "InterfaceEntry.h"
#include "InterfaceTableAccess.h"
#include "IPSocket.h"
#include "IPvXAddressResolver.h"
#include "IPvXAddress.h"
#include "IPv4Address.h"
#include "IPv4ControlInfo.h"
#include "IPv4Datagram.h"
#include "IPv4InterfaceData.h"
#include "NA_Notification_Controller.h"
#include "NA_notification_msg_struct_m.h"
#include "UDPPacket.h"

//class NA_Notification;

#define ALERTMSG   1
#define REQMSG     2
#define REPMSG     3

#define ALERTMSG_size   5
#define REQMSG_size     3
#define REPMSG_size     3


class NA_Notification : public cSimpleModule
{

  private:

    cModule * controlador;

    int protocolo;
    uint32_t srcAddr;
    IPv4Address srcAddress;
    IPv4Address destAddress;
    IPv4Address broadcastAddress;
    int srcPort;
    int destPort;
    simtime_t marcaTemporal;
    double marcaT;
    double delay;
    int idMensaje;
    IInterfaceTable *inet_ift;
    std::vector<int> ieWlanId;

    typedef std::multimap<uint32_t, int> NotificationTableMap;
    NotificationTableMap notificationTableMap;


  public:

    NA_Notification();
    ~NA_Notification();
    virtual void handleMessageFromNotificationController(cPacket *msg);
    static AlertMsg *alertMsg_create(uint8_t evento, uint8_t severidad, uint8_t confiabilidad, uint32_t idMalicioso);
    static AlertMsgAdaptation *alertMsg_createAdaptation(uint8_t evento, uint8_t severidad, uint8_t confiabilidad, const char* idMalicioso);
    static AlertMsg *alertMsg_create(uint8_t longitudTotal, uint8_t evento, uint8_t severidad, uint8_t confiabilidad, uint32_t idMalicioso, AlertMsg_extension datosOpcionales[]);
    static AlertMsg *alertMsg_addExtension(AlertMsg *msg, AlertMsg_extension datosOpcionales);
    static AlertMsg_extension alertExtension_create(uint8_t tipo, uint8_t longitud, uint8_t datos);

    static REQMsg *reqMsg_create(uint16_t nodos, uint16_t variables, uint32_t idNodoSolicitado[], REQMsg_extension datos[]);
    static REQMsg_extension reqExtension_create(uint8_t idProtocolo, uint32_t idVariable);

    static REPMsg *repMsg_create(uint16_t nodos, uint16_t variables, uint32_t idNodoSolicitante,  uint32_t idSolicitud,  uint32_t idNodoInformado[], REPMsg_extension datos[]);
    static REPMsg_extension repExtension_create(uint8_t idProtocolo, uint32_t idVariable, uint32_t valorVariable);

  protected:

    virtual cModule *getNotificationControllerModule();

    virtual void send_alert(AlertMsg *msg);
    virtual void alertMsg_process(AlertMsg *msg);

    virtual void send_req(REQMsg *msg);
    virtual void reqMsg_process(REQMsg *msg);

    virtual void send_rep(REPMsg *msg);
    virtual void repMsg_process(REPMsg *msg);

    void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();

    virtual bool table_find(uint32_t nodo, int mensaje);
    virtual InterfaceEntry *getInterfaceEntryById(int id) const {return inet_ift->getInterfaceById(id);}
    virtual void sendToIP(NotificationMsg *msg, int srcPort, IPv4Address destAddr, int destPort, int ttl, double delay, int  index);
    virtual void sendToIP(NotificationMsg *msg, int srcPort, IPv4Address destAddr, int destPort, int ttl, double delay, InterfaceEntry  *ie);

};

#endif /* NA_NOTIFICATION_H_ */

