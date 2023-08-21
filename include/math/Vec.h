

#ifndef P3_VEC_H
#define P3_VEC_H

#include <ostream>

class Vec {
private:
    float x, y;
public:
    Vec() : x(0), y(0) {}

    Vec(float _x, float _y) : x(_x), y(_y) {}

    virtual ~Vec() {}

    float getX() const;

    float getY() const;

    void setX(float x);

    void setY(float y);

    Vec operator+(Vec vec);

    Vec operator-(Vec vec);

    int operator*(Vec vec);

    void operator*(float scale);

    // rotate by anti-clockwise
    void operator<<(float angle);

    // rotate by clockwise
    void operator>>(float angle);

    void rotateAround(float angle, Vec center);
};

#endif //P3_VEC_H
