#ifndef P3_FIGURE_H
#define P3_FIGURE_H
#include "math/Vec.h"

class Figure{
protected:
    Vec anchor;
public:
    Figure(): anchor(0,0) {}

    Vec getAnchor();
    void setAnchor(Vec anchor);
    virtual void draw()=0;
    virtual void move(Vec dir)=0;
    virtual void rotate(float angle)=0;
    virtual void zoom(float scale,Vec center)=0;

    virtual ~Figure(){};
};

#endif //P3_FIGURE_H
