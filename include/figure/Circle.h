//
// Created by sjtu on 22-12-1.
//

#ifndef P3_CIRCLE_H
#define P3_CIRCLE_H
#include "figure/ColoredFigure.h"

class Circle: public ColoredFigure{
private:
    float radius;
public:
    Circle();
    Circle(Vec anchor,float radius);
    Circle(Vec anchor,float radius,std::vector<float> color);
    Circle(float radius);

    void draw() override;

    void move(Vec dir) override;

    void rotate(float angle) override;

    void rotate(float angle, Vec center);

    void zoom(float scale,Vec center) override;
};

#endif //P3_CIRCLE_H
