

#ifndef P3_UFO_H
#define P3_UFO_H

#include "group/Group.h"
#include "figure/SemiCircle.h"
#include "figure/Line.h"
#include "figure/Quadrilateral.h"

class UFO : public Group {
private:
    SemiCircle semiCircle;
    Line line1, line2;
    Quadrilateral footer1, footer2;
    Trajectory trajectory;
public:
    UFO();
    virtual void draw() override;
    virtual void move(Vec vec) override;
    virtual void moveTo(Vec vec) override;
    virtual void zoom(float scale,Vec center) override;
    virtual void rotate(float angle) override;
    virtual void drawTrajectory(int mode,float theta,int size) override;
    virtual  Trajectory *getTrajectory() override;
};

#endif //P3_UFO_H
