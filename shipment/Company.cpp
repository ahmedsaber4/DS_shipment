#include <fstream>
#include <iostream>
#include "Company.h"
//#include "Events.h"
//#include "Cargo.h"
#include "Truck.h"

using namespace std;


Company::Company()
{
	this->LoadingInFile();
	now.Day = 0;
	now.Hour = 0;
	//this->LoadingInFile();
}

void Company::incrementNow()
{
	if (now.Hour < 24)
		this->now.Hour += 1;
	else
	{
		this->now.Day += 1;
	}
}

void Company::simulation()
{
	this->incrementNow();
	this->runEvent();





}

void Company::runEvent()
{
	Event* E = nullptr;
	this->EventList.peek(E);
	if (E != nullptr) {
		if (E->geteventTimehour() == now.Hour && E->geteventTimeday() == now.Day) {
			E->execute();
			EventList.dequeue(E);
			delete E;
		}
	}
}



void Company::LoadingInFile()
{
	ifstream file;
	file.open("ayyad.txt");
	int N, S, V; //go back to project document to know the shortcuts
	file >> N >> S >> V; //reading the number of trucks 
	int NS, SS, VS;
	file >> NS >> SS >> VS; //reading the speed of the trucks
	int NTC, STC, VTC;
	file >> NTC >> STC >> VTC; // reading the capicty of the trucks hhtsgl 
	int J;
	int CN, CS, CV;
	file >> J >> CN >> CS >> CV; //reading no. of journeys and checkup durations

	int AutoP, MaxW;
	file >> AutoP >> MaxW; //reading the promotion time and the maximum wait time
	

	for (int i = 0; i < N; i++) {
		Truck* pTruck = new Truck("Normal",CN ,NTC,NS,J);
		AddENT(pTruck);
	}

	for (int i = 0; i < S; i++) {
		Truck* pTruck = new Truck("Special",CS, STC,  SS, J);
		AddEST(pTruck);
	}

	for (int i = 0; i < V; i++) {
		Truck* pTruck = new Truck("VIP", CV,VTC, VS, J);
		AddEVT(pTruck);
	}

	int E;
	file >> E; //reading number of events
	//setnumEvents(E);
	string Status, TYP;
	cTime x;
	int ID, DIST, LT;
	double COST, extramoney;
	char drop_it;

	for (int i = 0; i < E; i++) {
		file >> Status;

		if (Status == "R") {
			file >> TYP >> x.Day >> drop_it >> x.Hour >> ID >> DIST >> LT >> COST;
			//setMaxDay(x.Day);
			//setMaxHour(x.Hour);
			//calculatePriorty();
			/*Cargo* m = new Cargo(TYP, x, ID, DIST, LT, COST);
			cout << m->calculatePriorty() << endl;
			AddWVC(m);*/

			preparationEvent* PpreparationEvent= new preparationEvent(TYP,x,ID,DIST,LT,COST);
			EventList.enqueue(PpreparationEvent);
		}
		if (Status == "X") {
			file >> x.Day >> drop_it >> x.Hour >> ID;
			//setMaxDay(x.Day);
			//setMaxHour(x.Hour);
			cancelEvent* PcancelEvent = new cancelEvent(ID , x);
			EventList.enqueue(PcancelEvent);
		}
		if (Status == "P") {
			file >> x.Day >> drop_it >> x.Hour >> ID >> extramoney;
			//setMaxDay(x.Day);
			//setMaxHour(x.Hour);
			promoteEvent* PpromoteEvent = new promoteEvent(ID, x, extramoney);
			EventList.enqueue(PpromoteEvent);
		}
	}
}


void Company::SavingOutfile()
{
	ofstream file;
	file.open("ayyad2.txt");
	file << "CDT" << "\t" << "CID" << "\t" << "PT" << "\t" << "WT" << "\t" << "TID";

	file << "---------------------------------";
}



