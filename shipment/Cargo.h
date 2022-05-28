#pragma once
#include <iostream>
#include"Company.h"
using namespace std;





class Cargo {
private:
	Time preptime;

	string TYP;
	double DIST; // cargo distance in KM
	double LT;   // time to load or unload a cargo in hours
	double COST;

protected:
	static int ID;

public:
	Cargo();
	Cargo(string TYP, int day, int hour, int ID, double DIST, double LT, double COST);


	void setcargoID(int);
	int getcargoID();
	void setcargoType(string);
	string getcargoType();
	void setcargoDistance(double);
	double getcargoDistance();
	void setcargoLoadTime(double);
	double getcargoLoadTime();
	void setcargoCost(double);
	double getcargoCost();
	void setpreptime(int, int);
	int getpreptimeday();
	int getpreptimehour();

};