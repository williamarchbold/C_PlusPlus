//can be done with void pointer, but this is a safer, C++ 17 way
//std optional, variant, any all part of C++ 17

#include <iostream>
#include <any> //similar to std::variant, which requires you to list all your potential
				//types which adds safety
				//any stores small types as a union
				//any stores large types as void pointers, which is not good for performance
				//std varaint will work better for larger data and will perform better


void* operator new(size_t size)
{
	return malloc(size);
}


int main()
{
	std::any data;
	data = 2;
	data = "William";
	data = std::string("William");

	std::any_cast<std::string>(data);

	std::cin.get();
}