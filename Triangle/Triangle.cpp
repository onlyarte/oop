#include "Triangle.h"

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) :
	_a(x1, y1), _b(x2, y2), _c(x3, y3),
	_ab(0), _bc(0), _ca(0)
{
	return;
}

Triangle::Triangle(const Point & a, const Point & b, const Point & c) :
	_a(a), _b(b), _c(c),
	_ab(0), _bc(0), _ca(0)
{
	return;
}

Triangle::Triangle(const Triangle & t) :
	_a(t._a), _b(t._b), _c(t._c),
	_ab(0), _bc(0), _ca(0)
{
	return;
}

Triangle::~Triangle()
{
	delete _ab; delete _bc; delete _ca;
	_ab = _bc = _ca = 0;
	return;
}

Triangle & Triangle::operator=(const Triangle & t)
{
	_a = t._a; _b = t._b; _c = t._c;
	delete _ab; delete _bc; delete _ca;
	_ab = _bc = _ca = 0;
	return *this;
}

double Triangle::perimeter() const
{
	return side_a().length() + side_b().length() + side_c().length();
}

double Triangle::area() const
{
	return 0.5*side_a().length()*side_a().distance(_a);
}

const Segment & Triangle::side_a() const
{
	if (_bc == 0) _bc = new Segment(_b, _c);
	return *_bc;
}

const Segment & Triangle::side_b() const
{
	if (_ca == 0) _ca = new Segment(_c, _a);
	return *_ca;
}

const Segment & Triangle::side_c() const
{
	if (_ab == 0) _ab = new Segment(_a, _b);
	return *_ab;
}

ostream & operator<<(ostream & os, const Triangle & t)
{
	os << "Triangle: " << t.apexA() << t.apexB() << t.apexC() << endl;
	os << t.side_a() << t.side_b() << t.side_c() << endl;
	os << "perimeter " << t.perimeter() << endl;
	os << "area " << t.area() << endl;
	return os;
}