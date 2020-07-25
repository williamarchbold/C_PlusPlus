#include <iostream>
#include <vector>
#include <functional>  //std::function
#include <algorithm> //std::find_if

//Functions are CPU instructions stored somewhere within our binary/exe 

//lambdas are good for passing functions that you want to run some time in the future 



void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void HelloWorldTwo(int a)
{
	std::cout << "Hello World! " << a << std::endl;
}

void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
	{
		func(value);
	}
}

void ForEach2(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
	{
		func(value);
	}
}

namespace apple { //c libraries don't have namespaces. instead append namespace to beginning of function names. apple_print
	void Print(const std::string& text)
	{
		std::cout << text << std::endl;
	}
}

namespace orange {
	void Print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}

using namespace apple;
using namespace orange;
int main()
{
	auto function = HelloWorld; //remove parantheses and we have a function pointer which return the address of the function. 

	function();
	function();

	void(*William)() = HelloWorld; //type is what auto returns. William is arbitrary variable name

	typedef void(*Yo)();

	Yo function2 = HelloWorld;

	typedef void(*YoTwo)(int);

	YoTwo function3 = HelloWorldTwo;

	function3(5);

	std::vector<int> values = { 3, 5, 9, 1, 2 };

	ForEach(values, PrintValue); //silly to use create a function that will only be used once. so we can use a lambda expression

	ForEach(values, [](int value) {std::cout << "Value: " << value << std::endl; }); //square brackets are called capture parameters. 

	//***START OF LAMBDA VIDEO***

	int a = 5;

	auto lambda1 = [a](int value) {std::cout << "Value: " << a << std::endl; }; //pass a by value

	auto lambda2 = [&a](int value) {std::cout << "Value: " << a << std::endl; }; //pass a by reference

	auto lambda3 = [=](int value) {std::cout << "Value: " << a << std::endl; }; //pass everything in 

	auto lambda4 = [&](int value) {std::cout << "Value: " << a << std::endl; }; //pass everything in by reference

	ForEach2(values, lambda4);

	ForEach2(values, lambda3);

	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });

	std::cout << *it << std::endl;


	Print("hello"); //even though both namespaces in place, will use orange because matches argument better. runtime issue. 

	std::cin.get();
}