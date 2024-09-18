#pragma once
#include "RowData.h"  // Include the RowData definition
#include "Uav.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
using namespace std;

class Simulation
{
public:
	vector<double> readSimParamsFile(string SimParams);
	vector<RowData> readSimCmdsFile(string SimCmds);

};

