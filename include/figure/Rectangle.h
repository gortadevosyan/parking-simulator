

#ifndef P3_RECTANGLE_H
#define P3_RECTANGLE_H

#include "figure/Quadrilateral.h"
#include <vector>

#include <GL/freeglut.h>


class Rectangle : public Quadrilateral {
private:
    float height;
    float width;
public:
    Rectangle();

    Rectangle(std::vector<Vec> pts, Vec anchor);

    Rectangle(float height, float width, Vec anchor, std::vector<float> color);

    void draw() override;

    void move(Vec dir) override;

    void rotate(float angle) override;

    void rotate(float angle, Vec center);

    void zoom(float scale,Vec center) override;

    float getHeight() const;

    void setHeight(float height);

    float getWidth() const;

    void setWidth(float width);

    ~Rectangle() override;
};

#endif //P3_RECTANGLE_H
