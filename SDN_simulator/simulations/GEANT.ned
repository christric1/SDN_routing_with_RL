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
import sdn_simulator.Server;

//
// TODO auto-generated type
//
network GEANT
{
    parameters:
        int numNodes = 23;
        int numTx = 23;

        @display("bgb=1585.36,919.03");
    types:
        channel Channel_100MB extends ned.DatarateChannel
        {
            delay = 0ms;
            datarate = 100 Mbps;
        }

        channel Channel_25MB extends ned.DatarateChannel
        {
            delay = 0ms;
            datarate = 25 Mbps;
        }

        channel Channel_1550KB extends ned.DatarateChannel
        {
            delay = 0ms;
            datarate = 1.55 Mbps;
        }

    submodules:
        node1: Server {
            id = 0;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[3];
        }
        node2: Server {
            id = 1;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[6];
        }
        node3: Server {
            id = 2;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[5];
        }
        node4: Server {
            id = 3;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[2];
        }
        node5: Server {
            id = 4;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[2];
        }
        node6: Server {
            id = 5;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[2];
        }
        node7: Server {
            id = 6;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[6];
        }
        node8: Server {
            id = 7;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[2];
        }
        node9: Server {
            id = 8;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[3];
        }
        node10: Server {
            id = 9;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[5];
        }
        node11: Server {
            id = 10;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[2];
        }
        node12: Server {
            id = 11;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[3];
        }
        node13: Server {
            id = 12;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[4];
        }
        node14: Server {
            id = 13;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[2];
        }
        node15: Server {
            id = 14;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[2];
        }
        node16: Server {
            id = 15;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[5];
        }
        node17: Server {
            id = 16;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[5];
        }
        node18: Server {
            id = 17;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[2];
        }
        node19: Server {
            id = 18;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[3];
        }
        node20: Server {
            id = 19;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[3];
        }
        node21: Server {
            id = 20;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[3];
        }
        node22: Server {
            id = 21;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[2];
        }
        node23: Server {
            id = 22;
            numTx = parent.numTx;
            numNodes = parent.numNodes;
            gates:
                port[2];
        }

    connections:
        node1.port[0] <--> Channel_100MB <--> node3.port[0];
        node1.port[1] <--> Channel_100MB <--> node7.port[0];
        node1.port[2] <--> Channel_100MB <--> node16.port[0];

        node2.port[0] <--> Channel_100MB <--> node4.port[0];
        node2.port[1] <--> Channel_100MB <--> node7.port[1];
        node2.port[2] <--> Channel_100MB <--> node12.port[0];
        node2.port[3] <--> Channel_100MB <--> node13.port[0];
        node2.port[4] <--> Channel_25MB <--> node18.port[0];
        node2.port[5] <--> Channel_25MB <--> node23.port[0];

        node3.port[1] <--> Channel_100MB <--> node10.port[0];
        node3.port[2] <--> Channel_25MB <--> node11.port[0];
        node3.port[3] <--> Channel_1550KB <--> node14.port[0];
        node3.port[4] <--> Channel_100MB <--> node21.port[0];

        node4.port[1] <--> Channel_100MB <--> node16.port[1];

        node5.port[0] <--> Channel_25MB <--> node8.port[0];
        node5.port[1] <--> Channel_25MB <--> node16.port[2];

        node6.port[0] <--> Channel_1550KB <--> node7.port[2];
        node6.port[1] <--> Channel_1550KB <--> node19.port[0];

        node7.port[3] <--> Channel_100MB <--> node17.port[0];
        node7.port[4] <--> Channel_25MB <--> node19.port[1];
        node7.port[5] <--> Channel_100MB <--> node21.port[1];

        node8.port[1] <--> Channel_25MB <--> node9.port[0];

        node9.port[1] <--> Channel_25MB <--> node15.port[0];
        node9.port[2] <--> Channel_100MB <--> node16.port[3];

        node10.port[1] <--> Channel_25MB <--> node11.port[1];
        node10.port[2] <--> Channel_100MB <--> node12.port[1];
        node10.port[3] <--> Channel_100MB <--> node16.port[4];
        node10.port[4] <--> Channel_100MB <--> node17.port[1];

        node12.port[2] <--> Channel_100MB <--> node22.port[0];

        node13.port[1] <--> Channel_1550KB <--> node14.port[1];
        node13.port[2] <--> Channel_100MB <--> node17.port[2];
        node13.port[3] <--> Channel_25MB <--> node19.port[2];

        node15.port[1] <--> Channel_25MB <--> node20.port[0];

        node17.port[3] <--> Channel_100MB <--> node20.port[1];
        node17.port[4] <--> Channel_25MB <--> node23.port[1];

        node18.port[1] <--> Channel_25MB <--> node21.port[2];

        node20.port[2] <--> Channel_25MB <--> node22.port[1];
}
