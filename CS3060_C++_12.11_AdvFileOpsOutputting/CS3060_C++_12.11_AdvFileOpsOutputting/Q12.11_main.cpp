/*
William Archbold
CS 3060 Obj Oriented Programming C++
9 Oct 2019
*/

/*
Q12.11 Write a program that uses a structure to store the following data on a company division:
1. Division Name(East, West, North, South)
2. Quarter (1,2,3,4)
3. Quarterly Sales
User should be asked for the four quarters' sales figures for each division. The data should be
written to a file. 
*/


#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 12;

bool isNegative(double value);

struct Division
{
	char division_name[SIZE];
	int quarter;
	double sales;
};

int main()
{
	fstream file("corp.dat", ios::out | ios::binary);
	Division east, west, north, south;
	int qtr;

	strcpy_s(east.division_name, "East");
	strcpy_s(west.division_name, "West");
	strcpy_s(north.division_name, "North");
	strcpy_s(south.division_name, "South");

	cout << "\nEnter quarterly sales for" << east.division_name << " division.\n ";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		east.quarter = qtr;
		do
		{
			cout << "\tQuarter" << qtr << ":";
			cin >> east.sales;
		} while (isNegative(east.sales));
		
		file.write(reinterpret_cast<char*>(&east), sizeof(east)); //always typecast 1st argument to char* for binary file. 
	}

	cout << "\nEnter quarterly sales for" << west.division_name << " division.\n ";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		west.quarter = qtr;
		do
		{
			cout << "\tQuarter" << qtr << ":";
			cin >> west.sales;
		} while (isNegative(east.sales));
		
		file.write(reinterpret_cast<char*>(&west), sizeof(west));
	}

	cout << "\nEnter quarterly sales for" << north.division_name << " division.\n ";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		north.quarter = qtr;
		do
		{
			cout << "\tQuarter" << qtr << ":";
			cin >> north.sales;
		} while (isNegative(east.sales));
		
		file.write(reinterpret_cast<char*>(&north), sizeof(north));
	}

	cout << "\nEnter quarterly sales for" << south.division_name << " division.\n ";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		south.quarter = qtr;
		do
		{
			cout << "\tQuarter" << qtr << ":";
			cin >> south.sales;
		} while (isNegative(east.sales));
		
		file.write(reinterpret_cast<char*>(&south), sizeof(south));
	}

	file.close();
	return 0;


}

bool isNegative(double value)
{
	if (value <= 0)
	{
		cout << "\nCannot be negative.\n";
		return true;
	}
	else
	{
		return false;
	}
}