

#ifndef P3_PARKINGLOT_H
#define P3_PARKINGLOT_H

#include <vector>
#include <iostream>
#include <map>

#include "group/Group.h"
#include "figure/Figure.h"

#include "management/TicketManager.h"
#include "management/SlotManager.h"
#include "management/PlotManager.h"
#include "management/GroupManager.h"

class ParkingLot {
public:
    const GroupManager &getGroupManager() const;

    void setGroupManager(const GroupManager &groupManager);

    const TicketManager &getTicketManager() const;

    void setTicketManager(const TicketManager &ticketManager);

    const PlotManager &getPlotManager() const;

    void setPlotManager(const PlotManager &plotManager);

    const SlotManager &getSlotManager() const;

    void setSlotManager(const SlotManager &slotManager);

    static ParkingLot& getInstance(){
        static ParkingLot parkingLot;
        return parkingLot;
    }

    ParkingLot(const ParkingLot&)=delete;
    ParkingLot(ParkingLot&&)=delete;
    ParkingLot &operator=(const ParkingLot&)=delete;
    ParkingLot &operator=(ParkingLot&&)=delete;

    void init(int argc, char **argv, int slotNumber,
              int groupNumber, int floorNumber);
    void init(std::vector<int> params);
    void init(int argc,char **argv,std::vector<int> params);
    void simulate();
    void simulateAnimation();

private:
    TicketManager ticketManager;
    SlotManager slotManager;
    PlotManager plotManager;
    GroupManager groupManager;

    ParkingLot()=default;
    ~ParkingLot()=default;
};

#endif //P3_PARKINGLOT_H

