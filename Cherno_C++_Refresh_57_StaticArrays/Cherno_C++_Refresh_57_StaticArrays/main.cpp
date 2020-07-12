#include <iostream>
#include <array>

void PrintArray(int* array, unsigned int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << std::endl;
	}
}


int main()
{
	std::array<int, 5> data; //memory works the same as regular array not like a vector which goes on heap

	data[0] = 2;
	int dataOld[5];
	dataOld[0] = 0;
	
	data.begin(); 

	std::cin.get();
}