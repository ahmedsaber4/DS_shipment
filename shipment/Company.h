#pragma once
#include <fstream>
#include <iostream>
#include "Truck.h"
#include "Cargo.h"
#include "ds/stack/ArrayStack.h"
//#include "UI.h"
#include "ds/stack/StackADT.h"
//#include "Events.h"
#include "ds/queue/LinkedQueue.h"
#include "ds/linked list/LinkedList.h"


using namespace std;


class Company
{
private:

	int maxDay;
	int maxHour;
	int numEvents;
	int waitingCargoTime;
	
	//int AutoP, MaxW, N, S, V, NTC, STC, VTC ,J;
	//maint_time check_up;

protected:

	/*
	LinkedQueue<preparationEvent*> prepEventsList;
	LinkedQueue<cancelEvent*> cancEventsList;
	LinkedQueue<promoteEvent*> promEventsList;
	*/

	//waiting cargos vip priQueue
	LinkedList <Cargo*> WaitingNormalCargo;
	LinkedQueue <Cargo*> WaitingSpecialCargo;
	
	LinkedQueue <Cargo*> DeliveredCargos;
	
	LinkedQueue <Truck*> EmptyNormalTruck;
	LinkedQueue <Truck*> EmptySpecialTruck;
	LinkedQueue <Truck*> EmptyVIPTruck;
	
	//moving trucks priQueue

	LinkedQueue <Truck*> MaintNormalTruck;
	LinkedQueue <Truck*> MaintSpecialTruck;
	LinkedQueue <Truck*> MaintVIPTruck;

public:
	void simulation();
	/*
	-at start ,it loads the available trucks form the file
	-and make a list of cargos based on the TC of each type
	-to check if a truck is available	(maintenence or delivary)
	-if the company is during its working hours ,then do the coming #maintenece and delivary duting the off-hours
	*make a num of available cargos in the cargo calss
	-max of loading trucks is 3 ,one for each type
	--maxW->non-vip cargos only
	-assignment order ->vip ->special-> normal
	-vip assignment order -> (delv_dest*cost)/prep_time   <---priQ equ
	-cargo promotion or cancelation 
	-auto promotion of normal cargos


*/
	
	//void setMaxDay(int d);
	//int getMaxDay();

	//void setMaxHour(int d);
	//int getMaxHour();

	//void setnumEvents(int g);
	//int getnumEvents();
	//
	//int getTime();
	//void setTime(int s, int d);

	//bool isWorking();
	// 
	//void assigning();

	////Node<Cargo*> getHeadWNC();
	////LinkedList <Cargo*>getWaitingNormalList();

	//void AddWNC(Cargo* name); //adding to waiting normal waiting list
	//void AddWSC(Cargo* name); //adding to waiting special waiting list
	//void AddWVC(Cargo* name); //adding to waiting VIP waiting list

	//void AddMNC(Cargo* name); //adding to Moving normal waiting list
	//void AddMSC(Cargo* name); //adding to Moving special waiting list
	//void AddMVC(Cargo* name); //adding to Moving VIP waiting list

	//void AddDNC(Cargo* name); //adding to Deliverd normal waiting list
	//void AddDSC(Cargo* name); //adding to Deliverd special waiting list
	//void AddDVC(Cargo* name); //adding to Deliverd VIP waiting list

	//void AddENT(Truck* name); //adding to Empty normal truck
	//void AddEST(Truck* name); //adding to Empty Special truck
	//void AddEVT(Truck* name); //adding to Empty VIP truck

	//void AddANT(Truck* name); //adding to active normal truck
	//void AddAST(Truck* name); //adding to active Special truck
	//void AddAVT(Truck* name); //adding to active VIP truck

	//void AddMNT(Truck* name); //adding to Maintance normal truck
	//void AddMST(Truck* name); //adding to Maintance Special truck
	//void AddMVT(Truck* name); //adding to Maintance VIP truck
	//

	//void AddPrepEvent(preparationEvent* name); //adding to event list
	//void AddCancelEvent(cancelEvent* name);
	//void AddPromoEvent(promoteEvent* name);

	//void AddprepEvent(Event* name);
	//void AddcancEvent(Event* name);
	//void AddpromEvent(Event* name);

	void LoadingInFile();
	void SavingOutfile();

	//int getAutoP();
	//int getMaxW();	
	//int getN();
	//int getS();
	//int getV();
	//int getNTC();
	//int getSTC();
	//int getVTC();


	//void setAutoP(int number) {
	//	this->AutoP = number;
	//}
	//void setMaxW(int number) {
	//	this->MaxW = number;
	//}

	//void simulation();


};

