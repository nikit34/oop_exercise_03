#include "square.h"


Square::Square() : A{ Point{} }, B{ Point{} }, C{ Point{} }, D{ Point{} } {}

Square::Square(Point a, Point b, Point c, Point d) : 
	A{ a }, B{ b }, C{ c }, D{ d } {

	Vector AB{ A, B }, BC{ B, C }, CD{ C, D }, DA{ D, A };

	if (!isParallel(DA, BC)) {
		std::swap(A, B);
		AB = { A, B };
		BC = { B, C };
		DA = { D, A };
	}
	if (!isParallel(AB, CD)) {
		std::swap(B, C);
		AB = { A, B };
		BC = { B, C };
		DA = { D, A };
	}
	if (AB * BC || BC * CD || CD * DA || DA * AB) {
		throw std::logic_error("The sides of the square should be perpendicular");
	}
	if (Length(AB) != Length(BC) || Length(BC) != Length(CD) || Length(CD) != Length(DA) || Length(DA) != Length(AB)) {
		throw std::logic_error("The sides of the square should be equal");
	}
	if (!Length(AB) || !Length(BC) || !Length(CD) || !Length(DA)) {
		throw std::logic_error("The sides of the square must be greater than zero");
	}
}

Point Square::Center() const {
	return Point{ (B + D) / 2 };
}

double Square::Area() const {
	return Length(A, B) * Length(A, B);
}

std::ostream& Square::Print(std::ostream& out) const {
	out << "Square: A " << A << ", B " << B << ", C " << C << ", D " << D << std::endl;
	return out;
}

std::istream& Square::Scan(std::istream& in) {
	in >> A >> B >> C >> D;
	(*this) = Square(A, B, C, D);
	return in;
}
