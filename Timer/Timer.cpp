#include "Timer.h"

Timer::Timer(Date start_d, Time start_t, unsigned int delay, string message) :
	_start_d(start_d),
	_start_t(start_t),
	_delay(delay),
	_message(message)
{
	return;
}

void Timer::launch()
{
	//get current time
	time_t raw;
	time(&raw);
	struct tm t1, t2;
	localtime_s(&t1, &raw);

	//convert start time to tm
	t2.tm_year = startDate().year() - 1900;
	t2.tm_mon = startDate().month() - 1;
	t2.tm_mday = startDate().day();
	t2.tm_hour = startTime().hours();
	t2.tm_min = startTime().minutes();
	t2.tm_sec = startTime().seconds();

	//convert both times to time_t
	time_t tt1, tt2;
	tt1 = mktime(&t1);
	tt2 = mktime(&t2);

	//find difference
	time_t diff = tt2 - tt1;
	if (diff < 0) {
		cout << "Wrong timer info." << endl;
		return;
	}
	//wait till start time
	std::this_thread::sleep_for(std::chrono::seconds(diff));
	cout << "Timer started..." << endl;
	//wait for delay time
	std::this_thread::sleep_for(std::chrono::seconds(delay()));
	cout << message() << endl;
}
