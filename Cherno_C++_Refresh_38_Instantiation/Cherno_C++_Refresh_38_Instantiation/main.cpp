#include <iostream>
#include <string>

using String = std::string; //so you don't have to use namespace std;


class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Uknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

int main()
{
	Entity entity; //calls default constuctor. would look funny coming from Java or C#
					//this is faster than calling on heap
	std::cout << entity.GetName() << std::endl;
	Entity entity2 = Entity("Cherno"); //same thing but creates 1 object on stack and immediately replaces it 

	Entity* e;
	{
		Entity entity3("William");
		e = &entity3;
	}
				//object will still point to same address, but "William" would be gone

	Entity* e2;
	{
		Entity* entity4 = new Entity("Chernoble"); //new returns an entity pointer/the location
		e2 = entity4;
		std::cout << (*entity4).GetName() << std::endl;
	}
	//at this point entity4 is gone, but e2 is still pointing to the Entity object created on the heap

	delete e;
	delete e2;

	std::cin.get();
}