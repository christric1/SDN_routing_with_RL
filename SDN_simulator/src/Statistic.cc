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

#include "Statistic.h"
#include <limits>

namespace sdn_simulator {

Statistic *Statistic::inst = 0;

Statistic::Statistic() {
    // TODO Auto-generated constructor stub
    INI = 50;
    END = 650;
    collect = true;

    Traffic =  vector<vector<vector<double> > > (100, vector<vector<double> >(100, vector<double>()));
    Routing =  vector<vector<double>  > (100, vector<double>(100));
    Delay =  vector<vector<vector<double> > > (100, vector<vector<double> >(100, vector<double>()));

    DropsV =  vector<vector<double>  > (100, vector<double>(100, 0));
    drops = 0;
}

Statistic::~Statistic() {
    // TODO Auto-generated destructor stub
}

Statistic *Statistic::instance() {
    if (!inst)
      inst = new Statistic();
    return inst;
}

void Statistic::setMaxSim(double ms) {
    END = ms;
    SIMTIME = (END.dbl()-INI.dbl())*1000;
}

void Statistic::setRouting(int src, int dst, double r) {
    (Routing)[src][dst] = r;
}

void Statistic::infoTS(omnetpp::simtime_t time) {
    if (time > END and collect) {
        collect = false;
        printStats();
    }
    if (time < INI and not collect)
        collect = true;
}

void Statistic::setDelay(omnetpp::simtime_t time, int src, int dst, double d) {
    if (time > INI and collect)
        (Delay)[src][dst].push_back(d);
}

void Statistic::setTraffic(omnetpp::simtime_t time, int src, int dst, double t) {
    if (time > INI and collect)
        (Traffic)[src][dst].push_back(t);
}

void Statistic::setLost(omnetpp::simtime_t time, int n, int p) {
    if (time > INI and collect) {
        drops++;
        (DropsV)[n][p]++;
    }
}

void Statistic::setLost(omnetpp::simtime_t time) {
    if (time > INI and collect)
        drops++;
}

void Statistic::setLambda(double l) {
    lambdaMax = l;
}

void Statistic::setGeneration(int genType) {
    genT = genType;
}

void Statistic::setFolder(string folder) {
    folderName = folder;
}

void Statistic::setNumTx(int n) {
    numTx = n;
}

void Statistic::setNumNodes(int n) {
    numNodes = n;
}

void Statistic::setRoutingParaam(double r) {
    routingP = r;
}

void Statistic::printStats() {
    // Delay
    vector<double> features;
    for (int i = 0; i < numTx; i++) {
       for (int j = 0; j < numTx; j++) {
           long double d = 0;
           unsigned int numPackets = (Delay)[i][j].size();

           for (unsigned int k = 0; k < numPackets; k++)
               d += (Delay)[i][j][k];

           if (numPackets == 0){
               if (i == j)
                   features.push_back(-1);
               else
                   features.push_back(std::numeric_limits<double>::infinity());
           }
           else features.push_back(d/numPackets);
       }
    }

    // Write lossPacket into file
    ofstream outFile;
    outFile.open(folderName + "/lossPacket.csv", ios::out | ios::trunc);
    outFile << drops << endl;
    outFile.close();

    // Reset
    drops = 0;
    Traffic.clear();
    Delay.clear();

    // Write delay into file
    ofstream myfile;
    myfile.open (folderName + "/Delay.csv", ios::out | ios::trunc );
    for (unsigned int i = 0; i < features.size(); i++ ) {
        double d = features[i];
        if(i == features.size()-1 || (i+1) % numNodes == 0 )    myfile  << d << endl;
        else    myfile  << d << ",";
    }
    myfile.close();
}
} /* namespace sdn_simulator */
