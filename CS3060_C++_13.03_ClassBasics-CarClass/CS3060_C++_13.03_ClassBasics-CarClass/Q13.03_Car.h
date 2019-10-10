
/*
William Archbold
CS 3060 Obj Oriented Programming C++
10 Oct 2019
*/

/*
Q13.03 Write a class named Car that has the following member variables:
yearModel - int that holds the car's year model
make - a string that holds the make of the car
speed - an int that holds the car's current speed

a contructor that accpets year and make as arguments and assigns 0 to speed
member variable

accessors to get the values stored in member variables

accelerate add 5 to the speed each time it's called

brake subtracts 5 from the speed each time it's called
*/

#pragma once

#ifndef CAR_H
#define CAR_H
#include <string>

using namespace std;

class Car
{
private:
	int yearModel;
	string make;
	int speed;

public:
	//constructors 
	Car()
	{
		yearModel = 1900;
		make = "unkown";
		speed = 0;

	}

	Car(int year, string brand)
	{
		yearModel = year;
		make = brand;
		speed = 0;
	}

	//accessors 
	int getYearModel() const
		{ return yearModel; }

	string getMake() const
		{ return make; }

	int getSpeed() const
		{ return speed; }

	//mutators
	void Accelerate()
		{ speed += 5;}

	void Brake()
		{ speed -= 5;}
};
#endif
