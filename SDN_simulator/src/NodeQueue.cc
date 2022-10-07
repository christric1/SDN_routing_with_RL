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

#include "NodeQueue.h"
namespace sdn_simulator {

Define_Module(NodeQueue);

NodeQueue::NodeQueue() {
    // TODO Auto-generated constructor stub
}

NodeQueue::~NodeQueue() {
    // TODO Auto-generated destructor stub
    cancelAndDelete(endTxMsg);
    while (not portQueue.empty()) {
        delete portQueue.front();
        portQueue.pop();
    }
}

void NodeQueue::initialize(){
    deleted = 0;
    endTxMsg = new omnetpp::cMessage("endTxMsg");
}

void NodeQueue::handleMessage(omnetpp::cMessage *msg){
    if (msg->isSelfMessage()) {
        omnetpp::cMessage *packet = portQueue.front();
        portQueue.pop();
        send(packet, "line$o");
        if (not portQueue.empty()) {
            omnetpp::cChannel *txChannel = gate("line$o")->getTransmissionChannel();
            omnetpp::simtime_t txFinishTime = txChannel->getTransmissionFinishTime();
            scheduleAt(txFinishTime, endTxMsg);
        }
    }
    else if (msg->arrivedOn("in")) {
        omnetpp::cChannel *txChannel = gate("line$o")->getTransmissionChannel();
        omnetpp::simtime_t txFinishTime = txChannel->getTransmissionFinishTime();
        if (txFinishTime <= omnetpp::simTime()) {
            // channel free; send out packet immediately
            send(msg, "line$o");
        }

        else {
            // store packet and schedule timer; when the timer expires,
            // the packet should be removed from the queue and sent out
            if (portQueue.empty())
                scheduleAt(txFinishTime, endTxMsg);

            if (portQueue.size() < 32)
                portQueue.push(msg);
            else {
                deleted++;
                DataPacket *data = check_and_cast<DataPacket *>(msg);
                Statistic::instance()->setLost(omnetpp::simTime(), data->getSrcNode(), data->getDstNode());
                delete msg;
            }
        }
    }
    // from line
    else {
        send(msg,"out");
    }
}
} /* namespace sdn_simulator */
