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
	int test[SIZE] = { 1,2,3,3,3,2,2,1,3,4,5};

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


//Function getMode
// This function returns the mode of the array pointed to by array.
// If there is no mode, the function returns -1. 
int	getMode(int* array, int size)
{
	//variables

	//A pointer to reference a dynamically allocated array
	// to hold the frequencies of each value. 
	int* frequencies = nullptr;

	int mode = -1;//The mode, initilized to -1

	int highest = 0; //The value with highest frequency

	int element = 0; //To hold an element subscript

	int count = 0;

	/* Dynamically allocate an array to hold the frequencies of each 
		element in the array. When this function ends, frequencies[0]
		will hold the frequency of the value. 
	*/
	frequencies = makeArray(size);

	//Find the frequency of each element in array
	for (int count1 = 0; count1 < size; count1++)
	{
		cout << "\n\nNow finding frequency of the value at index " << count1 << " which is " << array[count1] << "...\n";
		//The inner loop compare the array elements at *(array + count1)
		//with every element in the array. When it finds a matching element,
		//it increments the element's frequency. 
		for (int count2 = 0; count2 < size; count2++)
			
		{
			cout << "At array index" << count2 << ", the value is " << array[count2] << endl;
			if (*(array + count2) == *(array + count1))
			{
				(*(frequencies + count1))++;
				cout << "Because " << array[count1] << " equals " << array[count2] << ", frequency at index " << count1 << "is incremented by 1 to " << *(frequencies + count1) << endl;
			}
		}
	}
	//Find the element with the highest frequency. 
	//Start by assuming the first element has the highest frequency
	highest = *frequencies;
	element = 0;
	cout << "\n\nInitilize highest frequency to first value in frequency array which is" << *frequencies << endl;
	//Step through the frequencies array and find the highest value
	for (count = 1; count < size; count++) {
		cout << "Comparing highest, which is " << highest << " to " << *(frequencies+count) <<"..." << endl;
		if (*(frequencies + count) > highest)
		{
			cout <<  *(frequencies + count) << "is higher than " << highest << "so changing highest..\n";
			highest = *(frequencies + count);
			element = count;

		}
	}
	
	frequencies = nullptr;

	// If there is no mode (no element has a frequency > 1), then return
	// -1. Otherwise return the element with the greatest frequency. 
	if (highest > 1) {
		mode = *(array + element);

	}
	cout << "\n\nNothing else to compare. The highest mode is " << mode;
	return mode;
}

//*************************
// Function makeArray
// This function dynamically allocates an array of ints
// and returns a pointer to it. The size parameter is the number
// of elements to allocate. 
//*************************
int * makeArray(int size)
{
	int* ptr = new int[size];
	return ptr;
}

