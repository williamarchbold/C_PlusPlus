#include <iostream>
#include <string>

//explicit disables implicit functionality; used infront of constructors 

class Entity
{
private:
	std::string name;
	int age;
public:
	Entity(const std::string& n)
		: name(n), age(-1) {}
	Entity(const int& a)
		: name("Unkown"), age(a) {}
};

void PrintEntity(const Entity& e)
{
	//printing
}

int main()
{
	Entity a("William");
	Entity b(22);
	Entity c = 'm'; //age set to 109
	Entity d = 22;
	Entity e = (std::string)"Willy";
	PrintEntity(45);
	PrintEntity((std::string)"Billy");
	std::cin.get();


}