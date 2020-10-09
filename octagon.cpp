#include "octagon.h"


Octagon::Octagon() : 
    A{ Point{} }, B{ Point{} }, C{ Point{} }, D{ Point{} },
	E{ Point{} }, F{ Point{} }, G{ Point{} }, H{ Point{} } {}

Octagon::Octagon(Point a, Point b, Point c, Point d,
    Point e, Point f, Point g, Point h) :
    A{ a }, B{ b }, C{ c }, D{ d },
    E{ e }, F{ f }, G{ g }, H{ h } {

    Vector AB{ A, B }, BC{ B, C }, CD{ C, D }, DE{ D, E }, EF{ E, F }, FG{ F, G }, GH{ G, H }, HA{ H, A };
}

Point Octagon::Center() const {
    return { (A + B + C + D + E + F + G + H) / 8};
}

double Octagon::Area() const {
    return 4.828 * Length(A, B) * Length(A, B);
}

std::ostream& Octagon::Print(std::ostream& out) const {
    out << "Octagon: A " << A << ", B " << B << ", C " << C << ", D " << D << ", E " << E << ", F " << F << ", G " << G << ", H " << H << std::endl;
    return out;
}

std::istream& Octagon::Scan(std::istream& in) {
    in >> A >> B >> C >> D >> E >> F >> G >> H;
    (*this) = Octagon(A, B, C, D, E, F, G, H);
    return in;
}

