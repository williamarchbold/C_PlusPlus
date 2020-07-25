//2D Array is an array of arrays i.e. collection of arrays. 

#include <iostream>	

int main()
{
	int* array = new int[50]; //allocated 200 bytes of memory. can use it to fill whatever like floats

	std::cout << "array: " << sizeof(array) << std::endl;
	std::cout << "int*: " << sizeof(int*) << std::endl;


	int** a2d = new int* [50];//pointer to collection of int pointers . essentially allocated 200 bytes of memory for 50 pointers
	std::cout << "a2d: " << sizeof(a2d) << std::endl; //a2d is integer pointer

	for (int i = 0; i < 50; i++)
	{
		a2d[i] = new int[50]; //allocated 50 arrays at each location in the a2d array. a 3D array would require a nested for loop
	}

	int*** a3d = new int** [50];

	for (int i = 0; i < 50; i++)
	{
		a3d[i] = new int*[50]; //allocated 50 arrays at each location in the a2d array. a 3D array would require a nested for loop
		for (int j = 0; j < 50; j++)
		{
			a3d[i][j] = new int[50];
		}
	}

	a3d[0][0][0] = 0;
	a3d[0][0][1] = 0; //rightmost row is always the actual integer
	a3d[0][1][0] = 0; //second to right row is integer*

	//a2d[] delete this is a memory leak!

	for (int i = 0; i < 50; i++)
	{
		delete[] a2d[i]; //allocated 50 arrays at each location in the a2d array. a 3D array would require a nested for loop
	}

	int** b2d = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		b2d[i] = new int[5]; //issue here is that every row of 2nd dimension is located somewhere else in memory. has to go over a buffer. could result in
	}						//has to go over a buffer. could result in a cache miss. a lot slower than a single array 
							//alot more efficient to just store a singel array of 5 by 5


	int* array2 = new int[5 * 5];

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			array2[x + y * 5] = 2;
		}
	}

	std::cin.get();
}
