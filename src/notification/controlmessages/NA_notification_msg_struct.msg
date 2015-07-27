//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

packet NotificationMsg
{
    uint8_t tipoMensaje;
    uint8_t longitudTotal;
    uint32_t idMensaje;
    uint32_t idSrc;
    uint8_t ttl;
}

struct AlertMsg_extension
{
    uint8_t tipo;
    uint8_t longitud;
    uint8_t datos;
}

packet AlertMsg extends NotificationMsg
{
    uint8_t evento;
    uint8_t severidad;
    uint8_t confiabilidad;
    uint32_t idMalicioso;
//	string maliciousNode;
    double marcaTemporal;
    AlertMsg_extension alertExtension[];
}

packet AlertMsgAdaptation extends NotificationMsg
{
    uint8_t evento;
    uint8_t severidad;
    uint8_t confiabilidad;
	string maliciousNode;
    double marcaTemporal;
    AlertMsg_extension alertExtension[];
}

struct REQMsg_extension
{
    uint8_t idProtocolo;
    uint32_t idVariable;
}

packet REQMsg extends NotificationMsg
{
    uint16_t nodos;
    uint16_t variables;
    uint32_t idNodoSolicitado[];
    REQMsg_extension reqExtension[];
}

struct REPMsg_extension
{
    uint8_t idProtocolo;
    uint32_t idVariable;
    uint32_t valorVariable;
}
    
packet REPMsg extends NotificationMsg
{
    uint16_t nodos;
    uint16_t variables;
    uint32_t idNodoSolicitante;
    uint32_t idNodoInformado[];
    REPMsg_extension repExtension[];
}

