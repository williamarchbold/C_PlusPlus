#include <iostream>

void PrintSum(int a, int b)
{
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
}

int main()
{

	int value = 0;

	PrintSum(value++, value++); //i expect this to pass 0 then 1, 
								//in release mode it's 0 + 0; in debug it's 0 + 1 
								//in release, compiler is allowed to work out what's happening in parallel 
								//this is undefined behavior!
								//but in C++ 17, will get 1 + 0 or 0 + 1 
								//Wandox has different compilers other than msvc 

	PrintSum(++value, ++value); //debug and release mode give 2 + 2
	std::cin.get();
}