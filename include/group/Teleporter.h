

#ifndef P3_TELEPORTER_H
#define P3_TELEPORTER_H

#include "group/Group.h"
#include "figure/Rectangle.h"

class Teleporter : public Group {
private:
    class Rectangle rectangle;
    Trajectory trajectory;
public:
    Teleporter();

    virtual void draw() override;

    virtual void move(Vec direction) override;

    virtual void rotate(float angle) override;

    virtual void moveTo(Vec vec) override;

    virtual Trajectory *getTrajectory() override;
};

#endif //P3_TELEPORTER_H
