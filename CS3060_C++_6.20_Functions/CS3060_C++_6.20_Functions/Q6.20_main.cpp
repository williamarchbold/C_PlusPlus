/*
William Archbold
CS 3060 Obj Oriented Programming C++
07 Sep 2019
*/

/*
Q6.20 Write a function that accepts # of shares, purchase price/share, 
puchase commision paid, sale price/share, sale commision paid. 
Function should return the profit/loss of the sale of the stock. Then display
to user result
*/

//Pseudocode 
//1. Get input from user
//2. Calculate profit/loss
//3. Display to user

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double getReturn();
int getShares();
double getValue(string);
void DisplayInput(const int&, const double&, const double&, const double&, const double&);

int main(int argc, char* argv[])
{
	double sell_return = getReturn();

	cout << setprecision(2) << fixed 
		<< "\n\nReturn - $" << sell_return << endl;

	return 0;
}

double getReturn() 
{
	int shares = getShares();

	double purchase_price = getValue("purchase price per share");

	double purchase_commission = getValue("purchase commission");

	double sales_price = getValue("sales price per share");

	double sales_commission = getValue("sell commission");

	DisplayInput(shares, purchase_price, purchase_commission, sales_price, sales_commission);

	return ((shares * sales_price) - sales_commission) - ((shares * purchase_price) - purchase_commission);
}

double getValue(string argument)
{
	double value;

	do {
		cout << "\nPlease input " << argument << " as a positive number: $";
		cin >> value;
	} while (value < 0.0);
	return value;
}

void DisplayInput(const int & shares, const double & purchase_price, const double &purchase_commission, const double& sales_price, const double& sales_commission)
{
	cout << "\nYou entered:\nShares - " << shares
		<< setprecision(2) << fixed
		<< "\nPurchase Price - $" << purchase_price
		<< "\nPurchase Commission - $" << purchase_commission
		<< "\nSales Price - $" << sales_price
		<< "\nSales Commision - $" << sales_commission;
}

int getShares() 
{
	int value;

	do {
		cout << "\nPlease input positive number of shares: ";
		cin >> value;
	} while (value < 0);
	return value;
}
