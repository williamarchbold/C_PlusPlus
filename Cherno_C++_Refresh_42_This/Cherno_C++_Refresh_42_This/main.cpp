#include <iostream>
#include <string>

void PrintEntity(Entity* e);


class Entity
{
public:
	int x, y;

	Entity(int x, int y)
	{
		(*this).x = x;   //Entity* e = this; 
		this->y = y;
		PrintEntity(this);
	}

	int GetX() const //const here means can't modify class
	{
		return this->x;
	}

};

void PrintEntity(Entity* e)
{
	//print
}

