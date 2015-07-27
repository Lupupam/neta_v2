//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

#include "NA_Notification_omnet.h"

const int UDP_HEADER_BYTES = 8;

Define_Module(NA_Notification);


NA_Notification:: NA_Notification()
{
}

/* Destructor for the AODV-UU routing agent */
NA_Notification:: ~ NA_Notification()
{
}

void NA_Notification:: initialize()
{
    srcPort=703;
    destPort=703;
    protocolo=200;
    delay=0.01;
    idMensaje=rand();
    broadcastAddress=IPv4Address((u_int32_t)0xffffffff);
    IPSocket socket(gate("to_ip"));
    socket.registerProtocol(protocolo);
    marcaTemporal=simTime();
    marcaT=SIMTIME_DBL(simTime());

    inet_ift  = InterfaceTableAccess().get();

    for (int i = 0; i < inet_ift->getNumInterfaces(); i++)
    {
        InterfaceEntry * ie =  inet_ift->getInterface(i);
        const char *name= ie->getName();
        if (strstr(name, "wlan") != NULL)
        {
            ieWlanId.push_back(ie->getInterfaceId());
        }
    }

    controlador=getNotificationControllerModule();

    cMessage *msg2 = new cMessage("Inicializar");
    scheduleAt(0.1, msg2);
}

/* Entry-level packet reception */
void NA_Notification::handleMessage (cMessage *msg)
{
    UDPPacket * udpPacket=NULL;
    cMessage *msg_aux=NULL;
    NotificationMsg *not_aux=NULL;

    if (msg->isSelfMessage() && strcmp(msg->getName(),"Inicializar")==0)
    {
        InterfaceEntry  *ie = getInterfaceEntryById(ieWlanId[0]);
        srcAddress =  ie->ipv4Data()->getIPAddress();
        srcAddr=srcAddress.getInt();
        delete msg;
        return;
    }


    if (dynamic_cast<UDPPacket *>(msg))
    {
        udpPacket = check_and_cast<UDPPacket*>(msg);

        if (udpPacket->getDestinationPort()!= 703)
        {
            delete  msg;
            return;
        }
        msg_aux  = udpPacket->decapsulate();
        delete udpPacket;

        if (dynamic_cast<NotificationMsg  *>(msg_aux)){

            not_aux = check_and_cast<NotificationMsg*>(msg_aux);
            int tipo = not_aux-> getTipoMensaje();


            switch ( tipo )
            {
            case ALERTMSG:
                alertMsg_process((AlertMsg *) not_aux);
                break;
            case REQMSG:
                reqMsg_process((REQMsg *) not_aux);
                break;
            case REPMSG:
                repMsg_process((REPMsg *) not_aux);
                break;
            }
        }
    }

}

void NA_Notification::handleMessageFromNotificationController(cPacket *msg)
{
    Enter_Method_Silent();
    take(msg);
    NotificationMsg *not_aux=NULL;

    if (dynamic_cast<NotificationMsg  *>(msg))
    {
        not_aux = check_and_cast<NotificationMsg*>(msg);
        int tipo = not_aux-> getTipoMensaje();
        uint32_t idMensaje=not_aux->getIdMensaje();

        switch ( tipo )
        {
            case ALERTMSG:
                EV << "Alerta enviada: " << uint32_t (idMensaje) << "\n";
                send_alert((AlertMsg *) not_aux);
                break;
            case REQMSG:
                send_req((REQMsg *) not_aux);
                break;
            case REPMSG:
                send_rep((REPMsg *) not_aux);
                break;
        }
    }

}

cModule *NA_Notification::getNotificationControllerModule()
{
    cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
    cTopology::Node *node;
    std::string nodeName;

    // extract all modules with the @attackType property set in the simulation
    topo.extractByProperty("controlador");

    // Now, only the modules contained in the parent module of this NA_Attack object are activated.
    std::string prefix = this->getParentModule()->getFullPath(); // First we get the full path of the parent node
    for (int i = 0; i < topo.getNumNodes(); i++) {
        node = topo.getNode(i);
        nodeName = node->getModule()->getFullPath();
        if (not nodeName.compare(0, prefix.size(), prefix)) {
            controlador=node->getModule();
        }
    }
    return controlador;
}


