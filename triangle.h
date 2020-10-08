#pragma once

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
public:
	Triangle();
	Triangle(Point a, Point b, Point c);

	Point Center() const override;
	double Area() const override;

	std::ostream& Print(std::ostream& out) const override;
	std::istream& Scan(std::istream& in) override;

private:
	Point A, B, C;
};

#endif