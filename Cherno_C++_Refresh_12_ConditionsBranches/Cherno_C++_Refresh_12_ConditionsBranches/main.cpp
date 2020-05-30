#include <iostream>	

int main() {
	int x = 6;
	bool comparisonResult = x == 5; //equality operator overload in c std library; each byte in memory has to be equal
	if (1) {
		std::cout << "hello world" << std::endl;
	}
	std::cin.get();
	if (comparisonResult)
		std::cout << "One line" << std::endl;
	std::cin.get();
	const char* ptr = "hello";
	if (ptr) //if ptr != nullptr
		std::cout << "pointer not null" << std::endl;
	else if (ptr == "hello")
		std::cout << "pointer is hello" << std::endl;
	else
		std::cout << "pointer null" << std::endl;
}