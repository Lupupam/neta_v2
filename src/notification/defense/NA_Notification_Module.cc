//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

#include "NA_Notification_Module.h"


void NA_Notification_Module::getNotificationControlllerModules()
{

}

void NA_Notification_Module::handleMessageFromNotificationController(cPacket *msg) {

    //LOG << "Class HackedModule: HandleMessageFromAttackController\n";

}

void NA_Notification_Module::newAlert(AlertMsg *msg)
{
    uint8_t longitudTotal=msg->getLongitudTotal();
    uint32_t idMensaje=msg->getIdMensaje();
    uint32_t idSrc=msg->getIdSrc();
    uint8_t evento=msg->getEvento();
    uint8_t severidad=msg->getSeveridad();
    uint8_t confiabilidad=msg->getSeveridad();
    double marcaTemporal=msg->getMarcaTemporal();
    uint32_t idMalicioso=msg->getIdMalicioso();

    EV << "Recibida una nueva alerta con ID " << idMensaje << " procedente de " << IPv4Address(idSrc) << ". " << "\n";

    EV << "longitudTotal: " << int(longitudTotal) << "\n";
    EV << "idMensaje: " << idMensaje << "\n";
    EV << "idSrc: " << IPv4Address(idSrc) << "\n";
    EV << "evento: " << int(evento) << "\n";
    EV << "severidad: " << int(severidad) << "\n";
    EV << "confiabilidad: " << int(confiabilidad) << "\n";
    EV << "marcaTemporal: " << marcaTemporal << "\n";
    EV << "idMalicioso: " << IPv4Address(idMalicioso)<< "\n";

}

void NA_Notification_Module::newAlert(AlertMsgAdaptation *msg)
{
    uint8_t longitudTotal=msg->getLongitudTotal();
    uint32_t idMensaje=msg->getIdMensaje();
    uint32_t idSrc=msg->getIdSrc();
    uint8_t evento=msg->getEvento();
    uint8_t severidad=msg->getSeveridad();
    uint8_t confiabilidad=msg->getSeveridad();
    double marcaTemporal=msg->getMarcaTemporal();
    const char* idMalicioso=msg->getMaliciousNode();

    EV << "Recibida una nueva alerta con ID " << idMensaje << " procedente de " << IPv4Address(idSrc) << ". " << "\n";

    EV << "longitudTotal: " << int(longitudTotal) << "\n";
    EV << "idMensaje: " << idMensaje << "\n";
    EV << "idSrc: " << IPv4Address(idSrc) << "\n";
    EV << "evento: " << int(evento) << "\n";
    EV << "severidad: " << int(severidad) << "\n";
    EV << "confiabilidad: " << int(confiabilidad) << "\n";
    EV << "marcaTemporal: " << marcaTemporal << "\n";
    EV << "idMalicioso: " << idMalicioso<< "\n";

}

void NA_Notification_Module::newREQ(REQMsg *msg)
{
    uint8_t longitudTotal=msg->getLongitudTotal();
        uint16_t nodos=msg->getNodos();
        uint16_t variables=msg->getVariables();
        uint32_t idMensaje=msg->getIdMensaje();
        uint32_t idSrc=msg->getIdSrc();

        uint32_t idNodoSolicitado[nodos];

        for (int i=0; i<nodos; i++)
        {
            idNodoSolicitado[i]=msg->getIdNodoSolicitado(i);
        }

        REQMsg_extension reqExtension[nodos*variables];

        for (int i=0; i<nodos*variables; i++)
        {
            reqExtension[i].idProtocolo=msg->getReqExtension(i).idProtocolo;
            reqExtension[i].idVariable=msg->getReqExtension(i).idVariable;
        }

        EV << "Recibida una nueva petición procedente de " << IPv4Address(idSrc) << " con los siguientes datos: " << "\n";

        EV << "longitudTotal: " << int(longitudTotal) << "\n";
        EV << "nodos: " << int(nodos) << "\n";
        EV << "variables: " << int(variables) << "\n";
        EV << "idMensaje: " << idMensaje << "\n";
        EV << "idSrc: " << IPv4Address(idSrc) << "\n";

        EV << "Pidiendo información de los nodos: " << "\n";

        for (int i=0; i<nodos; i++)
        {
            EV << "Nodo: " << IPv4Address(idNodoSolicitado[i]) << "\n";
        }

        EV << "De las variables: " << "\n";

        for (int i=0; i<variables; i++)
        {
            EV << "Protocolo: " << int(reqExtension[i].idProtocolo) << "  Variable: " << reqExtension[i].idVariable << "\n";
        }

        EV << "Y se procede a contestar la petición de información con los datos locales " << "\n";

        compose_reply(msg);


}

void NA_Notification_Module::newREP(REPMsg *msg)
{
    uint8_t longitudTotal=msg->getLongitudTotal();
    uint16_t nodos=msg->getNodos();
    uint16_t variables=msg->getVariables();
    uint32_t idMensaje=msg->getIdMensaje();
    uint32_t idNodoSolicitante=msg->getIdNodoSolicitante();
    uint32_t idSrc=msg->getIdSrc();

    uint32_t idNodoInformado[nodos];

    for (int i=0; i<nodos; i++)
    {
        idNodoInformado[i]=msg->getIdNodoInformado(i);
    }

    REPMsg_extension repExtension[nodos*variables];
    for (int i=0; i<nodos*variables; i++)
    {
        repExtension[i].idProtocolo=msg->getRepExtension(i).idProtocolo;
        repExtension[i].idVariable=msg->getRepExtension(i).idVariable;
        repExtension[i].valorVariable=msg->getRepExtension(i).valorVariable;
    }

    EV << "Recibida una nueva respuesta procedente de " << IPv4Address(idSrc) << " con los siguientes datos: " << "\n";

    EV << "longitudTotal: " << int(longitudTotal) << "\n";
    EV << "nodos: " << int(nodos) << "\n";
    EV << "variables: " << int(variables) << "\n";
    EV << "idMensaje: " << idMensaje << "\n";
    EV << "idNodoSolicitante: " << IPv4Address(idNodoSolicitante) << "\n";
    EV << "idSrc: " << IPv4Address(idSrc) << "\n";

    EV << "Dando la siguiente información: " << "\n";

    for (int i=0; i<nodos; i++)
    {
        EV << "Nodo: " << IPv4Address(idNodoInformado[i]) << "\n";

        for (int j=0; j<variables; j++)
        {
            EV << "Protocolo: " << int(repExtension[i*variables+j].idProtocolo) << "  Variable: " << repExtension[i*variables+j].idVariable << "  Valor de la variable: " << repExtension[i*variables+j].valorVariable << "\n";
        }
    }

    respuestas++;

        EV << "Recibidas " << respuestas << " nuevas respuestas a la petición ID " << idMensaje << ". " << "\n";
}


void NA_Notification_Module::compose_reply(REQMsg *msg)
{
    //metodo a sobreescribir
}

uint32_t NA_Notification_Module::calcular_variable(uint32_t idNodo, REQMsg_extension datos)
{
    return 1;
}

void NA_Notification_Module::sendMessage(cPacket *msg)
{
    //metodo a sobreescribir
}
