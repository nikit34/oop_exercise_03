#include "triangle.h"


Triangle::Triangle() : A{ Point() }, B{ Point() }, C{ Point() } {}

Triangle::Triangle(Point a, Point b, Point c) : A{ a }, B{ b }, C{ c } {
	double AB = Length(A, B);
	double BC = Length(B, C);
	double AC = Length(A, C);
	if (AB >= BC + AC || BC >= AB + AC || AC >= AB + BC) {
		throw std::logic_error("Points must not be on the same line.");
	}
}

Point Triangle::Center() const {
	Point middle { (A + C) / 2.0 };
	return { (B + middle * 2) / 3 };
}

double Triangle::Area() const {
	double AB = Length(A, B);
	double BC = Length(B, C);
	double AC = Length(A, C);
	double accumulate = AB + BC + AC;
	double heron = sqrt((accumulate / 2) * (accumulate / 2 - AB) * (accumulate / 2 - BC) * (accumulate / 2 - AC));
	return heron;
}

std::ostream& Triangle::Print(std::ostream& out) const {
	out << "Triangle: A " << A << ", B " << B << ", C " << C;
	return out;
}

std::istream& Triangle::Scan(std::istream& in) {
	in >> A >> B >> C;
	(*this) = Triangle(A, B, C);
	return in;
}
