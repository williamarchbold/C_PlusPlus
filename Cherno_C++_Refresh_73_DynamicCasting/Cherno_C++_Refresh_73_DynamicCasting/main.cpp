//two c++ style casts: c style and the c++ static dynamic 
//dynamic doesn't work in c
//dyanmic evaluated at runtime so does have a runtime cost
//used or inheritance hierachy 
//enemy cast to player will fail; if returns null then we know it's not a player

//C++ runttime type information (RTTI) controllable in Properties -> C/C++ -> Language
// Enable Runtime type information

#include <iostream>
#include <string>

class Entity
{
public:
	virtual void PrintName() {}
};

class Player : public Entity
{
public:
};

class Enemy : public Entity
{
public:	
};

int main()
{
	Player* player = new Player(); //alaerdy has two types Entity and Player

	Entity* actuallyPlayer = player; //implicit cast

	//Player* p = actuallyPlayer; doesn't work!

	Entity* actuallyEnemy = new Enemy();

	//Player* p = (Player*)e1; doesn't work

	Player* p0 = dynamic_cast<Player*>(actuallyEnemy); //this only worked once added virtual method

	Player* p1 = dynamic_cast<Player*>(actuallyPlayer); //this only worked once added virtual method


}