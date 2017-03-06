#pragma once
#include "Point.h"

class Segment

{

private:

	static unsigned int freeID;

	unsigned int segmentID;

	const Point& _a;

	const Point& _b;

	Segment& operator=(const Segment&);

public:

	Segment(const Point& start, const Point& end);

	~Segment();

	const Point& start() const { return _a; };

	const Point& end() const { return _b; };

	double length() const;

	double distance(const Point&) const;

};

ostream& operator<<(ostream &, const Segment &);