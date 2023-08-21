#include "group/Teleporter.h"
#include "utils/Utils.h"

Teleporter::Teleporter() {
    this->anchor = {0, 0};
    this->adjustParam = {0, 0};
    this->stepScale = 0;
    this->stepAddition = 0;
    rectangle = {0.4f, 0.2f, {0, 0}, {0, 0, 0}};
}

void Teleporter::draw() {
    Group::draw();
    // generate random RGB color, min step=0.1
    std::vector<float> colors;
    for (int i = 0; i < 3; ++i) {
        int colorScale = Utils::getRandomInteger(0, 10);
        colors.push_back((float) colorScale / 10);
    }
    rectangle.setColor(colors);
    rectangle.draw();
}

void Teleporter::move(Vec direction) {
    this->anchor = this->anchor + direction;
    rectangle.move(direction);
}

void Teleporter::rotate(float angle) {
    Group::rotate(angle);
}

void Teleporter::moveTo(Vec vec) {
    move(vec - this->anchor);
}

Trajectory *Teleporter::getTrajectory() {
    return &trajectory;
}
