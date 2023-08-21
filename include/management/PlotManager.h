

#ifndef P3_PLOTMANAGER_H
#define P3_PLOTMANAGER_H

#include <string>
#include <vector>
#include <cstdlib>
// TODO: FIX  cross-os-error
#include <unistd.h>
#include <cmath>

#include "figure/Rectangle.h"
#include "utils/CommonValue.h"
#include "management/SlotManager.h"
#include "management/GroupManager.h"



class PlotManager {
private:
    const char *windowName;
    std::pair<float, float> windowSize;
    int windowPos{};

    int argc;
    char **argv;

    int slotWidth{};

public:
    int getSlotWidth() const;

    void setSlotWidth(int slotWidth);

    PlotManager(){}

    PlotManager(int argc, char **argv);

    PlotManager(int argc, char **argv, std::string windowName, std::pair<float, float> windowSize);

    void render();
};

#endif //P3_PLOTMANAGER_H
