#include "figure/SemiCircle.h"

SemiCircle::SemiCircle() {
    anchor = {0, 0};
    color = {0.5, 0.5, 0.5};
    startAngle = 0;
    radius = 0.1;
}

SemiCircle::SemiCircle(Vec anchor, std::vector<float> color, float radius, float startAngle) :
        ColoredFigure(anchor, color), startAngle(startAngle), radius(radius) {}

void SemiCircle::draw() {
#ifndef NO_GUI
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 200; ++i) {
        glVertex2f(radius * cos(M_PI / 200 * i + startAngle) + anchor.getX(),
                   radius * sin(M_PI / 200 * i + startAngle) + anchor.getY());
    }
    glEnd();
    glFlush();
#endif
}

void SemiCircle::move(Vec dir) {
    ColoredFigure::move(dir);
}

void SemiCircle::rotate(float angle) {
    anchor << angle;
    startAngle += angle;
}

void SemiCircle::rotate(float angle, Vec center) {
    move({-center.getX(), -center.getY()});
    rotate(angle);
    move(center);
}

void SemiCircle::zoom(float scale,Vec center) {
    ColoredFigure::zoom(scale,center);
}
