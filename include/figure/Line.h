#ifndef P3_LINE_H
#define P3_LINE_H

#include "ColoredFigure.h"
#include <GL/glut.h>

class Line: public ColoredFigure{
private:
    std::vector<Vec> pts;
public:
    Line();

    Line(std::vector<Vec> pts, Vec anchor, std::vector<float> color);

    void draw();

    void move(Vec dir);

    void rotate(float angle);

    void rotate(float angle,Vec center);

    void zoom(float scale,Vec vec);
};

#endif //P3_LINE_H
