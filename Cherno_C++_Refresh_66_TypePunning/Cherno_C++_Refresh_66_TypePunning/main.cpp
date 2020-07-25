//C++ strongly typed language but can access memory and get around types 

//C++ does raw memory very well

#include <iostream>

struct Entity //empty structs have at least 1 byte for addressing, but this struct has two ints for two variables
{
	int x, y;

	int* GetPositions()
	{
		return &x;
	}
};

int main()
{
	int a = 50; //32 00 00 00 in hex memory
	double value = a; //00 00 00 00 00 00 49 40 implicited conversion

	double value2 = *(double*)&a; //32 00 00 00 cc cc cc //read from memory that's not ours so not good
	double& value3 = *(double*)a;

	Entity e = { 5, 8 };


	int* position = (int*)&e; 

	std::cout << position[0] << ", " << position[1] << std::endl; //converted Entity e into an array sort of

	int y = *(int*)((char*)&e + 4);

	std::cout << y << std::endl;

	std::cin.get();
}