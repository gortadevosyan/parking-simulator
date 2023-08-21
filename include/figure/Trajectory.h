#ifndef P3_TRAJECTORY_H
#define P3_TRAJECTORY_H

#include <iostream>
#include <queue>
#include <cmath>
#include "math/Vec.h"
#include "figure/ColoredFigure.h"
#include "utils/CommonValue.h"
#include <GL/glut.h>

class Trajectory : public ColoredFigure {
private:
    std::deque<Vec> trajectory;
    std::vector<Vec> history;
    int size;
public:
    Trajectory();

    Trajectory(int size, std::vector<float> color);

    void addTrajectory(Vec vec);

    void setTrajectoryLine(Vec startPoint, float theta, int size);

    void addHistory(Vec vec);

    bool ifParked();

    void draw();

    void plotHistory(int direction);
};

#endif //P3_TRAJECTORY_H
