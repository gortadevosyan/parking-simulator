

#ifndef P3_QUADRILATERAL_H
#define P3_QUADRILATERAL_H
#include "figure/ColoredFigure.h"
#include <vector>

class Quadrilateral:public ColoredFigure{
protected:
    std::vector<Vec> pts;
public:
    Quadrilateral();
    Quadrilateral(std::vector<Vec> pts,Vec anchor);

    Quadrilateral(std::vector<Vec> pts,Vec anchor,std::vector<float> color);

    Quadrilateral(Vec anchor);

    ~Quadrilateral() override;

    void draw() override;

    void move(Vec dir) override;

    void rotate(float angle) override;

    void rotate(float angle,Vec center) ;

    void zoom(float scale,Vec center) override;

    std::vector<Vec> getPts();
};

#endif //P3_QUADRILATERAL_H
