/*
William Archbold
CS 3060 Obj Oriented Programming C++
10 Oct 2019
*/

/*
Demonstrate the Car class in a program that creates a Car object, call accelerate 
5 times. after each call get the current speed and display it. then call brake 
five times. display the speed after each call. 
*/

#include <iostream>
#include <string>
#include "Q13.03_Car.h"

using namespace std;

int main()
{
	Car* newcar = new Car(1995, "Ferrari");


	for (int i = 0; i < 5; i++)
	{
		newcar->Accelerate();
		cout << "The " << newcar->getMake() << " accelerated. Speed is now " << newcar->getSpeed() <<".\n\n";
	}

	for (int i = 0; i < 5; i++)
	{
		newcar->Brake();
		cout << "The " << newcar->getMake() << " braked. Speed is now " << newcar->getSpeed() << ".\n\n";
	}



	delete newcar;
	newcar = nullptr;
	return 0;
}