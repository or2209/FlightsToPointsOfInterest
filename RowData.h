#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class RowData
{
public:
	RowData();
	RowData(double time, int num, double x, double y);
	double getTime();
	int getNum();
	double getX();
	double getY();
	void sortCommandsByTime(vector<RowData>& commands);

private:
	double time;
	int num;
	double x;
	double y;


};
