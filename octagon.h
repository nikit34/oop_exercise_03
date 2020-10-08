#pragma once

#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"


class Octagon : public Figure {
public:
    Octagon();
    Octagon(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h);

    Point Center() const override;
    double Area() const override;

    std::ostream& Print(std::ostream& out) const override;
    std::istream& Scan(std::istream& in) override;

private:
    Point A, B, C, D, E, F, G, H;
};

#endif