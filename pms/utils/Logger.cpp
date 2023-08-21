#include "utils/Logger.h"

std::vector<int> Logger::getInitParam() {
    std::vector<int> params;
    params.resize(3);
    std::cout << "Please input the slot number= ";
    std::cin >> params[0];
    std::cout << "Please input the group number= ";
    std::cin >> params[1];
    std::cout << "Please input the floor number= ";
    std::cin >> params[2];
    return params;
}

void Logger::logWelcome() {
    std::cout << "Welcome to the general parking lot simulation "
                 "program.\n\n";
}

void Logger::logSlot(std::vector<int> slots, SlotManager &slotManager) {
    if (slots.empty()) {
        std::cout << "\nSorry, slot not found." << std::endl;
    } else {
        std::cout << "\nSlot Found:\t";
        std::cout << slotManager.getSlotInfo(slots[0]) << "\n\n";
    }
}

void Logger::logInitSlots(SlotManager &slotManager) {
    std::cout << "Initializing slots: total " << slotManager.getSlotNumber() << " slots, " <<
              slotManager.getFloorNumber() << (slotManager.getFloorNumber() == 1 ? " floor." : "floors") <<
              "\n\n";
}

void Logger::logInitGroup(GroupManager &groupManager) {
    std::cout << "\nInitializing groups: total " << groupManager.getGroupNumber() << " groups\n\n";
}

void Logger::logSeparationLine() {
    std::cout << "===============================================================" << std::endl;
}

void Logger::logSlot(int slot, SlotManager &slotManager) {
    std::vector<int> slots;
    slots.push_back(slot);
    Logger::logSlot(slots, slotManager);
}
