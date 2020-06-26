#include <iostream>
#include <string>
//stack and heap both memory in RAM. stack usually fixed around 2MB
//stack and heap give us memory differently


struct Vector3
{
	float x, y, z;
	Vector3()
		: x(10), y(11), z(12)
	{}
};
int main()
{
	int value = 5; //allocate memory on the stack is 1 cpu instruction. eficient! 
	int value2 = 6;
	int* hvalue = new int;
	*hvalue = 6; 

	int array[5]; //stack pointer moves down (lower number in memory to allocate size for 5 int's)
	int* harray = new int[5]; //new usually calls malloc, but 
	for (int i = 0; i < 5; i++)
	{
		array[i] = i + 1;
		harray[i] = i + 1;
	}

	delete hvalue;
	std::cin.get();
}