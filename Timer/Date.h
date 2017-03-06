#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Date

{

public:

	struct BadDate;
	// to avoid problem 7.2.2002 7 feb or jul 2?

	enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

	Date(int d = 0, Month m = Month(0), int y = 0);
	Date(int d, int m, int y);
	Date(const Date&);
	~Date();

	int day() const { return _day; };
	Month month() const { return Month(_month); };
	int year() const { return _year; };

	const std::string getMonthName() const { return monthNames[_month - 1]; };
	void setDay(int d) { fillDate(d, Month(_month), _year); };
	void setMonth(int m) { fillDate(_day, Month(m), _year); };
	void setYear(int y) { fillDate(_day, Month(_month), y); };

	static void setDefault(int, Month, int);
	static void setDefault();
	static void showDefault();

	const Date& operator++();
	const Date  operator++(int);
	const Date& operator--();
	const Date  operator--(int);

private:

	int _day, _month, _year;

	bool leapYear(int y) { return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0); };

	void fillDate(int d, Month m, int y);

	static string monthNames[12];

	int daysAMonth(const int &m, const int &y);

	static bool defaultSet;
	static Date defaultDate;

};

ostream& operator<<(ostream& os, const Date & d);

struct Date::BadDate
{
	int _day, _month, _year;
	BadDate(int d, int m, int y) :_day(d), _month(m), _year(y) {};
};

ostream& operator<<(ostream& os, const Date::BadDate & bd);