#include "group/Group.h"

const Vec &Group::getAdjustParam() const {
    return adjustParam;
}

void Group::setAdjustParam(const Vec &adjustParam) {
    Group::adjustParam = adjustParam;
}

float Group::getStepScale() const {
    return stepScale;
}

void Group::setStepScale(float stepScale) {
    Group::stepScale = stepScale;
}

int Group::getStepAddition() const {
    return stepAddition;
}

void Group::setStepAddition(int stepAddition) {
    Group::stepAddition = stepAddition;
}

//const Trajectory &Group::getTrajectory() const {
//    return trajectory;
//}
//
//void Group::setTrajectory(const Trajectory &trajectory) {
//    Group::trajectory = trajectory;
//}
//
//void Group::addTrajectory() {
//    trajectory.addTrajectory(this->anchor);
//}
//
//void Group::addTrajectory(Vec vec) {
//    trajectory.addTrajectory(vec);
//}
//
//void Group::addHistory(Vec vec) {
//    trajectory.addHistory(vec);
//}
//


