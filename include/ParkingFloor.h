#ifndef PARKING_FLOOR
#define PARKING_FLOOR

#include <iostream>
#include <vector>
using namespace std;

class ParkingFloor
{
private:
	int floor_index;
	int slot_number;
	int *slot;
public:
	ParkingFloor(int floor_index,int slot_number);
	~ParkingFloor();
	void init_set(int floor_index,int slot_number);
	void check_in_slot(int slot_index,int car_index);
	void check_out_slot(int slot_index);
	int find_empty_slot();
};

#endif