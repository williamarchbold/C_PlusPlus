//C++ 17 feature part of standard library
//std variant is one of 3 classes new to C++ 17 that give us ability to store data
//of varying types juxtapose std::optional which handles data  that may or not be present


#include <iostream>
#include <variant>
#include <optional>


enum class ErrorCode
{
	None = 0, NotFound = 1, NoAccess = 2
};

std::variant<std::string, int> ReadFileAsString()
{
	return {};
}

int main()
{
	std::variant<std::string, int> data;
	data = "Cherno";
	std::cout << std::get<std::string>(data) << "\n";
	data = 2;
	// data = false; doable but not accessible 
	std::cout << std::get<int>(data) << "\n";

	//what if accidentally try to print as string when it's an int
	//...will throw exception, but alternative way to check below...
	//way 1
	data.index(); //string = 0 int = 1
	//way 2
	if (auto value = std::get_if<std::string>(&data))  //will return a pointer
	{
		std::cout << std::get<std::string>(data) << "\n";
	}

	union //size of biggest type, which would be the double, 8 bytes
	{
		double a;
		float b;
	};

}