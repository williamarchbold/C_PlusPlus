#include <iostream>
#include <string>



class Printable //pure virtual function. equivalent of interface in other language
{
public:
	virtual std::string GetClassName() = 0; //pure virtual so every inheriting class must define 
};

//virtual functions introduce dynamic dispatch via a v-table which holds a mapping of all the base
//class's virtual functions 

//virtual functions cost memory because base class stores a pointer to the v table
class Entity : Printable
{
public:
	virtual std::string GetName() { return "Entity"; }
	std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private: 
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) {}

	std::string GetName() override { return m_Name; } //override is optional, but helpful
	std::string GetClassName() override { return "Player"; }
};

int main()
{
	Entity* e = new Entity();
	std::cout << e->GetName() << std::endl;

	Player* p = new Player("Cherno");
	std::cout << p->GetName() << std::endl;


	Entity* f = p;
	std::cout << f->GetName() << std::endl;
	std::cin.get();
}