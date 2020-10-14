//playing with strings is bad and slow
//std::string allocates memory which is bad (see stack vs heap) 

//string view is a const char pointer owned by someone else plus a size

#include <iostream>
#include <string>
#include <string_view>

static uint32_t s_AllocCount = 0;

void* operator new(size_t size) //overload the new operator
{
	s_AllocCount++; //keep track of allocations 
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}

void PrintName(const std::string& name)  //no string copying
{
	std::cout << name << std::endl;
}

int main()
{
	const char* n = "William Achbold"; //*c string 
	std::string name = "William Archbold";
	PrintName(name); //1st scenario print name

	PrintName("William Archbold2");


	std::string_view firstName(name.c_str(), 3);
	std::string_view lastname(name.c_str() + 4, 9);

	std::cout << s_AllocCount << " allocations" << std::endl;
	std::cin.get();
}