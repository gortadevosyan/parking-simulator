

#ifndef P3_LOGGER_H
#define P3_LOGGER_H

#include <iostream>
#include <vector>
#include "management/SlotManager.h"
#include "management/GroupManager.h"

class Logger{
public:

    static void logWelcome();
    static std::vector<int> getInitParam();
    static void logSlot(std::vector<int> slots, SlotManager &slotManager);
    static void logSlot(int slot,SlotManager &slotManager);
    static void logInitSlots(SlotManager &slotManager);
    static void logInitGroup(GroupManager &groupManager);
    static void logSeparationLine();

};

#endif //P3_LOGGER_H
