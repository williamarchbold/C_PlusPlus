#include <iostream>
#include <string>

/*
void Print(int value)
{
	std::cout << value << std::endl;
}

void Print(float value)
{
	std::cout << value << std::endl;
}

void Print(std::string value)
{
	std::cout << value << std::endl;
}

//...ended up with manually overloading three different print functions which is fine but tedious!

*/

template <typename T> //can also write as <class T> <class William> ...whatever 
void Print(T value) //this isn't actual code. will be evaluated at compile time and only created when called
{
	std::cout << value << std::endl;
}

template <typename T> void Display(T value)
{
	std::cout << v << std::endl;  //this will still compile in msvc (but not clang) even though there's no v because templates don't exist until called
}

template <int N> class Array
{
	int m_Array[N]; //array is on the stack so needs to be known at compile time which is the same as tempaltes

public:
	int GetSize() { return N; }
};

template <typename T, int N> class Array2
{
	T m_array[N];
public:
	int GetSize() { return N; }
};

int main()
{
	Print<int>(5);
	Print(5); //C++ can infer integer 
	Print<std::string>("hello");
	Array<5> array;
	Array2<int, 6> array2;
	std::cin.get();
}