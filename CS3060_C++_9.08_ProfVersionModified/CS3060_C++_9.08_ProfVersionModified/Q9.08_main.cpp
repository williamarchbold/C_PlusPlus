/*
William Archbold
CS 3060 Obj Oriented Programming C++
29 Sep 2019
*/

/*
!!This is a modification of the professor provided solution.!!

Q9.08 Write a function that accepts as arguments an array of integers and an integer that indicates the
number of elements in the array. The function should return the mode of the array. If the function
doesn't have a mode, then return -1.
*/

#include <iostream>

using namespace std;

//Function prototypes
int getMode(int*, int);
int* makeArray(int);

int main()
{
	//Constant for the array size
	const int SIZE = 11;

	//An array of test values
	int test[SIZE] = { 1,2,3,3,3,2,2,1,3,4,5 };

	//A variable to hold  the mode of the test values
	int mode;

	//Get the mode of the test values
	mode = getMode(test, SIZE);

	//Display the mode, if any.
	if (mode==-1)
	{
		cout << "The test set has no mode.\n";
	}
	else
	{
		cout << "\nThe mode of the test set is: "
			<< mode << endl;
	}

	return 0;
}