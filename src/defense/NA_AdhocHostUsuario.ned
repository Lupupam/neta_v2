package nesg.netattacks.defense;

import inet.networklayer.IManetRouting;
import nesg.netattacks.nodes.NA_AdhocHostAlarm;

module NA_AdhocHostUsuario extends NA_AdhocHostAlarm
{
    parameters:
        @display("i=device/cellphone,white;bgl=4");        
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
        IPForward = default(true);
        @Usuario;


}
