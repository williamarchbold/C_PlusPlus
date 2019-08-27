/*
William Archbold
CS 3060 Obj Oriented Programming C++
26 Aug 2019
*/

/*
Q3.14 Write a program that asks for the month, year, and total amount 
collected at the cashier regisister (i.e. sales plus sales tax). Assume sales
tax is 4%. County sales tax is 2%. Total tax is 6%
*/

//Pseudocode 
//1. Prompt the user to enter the month then the total amount
//2. Calculate revenue from the total and the count and sales tax
//3. Display value to user


#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 

int main(int argc, char* argv[]) {

	string month; 

	cout << "Please enter the month: ";
	cin >> month;
	
	double total_cost;

	
	cout << "\n\nPlease enter the total cost: ";
	cin >> total_cost;
	
	double revenue = total_cost / 1.06;

	double state_tax = revenue * .04;
	double county_tax = revenue * .02;

	cout << "\n\nMonth: " << month << endl
		<< "-------------------" << endl
		<< setprecision(2) << fixed
		<< "Total Collected:\t$" << total_cost << endl
		<< "Sales:\t\t\t$" << revenue << endl
		<< "Count Sales Tax:\t$" << county_tax << endl
		<< "State Sales Tax:\t$" << state_tax << endl
		<< "Total Sales Tax:\t$" << county_tax + state_tax << endl;


	return 0;

}
