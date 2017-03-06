#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#include "Date.h"
#include "Time.h"

using namespace std;

/*IMPORTANT! VISUAL STUDIO 2011 OR LATER NEEDED*/

class Timer

{

private:

	Date _start_d;
	Time _start_t;
	int _delay;
	string _message;

public:

	Timer(Date start_d, Time start_t, unsigned int delay, string message);

	void launch();

	Date& startDate() { return _start_d; };
	Time& startTime() { return _start_t; };
	int& delay() { return _delay; };
	string& message() { return _message; };

	const Date& startDate() const { return _start_d; };
	const Time& startTime() const { return _start_t; };
	const int& delay() const { return _delay; };
	const string& message() const { return _message; };

};
