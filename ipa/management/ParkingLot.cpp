#include "management/ParkingLot.h"
#include "utils/Logger.h"

void ParkingLot::init(int argc, char **argv,
                       int slotNumber, int groupNumber, int floorNumber) {
    slotManager = {slotNumber, floorNumber};
    groupManager = {groupNumber,CommonValue::IPA_MODE};
    plotManager = {argc, argv};
    Utils::initRandom();
}

void ParkingLot::init(int argc, char **argv, std::vector<int> params) {
    // init
    groupManager = {params[1],CommonValue::IPA_MODE};
    slotManager = {params[0], params[2]};
    plotManager = {argc, argv};
    Utils::initRandom();
}

void ParkingLot::simulateAnimation() {
    plotManager.render();
}

const SlotManager &ParkingLot::getSlotManager() const {
    return slotManager;
}

void ParkingLot::setSlotManager(const SlotManager &slotManager) {
    ParkingLot::slotManager = slotManager;
}

const GroupManager &ParkingLot::getGroupManager() const {
    return groupManager;
}

void ParkingLot::setGroupManager(const GroupManager &groupManager) {
    ParkingLot::groupManager = groupManager;
}

const TicketManager &ParkingLot::getTicketManager() const {
    return ticketManager;
}

void ParkingLot::setTicketManager(const TicketManager &ticketManager) {
    ParkingLot::ticketManager = ticketManager;
}

const PlotManager &ParkingLot::getPlotManager() const {
    return plotManager;
}

void ParkingLot::setPlotManager(const PlotManager &plotManager) {
    ParkingLot::plotManager = plotManager;
}
