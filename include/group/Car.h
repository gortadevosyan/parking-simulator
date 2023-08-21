

#ifndef P3_CAR_H
#define P3_CAR_H

#include "group/Group.h"
#include "figure/Circle.h"
#include "figure/Rectangle.h"
#include "figure/Quadrilateral.h"

class Car : public Group {
private:
    Circle circle1;
    Circle circle2;
    class Rectangle rectangle;
    Quadrilateral quadrilateral;
    class Rectangle pipe;
    Trajectory trajectory;
public:
    Car();

    virtual void draw() override;

    virtual void move(Vec direction) override;

    virtual void rotate(float angle) override;

    virtual void moveTo(Vec vec) override;

    virtual void drawTrajectory(int mode,float theta,int size) override;

    virtual  Trajectory *getTrajectory() override;
};

#endif //P3_CAR_H
