//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package nesg.netattacks.nodes;

import nesg.netattacks.notification.controllers.NA_Notification_Controller;
import nesg.netattacks.notification.IManetNotification;
import nesg.netattacks.adaptation.notification.NA_ModuleAdapter;

module NA_AttackerAdhocHostAlarm extends NA_AttackerAdhocHostDetectorStandalone
{
    submodules:
        controler: NA_Notification_Controller {

            @display("p=608,59");
        }
        manetNotification: <default("NA_Notification")> like IManetNotification {
            @display("p=142,320");
        }
        adaptor: NA_ModuleAdapter {
            @display("p=716,361");
        }

    connections:

        networkLayer.transportOut++ --> manetNotification.from_ip;
        networkLayer.transportIn++ <-- manetNotification.to_ip;
}
