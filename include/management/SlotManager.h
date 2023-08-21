

#ifndef P3_SLOTMANAGER_H
#define P3_SLOTMANAGER_H

#include <iostream>
#include <vector>
#include <bitset>

#include "group/Group.h"
#include "utils/Utils.h"
#include "utils/CommonValue.h"


class SlotManager {
private:
    int slotNumber;
    int floorNumber;
    std::vector<int> slotSizes;
    std::vector<int> floorNum;
    std::vector<Group*> slotContent;
    std::bitset<CommonValue::MAX_SLOT_NUM> slotStatus; // false - empty ; true - taken
public:
    SlotManager();

    SlotManager(int slotNumber, int floorNumber);

    std::vector<int> findEmptySlot(Group group);

    int findFirstEmptySlot(Group *group);

    std::string getSlotInfo(int idx);

    int getSlotNumber() const;

    void setSlotNumber(int slotNumber);

    int getFloorNumber() const;

    void setFloorNumber(int floorNumber);

    Group* getGroup(int idx);

    void parkGroup(Group *group,int idx);

    int getSize(int idx);
    int getFloor(int idx);
};

#endif //P3_SLOTMANAGER_H
