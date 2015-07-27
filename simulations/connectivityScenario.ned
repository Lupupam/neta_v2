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

package nesg.netattacks.simulations;

import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import inet.world.radio.ChannelControl;
import inet.world.scenario.ScenarioManager;
import inet.base.LifecycleController;
import nesg.netattacks.defense.*;

network connectivityScenario
{
    parameters:
        int numUsuarios;
        int numAgentes;
        int numDroppers;
        @display("bgb=2000,1200");
    submodules:
        node[numUsuarios]: NA_AdhocHostUsuario {
            parameters:
                @display("r=,,#707070;p=419,202");
        }
        attacker[numDroppers]: NA_AttackerAdhocHostUsuario {
            @display("p=246,202");
        }
        Agente[numAgentes]: agente {
            parameters:
                @display("r=,,#707070;p=86,202");
        }
        lifecycleController: LifecycleController {
            parameters:
                @display("p=65,129");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=50,250");
        }

		//control: controlador 

        channelControl: ChannelControl {
            parameters:
                @display("p=53,29");
        }

        configurator: IPv4NetworkConfigurator {
            @display("p=190,30");
        }
        control: NA_NodoControl {
            @display("p=322,77");
        }
}

