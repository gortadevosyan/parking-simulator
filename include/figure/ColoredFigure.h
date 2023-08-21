

#ifndef P3_COLOREDFIGURE_H
#define P3_COLOREDFIGURE_H
#include "figure/Figure.h"
#include <vector>

class ColoredFigure: public Figure{
protected:
    std::vector<float> color;
    std::vector<Vec> pts;
public:
    const std::vector<float> &getColor() const;

    void setColor(const std::vector<float> &color);

    ColoredFigure(){};

    ColoredFigure(Vec anchor);

    ColoredFigure(Vec anchor,std::vector<float> color);

    ~ColoredFigure();

    void draw() override;

    void move(Vec dir) override;

    void rotate(float angle) override;

    void rotate(float angle,Vec center);

    void zoom(float scale,Vec center) override;
};

#endif //P3_COLOREDFIGURE_H
