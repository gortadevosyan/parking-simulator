#include "group/Car.h"
#include "math/Vec.h"
#include "figure/Rectangle.h"
#include "utils/Utils.h"
#include <GL/glut.h>


Car::Car() {
    this->anchor = {-0.68, -0.58};
    this->adjustParam = {-0.1, -0.02};
    this->stepAddition = 9;
    this->stepScale = 1.0;
    circle1 = {{-0.76, -0.64}, 0.03};
    circle1.setColor({1, 0.5, 0.4});
    circle2 = {{-0.60, -0.64}, 0.03};
    circle2.setColor({1, 0.5, 0.4});
    quadrilateral = {{{-0.76, -0.5}, {-0.6, -0.5}, {-0.56, -0.54}, {-0.8, -0.54}},
                     {-0.75,         -0.4},
                     {0.25,          1,            0.9}};
    rectangle = {0.08, 0.28, {-0.68, -0.58}, {1, 0.5, 0}};
    pipe = {0.02, 0.02, {-0.83, -0.6}, {0.3, 0.3, 0.3}};
}

void Car::move(Vec direction) {
    // add random slight shake tom simulate practical situation
//    Vec shake= {Utils::getRandomFloat(-0.0015, 0.0015), Utils::getRandomFloat(-0.0015, 0.0015)};
//    direction = direction + shake;
    setAnchor(this->getAnchor() + direction);
    circle1.move(direction);
    circle2.move(direction);
    quadrilateral.move(direction);
    rectangle.move(direction);
    pipe.move(direction);
}

void Car::draw() {
    trajectory.addTrajectory(pipe.getAnchor());
    trajectory.draw();
    circle1.draw();
    circle2.draw();
    quadrilateral.draw();
    rectangle.draw();
    pipe.draw();
}

void Car::rotate(float angle) {
    circle1.rotate(angle, anchor);
    circle2.rotate(angle, anchor);
    rectangle.rotate(angle, anchor);
    quadrilateral.rotate(angle, anchor);
    pipe.rotate(angle, anchor);
}

void Car::moveTo(Vec vec) {
    Group::moveTo(vec);
    move(vec - this->anchor);
}

Trajectory *Car::getTrajectory() {
    return &trajectory;
}

void Car::drawTrajectory(int mode, float theta, int size) {
    this->trajectory.addHistory(this->pipe.getAnchor());
    if (mode == CommonValue::FORWARD_MODE) {
        this->trajectory.addTrajectory(this->pipe.getAnchor());
    } else if (mode == CommonValue::BACK_MODE) {
        this->trajectory.setTrajectoryLine(this->pipe.getAnchor(), theta, size);
    }
    trajectory.draw();
}
