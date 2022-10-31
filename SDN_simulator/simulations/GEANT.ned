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

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.visualizer.canvas.integrated.IntegratedCanvasVisualizer;
import inet.common.misc.ThruputMeteringChannel;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import openflow.nodes.DistanceChannel;
import openflow.nodes.Open_Flow_Domain;
import openflow.openflow.controller.Open_Flow_Controller;
import openflow.utility.OpenFlowGraphAnalyzer;
import openflow.utility.StaticSpanningTree;

//
// TODO auto-generated type
//
network GEANT
{
    @display("bgb=1443.3575,838.825");
    types:
        channel Eth100M extends ThruputMeteringChannel
        {
            datarate = 100Mbps;
            thruputDisplayFormat = "u";
            @display("ls=#CC0000,2");
        }
        channel Eth25M extends ThruputMeteringChannel
        {
            datarate = 25Mbps;
            thruputDisplayFormat = "u";
            @display("ls=#4E9A06,2");
        }
        channel Eth1550K extends ThruputMeteringChannel
        {
            datarate = 1550kbps;
            thruputDisplayFormat = "u";
            @display("ls=#204A87,2");
        }

    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=85.011246,209.815");
        }
        visualizer: IntegratedCanvasVisualizer {
            @display("p=85.32875,75.205");
        }
        controller: Open_Flow_Controller {
            @display("p=85.32875,702.8775");
        }
        node1: Open_Flow_Domain {
            @display("p=555.36,565.48376;is=s");
        }
        node2: Open_Flow_Domain {
            @display("p=1073.1176,341.315;is=s");
        }
        node3: Open_Flow_Domain {
            @display("p=726.0175,726.0175;is=s");
        }
        node4: Open_Flow_Domain {
            @display("p=1165.6775,111.36125;is=s");
        }
        node5: Open_Flow_Domain {
            @display("p=241.52376,358.67;is=s");
        }
        node6: Open_Flow_Domain {
            @display("p=1268.3612,461.35376;is=s");
        }
        node7: Open_Flow_Domain {
            @display("p=1028.2838,478.70874;is=s");
        }
        node8: Open_Flow_Domain {
            @display("p=263.2175,157.64125;is=s");
        }
        node9: Open_Flow_Domain {
            @display("p=480.155,114.25375;is=s");
        }
        node10: Open_Flow_Domain {
            @display("p=263.2175,506.1875;is=s");
        }
        node11: Open_Flow_Domain {
            @display("p=309.4975,684.07623;is=s");
        }
        node12: Open_Flow_Domain {
            @display("p=890.89,257.4325;is=s");
        }
        node13: Open_Flow_Domain {
            @display("p=795.4375,617.54877;is=s");
        }
        node14: Open_Flow_Domain {
            @display("p=470.03125,744.8187;is=s");
        }
        node15: Open_Flow_Domain {
            @display("p=642.135,131.60875;is=s");
        }
        node16: Open_Flow_Domain {
            @display("p=433.875,296.48126;is=s");
        }
        node17: Open_Flow_Domain {
            @display("p=694.2,461.35376;is=s");
        }
        node18: Open_Flow_Domain {
            @display("p=1327.6575,257.4325;is=s");
        }
        node19: Open_Flow_Domain {
            @display("p=1246.6675,684.07623;is=s");
        }
        node20: Open_Flow_Domain {
            @display("p=629.1188,383.25626;is=s");
        }
        node21: Open_Flow_Domain {
            @display("p=934.2775,762.17377;is=s");
        }
        node22: Open_Flow_Domain {
            @display("p=830.1475,86.775;is=s");
        }
        node23: Open_Flow_Domain {
            @display("p=912.58374,341.315;is=s");
        }

    connections:
        // Data plane connect
        node1.gateDPlane++ <--> Eth100M <--> node3.gateDPlane++;
        node1.gateDPlane++ <--> Eth100M <--> node7.gateDPlane++;
        node1.gateDPlane++ <--> Eth100M <--> node16.gateDPlane++;

        node2.gateDPlane++ <--> Eth100M <--> node4.gateDPlane++;
        node2.gateDPlane++ <--> Eth100M <--> node7.gateDPlane++;
        node2.gateDPlane++ <--> Eth100M <--> node12.gateDPlane++;
        node2.gateDPlane++ <--> Eth100M <--> node13.gateDPlane++;
        node2.gateDPlane++ <--> Eth25M <--> node18.gateDPlane++;
        node2.gateDPlane++ <--> Eth25M <--> node23.gateDPlane++;

        node3.gateDPlane++ <--> Eth100M <--> node10.gateDPlane++;
        node3.gateDPlane++ <--> Eth25M <--> node11.gateDPlane++;
        node3.gateDPlane++ <--> Eth1550K <--> node14.gateDPlane++;
        node3.gateDPlane++ <--> Eth100M <--> node21.gateDPlane++;

        node4.gateDPlane++ <--> Eth100M <--> node16.gateDPlane++;

        node5.gateDPlane++ <--> Eth25M <--> node8.gateDPlane++;
        node5.gateDPlane++ <--> Eth25M <--> node16.gateDPlane++;

        node6.gateDPlane++ <--> Eth1550K <--> node7.gateDPlane++;
        node6.gateDPlane++ <--> Eth1550K <--> node19.gateDPlane++;

        node7.gateDPlane++ <--> Eth100M <--> node17.gateDPlane++;
        node7.gateDPlane++ <--> Eth25M <--> node19.gateDPlane++;
        node7.gateDPlane++ <--> Eth100M <--> node21.gateDPlane++;

        node8.gateDPlane++ <--> Eth25M <--> node9.gateDPlane++;

        node9.gateDPlane++ <--> Eth25M <--> node15.gateDPlane++;
        node9.gateDPlane++ <--> Eth100M <--> node16.gateDPlane++;

        node10.gateDPlane++ <--> Eth25M <--> node11.gateDPlane++;
        node10.gateDPlane++ <--> Eth100M <--> node12.gateDPlane++;
        node10.gateDPlane++ <--> Eth100M <--> node16.gateDPlane++;
        node10.gateDPlane++ <--> Eth100M <--> node17.gateDPlane++;

        node12.gateDPlane++ <--> Eth100M <--> node22.gateDPlane++;

        node13.gateDPlane++ <--> Eth1550K <--> node14.gateDPlane++;
        node13.gateDPlane++ <--> Eth100M <--> node17.gateDPlane++;
        node13.gateDPlane++ <--> Eth25M <--> node19.gateDPlane++;

        node15.gateDPlane++ <--> Eth25M <--> node20.gateDPlane++;

        node17.gateDPlane++ <--> Eth100M <--> node20.gateDPlane++;
        node17.gateDPlane++ <--> Eth25M <--> node23.gateDPlane++;

        node18.gateDPlane++ <--> Eth25M <--> node21.gateDPlane++;

        node20.gateDPlane++ <--> Eth25M <--> node22.gateDPlane++;

        // Control plane connect
        node1.gateCPlane++ <--> Eth100M <--> node3.gateCPlane++;
        node1.gateCPlane++ <--> Eth100M <--> node7.gateCPlane++;
        node1.gateCPlane++ <--> Eth100M <--> node16.gateCPlane++;

        node2.gateCPlane++ <--> Eth100M <--> node4.gateCPlane++;
        node2.gateCPlane++ <--> Eth100M <--> node7.gateCPlane++;
        node2.gateCPlane++ <--> Eth100M <--> node12.gateCPlane++;
        node2.gateCPlane++ <--> Eth100M <--> node13.gateCPlane++;
        node2.gateCPlane++ <--> Eth25M <--> node18.gateCPlane++;
        node2.gateCPlane++ <--> Eth25M <--> node23.gateCPlane++;

        node3.gateCPlane++ <--> Eth100M <--> node10.gateCPlane++;
        node3.gateCPlane++ <--> Eth25M <--> node11.gateCPlane++;
        node3.gateCPlane++ <--> Eth1550K <--> node14.gateCPlane++;
        node3.gateCPlane++ <--> Eth100M <--> node21.gateCPlane++;

        node4.gateCPlane++ <--> Eth100M <--> node16.gateCPlane++;

        node5.gateCPlane++ <--> Eth25M <--> node8.gateCPlane++;
        node5.gateCPlane++ <--> Eth25M <--> node16.gateCPlane++;

        node6.gateCPlane++ <--> Eth1550K <--> node7.gateCPlane++;
        node6.gateCPlane++ <--> Eth1550K <--> node19.gateCPlane++;

        node7.gateCPlane++ <--> Eth100M <--> node17.gateCPlane++;
        node7.gateCPlane++ <--> Eth25M <--> node19.gateCPlane++;
        node7.gateCPlane++ <--> Eth100M <--> node21.gateCPlane++;

        node8.gateCPlane++ <--> Eth25M <--> node9.gateCPlane++;

        node9.gateCPlane++ <--> Eth25M <--> node15.gateCPlane++;
        node9.gateCPlane++ <--> Eth100M <--> node16.gateCPlane++;

        node10.gateCPlane++ <--> Eth25M <--> node11.gateCPlane++;
        node10.gateCPlane++ <--> Eth100M <--> node12.gateCPlane++;
        node10.gateCPlane++ <--> Eth100M <--> node16.gateCPlane++;
        node10.gateCPlane++ <--> Eth100M <--> node17.gateCPlane++;

        node12.gateCPlane++ <--> Eth100M <--> node22.gateCPlane++;

        node13.gateCPlane++ <--> Eth1550K <--> node14.gateCPlane++;
        node13.gateCPlane++ <--> Eth100M <--> node17.gateCPlane++;
        node13.gateCPlane++ <--> Eth25M <--> node19.gateCPlane++;

        node15.gateCPlane++ <--> Eth25M <--> node20.gateCPlane++;

        node17.gateCPlane++ <--> Eth100M <--> node20.gateCPlane++;
        node17.gateCPlane++ <--> Eth25M <--> node23.gateCPlane++;

        node18.gateCPlane++ <--> Eth25M <--> node21.gateCPlane++;

        node20.gateCPlane++ <--> Eth25M <--> node22.gateCPlane++;

        // Controller 
        node11.gateCPlane++ <--> Eth100M <--> controller.ethg++;
}
