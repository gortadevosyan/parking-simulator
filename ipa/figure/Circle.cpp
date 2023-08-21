
#include "figure/Circle.h"
#include <GL/freeglut.h>
#include <cmath>
#include <utility>


Circle::Circle(float radius) {
    this->radius = radius;
}

void Circle::draw() {
#ifndef NO_GUI
    glColor3f(color[0], color[1], color[2]);

    glBegin(GL_POLYGON);
    for (float i = 0; i < 400; ++i) {
        glVertex2f(radius * cos(2 * M_PI / 400 * i) + anchor.getX(),
                   radius * sin(2 * M_PI / 400 * i) + anchor.getY());
    }
    glEnd();
#endif
}

void Circle::move(Vec dir) {
    ColoredFigure::move(dir);

}

void Circle::rotate(float angle) {
    ColoredFigure::rotate(angle);
}

void Circle::rotate(float angle, Vec center) {
    ColoredFigure::rotate(angle, center);
    anchor.rotateAround(angle, center);
}


void Circle::zoom(float scale, Vec center) {
    ColoredFigure::zoom(scale, center);
}

Circle::Circle(Vec anchor, float radius) {
    this->anchor = anchor;
    this->radius = radius;
}

Circle::Circle() {

}

Circle::Circle(Vec anchor, float radius, std::vector<float> color) {
    this->anchor = anchor;
    this->radius = radius;
    this->color = std::move(color);
}



