#include "figure/Line.h"

#include <utility>

Line::Line() {
    anchor = {0, 0};
    color = {0.5, 0.5, 0.5};
    pts.resize(2);
    pts = {{1, 1},
           {0, 0}};
}

Line::Line(std::vector<Vec> pts, Vec anchor, std::vector<float> color) :
        ColoredFigure(anchor, std::move(color)), pts(std::move(pts)) {}

void Line::draw() {
#ifndef NO_GUI
    glColor3f(color[0], color[1], color[2]);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(pts[0].getX(), pts[0].getY());
    glVertex2f(pts[1].getX(), pts[1].getY());
    glEnd();
#endif
}

void Line::move(Vec dir) {
    ColoredFigure::move(dir);
    for (int i = 0; i < 2; ++i) {
        pts[i] = pts[i] + dir;
    }
}

void Line::rotate(float angle) {
    anchor << angle;
    for (int i = 0; i < 2; ++i) {
        pts[i] << angle;
    }
}

void Line::rotate(float angle, Vec center) {
    move({-center.getX(), -center.getY()});
    rotate(angle);
    move(center);
}

void Line::zoom(float scale,Vec vec) {
    ColoredFigure::zoom(scale,vec);
}
