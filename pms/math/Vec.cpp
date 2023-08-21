#include "math/Vec.h"
#include <cmath>

float Vec::getX() const {
    return x;
}

float Vec::getY() const {
    return y;
}

void Vec::setX(float x) {
    this->x = x;
}

void Vec::setY(float y) {
    this->y = y;
}

Vec Vec::operator+(Vec vec) {
    return {this->x + vec.getX(), this->y + vec.getY()};
}

Vec Vec::operator-(Vec vec) {
    return {this->x - vec.getX(), this->y - vec.getY()};
}

int Vec::operator*(Vec vec) {
    return this->x * vec.x + this->y * vec.y;
}

void Vec::operator*(float scale) {
    this->x *= scale;
    this->y *= scale;
}

// rotate by anti-clockwise
void Vec::operator<<(float angle) {
    float rotation_mat[2][2] = {{static_cast<float>(cos(angle)), static_cast<float>(-sin(angle))},
                                {static_cast<float>(sin(angle)), static_cast<float>(cos(angle))}};

    Vec ret = {rotation_mat[0][0] * this->x + rotation_mat[0][1] * this->y,
               rotation_mat[1][0] * this->x + rotation_mat[1][1] * this->y};
    this->x = ret.x;
    this->y = ret.y;
}

// rotate by clockwise
void Vec::operator>>(float angle) {
    (*this) << (-angle);
}

void Vec::rotateAround(float angle, Vec center) {
    this->setX(this->getX()-center.getX());
    this->setY(this->getY()-center.getY());

    (*this)<<angle;

    this->setX(this->getX()+center.getX());
    this->setY(this->getY()+center.getY());
}