AlertMsg *NA_Notification::alertMsg_create(uint8_t evento, uint8_t severidad, uint8_t confiabilidad, uint32_t idMalicioso)
{
    AlertMsg *msg = new AlertMsg("AlertMsg");
    msg->setTipoMensaje(1);
    msg->setEvento(evento);
    msg->setSeveridad(severidad);
    msg->setConfiabilidad(confiabilidad);
    msg->setIdMalicioso(idMalicioso);
    msg->setTtl(30);
    double marcaTemporal=SIMTIME_DBL(simTime());
    msg->setMarcaTemporal(marcaTemporal);
    return msg;
}

AlertMsgAdaptation *NA_Notification::alertMsg_createAdaptation(uint8_t evento, uint8_t severidad, uint8_t confiabilidad, const char* idMalicioso)
{
    AlertMsgAdaptation *msg = new AlertMsgAdaptation("AlertMsgAdaptation");
    msg->setTipoMensaje(1);
    msg->setEvento(evento);
    msg->setSeveridad(severidad);
    msg->setConfiabilidad(confiabilidad);
    msg->setMaliciousNode(idMalicioso);
    msg->setTtl(30);
    double marcaTemporal=SIMTIME_DBL(simTime());
    msg->setMarcaTemporal(marcaTemporal);
    return msg;
}

AlertMsg *NA_Notification::alertMsg_create(uint8_t longitudTotal, uint8_t evento, uint8_t severidad, uint8_t confiabilidad, uint32_t idMalicioso, AlertMsg_extension datosOpcionales[])
{
    AlertMsg *msg = new AlertMsg("AlertMsg");
    msg->setTipoMensaje(1);
    msg->setLongitudTotal(longitudTotal);
    msg->setBitLength(longitudTotal*32);
    msg->setEvento(evento);
    msg->setSeveridad(severidad);
    msg->setConfiabilidad(confiabilidad);
    msg->setIdMalicioso(idMalicioso);
    msg->setTtl(30);

    double marcaTemporal=SIMTIME_DBL(simTime());
    msg->setMarcaTemporal(marcaTemporal);
    unsigned int size=longitudTotal - 5;
    if (size>0)
    {
        msg->setAlertExtensionArraySize(size);
        for (unsigned int i=0; i<size; i++)
        {
            msg->setAlertExtension(i,datosOpcionales[i]);
        }
    }
    return msg;
}

AlertMsg *NA_Notification::alertMsg_addExtension(AlertMsg *msg, AlertMsg_extension datosOpcionales)
{
    int size=msg->getAlertExtensionArraySize();
    msg->setAlertExtensionArraySize(size+1);
    msg->setAlertExtension(size, datosOpcionales);

    msg->setBitLength(msg->getBitLength()+32);

    return msg;
}

AlertMsg_extension NA_Notification::alertExtension_create(uint8_t tipo, uint8_t longitud, uint8_t datos)
{
    AlertMsg_extension datosOpcionales= AlertMsg_extension();
    datosOpcionales.tipo=tipo;
    datosOpcionales.longitud=longitud;
    datosOpcionales.datos=datos;

    return datosOpcionales;
}

 void NA_Notification::send_alert(AlertMsg *msg)
 {
    msg->setLongitudTotal(ALERTMSG_size);
    msg->setBitLength(ALERTMSG_size*32);
    idMensaje++;
    msg->setIdMensaje(idMensaje);
    msg->setIdSrc(srcAddr);

    sendToIP(msg, srcPort, broadcastAddress, destPort, msg->getTtl(), delay, ieWlanId[0]);
 }

