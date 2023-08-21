#include "group/Spacecraft.h"


Spacecraft::Spacecraft() {
    this->anchor = {0.02, 0.1};
    this->adjustParam = {-0.10, 0};
    this->stepScale = 1;
    this->stepAddition = 7;
    this->scale = 0.956;
    mainBody = {0.20,
                0.04,
                {0.02, 0.1},
                {1, 1, 0}};
    door = {0.016,
            0.008,
            {0.02, 0.1},
            {0, 1, 1}};
    leftWindow = {0.01,
                  0.01,
                  {0.01, 0.13},
                  {1, 0, 0}};
    rightWindow = {0.01,
                   0.01,
                   {0.03, 0.13},
                   {1, 0, 0}};
    leftWing = {{{-0.025, 0}, {0, 0}, {0, 0.06}},
                {-0.0125,     0.03},
                {1,           0.64,   0}};
    rightWing = {{{0.04, 0}, {0.065, 0}, {0.04, 0.06}},
                 {0.0625,    0.03},
                 {1,         0.64,       0}};
    header = {{{0, 0.2}, {0.02, 0.25}, {0.04, 0.2}},
              {0.24,     0.02},
              {0,        0.5,          0}};
    base = {{{0, 0}, {-0.01, -0.02}, {0.05, -0.02}, {0.04, 0}},
            {0.02,   -0.01},
            {0,      0,              0}};

}

void Spacecraft::draw() {
    // customize trajectory tracking anchor -> base
    trajectory.addTrajectory(base.getAnchor());
    trajectory.draw();
    // adjust scale under boundary situation
    if(!trajectory.ifParked()){
        if (stepScale < CommonValue::SPACECRAFT_SCALE_MIN) scale = 1.037;
        if (stepScale > CommonValue::SPACECRAFT_SCALE_MAX) scale = 0.956;
        zoom(scale, getAnchor());
    }
    // components plotting
    mainBody.draw();
    door.draw();
    leftWindow.draw();
    rightWindow.draw();
    base.draw();
    leftWing.draw();
    rightWing.draw();
    header.draw();
}

void Spacecraft::move(Vec dir) {
    anchor = anchor + dir;

    mainBody.move(dir);
    door.move(dir);
    leftWindow.move(dir);
    rightWindow.move(dir);
    base.move(dir);
    rightWing.move(dir);
    leftWing.move(dir);
    header.move(dir);
}

void Spacecraft::rotate(float angle) {
    mainBody.rotate(angle, this->anchor);
    door.rotate(angle, this->anchor);
    leftWindow.rotate(angle, this->anchor);
    rightWindow.rotate(angle, this->anchor);
    base.rotate(angle, this->anchor);
    rightWing.rotate(angle, this->anchor);
    leftWing.rotate(angle, this->anchor);
    header.rotate(angle, this->anchor);
}

void Spacecraft::moveTo(Vec vec) {
    move(vec - this->anchor);
}

Trajectory *Spacecraft::getTrajectory() {
    return &trajectory;
}

void Spacecraft::drawTrajectory(int mode, float theta, int size) {
    this->trajectory.addHistory(this->anchor);
    if (mode == CommonValue::FORWARD_MODE) {
        this->trajectory.addTrajectory(this->base.getAnchor());
    } else if (mode == CommonValue::BACK_MODE) {
        this->trajectory.setTrajectoryLine(this->base.getAnchor(), theta, size);
    }
    trajectory.draw();
}

void Spacecraft::zoom(float scale, Vec center) {
    this->stepScale *= scale;
    mainBody.zoom(scale, center);
    door.zoom(scale, center);
    leftWindow.zoom(scale,center);
    rightWindow.zoom(scale, center);
    base.zoom(scale, center);
    rightWing.zoom(scale, center);
    leftWing.zoom(scale,center);
    header.zoom(scale, center);
}




