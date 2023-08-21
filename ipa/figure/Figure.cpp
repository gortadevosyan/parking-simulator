#include "figure/Figure.h"


Vec Figure::getAnchor() {
    return this->anchor;
}

void Figure::setAnchor(Vec anchor) {
    this->anchor=anchor;
}