#include "Uav.h"
#include "Simulation.h"  
#include "RowData.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    Simulation sim;
    vector<Uav> uavs;
    RowData r;
    vector<RowData> commandsSimulation = sim.readSimCmdsFile("SimCmds.txt");
    r.sortCommandsByTime(commandsSimulation);
    vector<double> initSim = sim.readSimParamsFile("SimParams.ini");
    int n_uav = initSim[1];
    double dt= initSim[0];
    double timeLim = initSim[8];
    for (int i = 0; i < n_uav; i++)
    {
        uavs.push_back(Uav(i, initSim[2], initSim[3], initSim[4], -1
            , -1, initSim[5], initSim[6],
            initSim[7]));
        //this is for write the details of each uav in the 0 second to the file
        uavs[i].createSimulationCycleOutput(0);
    }

   
    int currentCommandIndex = 0;
    double currentTime = dt;
    while (currentTime <= timeLim) {
        for (Uav& uav : uavs) {
            // Process commands at the current simulation time
            uav.executeCommands(commandsSimulation, uavs, currentTime, currentCommandIndex);
            uav.updateUav(dt);
            uav.createSimulationCycleOutput(currentTime);
        }
        // Increment simulation time
        currentTime += dt; 
    }

    return 0;
}

