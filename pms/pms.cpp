#include "management/ParkingLot.h"
#include "utils/Logger.h"

using namespace std;


// demo mode

int main() {
    Logger::logWelcome();
    auto param = Logger::getInitParam();
    ParkingLot &parkingLot=ParkingLot::getInstance();
    parkingLot.init(param);
    parkingLot.simulate();
    return 0;
}
