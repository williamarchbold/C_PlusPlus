/*
William Archbold
CS 3060 Obj Oriented Programming C++
05 Nov 2019
*/

/*
14.13 Write a proram that includes a RoomCarpet class that has a RoomDimension object 
which itself has two FeetInches objects. Prompt the user to enter the dimensions of the 
room and the price of carpet per square foot. Give the user the total price. 
*/


#include <iostream>
#include <iomanip>

#include "RoomCarpet.h"

using namespace std;

int main()
{
	double cost = 0.0;
	RoomCarpet room_carpet;
	FeetInches length;
	FeetInches width;
	cout << "Please enter the cost per square foot: $";
	cin >> cost;
	while (cost != -1)
	{
		room_carpet.SetCostPerSqFoot(cost);
		cout << "Please enter room length(feet [space] inches)";
		cin >> length;
		cout << "Please enter room width(feet [space] inches)";
		cin >> width;
		room_carpet.SetRoomSize(length, width);
		cout << "Price of carpet is $" << setprecision(2) << fixed << room_carpet.getCarpetCost() << endl;
		cout << "Please enter the cost per square foot (-1 to exit): $";
		cin >> cost;


	}
}