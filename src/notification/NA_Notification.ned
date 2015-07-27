//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014


package nesg.netattacks.notification;

import nesg.netattacks.notification.IManetNotification;


simple NA_Notification like IManetNotification
{
    parameters:

        //# Normal parameters.
        @notificador;
        @display("i=,red;i2=status/excl3");
        @class(NA_Notification);

    gates:
        input from_ip;
        output to_ip;
}

