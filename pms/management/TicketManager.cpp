#include "management/TicketManager.h"

void TicketManager::printEnterTicket(Group &group) {
    std::cout << "Welcome entering: group-id= " << group.getId() << std::endl;
    std::cout << "Vehicle Type= " << group.getTypeStr() << std::endl;
    std::cout << "Vehicle Size= " << group.getSize() << std::endl;
    std::cout << "Current System time= " << Utils::getCurrentTimeStr() << std::endl;
    std::cout << "Your fee criterion= " << group.getSize() << std::endl;
    // some time diff may occur, but can be neglected
    group.setTime(Utils::getCurrentTime());
}

void TicketManager::printExitTicket(Group &group) {
    std::cout << "Welcome exiting: group-id= " << group.getId() << std::endl;
    std::cout << "Current System time= " << Utils::getTimeStr(group.getTime() + group.getDuration())
              << std::endl;
    std::cout << "Duration (in seconds)= " << group.getDuration() << std::endl;
    std::cout << "Your fee = " << (group.getDuration() ? (float) group.getDuration() * group.getSize() :
                                   calcPrice(group, Utils::getTimeDiff(group.getTime(), Utils::getCurrentTime())))
              << std::endl;
}

float TicketManager::calcPrice(Group group, double diffTime) {
    return (float) diffTime * (float) group.getSize();
}

