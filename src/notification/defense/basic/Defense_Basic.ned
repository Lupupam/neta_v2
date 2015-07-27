//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014


package nesg.netattacks.notification.defense.basic;


simple Defense_Basic
{
    parameters:
        @defense;
        @display("i=misc/cloud3,green,100;is=l");
        string notificationType @enum("alerta","peticion") = default("");  //String with the type of notification
        //bool active = default(false);  //Indicates if this attack is active or not in the node
}