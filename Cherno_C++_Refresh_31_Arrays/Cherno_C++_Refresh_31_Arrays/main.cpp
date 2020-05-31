#include <iostream>

class A {
public:
	int example[5];
	A() 
	{
		for (int i = 0; i < 5; i++) {
			example[i] = 2;
		}
	}
};


class B {
public:
	int* example = new int[5]; //jumping around memory like this is a performance hit
	B()
	{
		for (int i = 0; i < 5; i++) {
			example[i] = 2;
		}
	}
};

int main() {
	int example[5]; //integer pointer

	for (int i = 0; i < 5; i++) {
		example[i] = 2;
	}
	int* ptr = example;

	example[2] = 5;

	*(ptr + 2) = 6;  //equivalent of example[2] //ptr addition depends on pointer type
					//ptr + 2 is really ptr + 2*4
	*(int*)((char*)ptr + 8) = 7; //char* moves 1 byte at time. recast to int* when setting memory value to 7

	example[0] = 2;

	example[4] = 4; 

	//debug mode would catch an out of bounds access, but release mode probably won't. 

	int* another = new int[5]; //on the heap will be alive until program ends or destroyed
	for (int i = 0; i < 5; i++) {
		*(another + i) = 2;
	}
	delete[] another;

	std::cout <<  "Size of example" << sizeof(example) << std::endl;
	std::cout << "Size of example element" << sizeof(example) / sizeof(int) << std::endl;
	std::cout << example[0] << std::endl;
	std::cout << example << std::endl;

	A x;
	B y;

	unsigned int i = 1;
	char* c = (char*)&i;
	if (*c)
		std::cout << "Little endian";
	else
		std::cout << "Big endian";
	std::cin.get();
}