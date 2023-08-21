#include "management/ParkingLot.h"
#include "utils/Logger.h"



int main(int argc, char **argv) {
    Logger::logWelcome();
    auto params=Logger::getInitParam();
    ParkingLot &parkingLot=ParkingLot::getInstance();
    parkingLot.init(argc,argv,params);
    parkingLot.simulateAnimation();
    return 0;
}
