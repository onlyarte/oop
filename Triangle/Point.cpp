#include "Point.h"

int Point::freeID = 0;

Point::Point(double x, double y) :
	_x(x),
	_y(y),
	pointID(++freeID)
{
	return;
};

Point::Point(const Point& u) :
	_x(u._x),
	_y(u._y),
	pointID(++freeID)
{
	return;
};

Point::~Point()
{
	return;
};

ostream& operator<<(ostream& os, const Point& p)
{
	os << '#' << p.getID() << '(' << p.x() << ';' << p.y() << ')';
	return os;
}

Point& Point::operator=(const Point& u)
{
	_x = u.x();
	_y = u.y();
	return *this;
}

const Point operator+(const Point& u, const Point& v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& operator+=(Point& u, const Point& v)
{
	u = u + v;
	return u;
}

bool operator==(const Point& a, const Point& b)
{
	return a.x() == b.x() && a.y() == b.y();
}

bool operator!=(const Point& a, const Point& b)
{
	return !(a == b);
}
