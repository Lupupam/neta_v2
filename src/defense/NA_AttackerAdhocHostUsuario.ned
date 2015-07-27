package nesg.netattacks.defense;

import inet.networklayer.IManetRouting;
import nesg.netattacks.nodes.NA_AttackerAdhocHostAlarm;

module NA_AttackerAdhocHostUsuario extends NA_AttackerAdhocHostAlarm
{
    parameters:        
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
        IPForward = default(true);
        @Usuario;

}
