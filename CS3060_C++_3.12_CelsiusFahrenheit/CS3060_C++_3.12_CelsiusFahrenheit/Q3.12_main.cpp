/*
William Archbold
CS 3060 Obj Oriented Programming C++
26 Aug 2019
*/

/*
Q3.12 Write a program that converts Celsius to Fahrenheit where F = 9/5C * 32
*/

//Pseudocode 
//1. Prompt the user to enter a celsius value
//2. Convert the value to fahrenheit
//3. Display value to user

#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char *argv[]) {

	double celsius; 

	cout << "Please enter a value for celsius: ";
	cin >> celsius;

	double fahrenheit = (9.0/5) * celsius + 32; 



	cout << setprecision(2) << fixed 
		<< "\n\n You entered " << celsius 
		<< " degrees celsius, which is " << fahrenheit 
		<< " degrees fahrenheit.\n"; 

	return 0;	
}