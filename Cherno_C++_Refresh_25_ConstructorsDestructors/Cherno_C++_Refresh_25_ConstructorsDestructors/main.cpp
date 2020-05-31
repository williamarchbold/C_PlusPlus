#include <iostream>

class Entity
{
public:
	float X, Y;

	//this could be a constructor but why not use built in initializer below
	void Init() {
		X = 0.0f;
		Y = 0.0f;
	}

	Entity() //initialzer is automatic in C++ but blank. Primitive data types must be set to a value. Not automatic
	{
		X = 0.0f;
		Y = 0.0f;
	}

	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}


	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print() {
		std::cout << X << ", " << Y << std::endl;
	}
};

void CreationDestructionDemo() {
	Entity e;
	e.Print(); //object on stack so will be destroyed once function returns and goes out of scope
}

int main() {

	Entity e;
	std::cout << e.X << std::endl; //won't compile 
	e.Print(); //will compile but get random values for x and y because we didn't initialize memory


	Entity e1;
	e1.Init();

	Entity e2;
	e2.Print();

	Entity e3(3.2, 5.2);

	CreationDestructionDemo();

	e3.~Entity();

	std::cin.get();
}