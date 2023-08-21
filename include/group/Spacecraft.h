

#ifndef P3_SPACECRAFT_H
#define P3_SPACECRAFT_H

#include "group/Group.h"

#include "figure/Figure.h"
#include "figure/Quadrilateral.h"
#include "figure/Rectangle.h"
#include "figure/Quadrilateral.h"
#include "figure/Triangle.h"


class Spacecraft : public Group {
private:
    class Rectangle mainBody;
    class Rectangle door;
    class Rectangle leftWindow;
    class Rectangle rightWindow;
    Quadrilateral base;
    Triangle leftWing;
    Triangle rightWing;
    Triangle header;
    Trajectory trajectory;

    float scale;
public:
    Spacecraft();

    virtual void draw() override;

    virtual void move(Vec dir) override;

    virtual void rotate(float angle) override;

    virtual void zoom(float scale,Vec center) override;

    virtual void moveTo(Vec vec) override;

    virtual void drawTrajectory(int mode,float theta,int size) override;

    virtual Trajectory *getTrajectory() override;

};

#endif //P3_SPACECRAFT_H
