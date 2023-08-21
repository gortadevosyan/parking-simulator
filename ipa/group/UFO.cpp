#include "group/UFO.h"

UFO::UFO() {
    this->anchor = {0, 0};
    this->adjustParam = {-0.07, 0};
    this->stepAddition = 6;
    this->stepScale = 1.0;
    semiCircle = {{0, 0}, {0, 0, 1}, 0.1, 0};
    footer1 = {{{-0.075, 0}, {-0.025, 0}, {-0.02, -0.025}, {-0.08, -0.025}},
               {0,           0},
               {1,           0.8,         0}};
    footer2 = {{{0.075, 0}, {0.025, 0}, {0.02, -0.025}, {0.08, -0.025}},
               {0,          0},
               {1,          0.8,        0}};
    line1 = {{{0.07, 0.07}, {0.095, 0.095}},
             {0,            0},
             {1,            0.5, 0}};
    line2 = {{{-0.07, 0.07}, {-0.095, 0.095}},
             {0,             0},
             {1,             0.5, 0}};
}

void UFO::draw() {
    if(!trajectory.ifParked()) rotate(CommonValue::UFO_ROTATION_DEGREE);
    semiCircle.draw();
    line1.draw();
    line2.draw();
    footer1.draw();
    footer2.draw();
}

void UFO::move(Vec direction) {
    setAnchor(this->getAnchor() + direction);
    semiCircle.move(direction);
    line1.move(direction);
    line2.move(direction);
    footer1.move(direction);
    footer2.move(direction);
}

void UFO::moveTo(Vec vec) {
    move(vec - anchor);
}

void UFO::rotate(float angle) {
    semiCircle.rotate(angle, anchor);
    line1.rotate(angle, anchor);
    line2.rotate(angle, anchor);
    footer1.rotate(angle, anchor);
    footer2.rotate(angle, anchor);
}

void UFO::drawTrajectory(int mode, float theta, int size) {
    this->trajectory.addHistory(this->anchor);
    if (mode == CommonValue::FORWARD_MODE) {
        this->trajectory.addTrajectory(this->anchor);
    } else if (mode == CommonValue::BACK_MODE) {
        this->trajectory.setTrajectoryLine(this->anchor, theta, size);
    }
    trajectory.draw();
}

Trajectory *UFO::getTrajectory() {
    return &(trajectory);
}

void UFO::zoom(float scale, Vec center) {
	this->stepScale+=scale;
	this->stepScale-=scale;
	anchor=anchor+center;
	anchor=anchor-center;
}
