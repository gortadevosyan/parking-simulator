#include "management/GroupManager.h"
#include "utils/CommonValue.h"
#include "utils/Utils.h"
#include "group/Group.h"
#include "group/Car.h"
#include "group/Teleporter.h"
#include "group/Spacecraft.h"
#include "group/UFO.h"

GroupManager::GroupManager(int groupNumber, int mode) {
    this->groupNumber = groupNumber;
    if (mode == CommonValue::IPA_MODE) {
        for (int i = 0; i < groupNumber; ++i) {
            int type = Utils::getRandomInteger(5, 8);
            switch (type) {
                case (int) GroupType::IPA_CAR: {
                    Group *car = new Car();
                    car->setGroupType(GroupType::IPA_CAR);
                    groups.push_back(car);
                }
                    break;
                case (int) GroupType::IPA_SPACECRAFT: {
                    Group *spacecraft = new Spacecraft();
                    spacecraft->setGroupType(GroupType::IPA_SPACECRAFT);
                    groups.push_back(spacecraft);
                }
                    break;
                case (int) GroupType::IPA_TELEPORTED: {
                    Group *teleported = new Teleporter();
                    teleported->setGroupType(GroupType::IPA_TELEPORTED);
                    groups.push_back(teleported);
                }
                    break;
                case (int) GroupType::IPA_UFO: {
                    Group *ufo = new UFO();
                    ufo->setGroupType(GroupType::IPA_UFO);
                    groups.push_back(ufo);
                }
                    break;
                default: {
                }
                    break;
            }
        }

        for (int i = 0; i < groupNumber; i++) {
            groups[i]->setId(i);
            groups[i]->setTime(Utils::getCurrentTime());
            groups[i]->setDuration(Utils::getRandomInteger(1, CommonValue::MAX_DURATION));
        }
    }
}

