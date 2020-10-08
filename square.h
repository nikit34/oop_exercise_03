#pragma once

#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"


class Square : public Figure {
public:
	Square();
	Square(Point a, Point b, Point c, Point d);

	Point Center() const override;
	double Area() const override;

	std::ostream& Print(std::ostream& out) const override;
	std::istream& Scan(std::istream& in) override;

private:
	Point A, B, C, D;
};

#endif