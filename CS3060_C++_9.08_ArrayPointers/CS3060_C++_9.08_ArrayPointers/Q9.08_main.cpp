/*
William Archbold
CS 3060 Obj Oriented Programming C++
15 Sep 2019
*/

/*
Q9.08 Write a function that accepts as arguments an array of integers and an integer that indicates the
number of elements in the array. The function should return the mode of the array. If the function
doesn't have a mode, then return -1. 
*/

#include <iostream>
#include <time.h>

using namespace std;

void fillArray(int random_numbers[]);
int findMode(int* array_start, int size);

const int NUM_ELEMENTS = 100;
const int NUM_CANDIDATES = 10;

int main(int argc, char*[])
{
	int num_array[NUM_ELEMENTS];

	
	fillArray(num_array);

	int result = findMode(num_array, NUM_ELEMENTS);

	if (result == -1)
	{
		cout << "\nTwo numbers appeared the highest an equal number of times therefore no mode!\n";
	}
	else
	{
		cout << "\n" << result << " appeared the most!\n";
	}

	return 0;
}

void fillArray(int random_numbers[])
{
	srand(time(0));

	cout << "Filling an array of size 100 with random integers 1 - 10 repeatable...\n";

	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		random_numbers[i] =( rand() % NUM_CANDIDATES) + 1;
	}
}

int findMode(int * array_start, int size)
{
	cout << "\nFinding the mode...\n";

	int mode,
		mode_tally = 0,
		other_mode,
		other_mode_tally = 0; 


	for (int i = 1; i <= NUM_CANDIDATES; i++)
	{
		int candidate = i,
			candidate_tally = 0;
		int* candidate_pointer;
		//iterate through array to add up number of times candidate is present
		for (candidate_pointer = array_start; candidate_pointer < array_start + size; candidate_pointer++)
		{
			if (*candidate_pointer == candidate)
			{
				candidate_tally++;
			}
		}
		if (candidate_tally > mode_tally)
		{
			mode = candidate;
			mode_tally = candidate_tally;
		}
		else if (candidate_tally == mode_tally)
		{
			other_mode = candidate;
			other_mode_tally = candidate_tally;
		}
	}

	if (mode_tally == other_mode_tally)
	{
		return -1;
	}
	else
	{
		return mode;
	}

	return 0;
}