void NA_Notification::alertMsg_process(AlertMsg *msg)
{

    uint32_t origen=msg->getIdSrc();
    int ttl=msg->getTtl();
    int mensaje=msg->getIdMensaje();

    if ( IPv4Address(origen) == srcAddress)
    {
        delete msg;
        return;
    }

    if (table_find(origen,mensaje)==false)
    {
        notificationTableMap.insert(std::make_pair(origen,mensaje));

        AlertMsg *msg2 = msg->dup();

        NA_Notification_Controller *controla;
        controla = dynamic_cast<NA_Notification_Controller *>(controlador);
        controla->sendMessageToDefenseModules(msg2);

        if (ttl >1)
            {
                ttl--;
                msg->setTtl(ttl);
                sendToIP(msg, srcPort, broadcastAddress, destPort, ttl, exponential(1), ieWlanId[0]);
            }
        else
        {
            delete msg;
            return;
        }
    }

    else
        delete msg;
}


REQMsg *NA_Notification::reqMsg_create(uint16_t nodos, uint16_t variables, uint32_t idNodoSolicitado[], REQMsg_extension datos[])
{
    REQMsg *msg = new REQMsg("REQMsg");
    msg->setTipoMensaje(2);
    msg->setLongitudTotal(REQMSG_size+(variables+1)*nodos);
    msg->setBitLength((REQMSG_size+(variables+1)*nodos)*32);
    msg->setNodos(nodos);
    msg->setVariables(variables);
    msg->setTtl(1);

    msg->setIdNodoSolicitadoArraySize(nodos);

    for (int i=0; i<nodos; i++)
    {
        msg->setIdNodoSolicitado(i, idNodoSolicitado[i]);
    }

    msg->setReqExtensionArraySize(variables*nodos);

    for (int i=0; i<variables*nodos; i++)
    {
        msg->setReqExtension(i, datos[i]);
    }
    return msg;
}


REQMsg_extension NA_Notification::reqExtension_create(uint8_t idProtocolo, uint32_t idVariable)
{
    REQMsg_extension reqExtension= REQMsg_extension();
    reqExtension.idProtocolo=idProtocolo;
    reqExtension.idVariable=idVariable;

    return reqExtension;
}

void NA_Notification::reqMsg_process(REQMsg *msg)
{
    uint32_t origen=msg->getIdSrc();
    int mensaje=msg->getIdMensaje();
    int ttl=msg->getTtl();

    if ( IPv4Address(origen) == srcAddress)
    {
        delete msg;
        return;
    }

    if (table_find(origen,mensaje)==false)
    {
        notificationTableMap.insert(std::make_pair(origen,mensaje));

        //enviar al controlador
        REQMsg *msg2 = msg->dup();
        NA_Notification_Controller *controla;
        controla = dynamic_cast<NA_Notification_Controller *>(controlador);
        controla->sendMessageToDefenseModules(msg2);

        if (ttl >1)
            {
                ttl--;
                msg->setTtl(ttl);
                sendToIP(msg, srcPort, broadcastAddress, destPort, ttl, exponential(1), ieWlanId[0]);
            }
        else
        {
            delete msg;
            return;
        }
    }

    else
        delete msg;
}

void NA_Notification::send_req(REQMsg *msg)
{
   idMensaje++;
   msg->setIdMensaje(idMensaje);
   msg->setIdSrc(srcAddr);

   sendToIP(msg, srcPort, broadcastAddress, destPort, msg->getTtl(), delay, ieWlanId[0]);
}


REPMsg *NA_Notification::repMsg_create(uint16_t nodos, uint16_t variables, uint32_t idNodoSolicitante, uint32_t idSolicitud, uint32_t idNodoInformado[], REPMsg_extension datos[])
{
    REPMsg *msg = new REPMsg("REPMsg");
    msg->setTipoMensaje(3);
    msg->setLongitudTotal(REPMSG_size+(variables*2+1)*nodos);
    msg->setBitLength((REPMSG_size+(variables*2+1)*nodos)*32);
    msg->setNodos(nodos);
    msg->setVariables(variables);
    msg->setIdNodoSolicitante(idNodoSolicitante);
    msg->setIdMensaje(idSolicitud);
    msg->setTtl(30);

    msg->setIdNodoInformadoArraySize(nodos);

    for (int i=0; i<nodos; i++)
    {
        msg->setIdNodoInformado(i, idNodoInformado[i]);
    }

    msg->setRepExtensionArraySize(variables*nodos);

    for (int i=0; i<variables*nodos; i++)
    {
        msg->setRepExtension(i, datos[i]);
    }

    return msg;
}


