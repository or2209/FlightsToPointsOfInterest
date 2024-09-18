#pragma once
#include "RowData.h"
#include <iostream>
using namespace std;
class Uav
{
private:
	int id;
	double r;
	double x;
	double y;
	double destX;
	double destY;
	double z;
	double v;
	double azimuth;
	bool waiting;//waiting-true. not waiting-false
	double waitStartTime;
public:
	Uav(int id,double r,double x,double y,double destX,double destY,double z,double v,
		double azimuth);
	double getX();
	void setX(double x);
	double getY();
	void setY(double y);
	double getDestX();
	void setDestX(double destX);
	double getDestY();
	void setDestY(double DestY);
	double getR();
	void setR(double r);
	double getZ();
	void setZ(double z);
	double getV();
	void setV(double v);
	double getAzimuth();
	void setAzimuth(double azimuth);
	double getId();
	void setId(int id);
	bool getWaiting();
	void setWaiting(bool waiting);
	void executeCommands(vector<RowData> &commands, vector<Uav>& uavs,double currentTime, int& currentCommandIndex);
	void updateUav(double dt);
	void createSimulationCycleOutput(double time);
};

