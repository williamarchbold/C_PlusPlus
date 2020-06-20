#include <iostream>
#include <string>

class Entity
{
private:
	int x = 1;
public:
	void Print() { std::cout << "hello!" << std::endl; }
};

class ScopedPtr
{
private:
	Entity* m_obj;
public:
	ScopedPtr(Entity* entity)
		: m_obj(entity)
	{
	}
	~ScopedPtr()
	{
		delete m_obj;
	}
	Entity* operator->()
	{
		return m_obj;
	}
};

struct Vector3
{
	float x, y, z; //each float = 4 bytes so offset of y will be 4/ 4 bytes into the struct
};

int main()
{
	Entity e;
	e.Print();

	Entity* ptr = &e;
	Entity a = *ptr; //
	a.Print();

	Entity& b = *ptr;
	b.Print();


	(*ptr).Print();

	ptr->Print();

	ScopedPtr f = new Entity();
	f->Print();

	auto g = (int)&((Vector3*)nullptr)->x;

	std::cin.get();
}