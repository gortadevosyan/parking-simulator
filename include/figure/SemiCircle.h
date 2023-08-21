#ifndef P3_SEMICIRCLE_H
#define P3_SEMICIRCLE_H

#include "ColoredFigure.h"
#include <cmath>
#include <GL/glut.h>

class SemiCircle : public ColoredFigure {
private:
    float startAngle;
    float radius;
public:
    SemiCircle();

    SemiCircle(Vec anchor, std::vector<float> color, float radius, float startAngle);

    void draw() override;

    void move(Vec dir) override;

    void rotate(float angle) override;

    void rotate(float angle, Vec center);

    void zoom(float scale,Vec center) override;

};

#endif //P3_SEMICIRCLE_H
