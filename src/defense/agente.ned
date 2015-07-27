package nesg.netattacks.defense;

import inet.networklayer.IManetRouting;
import inet.nodes.inet.AdhocHost;
import nesg.netattacks.nodes.NA_AdhocHostAlarm;

module agente extends AdhocHost//NA_AdhocHostAlarm
{
    parameters:
        @display("i=device/cellphone,blue;gl=4");//bgb=700;b
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
        IPForward = default(true);
        @Agente;

}
