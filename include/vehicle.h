#ifndef VEHICLE
#define VEHICLE

#include <iostream>
#include <string>
const string VEHICLE_INDEX[4]={"van","car","motor","bike"};
const int PRICE_INDEX[4]={100,50,30,20};
using namespace std;

class ParkingFloor;
class ParkingLot;

class Vehicle
{
private:
	// van, car, motercycle, bicycle;0,1,2,3
	int vehicle_type;
	int price_per_min;
	ParkingFloor* park_floor;
	int park_slot;
	int time_arrived;
	int time_spend;

public:
	Vehicle(int time_arrived);
	~Vehicle();
	void arrive();
	void get_slot();
	void printArriveTicket();

	void leave();
	void printDepartureTicket();
	// to be continue;
};

#endif