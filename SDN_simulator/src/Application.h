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

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <omnetpp.h>
#include <string>
#include "messages/TimerNextPacket_m.h"
#include "messages/DataPacket_m.h"
#include "messages/ControlPacket_m.h"
#include "Statistic.h"

using namespace std;

namespace sdn_simulator {

class Application : public omnetpp::cSimpleModule{
    private:
        TimerNextPacket *interArrival;
        int id;

        int numPackets;
        int packetSize;
        int genT;
        double lambdaFactor;
        int numRx;
        double lambda;
        double MAXSIM;
        int dest;
        double intervalTime;

    public:
        Application();
        virtual ~Application();

    protected:
      virtual void initialize();
      virtual void handleMessage(omnetpp::cMessage *msg);

    private:
      double nextPacket(int i);
      int nextDest();
      int extractId(string name, int pos);
      void initSignals();
};

} /* namespace sdn_simulator */

#endif /* APPLICATION_H_ */
