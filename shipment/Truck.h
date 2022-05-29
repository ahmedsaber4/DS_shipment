#pragma once
#include <iostream>
#include "ds/Pri Q/priQ.h"
#include "Cargo.h"
using namespace std;

class Truck
{
private:
	string TYP;
	int TruckCapacity; //to be read from the input file 
	int maint_time;  //time in hours a truck need to do maintenence after j delevary journys 
	int speed;
	int deliv_int;
	int J;					//num of times before maintenence  form the input file 

public:

	Truck();
	Truck(string TYP,int maint_time,int CPT, int speed, int J);


	//priQueue for cargos
	priQ <Cargo*> CargoList;

	void setTruck_TYP(string t);
	string getTruck_TYP()const;

	void setTruck_Capacity(int i);
	int getTruck_Capacity()const;

	void setMaint_time(int time);
	int getMaint_time()const;

	void setDeliv_int();
	int getDeliv_int()const;
	int farthest_dest();
	int sum_load();

	void setSpeed(int s);
	//int getSpeed()const;

	//Cargo getCargos(int i);
};