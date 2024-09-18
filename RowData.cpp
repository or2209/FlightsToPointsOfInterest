#include "RowData.h"


RowData::RowData() {
	this->time = 0;
	this->num = 0;
	this->x = 0;
	this->y = 0;
}
RowData::RowData(double time, int num, double x, double y) {
	this->time = time;
	this->num = num;
	this->x = x;
	this->y = y;
	}

double RowData::getTime() {
	return time;
}

int RowData::getNum() {
	return num;
}

double RowData::getX() {
	return x;
}

double RowData::getY() {
	return y;
}

void RowData::sortCommandsByTime(vector<RowData>& commands) {
	sort(commands.begin(), commands.end(), [](RowData& command1, RowData& command2) {
		return command1.getTime() < command2.getTime();
		});
}

