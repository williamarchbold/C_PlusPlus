//const's are a promise that something won't change
#include <iostream>
#include <string>

class Entity
{
private:
	int m_X, m_Y;
	int* m_Z;
	int* x, y; //y isn't an int* only x
	int* a, * b; //now both varaibles are int pointers
	mutable int var; //allows const methods to change varaibles

public:
	int GetX() const {  //this const usage only works in a class. means cannot modify any of the members
		var = 5;
		return m_X;
	}
	int GetX() {
		return m_X;
	}
	const int* const GetZ() const //return a immutable pointer and who's contents cannot be modified and the method won't modify the class attribute
	{
		return m_Z;
	}
};

void PrintEntity(const Entity &e) //pass by reference so we don't copy and use more memory, but also don't want to modify so use const
{
	std::cout << e.GetX() << std::endl; //will call GetX() const method because of the const keyword in the parameter
}

int main()
{
	const int MAX_LIFE = 5;

	int* a = new int;

	*a = 2;

	a = (int*)&MAX_LIFE; //not something you should normally do

	std::cout << a << std::endl;

	const int* b = new int; //const int pointer means you cannot modify contents of the pointer

	int const* d = new int; //same thing as above, const int*; cannot modify dereferenced value

	int* const c = new int;

	*c = 4; //can't move pointer but can change the dereferenced value of the pointer 

	/*
	For people having trouble remembering the order in which const keyword is to be used, here's a quick tip.
You have to read it backward, like the compiler does. For instance :

-const int * A; -> "A is a pointer to an int that is constant."
(or, depending on how you prefer to write it)
int const* A; -> "A is a pointer to a const int"
but both are the same as explained in the video.

-int * const A; -> "A is a const pointer to an int."
-const int* const A; -> "A is a const pointer to an int that is constant".
	*/

	std::cin.get();
}