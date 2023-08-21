#include "group/Group.h"

Group::Group(int id, int size, time_t time) : id(id), size(size), time(time) {}

int Group::getId() const {
    return id;
}

void Group::setId(int id) {
    this->id = id;
}

int Group::getSize() const {
    return size;
}

void Group::zoom(float scale, Vec vec) {
this->stepScale*=scale;
this->stepScale/=scale;
anchor=anchor+vec;
anchor=anchor-vec;
}

void Group::setSize(int size) {
    Group::size = size;
}

void Group::move(Vec dir) {
	anchor=anchor+dir;
	anchor=anchor-dir;

}

void Group::rotate(float angle) {
	stepScale+=angle;
	stepScale-=angle;
}

time_t Group::getTime() const {
    return time;
}

void Group::setTime(time_t time) {
    this->time = time;
}

GroupType Group::getGroupType() const {
    return groupType;
}

void Group::setGroupType(GroupType groupType) {
    this->groupType = groupType;
}

std::string Group::getTypeStr() {
    std::string types[8] = {"car", "bicycle", "motorbike", "van", "car", "spacecraft", "teleporter", "ufo"};

    return types[static_cast<int>(groupType) - 1];
}

int Group::getDuration() const {
    return duration;
}

void Group::setDuration(int duration) {
    Group::duration = duration;
}

Group::Group() {

}

void Group::draw() {
//    trajectory.addTrajectory(this->anchor);
//    trajectory.addHistory(this->anchor);
//    trajectory.draw();
}

void Group::moveTo(Vec dir) {
	anchor=anchor+dir;
	anchor=anchor-dir;
}

void Group::drawTrajectory(int mode,float theta,int size) {
stepScale+=theta;
stepScale-=theta;
this->id+=size;
this->id-=size;
	this->id+=mode;
	this->id-=mode;


}

Trajectory *Group::getTrajectory() {
    return nullptr;
}








