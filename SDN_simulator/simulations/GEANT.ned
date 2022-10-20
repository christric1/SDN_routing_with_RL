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

import inet.node.inet.Router;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.visualizer.canvas.integrated.IntegratedCanvasVisualizer;
import inet.node.ethernet.Eth1550K;
import inet.node.ethernet.Eth25M;
import inet.node.ethernet.Eth100M;

//
// TODO auto-generated type
//
network GEANT
{
    @display("bgb=1153,683");
    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=55,175");
        }
        visualizer: IntegratedCanvasVisualizer {
            @display("p=55,76");
        }
        node1: Router {
            @display("p=345,428");
        }
        node2: Router {
            @display("p=754,300");
        }
        node3: Router {
            @display("p=569,584");
        }
        node4: Router {
            @display("p=637,122");
        }
        node5: Router {
            @display("p=157,252");
        }
        node6: Router {
            @display("p=1027,366");
        }
        node7: Router {
            @display("p=815,405");
        }
        node8: Router {
            @display("p=239,72");
        }
        node9: Router {
            @display("p=368,162");
        }
        node10: Router {
            @display("p=125,397");
        }
        node11: Router {
            @display("p=164,567");
        }
        node12: Router {
            @display("p=1010,91");
        }
        node13: Router {
            @display("p=637,518");
        }
        node14: Router {
            @display("p=368,615");
        }
        node15: Router {
            @display("p=432,60");
        }
        node16: Router {
            @display("p=271,252");
        }
        node17: Router {
            @display("p=556,344");
        }
        node18: Router {
            @display("p=1049,175");
        }
        node19: Router {
            @display("p=971,518");
        }
        node20: Router {
            @display("p=471,283");
        }
        node21: Router {
            @display("p=783,615");
        }
        node22: Router {
            @display("p=556,49");
        }
        node23: Router {
            @display("p=793,111");
        }
        
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
