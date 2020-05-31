#include <iostream>
#include <string>

class Entity //default visibility of class is private. struct public by default
{
private: //only this entity class can access these variables, but exception is "friend" keyword 
	int x, y;
protected: //subclasses can use protected methods and public method, but not in main()
	void Print() {}
public:
	Entity()
	{
		x = 0;
		Print();
	}
};

class Player : public Entity
{
	
};

int main()
{
	std::cin.get();
}