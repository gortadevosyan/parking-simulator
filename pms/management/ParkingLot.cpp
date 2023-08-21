#include "management/ParkingLot.h"
#include "utils/Logger.h"


// 0 - slotNum, 1 - groupNum, 2 - floorNum
void ParkingLot::init(std::vector<int> params) {
    // init
    groupManager = {params[1]};
    slotManager = {params[0], params[2]};
    Utils::initRandom();
    // log init
    Logger::logInitGroup(groupManager);
    Logger::logInitSlots(slotManager);
}

void ParkingLot::simulate() {
    for (int i = 0; i < groupManager.getGroupNumber(); ++i) {
        Group *group = groupManager.getGroup(i);
        ticketManager.printEnterTicket(*group);
        auto slots = slotManager.findEmptySlot(*group);
        Logger::logSlot(slots, slotManager);
        Logger::logSeparationLine();
    }

    groupManager.sortGroupByDuration();

    for (int i = 0; i < groupManager.getGroupNumber(); ++i) {
        Group *group = groupManager.getGroup(i);
        ticketManager.printExitTicket(*group);
        std::cout << "\n" << std::endl;
        Logger::logSeparationLine();
    }
}




//void ParkingLot::plotParkingLot() {
//
//}
//
//void ParkingLot::plotSlot() {
//
//}



//std::vector<int> ParkingLot::findEmptySlot(Group group) {
//    return this->slotManager.findEmptySlot(group);
//}


