#include "figure/ColoredFigure.h"


ColoredFigure::ColoredFigure(Vec anchor) {
    this->anchor = anchor;
}

ColoredFigure::ColoredFigure(Vec anchor, std::vector<float> color) {
    this->anchor = anchor;
    this->color = color;
}

ColoredFigure::~ColoredFigure() {

}

void ColoredFigure::rotate(float angle, Vec center) {
	color.push_back(angle);
	color.pop_back();
	anchor=anchor+center;
	anchor=anchor-center;
}

void ColoredFigure::draw() {

}

void ColoredFigure::move(Vec dir) {
    anchor = anchor + dir;
}

void ColoredFigure::rotate(float angle) {
    std::vector<Vec>::iterator it;
    for(it=pts.begin();it!=pts.end();++it)
    {
        Vec v{(*it)-getAnchor()};
        v>>angle;
        (*it)=v;
    }
}

void ColoredFigure::zoom(float scale,Vec center) {
	color.push_back(scale);
	color.pop_back();
	anchor=anchor+center;
	anchor=anchor-center;
}

const std::vector<float> &ColoredFigure::getColor() const {
    return color;
}

void ColoredFigure::setColor(const std::vector<float> &color) {
    ColoredFigure::color = color;
}

