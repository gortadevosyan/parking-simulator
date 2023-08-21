

#ifndef P3_TICKETMANAGER_H
#define P3_TICKETMANAGER_H
#include <iostream>
#include <ctime>

#include "group/Group.h"
#include "utils/Utils.h"

class TicketManager{
private:
public:
    void printEnterTicket(Group &group);
    void printExitTicket(Group &group);
    float calcPrice(Group group, double diffTime);
};

#endif //P3_TICKETMANAGER_H
