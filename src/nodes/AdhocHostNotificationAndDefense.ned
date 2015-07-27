//
// Proyecto fin de carrera
// Ingeniero de Telecomunicación
// Universidad de Granada
//
// @author: Vicente Roldán Pérez (visen@correo.ugr.es)
// @date: 12/12/2014

package nesg.netattacks.nodes;

import nesg.netattacks.nodes.AdhocHostNotification;
import nesg.netattacks.notification.defense.basic.Defense_Basic;


module AdhocHostNotificationAndDefense extends AdhocHostNotification
{
    parameters:
        @display("i=device/cellphone,white;bgb=803,448;i2=status/green");

    submodules:
        defenseBasic: Defense_Basic {
            @display("p=728,286");
        }
}
