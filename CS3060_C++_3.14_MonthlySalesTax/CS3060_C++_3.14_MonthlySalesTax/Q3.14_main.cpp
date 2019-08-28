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

	string month, year;

	cout << "Please enter the month: ";
	cin >> month;

	cout << "Please enter the year: ";
	cin >> year;
	
	double total_cost;

	const double STATE_TAX = 0.04;
	const double COUNTY_TAX = 0.02;

	
	cout << "\n\nPlease enter the total cost: ";
	cin >> total_cost;
	
	double revenue = total_cost / (1 + STATE_TAX + COUNTY_TAX);

	cout << "\n\nMonth: " << month << "Year: " << year << endl
		<< "-------------------" << endl
		<< setprecision(2) << fixed
		<< "Total Collected:\t$" << total_cost << endl
		<< "Sales:\t\t\t$" << revenue << endl
		<< "Count Sales Tax:\t$" << COUNTY_TAX * revenue << endl
		<< "State Sales Tax:\t$" << STATE_TAX * revenue << endl
		<< "Total Sales Tax:\t$" << (COUNTY_TAX + STATE_TAX) * revenue << endl;


	return 0;

}
