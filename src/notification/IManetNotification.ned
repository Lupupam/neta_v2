//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014


package nesg.netattacks.notification;


moduleinterface IManetNotification
{
    @display("i=block/routing");
    gates:
        input from_ip;
        output to_ip;
}
