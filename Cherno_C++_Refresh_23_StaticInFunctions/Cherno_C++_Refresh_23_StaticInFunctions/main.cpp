#include <iostream>


enum Example
{
	A, B = 4, C //these are just integers at the end of the day defaulted to 0 value 32 bit 
};

enum ExampleTwo : unsigned char //enums default 32 bit, unsigned char shrinks down to 8 bit
{
	X, Y, Z
};

void FunctionOne() { //every call will print 0. 

	int i = 0;
	i++;
	std::cout << i << std::endl;
}

void FunctionTwo() {//might as well have moved i out of FunctionTwo and into the global space

	static int i = 0;
	i++;
	std::cout << i << std::endl;
}

class Singleton {//Singleton class should only have one instance. This is how you call methods of a class 
				 //without an instance
public:
	static Singleton& Get()
	{
		static Singleton instance; //without static. instance would be on stack and could be temporary
		return instance;
	}

	void Hello() {}
};


int main() {

	FunctionOne();
	FunctionOne();
	FunctionOne();

	FunctionTwo();
	FunctionTwo();
	FunctionTwo();

	std::cin.get();
}