REPMsg_extension NA_Notification::repExtension_create(uint8_t idProtocolo, uint32_t idVariable, uint32_t valorVariable)
{
    REPMsg_extension repExtension= REPMsg_extension();
    repExtension.idProtocolo=idProtocolo;
    repExtension.idVariable=idVariable;
    repExtension.valorVariable=valorVariable;

    return repExtension;
}

void NA_Notification::send_rep(REPMsg *msg)
{
    msg->setIdSrc(srcAddr);


    sendToIP(msg, srcPort, IPv4Address(msg->getIdNodoSolicitante()), destPort, msg->getTtl(), delay, ieWlanId[0]);
}

void NA_Notification::repMsg_process(REPMsg *msg)
{
    EV << "Recibido un mensaje REP desde " << IPv4Address(msg->getIdSrc()) << "\n";
    //comprobar si el mensaje es repetido
    uint32_t origen=msg->getIdSrc();
    uint32_t destino=msg->getIdNodoSolicitante();
    int mensaje=msg->getIdMensaje();
    int ttl=msg->getTtl();

    if ( IPv4Address(origen) == srcAddress)
    {
        delete msg;
        return;
    }


    if (table_find(origen,mensaje)==false)
    {
        EV << "Es un mensaje reply nuevo "<< "\n";
        EV << "Que es para "<< IPv4Address(destino) << "Y yo soy " << srcAddress << "\n";
        notificationTableMap.insert(std::make_pair(origen,mensaje));

        if ( IPv4Address(destino) == srcAddress)
        {
            NA_Notification_Controller *controla;
            controla = dynamic_cast<NA_Notification_Controller *>(controlador);
            controla->sendMessageToDefenseModules(msg);
            return;
        }

        if (ttl >1)
        {
            ttl--;
            msg->setTtl(ttl);
            sendToIP(msg, srcPort, broadcastAddress, destPort, ttl, exponential(1), ieWlanId[0]);
        }
        else
        {
            delete msg;
            return;
        }

    }

    else
        delete msg;
}


void NA_Notification:: sendToIP(NotificationMsg *msg, int srcPort, IPv4Address destAddr, int destPort, int ttl, double delay, InterfaceEntry  *ie){

    int interfaceid;

    UDPPacket *udpPacket = new UDPPacket(msg->getName());
    udpPacket->setByteLength(UDP_HEADER_BYTES);
    udpPacket->encapsulate(msg);

    // set source and destination port
    udpPacket->setSourcePort(srcPort);
    udpPacket->setDestinationPort(destPort);

    if (ie){
        srcAddress =  ie->ipv4Data()->getIPAddress();
        interfaceid=ie->getInterfaceId(); // This is the interface id
    }

    IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
    ipControlInfo->setDestAddr(destAddr);
    ipControlInfo->setSrcAddr(srcAddress);
    ipControlInfo->setProtocol(protocolo);
    ipControlInfo->setTimeToLive(ttl);
    ipControlInfo->setMacDest(MACAddress(0xffffffff));

    if (destAddr == broadcastAddress)
        ipControlInfo->setInterfaceId(interfaceid);
    else
        ipControlInfo->setInterfaceId(-1);

    udpPacket->setControlInfo(ipControlInfo);

    sendDelayed(udpPacket, delay, "to_ip");

}

void NA_Notification:: sendToIP(NotificationMsg *msg, int srcPort, IPv4Address destAddr, int destPort, int ttl, double delay, int  index)
{
    InterfaceEntry  *ie = NULL;
    if (index!=-1)
        ie = getInterfaceEntryById(index); // The user want to use a pre-defined interface

    sendToIP(msg, srcPort, destAddr, destPort, ttl, delay, ie);

}

bool NA_Notification:: table_find(uint32_t nodo, int mensaje)
{
    for (NotificationTableMap::iterator it = notificationTableMap.begin();it != notificationTableMap.end();it++)
    {
        if (it->first == nodo && it->second == mensaje)
        {
            return true;
        }
    }
    return false;
}


void NA_Notification:: finish()
{
}
