#include "management/GroupManager.h"
#include "utils/Utils.h"
#include "utils/CommonValue.h"

GroupManager::GroupManager(int groupNumber) {
    this->groupNumber = groupNumber;
    for (int i = 0; i < groupNumber; ++i) {
        Group *group=new Group(i,
                    Utils::getRandomInteger(CommonValue::MIN_GROUP_SIZE, CommonValue::MAX_GROUP_SIZE),
                    Utils::getCurrentTime());
        group->setGroupType(static_cast<GroupType>(Utils::getRandomInteger(1, CommonValue::PMS_TYPE_MAX)));
        group->setDuration(Utils::getRandomInteger(1, CommonValue::MAX_DURATION));
        this->groups.push_back(group);
    }
}

GroupManager::GroupManager() {

}

int GroupManager::getGroupNumber() const {
    return groupNumber;
}

void GroupManager::setGroupNumber(int groupNumber) {
    GroupManager::groupNumber = groupNumber;
}

Group *GroupManager::getGroup(int idx){
    return this->groups[idx];
}

void GroupManager::sortGroupByDuration() {
    std::sort(groups.begin(), groups.end(), [](Group *group1, Group *group2) {
        return group1->getDuration() < group2->getDuration();
    });
}

const std::vector<Group*> &GroupManager::getGroups() const {
    return groups;
}


