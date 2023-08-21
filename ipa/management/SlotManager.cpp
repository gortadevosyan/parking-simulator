#include "management/SlotManager.h"

Group *SlotManager::getGroup(int idx) {
    if ((idx >= slotNumber) || (idx < slotNumber && !slotStatus[idx])) {
        return nullptr;
    } else {
        return slotContent[idx];
    }
}

void SlotManager::parkGroup(Group *group, int idx) {
    slotContent[idx] = group;
}

int SlotManager::findFirstEmptySlot(Group *group) {
    int ret = -1;
    for (int i = 0; i < slotNumber; ++i) {
        if (group->getSize() <= slotSizes[i] && !slotStatus[i]) {
            ret = i;
            break;
        }
    }

    if (ret == -1) {
        std::cout << "cannot find any slot." << std::endl;
    } else {
        slotStatus[ret] = true;
    }
    return ret;
}
