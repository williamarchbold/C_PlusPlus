#include <iostream>

#define LOG(x) std::cout << x << std::endl 

void Increment_By_Pointer(int* value) {
	
	(*value)++; //without the dereference (asterisk) increment, the memory address just increments by one. not the value we're pointing to
}

void Increment_By_Reference(int& value) {//does exact same thing as Increment_By_Pointer but looks cleaner

	value++;
}

int main() {

	int a = 5;

	int& ref = a; //reference. compiling code at this point won't create two variables. only creates a, but can use ref as if it were a

	ref = 2;

	LOG(a);
	
	Increment_By_Pointer(&a);

	Increment_By_Reference(a);

	int c = 5;
	int& ref_2 = c; // can't do int& ref_2; need to set it equal to something because compiler doesn't recognize standalone reference variables
	ref_2 = 6;

	std::cin.get();
}