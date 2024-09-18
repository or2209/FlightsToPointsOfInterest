#include "Uav.h"
#include "Simulation.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PAI = 3.14159265358979323846;


Uav::Uav(int id, double r, double x, double y, double destX, double destY, double z, double v,
	double azimuth) {
	this->id = id;
	this->r = r;
	this->x = x;
	this->y = y;
	this->destX = destX;
	this->destY = destY;
	this->z = z;
	this->v = v;
	this->azimuth = azimuth;
	this->waiting = false;
	this->waitStartTime = 0;
}

double Uav::getX() {
	return this->x;
}

void Uav::setX(double x) {
	this->x = x;
}

double Uav::getY() {
	return this->y;
}

void Uav::setY(double y) {
	this->y = y;
}

double Uav::getDestX()
{
	return this->destX;
}

void Uav::setDestX(double destX)
{
	this->destX = destX;
}

double Uav::getDestY()
{
	return this->destY;
}

void Uav::setDestY(double destY)
{
	this->destY = destY;
}

double Uav::getR()
{
	return this->r;
}

void Uav::setR(double r)
{
	this->r = r;
}

double Uav::getZ()
{
	return this->z;
}

void Uav::setZ(double z)
{
	this->z = z;
}

double Uav::getV()
{
	return this->v;
}

void Uav::setV(double v)
{
	this->v = v;
}

double Uav::getAzimuth()
{
	return this->azimuth;
}

void Uav::setAzimuth(double azimuth)
{
	this->azimuth = azimuth;
}

double Uav::getId()
{
	return this->id;
}

void Uav::setId(int id)
{
	this->id = id;
}

bool Uav::getWaiting()
{
	return this->waiting;
}

void Uav::setWaiting(bool waiting)
{
	this->waiting = waiting;
}

void Uav::executeCommands(vector<RowData>& commands, vector<Uav>& uavs, double currentTime, int& currentCommandIndex) {
	while (currentCommandIndex < commands.size() && commands[currentCommandIndex].getTime() == currentTime) {
		int uavIndex = commands[currentCommandIndex].getNum();
		uavs[uavIndex].setDestX(commands[currentCommandIndex].getX());
		uavs[uavIndex].setDestY(commands[currentCommandIndex].getY());
		uavs[uavIndex].setWaiting(false);
		//update the index, indicate that we allready do this command
		currentCommandIndex+=1;
	}
}


void Uav::updateUav(double dt) {
	if (this->waiting) {
		// the UAV is circling. Update position and azimuth.
		this->setAzimuth(this->getAzimuth() - (this->getV() / this->getR()) * dt);
		this->setX(this->getDestX() + this->getR() * cos(this->getAzimuth()));
		this->setY(this->getDestY() + this->getR() * sin(this->getAzimuth()));
	}
	else {
		// the UAV is flying straight.
		this->setX(this->getX() + this->getV() * cos(this->getAzimuth()) * dt);
		this->setY(this->getY() + this->getV() * sin(this->getAzimuth()) * dt);
	}

	if (this->getDestX() != -1 && this->getDestY() != -1 && this->getWaiting() == false) {
		// Fly to the destination.
		double dx = this->getDestX() - this->getX();
		double dy = this->getDestY() - this->getY();
		double distance = sqrt(dx * dx + dy * dy);
		this->setAzimuth(atan2(dy, dx));
		if (distance <= this->getV() * dt) {
			this->setX(this->getDestX());
			this->setY(this->getDestY());
			this->setWaiting(true);
		}
	}
}


// Write output to file
void Uav::createSimulationCycleOutput(double time) {
	ofstream file("Uav" + to_string(id) + ".txt", ios_base::app);
	double azimuth_degrees = this->azimuth * (180.0 / PAI);
	file << fixed << setprecision(2) << time << " " << x << " " << y << " " << azimuth_degrees << "\n";
}
