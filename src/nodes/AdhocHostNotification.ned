//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

package nesg.netattacks.nodes;

//import inet.nodes.inet.AdhocHost;
import nesg.netattacks.notification.IManetNotification;
//port nesg.netattacks.notification.NA_Notification;
import nesg.netattacks.notification.controllers.NA_Notification_Controller;


module AdhocHostNotification extends NA_AdhocHostDetectorStandalone
{
    parameters:
        @display("i=device/cellphone,white;bgb=803,448;i2=status/green");

    submodules:
        
        manetNotification: <default("NA_Notification")> like IManetNotification {
            @display("p=142,314");
        }
        //# Include notification controller
        notificationController: NA_Notification_Controller {
            @display("p=728,182");
        }

    connections:

        networkLayer.transportOut++ --> manetNotification.from_ip;
        networkLayer.transportIn++ <-- manetNotification.to_ip;
}
