package nesg.netattacks.hackedmodules.linklayer.ieee80211.mac;

import inet.linklayer.ieee80211.mac.Ieee80211Mac;

simple NA_Ieee80211Mac extends Ieee80211Mac
{
    parameters:
        @class(NA_Ieee80211Mac);

        //Labels for the potential detection that affect this module
        @droppingSA;
        @droppingD;
        @display("i=,red");
}
