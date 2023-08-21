#include "figure/Triangle.h"

void Triangle::draw() {
#ifndef NO_GUI
    ColoredFigure::draw();
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i <= 2; i++) {
        glVertex2f(this->pts[i].getX(), this->pts[i].getY());
    }
    glEnd();
#endif
}

void Triangle::move(Vec dir) {
    ColoredFigure::move(dir);
    for (int i = 0; i <= 2; ++i) {
        pts[i] = pts[i] + dir;
    }
}

void Triangle::rotate(float angle) {
    anchor << angle;
    for (int i = 0; i <= 2; ++i) {
        pts[i] << angle;
    }
}

void Triangle::rotate(float angle, Vec anchor) {
    move({-anchor.getX(), -anchor.getY()});
    rotate(angle);
    move(anchor);
}

void Triangle::zoom(float scale, Vec center) {
    Vec dis = {(center.getX() - anchor.getX()) * (1 - scale), (center.getY() - anchor.getY()) * (1 - scale)};
    Vec _anchor = anchor;
    move({-anchor.getX(), -anchor.getY()});
    for (int i = 0; i < (int)pts.size(); ++i) {
        pts[i] * scale;
    }
    move(_anchor);
    move(dis);
}

Triangle::~Triangle() {}


Triangle::Triangle(std::vector<Vec> pts, Vec anchor) {
    this->pts = pts;
    this->anchor = anchor;
}

Triangle::Triangle(std::vector<Vec> pts, Vec anchor, std::vector<float> color) {
    this->pts = pts;
    this->anchor = anchor;
    this->color = color;
}

std::vector<Vec> Triangle::getPts() {
    return pts;
}

Triangle::Triangle() {

}




