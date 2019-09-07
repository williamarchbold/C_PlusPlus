/*
William Archbold
CS 3060 Obj Oriented Programming C++
07 Sep 2019
*/

/*
Q6.06 Write a function that accepts an object's mass and velocity and returns 
it's amount of kenetic energy. 
*/

//Pseudocode 
//1. Prompt the user to enter the mass of an object in kg's and velocity, m/s
//2. Store values in variables
//3. Call function that takes these variables as parameters 
//4. Function calculates kinetic energy
//5. Function returns energy to calling function 
//6. Display results to user


#include <iostream>
#include <iomanip>

using namespace std; 

double kineticEnergy(double&, double&);

int main(int argc, char * argv[]) {

	double mass; 

	do {
		cout << "\nPlease enter a non-negative number for object's mass in kg's: ";
		cin >> mass;
	} while (mass < 0); 

	double velocity;

	do {
		cout << "\nPlease enter a non-negative number for object's velocity in m/s: ";
		cin >> velocity;
	} while (velocity < 0);

	cout << "\nYou entered " << mass
		<< " for mass and " << velocity
		<< " for velocity.\n"
		<< setprecision(3) << fixed
		<< "Kinetic energy = " << kineticEnergy(mass, velocity) << " Joules\n"; 

	return 0;
}

double kineticEnergy(double& mass, double& velocity)
{
	return 0.5 * mass * pow(velocity, 2); 
}
