#include "Simulation.h"
#include "RowData.h"
#include <iostream>
#include <vector>
using namespace std;

vector<RowData> Simulation::readSimCmdsFile(string SimCmds) {
	ifstream file;
	vector<RowData> commandsSimulation;
	double time;
	double x;
	double y;
	int num;
	file.open(SimCmds);
	if (file.is_open()) {
		while (file >> time >> num >> x >> y) {
			commandsSimulation.push_back(RowData(time, num, x, y));
		}
		file.close();
		}
	return commandsSimulation;
}

vector<double> Simulation::readSimParamsFile(string SimParams) {
	vector<double>initSim;
	ifstream file;
	file.open(SimParams);
	if (file.is_open()) {
		string str;
		while (getline(file, str)) {
				int sign = str.find("=");
				if (sign == -1) {
					break;
				}
				double value = stod(str.substr(sign + 1));
			//	cout << str << endl;
				initSim.push_back(value);
		}
		file.close();
	}
	return initSim;
}

