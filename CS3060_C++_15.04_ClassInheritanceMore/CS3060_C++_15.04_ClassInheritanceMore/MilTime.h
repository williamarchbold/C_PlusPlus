#pragma once

#ifndef MILTIME_H
#define MILTIME_H

#include <iostream>
#include "Time.h"

using namespace std;

class MilTime : public Time
{
private:
	int milHours = 0;
	int milSeconds = 0;
public:
	MilTime() {}
	MilTime(int mHours, int mSeconds);

	virtual int getHour() const override
	{ return milHours; }

	int getStandHr()
	{ return hour; }

	bool setTime(int mHours, int mSeconds);
};
#endif // !MILTIME_H

MilTime::MilTime(int mHours, int mSeconds)  
{	
	setTime(mHours, mSeconds);
}

bool MilTime::setTime(int mHours, int mSeconds)
{
	//1230 - 12:30
	// 1330 - 1:30
	// 0 - 0
	// 1000 - 1:00
	if (mHours < 0 || mHours >= 2400)
	{
		cout << "Invalid military hours!\n";
		return false;
	}
	if (mSeconds < 0 || mSeconds > 59)
	{
		cout << "Invalid military seconds! ";
		return false;
	}
	milHours = mHours;
	milSeconds = mSeconds;

	if (mHours <= 1259)
	{
		hour = mHours / 100;
	}
	else
	{
		hour = mHours / 100 - 12;
	}

	min = mHours % 100;
	sec = mSeconds;
	return true;
}


