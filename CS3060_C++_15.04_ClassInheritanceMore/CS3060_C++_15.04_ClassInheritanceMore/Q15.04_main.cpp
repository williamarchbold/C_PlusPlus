/*
William Archbold
CS 3060 Obj Oriented Programming C++
12 Oct 2019
*/

/* Q15.04 Use the Time class provided within the book as the base class for a MilTime
class that should include milHours, milSeconds, constructor, setTime(), getHour(), getStandHr()
*/
#include <iostream>
#include "MilTime.h"

using namespace std;

int main()
{
	MilTime military_clock;
	int military_hours, military_seconds;
	do
	{
		cout << "\nPlease enter military hours (negative hrs to exit program): ";
		cin >> military_hours;
		cout << "\nPlease enter military seconds: ";
		cin >> military_seconds;
		if(military_clock.setTime(military_hours, military_seconds) == true)
			cout << "\nHours:" << military_clock.getStandHr() << ", Mins:" << military_clock.getMin() << ", Secs:" << military_clock.getSec() << endl;
	} while (military_hours >= 0);
}