
#include "figure/Quadrilateral.h"
#include <GL/freeglut.h>


void Quadrilateral::draw() {
#ifndef NO_GUI
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; ++i) {
        glVertex2f(pts[i].getX(), pts[i].getY());
    }
    glEnd();
#endif
}

void Quadrilateral::move(Vec dir) {
    ColoredFigure::move(dir);
    for (int i = 0; i < 4; ++i) {
        pts[i] = pts[i] + dir;
    }
}

void Quadrilateral::rotate(float angle) {
    ColoredFigure::rotate(angle);
}

void Quadrilateral::zoom(float scale, Vec center) {
    Vec dis = {(center.getX() - anchor.getX()) * (1-scale), (center.getY() - anchor.getY()) * (1-scale)};
    Vec _anchor = anchor;
    move({-anchor.getX(), -anchor.getY()});
    for (int i = 0; i < (int)pts.size(); ++i) {
        pts[i] * scale;
    }
    move(_anchor);
    move(dis);
}

Quadrilateral::~Quadrilateral() {

}


std::vector<Vec> Quadrilateral::getPts() {
    return this->pts;
}

Quadrilateral::Quadrilateral(std::vector<Vec> pts, Vec anchor) {
    this->pts = pts;
    this->anchor = anchor;
}

Quadrilateral::Quadrilateral(std::vector<Vec> pts, Vec anchor, std::vector<float> color) {
    this->pts = pts;
    this->anchor = anchor;
    this->color = color;
}

Quadrilateral::Quadrilateral(Vec anchor) : ColoredFigure(anchor) {

}

Quadrilateral::Quadrilateral() {

}

void Quadrilateral::rotate(float angle, Vec center) {
    ColoredFigure::rotate(angle, center);
    anchor.rotateAround(angle, center);
    for (int i = 0; i < 4; ++i) {
        pts[i].rotateAround(angle, center);
    }
}


