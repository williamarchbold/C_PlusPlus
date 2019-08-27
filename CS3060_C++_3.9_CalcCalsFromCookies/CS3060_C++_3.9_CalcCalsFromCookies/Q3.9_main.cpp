/*
William Archbold
CS 3060 Obj Oriented Programming C++
26 Aug 2019
*/

/*
Q3.9 Bag holds 30 cookies. 10 "servings per bag . 300 calories per serving. Ask user how many cookies he/she ate.
Report how many total calories were consumed. 
*/

//Pseudocode 
//1. Prompt user for how many cookies they ate. 
//2. Convert cookies to calories
//3. Display calories to user


#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	
	int cookies;

	const int BAG_CAPACITY = 30;

	const int SERVINGS_PER_BAG = 10;

	const int CALORIES_PER_SERVING = 300;

	cout << "How many cookies did you eat?\n Enter cookies: ";
	cin >> cookies;

	double consumed_bags = static_cast<double>(cookies) / BAG_CAPACITY;

	double total_servings = consumed_bags * SERVINGS_PER_BAG;

	double total_calories = total_servings * CALORIES_PER_SERVING;

	cout << "You consumed " << total_calories << " calories from " << cookies << " cookies or " << total_servings << " servings.\n";

	return 0;
}