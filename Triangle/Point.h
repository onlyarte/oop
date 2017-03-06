#pragma once
#include <iostream>

using namespace std;

class Point

{

private:

	static int freeID;

	const int pointID;

	double _x;

	double _y;

public:

	Point(double x = 0, double y = 0);

	Point(const Point &);

	~Point();

	Point& operator=(const Point &);

	double& x() { return _x; };

	double& y() { return _y; };

	const double& x()const { return _x; };

	const double& y()const { return _y; };

	const int getID() const { return pointID; };

	//return amount of points created
	static int amount() { return freeID; };

};

ostream& operator<<(ostream&, const Point&);

const Point operator+ (const Point &u, const Point & v);

Point& operator+=(Point &, const Point&);

bool operator==(const Point & u, const Point &v);

bool operator!=(const Point & u, const Point &v);
