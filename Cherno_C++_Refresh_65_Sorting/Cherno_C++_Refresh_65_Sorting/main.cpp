#include <iostream>
#include <vector>;
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> values = { 4,5,1,4,2 };

	std::sort(values.begin(), values.end(), [](int a, int b) {return a > b; }); //n*logn; if a comes first 
	std::cin.get();
}