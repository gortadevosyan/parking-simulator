#include "figure/Rectangle.h"


void Rectangle::draw() {
    Quadrilateral::draw();
}

void Rectangle::move(Vec dir) {
    Quadrilateral::move(dir);
}

void Rectangle::rotate(float angle) {
    Quadrilateral::rotate(angle);
    anchor << angle;
}

void Rectangle::zoom(float scale, Vec center) {
    Quadrilateral::zoom(scale, center);
    height *= scale;
    width *= scale;
}

float Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(float height) {
    Rectangle::height = height;
}

float Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(float width) {
    Rectangle::width = width;
}

Rectangle::~Rectangle() {}

Rectangle::Rectangle(std::vector<Vec> pts, Vec anchor) : Quadrilateral(pts, anchor) {

}

Rectangle::Rectangle(float height, float width, Vec anchor, std::vector<float> color) : Quadrilateral(anchor) {
    this->height = height;
    this->width = width;
    this->color = color;

    float dx[4] = {-1, 1, 1, -1};
    float dy[4] = {-1, -1, 1, 1};

    for (int i = 0; i < 4; ++i) {
        Vec vec = {anchor.getX() + width / 2 * dx[i], anchor.getY() + height / 2 * dy[i]};
        this->pts.push_back(vec);
    }
}

Rectangle::Rectangle() {

}

void Rectangle::rotate(float angle, Vec center) {
    Quadrilateral::rotate(angle, center);
}




