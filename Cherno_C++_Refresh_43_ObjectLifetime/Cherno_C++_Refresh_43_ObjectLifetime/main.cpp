#include <iostream>
#include <string>
//smart pointers are wrappers around normal pointers
#include <memory>

//scope can be function, if or empty scope {}

//unique pointer will delete when gone out of scope aka scope pointers
  //cannot copy unique pointers

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}
	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
	void PrintEntity()
	{

	}
};

int* CreateArray()
{
	int* array = new int[50];
	return array;
}

class ScopedPtr //Own version of Unique Pointer
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* ptr)
		: m_Ptr(ptr)
	{
	}
	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

int main()
{

	int* a = CreateArray();

	{
		Entity e;
	}
				//end of scope, desctructor called auotomatically! 
	{
		Entity* e = new Entity(); //heap based variable//need to delete or let program collect memory when it terminates 
		ScopedPtr d = new Entity(); //this will be destroyed once out of scope because scopedptr object put on the stack 
	}

	{
		std::unique_ptr<Entity> f(new Entity()); //def says excplicit so no conversion with "= new .." though not preferred fomat
		f->PrintEntity(); //exactly the same as regular object call

		std::unique_ptr<Entity> g = std::make_unique<Entity>(); //preffered format due to exception safety
		g->PrintEntity();

	}


	std::shared_ptr<Entity> e0;
	{
		std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); //shared entity creates a block of memory that stores reference count
		std::weak_ptr<Entity> weakEntity = sharedEntity; //assigns reference, but doesn't increase ref count 
		e0 = sharedEntity;
	}
		//here, sharedEntity is destroyed but, the entity it poitns to still alive because e0 is still within scope. whn e0 dies with main, then the object dies

	std::cin.get();
}