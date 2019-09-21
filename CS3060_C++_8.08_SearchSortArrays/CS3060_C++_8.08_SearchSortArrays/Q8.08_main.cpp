/*
William Archbold
CS 3060 Obj Oriented Programming C++
20 Sep 2019
*/

/*
Q8.08 Write a program that has an array of at least 20 integers. It should call a function
that uses linear search to locate one of the values. The function should keep track of the
number of comparisons until it finds the value. Another function should do the same thing
but use the binary search algorithm to find the same value and keep count of the number of 
comparisions. 
*/


#include <iostream>
#include <time.h>
using namespace std; 

void fillList(int random_numbers[]);
bool candidateFound(int list[], int candidate);
void linearSearch(int list[], int saught);
void binarySearch(int list[], int saught);

const int NUM_ELEMENTS = 100;

int main(int arc, char* argv[])
{
	int number_list[NUM_ELEMENTS];
	fillList(number_list);

	int saught_number;

	cout << "Pick a random number between 1 and 100 to find: ";
	cin >> saught_number;

	linearSearch(number_list, saught_number);

	binarySearch(number_list, saught_number);


	return 0;
}

/*
void fillArray(int random_numbers[])
{
	srand(time(0));
	
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		bool invalid_candidate = true;
		int candidate = 0;
		while (invalid_candidate)
		{
			candidate = rand() % 100;
			if (!candidateFound(random_numbers, candidate))
			{
				random_numbers[i] = candidate;
				invalid_candidate = false;
			}
			else
			{
				continue;
			}
		}
	}
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		random_numbers[i]++;
	}
}
*/

void fillList(int list[]) {
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		list[i] = i + 1;
	}
}

bool candidateFound(int list[], int candidate)
{
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		if (list[i] == candidate)
		{
			return true;
		}
	}

	return false;
}

void linearSearch(int list[], int saught)
{
	cout << "\nConducting linear search...\n";

	int tally = 1;

	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		if (list[i] == saught)
		{
			break;
		}
		else
		{
			tally++;
		}
	}

	cout << "Found! Took " << tally << " comparisons.\n";

}

void binarySearch(int list[], int saught)
{
	cout << "\nNow conducting binary search...\n";



	int first = 0,
		last = NUM_ELEMENTS - 1,
		middle,
		position = -1, 
		tally = 0;
	bool found = false;

	while (!found && first <= last)
	{
		tally++;
		middle = (first + last) / 2; 
		if (list[middle] == saught)
		{
			found = true;
			position = middle;
		}
		else if (saught < list[middle])
		{
			last = middle - 1; 
		}
		else
		{
			first = middle + 1; 
		}
	}

	cout << "Found! Took " << tally << " comparisons.\n";
}
