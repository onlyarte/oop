#include "Time.h"

const double hourToDec = 1. / 3600.;

void Time::normalizeTime()
{
	_hours += ((_minutes + (_seconds / 60)) / 60);
	_minutes = (_minutes + (_seconds / 60)) % 60;
	_seconds %= 60;
}

Time::Time(int s, int m, int h) :
	_seconds(s),
	_minutes(m),
	_hours(h)
{
	normalizeTime();
	return;
}

Time::Time(const Time &t) :
	_seconds(t._seconds),
	_minutes(t._minutes),
	_hours(t._hours)
{
	return;
}

Time & Time::operator=(const Time &t)
{
	_hours = t._hours;
	_minutes = t._minutes;
	_seconds = t._seconds;
	return *this;
}

Time::operator int() const
{
	return _hours * 3600 + _minutes * 60 + _seconds;
}

Time::operator double() const
{
	return _hours * 60 + _minutes + _seconds / 60;
}

const Time & Time::operator++()
{
	seconds() = seconds() + 1;
	normalizeTime();
	return *this;
}

const Time Time::operator++(int)
{
	const Time res(*this);
	(*this)++;
	return res;
}

const Time & Time::operator--()
{
	seconds() = seconds() - 1;
	normalizeTime();
	return *this;
}

const Time Time::operator--(int)
{
	const Time res(*this);
	(*this)--;
	return res;
}

double operator+(const Time &u, const Time &v)
{
	return int(u)*hourToDec + int(v)*hourToDec;
}

ostream & operator<<(ostream &os, const Time &t)
{
	os << "(" << t.hours() << ":" << t.minutes()
		<< ":" << t.seconds() << ")";
	return os;
}
