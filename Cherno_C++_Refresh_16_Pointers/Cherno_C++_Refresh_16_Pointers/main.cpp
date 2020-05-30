#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main() {
	//ptr is just an address of something else
	void* ptr = nullptr; //nullptr introduced in c++ 11; equivalent of NULL or void* ptr = 0 
	int var = 8; 
	ptr = &var;
	ptr = (double*)&var; //if go to ptr memory value, still 4 bytes for int 
	//*ptr = 10; //can't dereference because types don't match 
	int *ptr_2 = nullptr;
	ptr_2 = &var;
	*ptr_2 = 10;

	char* buffer = new char[8];
	memset(buffer, 0, 8); //sets memory beginning at first argument to value of second argument for third element number of bytes
	
	char** ptr_3 = &buffer;

	delete[] buffer;
	std::cin.get();
}