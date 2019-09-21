/*
William Archbold
CS 3060 Obj Oriented Programming C++
21 Sep 2019
*/

/*
Q9.09 Write a function that accepts as arguments an array of integers and an integer that indicates the
number of elements in the array. The function should return the median of the array as a double. The array
should be sorted before it enters the function. 
*/


#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void fillArray(int random_numbers[]);
void sortArray(int random_numbers[]);
void swap(int &a, int &b);
double findMedian(int* array_start, int size);

const int NUM_ELEMENTS = 100;
const int NUM_CANDIDATES = 25;

int main(int argc, char* argv[])
{
	int num_array[NUM_ELEMENTS];

	fillArray(num_array);

	sortArray(num_array);

	double median = findMedian(num_array, NUM_ELEMENTS);

	cout << "\n\nThe median is " << setprecision(2) << median << " !\n\n";

	return 0;
}

void fillArray(int random_numbers[])
{
	srand(time(0));

	cout << "Filling an array of size 100 with random integers 1 - " << NUM_CANDIDATES << " repeatable...\n";

	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		random_numbers[i] = (rand() % NUM_CANDIDATES) + 1;
	}

	cout << "\nHere is the unsorted array...\n";
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		cout << random_numbers[i] << " ";
	}
}

void sortArray(int random_numbers[])
{
	int max_element,
		index;
	for (max_element = NUM_ELEMENTS - 1; max_element > 0; max_element--)
	{
		for (int i = 0; i < max_element; i++)
		{
			if (random_numbers[i] > random_numbers[i+1])
			{
				swap(random_numbers[i], random_numbers[i + 1]);
			}
		}
	}
	cout << "\n\nHere is the sorted array...\n";
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		cout << random_numbers[i] << " ";
	}
}

void swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

double findMedian(int * array_start, int size)
{
	cout << "\nFinding the median...\n";
	double median;
	if (size % 2 == 0)
	{
		int* median_ptr = array_start + (size / 2);
		median = *median_ptr + *(median_ptr+1);
		median /= 2;
	}
	else
	{
		int* median_ptr = array_start + (size / 2) + 1;
		median = *median_ptr;
	}

	return median;
}
