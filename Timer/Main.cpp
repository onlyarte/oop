#include "Timer.h"

using namespace std;

int main() {
	Date dt(5, 3, 2017);
	Time tm(0, 53, 19);
	Timer tmr(dt, tm, 20, "You should not sleep tonight");
	tmr.launch();
	return 0;
}