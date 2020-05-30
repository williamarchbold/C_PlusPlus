#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
	string first_name;
	string last_name;
	char gender; 
	int number;
	string hire_date;

public:
	Employee(string first, string last, char g, int num, string hireDate)
	{
		first_name = first; last_name = last; gender = g; number = num; hire_date = hireDate;
	}

	void setFirst(string input)
	{ first_name = input; }

	string getFirst() 
	{ return first_name; }

	void setLast(string input)
	{ last_name = input; }

	string getLast()
	{ return last_name; }

	void setNumber(int num)
	{ number = num; }

	int getNumber()
	{ return number; }

	void setHireDate(string date)
	{ hire_date = date; }

	string getHireDate()
	{ return hire_date; }

	void DisplayInfo()
	{
		cout << "\nFirst: " << first_name << endl;
		cout << "\nLast: " << last_name << endl;
		cout << "\nGender: " << gender << endl;
		cout << "Number: " << number << endl;
		cout << "Hire date: " << hire_date << endl;

	}

};


//Employee::Employee(string n, int num, string hireDate)



#endif // !EMPLOYEE_H

