#include "Date.h"

string Date::monthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
bool Date::defaultSet = false;
Date Date::defaultDate;

Date::Date(int d, Month m, int y)
{
	fillDate(d, m, y);
}

Date::Date(int d, int m, int y)
{
	fillDate(d, Month(m), y);
}

Date::Date(const Date &another) :
	_day(another._day),
	_month(another._month),
	_year(another._year)
{
	return;
}

Date::~Date()
{
	return;
}

void Date::setDefault(int d, Month m, int y)
{
	defaultSet = true; defaultDate = Date(d, m, y);
}

void Date::setDefault()
{
	defaultSet = true;
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	defaultDate._day = timeinfo.tm_mday;
	defaultDate._month = ++(timeinfo.tm_mon);
	defaultDate._year = timeinfo.tm_year += 1900;
}

void Date::showDefault()
{
	cout << defaultDate;
}

const Date & Date::operator++()
{
	if (++_day > daysAMonth(_month, _year)) {
		_day = 1;
		_month == 12 ? _month = 1, _year++ : _month++;
	}
	return *this;
}

const Date Date::operator++(int)
{
	const Date res(*this);
	++(*this);
	return res;
}

const Date & Date::operator--()
{
	if (--_day == 0) {
		_month == 1 ? _month = 12, _year-- : _month--;
		_day = daysAMonth(_month, _year);
	}
	return *this;
}

const Date Date::operator--(int)
{
	const Date res(*this);
	--(*this);
	return res;
}


void Date::fillDate(int d, Month m, int y)
{
	if (!defaultSet) setDefault();
	_day = d ? d : defaultDate._day;
	_month = m ? m : defaultDate._month;
	_year = y ? y : defaultDate._year;
	int numberOfDays = daysAMonth(_month, _year);
	if (_day < 1 || numberOfDays < _day || _year < 0)
		throw BadDate(_day, _month, _year);
}

int Date::daysAMonth(const int &m, const int &y)
{
	switch (m) {
	case 2: return 28 + leapYear(y);
	case 4: case 6: case 9: case 11: return 30;
	case 1: case 3: case 5: case 7: case 8:
	case 10: case 12: return 31;
	default: return 0;
	}
}

ostream & operator<<(ostream & os, const Date & d)
{
	os << d.day() << " " << d.getMonthName() << " " << d.year() << endl;
	return os;
}

ostream & operator<<(ostream & os, const Date::BadDate & bd)
{
	os << bd._day << " " << bd._month << " " << bd._year << endl;
	return os;
}
