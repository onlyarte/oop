#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Time

{

private:

	int _hours;
	int _minutes;
	int _seconds;
	void normalizeTime();

public:

	static const double hourToDec;

	Time(int s = 0, int m = 0, int h = 0);
	Time(const Time&);
	~Time() {};

	Time& operator=(const Time&);
	operator int() const;
	operator double() const;

	int hours() const { return _hours; }
	int minutes() const { return _minutes; }
	int seconds() const { return _seconds; }

	int& hours() { return _hours; }
	int& minutes() { return _minutes; }
	int& seconds() { return _seconds; }

	const Time& operator++();
	const Time operator++(int);
	const Time& operator--();
	const Time operator--(int);

};

double operator+ (const Time&, const Time&);

ostream& operator<<(ostream&, const Time &);