#ifndef P3_TRIANGLE_H
#define P3_TRIANGLE_H

#include "figure/Figure.h"
#include "figure/ColoredFigure.h"
#include "math/Vec.h"
#include "GL/freeglut.h"


class Triangle: public  ColoredFigure{
private:
    std::vector<Vec> pts;
public:
    Triangle();

    Triangle(std::vector<Vec> pts,Vec anchor);

    Triangle(std::vector<Vec> pts,Vec anchor,std::vector<float> color);

    ~Triangle() override;

    void draw() override;

    void move(Vec dir) override;

    void rotate(float angle) override;

    void rotate(float angle,Vec anchor);

    void zoom(float scale,Vec  center) override;

    std::vector<Vec> getPts();
};


#endif //P3_TRIANGLE_H
