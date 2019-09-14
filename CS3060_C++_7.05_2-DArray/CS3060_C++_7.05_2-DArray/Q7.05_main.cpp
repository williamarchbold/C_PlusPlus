/*
William Archbold
CS 3060 Obj Oriented Programming C++
14 Sep 2019
*/

/*
Q7.05 Write a program that uses a two dimensional array to store monkey names and how much food they eat
each day of the work week. Display average amount of food eaten per day by the family of monkeys, least 
and highest amount of food eaten by any one monkey. Do not accept negative pounds of food eaten. 
*/

/* Pseudocode
1. Create 3x5 list of monkeys and days
2. Get the user to input monkey names and how much they ate each day
3. Calculate highest and lowest amount of food
4. Display all results back to user
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_MONKEYS = 3;
const int NUM_DAYS = 5;

void getFood(int food_matrix[NUM_MONKEYS][NUM_DAYS]);
void displayFood(const int food_matrix[NUM_MONKEYS][NUM_DAYS]);
void displayAverage(const int food_matrix[NUM_MONKEYS][NUM_DAYS]);
void fatMonkey(const int food_matrix[NUM_MONKEYS][NUM_DAYS]);
void skinnyMonkey(const int food_matrix[NUM_MONKEYS][NUM_DAYS]);



int main(int argc, char* argv[])
{
	int food_matrix[NUM_MONKEYS][NUM_DAYS]; 

	getFood(food_matrix);

	displayFood(food_matrix);

	return 0;
}

void getFood(int food_matrix[NUM_MONKEYS][NUM_DAYS])
{
	int food = 0;

	for (int monkey = 0; monkey < NUM_MONKEYS; monkey++)
	{
		for (int day = 0; day < NUM_DAYS; day++)
		{
			cout << "\nPlease input number of pounds eaten by monkey " << monkey + 1
				<< " on day " << day + 1 << " of 5: ";
			cin >> food;
			while (food < 0)
			{
				cout << "\nInvalid amount. Please input number of pounds eaten by monkey " << monkey + 1
					<< " on day " << day + 1 << " of 5: ";
				cin >> food;
			}
			food_matrix[monkey][day] = food;
		}
	}
}

void displayFood(const int food_matrix[NUM_MONKEYS][NUM_DAYS])
{
	displayAverage(food_matrix);

	fatMonkey(food_matrix);

	skinnyMonkey(food_matrix);

}

void displayAverage(const int food_matrix[NUM_MONKEYS][NUM_DAYS])
{
	for (int current_day = 0; current_day < NUM_DAYS; current_day++)
	{
		int total = 0;
		int current_monkey;
		for (current_monkey = 0; current_monkey < NUM_MONKEYS; current_monkey++)
		{
			total += food_matrix[current_monkey][current_day];
		}
		cout << setprecision(2) << fixed
			<<"\nAverage amount of food eaten for day " << current_day + 1 << ": "
			<< static_cast<double>(total) / NUM_MONKEYS;
	}
}

void fatMonkey(const int food_matrix[NUM_MONKEYS][NUM_DAYS])
{
	int fatest_monkey = 0;
	int most_food = 0;
	for (int current_monkey = 0; current_monkey < NUM_MONKEYS; current_monkey++)
	{
		int total = 0;
		int day;
		for (day = 0; day < NUM_DAYS; day++)
		{
			total += food_matrix[current_monkey][day];
		}
		if (total > most_food)
		{
			fatest_monkey = current_monkey;
			most_food = total;
		}
	}

	cout << "\nMonkey " << fatest_monkey + 1 
		<< " ate " << most_food 
		<< " pounds which was the largest amount of food during the week";
}

void skinnyMonkey(const int food_matrix[NUM_MONKEYS][NUM_DAYS])
{
	int thinnest_monkey = 0;
	int least_food;
	for (int current_monkey = 0; current_monkey < NUM_MONKEYS; current_monkey++)
	{
		int total = 0;
		int day;
		for (day = 0; day < NUM_DAYS; day++)
		{
			total += food_matrix[current_monkey][day];
		}
		if (current_monkey == 0)
		{
			least_food = total;
		}
		else if (total < least_food)
		{
			thinnest_monkey = current_monkey;
			least_food = total;
		}
	}

	cout << "\nMonkey " << thinnest_monkey + 1
		<< " ate " << least_food
		<< " pounds which was the smallest amount of food during the week";
}
