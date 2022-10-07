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

#include "Routing.h"
namespace sdn_simulator {

Define_Module(Routing);

Routing::Routing() {
    // TODO Auto-generated constructor stub
}

Routing::~Routing() {
    // TODO Auto-generated destructor stub
}

void Routing::initialize(){
    numPorts = gateSize("in");
    id = par("id");
    numTx = par("numTx");
    numNodes = par("numNodes");
    folderName = par("folderName").stdstringValue();

    int diff = numNodes - numTx;
    getRoutingInfo(id-diff, outPort);

    Statistic::instance()->setNumNodes(numNodes);
    Statistic::instance()->setNumTx(numTx);
    Statistic::instance()->setFolder(folderName);
}

void Routing::handleMessage(omnetpp::cMessage *msg){
    DataPacket *data = check_and_cast<DataPacket *>(msg);

    if (id == data->getDstNode()) {
        EV << this->getFullPath() << "  Message received" << endl;
        omnetpp::simtime_t delayPaquet= omnetpp::simTime() - data->getCreationTime();
        Statistic::instance()->setDelay(omnetpp::simTime(), data->getSrcNode(), id, delayPaquet.dbl());
        delete msg;
    }
    else if (data->getTtl() == 0) {
        EV << this->getFullPath() << "  TTL = 0. Msg deleted" << endl;
        Statistic::instance()->setLost(omnetpp::simTime(), data->getSrcNode(), data->getDstNode());
        delete msg;
    }
    else {
        int destPort = outPort[data->getDstNode()];;
        data->setTtl(data->getTtl()-1);
        send(msg, "out", destPort);

        EV << "Routing: " << this->getFullPath() << "  Source: " << data->getSrcNode() << " Dest: " << data->getDstNode()
                << " using port: "<< destPort << endl;
    }
}

void Routing::getRoutingInfo(int id, int rData[]) {
     ifstream myfile (folderName + "/Routing.txt");
     double val;

     if (myfile.is_open()) {
         int i = 0;
         while (id != i) {
             for(int k = 0; k < numTx; k++) {
                 string aux;
                 getline(myfile, aux, ',');
             }
             i++;
         }
         for(int k = 0; k < numTx; k++) {
             string aux;
             getline(myfile, aux, ',');
             val = stod(aux);
             rData[k] = val;
         }
         myfile.close();
     }
}
} /* namespace sdn_simulator */
