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

package sdn_simulator.simulations;

import inet.node.ethernet.EthernetSwitch;
import inet.node.ethernet.Eth1550K;
import inet.node.ethernet.Eth25M;
import inet.node.ethernet.Eth100M;

//
// TODO auto-generated type
//
network GEANT
{
    @display("bgb=2311.9949,1410.2374");
    submodules:
        node1: EthernetSwitch;
        node2: EthernetSwitch;
        node3: EthernetSwitch;
        node4: EthernetSwitch;
        node5: EthernetSwitch;
        node6: EthernetSwitch;
        node7: EthernetSwitch;
        node8: EthernetSwitch;
        node9: EthernetSwitch;
        node10: EthernetSwitch;
        node11: EthernetSwitch;
        node12: EthernetSwitch;
        node13: EthernetSwitch;
        node14: EthernetSwitch;
        node15: EthernetSwitch;
        node16: EthernetSwitch;
        node17: EthernetSwitch;
        node18: EthernetSwitch;
        node19: EthernetSwitch;
        node20: EthernetSwitch;
        node21: EthernetSwitch;
        node22: EthernetSwitch;
        node23: EthernetSwitch;
        
    connections:
        node1.ethg++ <--> Eth100M <--> node3.ethg++;
        node1.ethg++ <--> Eth100M <--> node7.ethg++;
        node1.ethg++ <--> Eth100M <--> node16.ethg++;

        node2.ethg++ <--> Eth100M <--> node4.ethg++;
        node2.ethg++ <--> Eth100M <--> node7.ethg++;
        node2.ethg++ <--> Eth100M <--> node12.ethg++;
        node2.ethg++ <--> Eth100M <--> node13.ethg++;
        node2.ethg++ <--> Eth25M <--> node18.ethg++;
        node2.ethg++ <--> Eth25M <--> node23.ethg++;

        node3.ethg++ <--> Eth100M <--> node10.ethg++;
        node3.ethg++ <--> Eth25M <--> node11.ethg++;
        node3.ethg++ <--> Eth1550K <--> node14.ethg++;
        node3.ethg++ <--> Eth100M <--> node21.ethg++;

        node4.ethg++ <--> Eth100M <--> node16.ethg++;

        node5.ethg++ <--> Eth25M <--> node8.ethg++;
        node5.ethg++ <--> Eth25M <--> node16.ethg++;

        node6.ethg++ <--> Eth1550K <--> node7.ethg++;
        node6.ethg++ <--> Eth1550K <--> node19.ethg++;

        node7.ethg++ <--> Eth100M <--> node17.ethg++;
        node7.ethg++ <--> Eth25M <--> node19.ethg++;
        node7.ethg++ <--> Eth100M <--> node21.ethg++;

        node8.ethg++ <--> Eth25M <--> node9.ethg++;

        node9.ethg++ <--> Eth25M <--> node15.ethg++;
        node9.ethg++ <--> Eth100M <--> node16.ethg++;

        node10.ethg++ <--> Eth25M <--> node11.ethg++;
        node10.ethg++ <--> Eth100M <--> node12.ethg++;
        node10.ethg++ <--> Eth100M <--> node16.ethg++;
        node10.ethg++ <--> Eth100M <--> node17.ethg++;

        node12.ethg++ <--> Eth100M <--> node22.ethg++;

        node13.ethg++ <--> Eth1550K <--> node14.ethg++;
        node13.ethg++ <--> Eth100M <--> node17.ethg++;
        node13.ethg++ <--> Eth25M <--> node19.ethg++;

        node15.ethg++ <--> Eth25M <--> node20.ethg++;

        node17.ethg++ <--> Eth100M <--> node20.ethg++;
        node17.ethg++ <--> Eth25M <--> node23.ethg++;

        node18.ethg++ <--> Eth25M <--> node21.ethg++;

        node20.ethg++ <--> Eth25M <--> node22.ethg++;
}
