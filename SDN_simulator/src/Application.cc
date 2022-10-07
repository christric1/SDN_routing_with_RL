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

#include "Application.h"
namespace sdn_simulator {

Define_Module(Application);

Application::Application() {
    // TODO Auto-generated constructor stub
    interArrival = NULL;
}

Application::~Application() {
    // TODO Auto-generated destructor stub
    cancelAndDelete(interArrival);
}

void Application::initialize(){
    EV << "Ratio: " << endl;
    //id = extractId(this->getFullPath(), 12);
    id = par("id");
    genT = par("generation");
    lambdaFactor = par("lambda");
    dest = par("dest");
    MAXSIM = par("simulationDuration"); // 1024
    numRx = par("numNodes");
    numPackets = 0;
    packetSize = 1176000;

    Statistic::instance()->setGeneration(genT);
    Statistic::instance()->setMaxSim(MAXSIM);
    Statistic::instance()->setLambda(lambdaFactor);
}

void Application::handleMessage(omnetpp::cMessage *msg){
    if (msg->isSelfMessage()) {

        DataPacket *data = new DataPacket("dataPacket");

        data->setBitLength(packetSize);
        data->setTtl(numRx);

        data->setDstNode(dest);
        data->setSrcNode(id);
        data->setLastTS(omnetpp::simTime().dbl());

        send(data, "out");

        numPackets++;
        Statistic::instance()->setTraffic(omnetpp::simTime(), id, dest, packetSize);
        Statistic::instance()->infoTS(omnetpp::simTime());

        if (omnetpp::simTime() < MAXSIM)
            scheduleAt(omnetpp::simTime() + intervalTime, msg);

        else {
            // Statistic::instance()->outAvgDelay();
            EV << "END simulation" << endl;
        }
    }
    else {
        ControlPacket *data = check_and_cast<ControlPacket *>(msg);
        double flowBW = data->getData();
        int numPacketsPerSec = ceil(flowBW / packetSize * 1000);
        if(numPacketsPerSec > 0)
            intervalTime = 1.0 / numPacketsPerSec;

        interArrival = new TimerNextPacket("timer");
        interArrival->setLambda(intervalTime);

        if (dest != id && flowBW != 0 && flowBW != -1)
            scheduleAt(omnetpp::simTime() + intervalTime, interArrival);

        EV << "flowBW: " << flowBW  << "   intervalTime: " << intervalTime << "   numPacketsPerSec: " << numPacketsPerSec << endl;

        delete data;
    }
}
} /* namespace sdn_simulator */
