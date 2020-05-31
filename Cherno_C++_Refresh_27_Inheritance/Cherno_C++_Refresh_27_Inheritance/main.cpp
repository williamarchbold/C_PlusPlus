#include <iostream>
#include <string>

class Entity
{
public:
	float x, y;

	void Move(float xa, float ya)
	{
		x += xa;
		y += ya;
	}
};

//anything that's private won't be available in inherited classes

class Player : public Entity  //inherited Entity. Player is a subclass of Entity
	//if use override will have to use a vtable
{
public:
	const char* Name;

	void PrintName() {
		std::cout << Name << std::endl;
	}

};


int main()
{
	std::cout << sizeof(Entity) << std::endl;
	Player player;
	player.Move(2, 4);
	std::cin.get();
}