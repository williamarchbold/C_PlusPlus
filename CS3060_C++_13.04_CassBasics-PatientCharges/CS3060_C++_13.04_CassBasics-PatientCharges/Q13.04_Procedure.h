/*
William Archbold
CS 3060 Obj Oriented Programming C++
11 Oct 2019
*/

/*
Q13.04 Write a class named Procedure that has member variables for the following data:
Name of the procedure
Date of the procedure
Name of the practiioner who performed the procedure
Charges for the procedure
*/

#pragma once
#pragma once
#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <string>

using namespace std;

class Procedure 
{
private:
	string name;
	string date;
	string practioner;
	double charges; 

public:
	//Constructor
	Procedure(string na, string da, string prac, double cost) 
	{ name = na; date = da; practioner = prac; charges = cost; }

	//Accessor functions
	string getName()
	{ return name; }

	string getDate()
	{ return date; }

	string getPractitioner()
	{ return practioner; }

	double getCharges()
	{ return charges; }

	//Mutator functions
	void setName(string na)
	{ name = na; }

	void setDate(string da)
	{ date = da; }

	void setPractioner(string prac)
	{ practioner = prac; }

	void setCharges(double charge)
	{ charges = charge; }
};

#endif