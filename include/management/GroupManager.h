

#ifndef P3_GROUPMANAGER_H
#define P3_GROUPMANAGER_H

#include <vector>
#include <iostream>
#include <algorithm>

#include "group/Group.h"

class GroupManager{
private:
    int groupNumber;
    std::vector<Group*> groups;
public:
    const std::vector<Group*> &getGroups() const;

    int getGroupNumber() const;

    void setGroupNumber(int groupNumber);

    Group *getGroup(int idx);

    void sortGroupByDuration();

    GroupManager();
    GroupManager(int groupNumber);
    GroupManager(int groupNumber,int mode);
};

#endif //P3_GROUPMANAGER_H
