/*
William Archbold
CS 3060 Obj Oriented Programming C++
07 Sep 2019
*/

/*
Q6.18 Write a modular program that will ask for the  
number of rooms, square feet of wall space, price of paint/gallon. 
Display all the costs. 
*/

//Pseudocode 
//1. Get number of rooms
//2. Get square feet of wall space
//3. Get price of paint/gallon. 
//4. Compute data and display to user


#include <iostream>
#include <iomanip>

using namespace std;

//prototypes
void RunPaintEstimate();
int getRooms();
double getPaintPrice();
double getSquareFootage();
void DisplayInput(const int&, const double&, const double&);
double CalculateFootage(const int&, const double&);
double CalculateGallons(const double&);
double CalculateHours(const double&);
double CalculateLaborCost(const double&);
void DisplayResults(const double&, const double&, const double&, const double&, const double&);


int main(int argc, char* argv[]) {

	RunPaintEstimate();

	return 0;
}

void RunPaintEstimate()
{
	int room_count = getRooms();

	double paint_price = getPaintPrice();

	double square_footage = getSquareFootage();

	DisplayInput(room_count, paint_price, square_footage);

	double required_footage = CalculateFootage(room_count, square_footage);

	double required_gallons = CalculateGallons(required_footage);

	double required_hours = CalculateHours(required_footage);

	double required_labor_cost = CalculateLaborCost(required_hours);

	DisplayResults(required_footage, required_gallons, required_hours, required_labor_cost, paint_price);
}

int getRooms()
{
	int rooms;
	do {
		cout << "\nPlease enter number of rooms you need painted greater than or equal to 1: ";
		cin >> rooms;
	} while (rooms < 1);

	return rooms;
}

double getPaintPrice()
{
	double price;
	do {
		cout << "\nPlease enter price of paint in dollars and cents greater than or equal to $10.00: ";
		cin >> price;
	} while (price < 10.0);

	return price;
}

double getSquareFootage()
{
	double footage;
	do {
		cout << "\nPlease enter a positive value for each room's square footage: ";
		cin >> footage;
	} while (footage <= 0.0);

	return footage;
}

void DisplayInput(const int & rooms, const double & price, const double & footage)
{	
	cout << "\nYou entered:\nRooms - " << rooms
		<< setprecision(2) << fixed
		<< "\nPrice - $" << price
		<< "\nFootage - " << footage;
}


double CalculateFootage(const int & rooms, const double & footage)
{
	return rooms * footage;
}

double CalculateGallons(const double & footage)
{
	return footage / 110.0;
}

double CalculateHours(const double & footage)
{
	return 8.0*(footage / 110.0);
}

double CalculateLaborCost(const double & hours)
{
	return hours * 25.0;
}

void DisplayResults(const double& footage, const double& gallons, const double& hours, const double& labor_cost, const double& paint_price)
{
	cout << setprecision(2) << fixed
		<< "\n\nThe total square footage is: "
		<< footage
		<< "\n\nEstimate of work:"
		<< "\nGallons: " << gallons
		<< "\nHours: " << hours
		<< "\nLabor Cost: $" << labor_cost
		<< "\nPaint Cost: $" << paint_price * gallons
		<< "\nTotal Cost: $" << labor_cost + (paint_price * gallons);
}

