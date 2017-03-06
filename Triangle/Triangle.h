#pragma once
#include "Point.h"
#include "Segment.h"
#include <cmath>

class Triangle

{

public:

	Triangle(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0,
		const double x3 = 0, const double y3 = 1);

	Triangle(const Point &a, const Point& b, const Point& c);

	Triangle(const Triangle&);

	~Triangle();

	Triangle& operator= (const Triangle&);

	double perimeter() const;

	double area() const;

	const Point& apexA() const { return _a; };
	const Point& apexB() const { return _b; };
	const Point& apexC() const { return _c; };

	Point& apexA() { return _a; };
	Point& apexB() { return _b; };
	Point& apexC() { return _c; };

	const Segment& side_a() const;
	const Segment& side_b() const;
	const Segment& side_c() const;

	double length_a() const { return side_a().length(); };
	double length_b() const { return side_b().length(); };
	double length_c() const { return side_c().length(); };

private:

	Point _a, _b, _c;

	mutable Segment *_ab, *_bc, *_ca;

};

ostream& operator<<(ostream &, const Triangle &);