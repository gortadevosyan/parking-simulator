#include "figure/Trajectory.h"

Trajectory::Trajectory(int size, std::vector<float> color) {
    this->size = size;
    this->color = color;
}

Trajectory::Trajectory() {
    this->size = CommonValue::TRAJECTORY_POINTS_NUM;
    this->color = {1, 0, 0};
}

void Trajectory::addTrajectory(Vec vec) {
    if ((int)trajectory.size() == size) {
        trajectory.push_front(vec);
        trajectory.pop_back();
    } else {
        trajectory.push_front(vec);
    }
}

void Trajectory::setTrajectoryLine(Vec startPoint, float theta, int size) {
    trajectory.clear(); // clear history trajectory

    this->size = size;
    float k = -1, dx = 0, dy = 0;
    if (abs(theta - M_PI_2) >= 1e-5) k = tan(theta);

    for (int i = 0; i < size; ++i) {
        float dis = CommonValue::DELTA_DIS;
        if (abs(theta - M_PI_2) >= 1e-5) {
            dx = dis / (sqrt(pow(k, 2) + 1)) * i;
            dy = dis * k / (sqrt(pow(k, 2) + 1)) * i;
        } else {
            dx = 0;
            dy = dis * i;
        }
        trajectory.emplace_back(dx + startPoint.getX(), dy + startPoint.getY());
    }
}

void Trajectory::addHistory(Vec vec) {
    history.push_back(vec);
}

void Trajectory::draw() {
    int cnt = trajectory.size();
#ifndef NO_GUI
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glLineWidth(3);
    for (int i = 0; i < cnt - 1; ++i) {
        float scale = ((float) cnt - (float) i) / (float) cnt;
        glColor4f(color[0], color[1], color[2], scale * 1);
        glBegin(GL_LINES);
        glVertex2f(trajectory[i].getX(), trajectory[i].getY());
        glVertex2f(trajectory[i + 1].getX(), trajectory[i + 1].getY());
        glEnd();
    }
    glDisable(GL_BLEND);
#endif
}

void Trajectory::plotHistory(int direction) {
#ifndef NO_GUI
    glLineWidth(3);
    glColor3f(0.2, 0.8, 0.8);
    glBegin(GL_LINES);
    // plot history
    for (int i = 0; i < (int)history.size() - 1; ++i) {
        glVertex2f(history[i].getX(), history[i].getY());
        glVertex2f(history[i + 1].getX(), history[i + 1].getY());
    }
    glEnd();
    // plot arrow
    Vec lastPoint = history[history.size() - 1];
    glBegin(GL_LINES);
    glVertex2f(lastPoint.getX() - 0.02, lastPoint.getY() + (direction == CommonValue::DOWN ? 0.02 : -0.02));
    glVertex2f(lastPoint.getX(), lastPoint.getY());
    glVertex2f(lastPoint.getX(), lastPoint.getY());
    glVertex2f(lastPoint.getX() + 0.02, lastPoint.getY() + (direction == CommonValue::DOWN ? 0.02 : -0.02));
    glEnd();
#endif
}

bool Trajectory::ifParked() {
    if (history.size() <= 5) return false;
    else {
        Vec p1 = history[history.size()-1];
        Vec p2 = history[history.size()-5];
        if (abs(p1.getX() - p2.getX()) < 1e-6 && abs(p1.getY() - p2.getY()) < 1e-6) {
            return true;
        } else return false;
    }
}







