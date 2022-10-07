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

#ifndef NODEQUEUE_H_
#define NODEQUEUE_H_

#include <omnetpp.h>
#include <queue>
#include "messages/DataPacket_m.h"
#include "Statistic.h"

using namespace std;

namespace sdn_simulator {

class NodeQueue : public omnetpp::cSimpleModule{
    public:
        NodeQueue();
        virtual ~NodeQueue();

    protected:
        virtual void initialize();
        virtual void handleMessage(omnetpp::cMessage *msg);

    private:
        queue<omnetpp::cMessage*> portQueue;
        omnetpp::cMessage* endTxMsg;
        int deleted;
};

} /* namespace sdn_simulator */

#endif /* NODEQUEUE_H_ */
