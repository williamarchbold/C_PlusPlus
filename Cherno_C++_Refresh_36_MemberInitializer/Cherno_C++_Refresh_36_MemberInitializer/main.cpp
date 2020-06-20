#include <iostream>
#include <string>

class Example
{
public:
	Example()
	{
		std::cout << "Created Entity!" << std::endl;
	}
	Example(int x)
	{
		std::cout << "Created Entity with " << x << std::endl;
	}
};

class Entity
{
private:
	std::string m_Name;
	int m_Score;
	Example example;
public:
	Entity()
		: m_Name("unkown"), m_Score(0), example(8)
	{
		//example = Example(8); //threw away old example and replaced with new Example so printed "Created.." twice!
	} //member initializer style, must be done in order of decleration above

	Entity(const std::string& name)
	{
		m_Name = name;
	}
	const std::string& GetName() const { return m_Name; }
};

int main()
{
	Entity e;
	std::cin.get();
}