//int Company::getAutoP()
//{
//	return AutoP;
//}
//int Company::getMaxW()
//{
//	return MaxW;
//}
//int Company::getN()
//{
//	return 0;
//}
//int Company::getS()
//{
//	return 0;
//}
//int Company::getV()
//{
//	return 0;
//}
//int Company::getNTC()
//{
//	return 0;
//}
//int Company::getSTC()
//{
//	return 0;
//}
//int Company::getVTC()
//{
//	return 0;
//}
//void Company::setAutoP(int number)
//{
//}
//void Company::setMaxW(int number)
//{
//}
//void Company::simulation()
//{
//	int day, hour;
//
//	for (int i = 0; i <(getMaxDay()*24 +getMaxHour() ); i++) {
//		hour++;
//		if (hour == 24) { day++; hour = 1; }
//		promoteEvent* ne = nullptr;
//		//promEventsList.dequeue(ne);
//		if (ne->geteventTimeday() == day && ne->geteventTimehour() == hour) {
//			ne->execute();
//		}
//		else {
//			promEventsList.enqueue(ne);
//		}
//
//		preparationEvent* e = nullptr;
//		//prepEventsList.dequeue(e);
//		if (e->geteventTimeday() == day && e->geteventTimehour() == hour) {
//			e->execute();
//		}
//		else {
//			prepEventsList.enqueue(e);
//		}
//
//
//		cancelEvent* x = nullptr;
//		cancEventsList.dequeue(x);
//		if (x->geteventTimeday() == day && x->geteventTimehour() == hour) {
//			x->execute();
//		}
//		else {
//			cancEventsList.enqueue(x);
//		}
//		setTime(day, hour);
//	}
//
//
//}
////////////////////////////////////////////////////////////////////////
////////////////////////Adding waiting cargo list
//
//void Company::setMaxDay(int d)
//{
//	if (d > maxDay) {
//		maxDay=d;
//	}
//}
//
//int Company::getMaxDay( )
//{
//
//	return maxDay;
//}
//
//void Company::setMaxHour(int d)
//{
//	if (maxHour < d)maxHour=d;
//
//}
//
//int Company::getMaxHour()
//{
//	return maxHour;
//}
//
//
//void Company::setnumEvents(int g)
//{
//	numEvents = g;
//}
//
//int Company::getnumEvents()
//{
//	return numEvents;
//}
//
//int Company::getTime()
//{
//	return t.Day, t.Hour;
//}
//
//void Company::setTime(int s, int d)
//{
//	t.Day = s; t.Hour = d;
//}
//
//bool Company::isWorking()
//{
//	int d, h = getTime();
//	if (h > 5 && h < 23) { return true; }
//}
//
//void Company::assigning()
//{
//	if (this->isWorking()) {
//		if (this->getV()>this->getVTC()) {
//			Truck t;
//			for (int i = 0; i < getVTC(); i++) {
//				t.getCargos(i);
//			}
//		}
//	}
//}
//
//Node<Cargo*> Company::getHeadWNC()
//{
//	return WaitingNormalCargo.getHead();
//}
//
void Company::AddWNC(Cargo* name)
{
	if (name != nullptr)
		WaitingNormalCargo.InsertBeg(name);
}
void Company::AddWSC(Cargo* name)
{
	WaitingSpecialCargo.enqueue(name);
}

void Company::AddWVC(Cargo* name )
{
	WaitingVipCargo.insert(name , name->calculatePriorty());
}

//////////////////////////////////////////////////////////////////////
////////////////////////Adding delivered cargo list
void Company::AddCTD(Cargo* name)
{
	DeliveredCargos.enqueue(name);
}


//////////////////////////////////////////////////////////////////////
//////////////////////Adding maintance truck list
void Company::AddMNT(Truck* name)
{
	if (name)
		MaintNormalTruck.enqueue(name);
}
void Company::AddMST(Truck* name)
{
	if (name)
		MaintSpecialTruck.enqueue(name);
}
void Company::AddMVT(Truck* name)
{
}

/// ////////////////////////////////////////////////////////////////
/// 


//////////////////////////////////////////////////////////////////////
//////////////////////Adding Empty truck list
void Company::AddENT(Truck* name)
{
	if (name)
		EmptyNormalTruck.enqueue(name);
}
void Company::AddEST(Truck* name)
{
	if (name)
		EmptySpecialTruck.enqueue(name);
}
void Company::AddEVT(Truck* name)
{
	if (name)
		EmptyVIPTruck.enqueue(name);
}
////////////////////////////////////////////////////////
