#pragma once

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include <string>
#include "Employee.h"

using namespace std;

class ProductionWorker : public Employee
{
private:
	int shift; //integer with 1 for day 2 for night
	double hourly_pay_rate;

public:

	void setShift(int num)
	{ shift = num; }

	int getShift()
	{ return shift; }

	void setHourlyRate(double num)
	{ hourly_pay_rate = num; }

	double setHourlyRate()
	{ return hourly_pay_rate; }

	ProductionWorker(string first, string last, char g, int num, string hire_date, int time, double rate) : Employee(first, last, g, num, hire_date)
	{
		if (time==1 || time ==2)
		{
			shift = time;
		}
		else
		{
			shift = 1;
		}
		hourly_pay_rate = rate;
	}

	void DisplayInfo()
	{
		Employee::DisplayInfo();
		cout << "Shift: " << shift << endl;
		cout << "Pay Rate: " << hourly_pay_rate << endl;
	}
};


#endif // !PRODUCTIONWORKER_H

