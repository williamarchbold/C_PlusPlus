#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee
{
private:
	string name;
	int number;
	string hire_date;

public:
	Employee(string n, int num, string hireDate)
	{ name = n; number = num; hire_date = hireDate; }

	void setName(string input)
	{ name = input; }

	string getName() 
	{ return name; }

	void setNumber(int num)
	{ number = num; }

	int getNumber()
	{ return number; }

	void setHireDate(string date)
	{ hire_date = date; }

	string getHireDate()
	{ return hire_date; }

};


//Employee::Employee(string n, int num, string hireDate)



#endif // !EMPLOYEE_H

