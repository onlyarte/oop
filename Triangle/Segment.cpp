#include "Segment.h"

unsigned int Segment::freeID = 0;

Segment::Segment(const Point & start, const Point & end) :
	_a(start),
	_b(end),
	segmentID(++freeID)
{
	return;
}

Segment::~Segment()
{
	return;
}

double Segment::length() const
{
	return (double)sqrt((end().x() - start().x()) * (end().x() - start().x()) +
		(end().y() - start().y()) * (end().y() - start().y()));
}

double Segment::distance(const Point &u) const
{
	double A = u.x() - start().x(),
		B = u.y() - start().y(),
		C = end().x() - start().x(),
		D = end().y() - start().y();

	double dot = A * C + B * D;
	double len_sq = C * C + D * D;
	double param = -1;
	if (len_sq != 0) //in case of 0 length line
		param = dot / len_sq;

	double xx, yy;

	if (param < 0) {
		xx = start().x();
		yy = start().y();
	}
	else if (param > 1) {
		xx = end().x();
		yy = end().y();
	}
	else {
		xx = start().x() + param * C;
		yy = start().y() + param * D;
	}

	double dx = u.x() - xx,
		dy = u.y() - yy;
	return sqrt(dx * dx + dy * dy);
}

ostream & operator<<(ostream & os, const Segment & t)
{
	os << "[" << t.start() << "," << t.end() << "]" << endl;
	return os;
}
