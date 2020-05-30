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

struct Dispensary
{
	char division_name[SIZE];
	int quarter;
	double sales_quarter;
	double sales_year;
};

int main()
{
	fstream file("dispensaries.dat", ios::out | ios::binary);
	Dispensary Manitou, Denver, Boulder, Estes_Park;
	int qtr;

	strcpy_s(Manitou.division_name, "Manitou");
	strcpy_s(Denver.division_name, "Denver");
	strcpy_s(Boulder.division_name, "Boulder");
	strcpy_s(Estes_Park.division_name, "Estes Park");

	file.write(reinterpret_cast<char*>(&Manitou.division_name), sizeof(Manitou.division_name));
	cout << "\nEnter quarterly sales for" << Manitou.division_name << " division.\n ";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		Manitou.quarter = qtr;
		do
		{
			cout << "\tQuarter" << qtr << ":";
			cin >> Manitou.sales_quarter;
		} while (isNegative(Manitou.sales_quarter));

		Manitou.sales_year += Manitou.sales_quarter;
		
		file.write(reinterpret_cast<char*>(&Manitou.sales_quarter), sizeof(Manitou.sales_quarter)); //always typecast 1st argument to char* for binary file. 
	}
	file.write(reinterpret_cast<char*>(&Manitou.sales_year), sizeof(Manitou.sales_year));

	file.write(reinterpret_cast<char*>(&Denver.division_name), sizeof(Denver.division_name));
	cout << "\nEnter quarterly sales for" << Denver.division_name << " division.\n ";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		Denver.quarter = qtr;
		do
		{
			cout << "\tQuarter" << qtr << ":";
			cin >> Denver.sales_quarter;
		} while (isNegative(Denver.sales_quarter));
		
		Denver.sales_year += Denver.sales_quarter;

		file.write(reinterpret_cast<char*>(&Denver.sales_quarter), sizeof(Denver.sales_quarter));
	}
	file.write(reinterpret_cast<char*>(&Denver.sales_year), sizeof(Denver.sales_year));


	file.write(reinterpret_cast<char*>(&Boulder.division_name), sizeof(Boulder.division_name));
	cout << "\nEnter quarterly sales for" << Boulder.division_name << " division.\n ";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		Boulder.quarter = qtr;
		do
		{
			cout << "\tQuarter" << qtr << ":";
			cin >> Boulder.sales_quarter;
		} while (isNegative(Boulder.sales_quarter));

		Boulder.sales_year += Boulder.sales_quarter;
		
		file.write(reinterpret_cast<char*>(&Boulder.sales_quarter), sizeof(Boulder.sales_quarter));
	}
	file.write(reinterpret_cast<char*>(&Boulder.sales_year), sizeof(Boulder.sales_year));

	file.write(reinterpret_cast<char*>(&Estes_Park.division_name), sizeof(Estes_Park.division_name));
	cout << "\nEnter quarterly sales for" << Estes_Park.division_name << " division.\n ";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		Estes_Park.quarter = qtr;
		do
		{
			cout << "\tQuarter" << qtr << ":";
			cin >> Estes_Park.sales_quarter;
		} while (isNegative(Estes_Park.sales_quarter));
		
		Estes_Park.sales_year += Estes_Park.sales_quarter;

		file.write(reinterpret_cast<char*>(&Estes_Park.sales_quarter), sizeof(Estes_Park.sales_quarter));
	}
	file.write(reinterpret_cast<char*>(&Estes_Park.sales_year), sizeof(Estes_Park.sales_year));

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