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

#ifndef TRAFFICCONTROLLER_H_
#define TRAFFICCONTROLLER_H_

#include <omnetpp.h>
#include "messages/ControlPacket_m.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <string>

namespace sdn_simulator {

class TrafficController : public omnetpp::cSimpleModule{
    public:
        TrafficController();
        virtual ~TrafficController();

    private:
        double nodeRatio;
        int numNodes;
        int id;

    double flowRatio[100];
        string  folderName;

    protected:
        virtual void initialize();
        virtual void handleMessage(omnetpp::cMessage *msg);
        void getTrafficInfo(int id, double rData[]);
};

} /* namespace sdn_simulator */

#endif /* TRAFFICCONTROLLER_H_ */
