#include "management/SlotManager.h"
#include "utils/CommonValue.h"

SlotManager::SlotManager(int slotNumber, int floorNumber) {
    this->slotNumber = slotNumber;
    this->floorNumber = floorNumber;
    slotSizes.resize(slotNumber);
    floorNum.resize(slotNumber);
    slotContent.resize(slotNumber);

    // randomly generate each floor's empty slot & their size
    for (int i = 0; i < slotNumber; ++i) {
        floorNum[i] = floorNumber > 1 ? Utils::getRandomInteger(1, floorNumber) : 1;
        slotSizes[i] = Utils::getRandomInteger(CommonValue::MIN_GROUP_SIZE,
                                               CommonValue::MAX_GROUP_SIZE);
    }
}

SlotManager::SlotManager() {

}

std::vector<int> SlotManager::findEmptySlot(Group group) {
    std::vector<int> ret;
    for (int i = 0; i < slotNumber; ++i) {
        if (group.getSize() <= slotSizes[i] && !slotStatus[i]) {
            ret.push_back(i);
        }
    }
    // default case: slot 0 will be taken
    slotStatus[ret[0]] = true;
    return ret;
}

int SlotManager::getSize(int idx) {
    return slotSizes[idx];
}

int SlotManager::getFloor(int idx) {
    return floorNum[idx];
}

std::string SlotManager::getSlotInfo(int idx) {
    std::string info;
    info = "slot idx=" + std::to_string(idx) +
           ", slot floor=" + std::to_string(floorNum[idx]) +
           ", slot size=" + std::to_string(slotSizes[idx]);
    return info;
}

int SlotManager::getSlotNumber() const {
    return slotNumber;
}

void SlotManager::setSlotNumber(int slotNumber) {
    SlotManager::slotNumber = slotNumber;
}

int SlotManager::getFloorNumber() const {
    return floorNumber;
}

void SlotManager::setFloorNumber(int floorNumber) {
    SlotManager::floorNumber = floorNumber;
}





