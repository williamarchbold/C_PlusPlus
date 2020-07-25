//have class a and b derived from a
//reference class b as class a, delete a 
//also need destructor of b not only a to run 

#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base Constructed\n"; }
	virtual ~Base() { std::cout << "Base Destructed\n"; }  //100% need to mark base destructor as virtual if you think you'll make a derived class
};

class Derived: public Base
{
public:
	Derived() { m_Array = new int[5]; std::cout << "Derived Constructed\n"; } //will first call base constructor
	~Derived() { delete[] m_Array; std::cout << "Derived Destructed\n"; } //will first call base destructor

private:
	int* m_Array;
};

class AnotherClass : public Base
{
public:
	AnotherClass() {};
	~AnotherClass() {};
};

int main()
{
	Base* base = new Base();
	delete base;
	std::cout << "---------------\n";

	Derived* derived = new Derived();
	delete derived;

	std::cout << "---------------\n";

	Base* base_poly = new Derived();

	delete base_poly; //will delete base but not derived so need to mark ~Base as virtual to notify C++ to call derived destructors if present

	int a = 5;

	double value = a; //implicit cast because no data loss

	double b = 5.24; 

	int c = b; //implicit cast assumes user acknowledges data loss
	int d = (int)b; //explicit c cast

	double e = (int)(b + 5.3);

	double f = static_cast<int>(b) + 5.3; //static_cast is c++ version of c cast. no real difference just written to show whats happening better

	Derived* derived2 = new Derived();

	Base* base2 = derived2;

	AnotherClass* ac = dynamic_cast<AnotherClass*>(base2);

	Base* base3 = new Base();

	delete ac;
	delete base2, base3;

	//derived = base2; //not valid! 

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			b += 1;
		}
	}

	std::cin.get();
}