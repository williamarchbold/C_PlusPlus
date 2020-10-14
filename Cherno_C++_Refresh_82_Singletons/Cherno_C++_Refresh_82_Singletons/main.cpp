//when you plan to have a single instance of a class 
//whole purpose of object oriented programming is making lots of objects
//in C++ we don't have to have a class, we can just have functiosn and variables that aren't tied to a class
//functionality that applies to some globalet of data 
//good example = random number generator or a renderer

#include <iostream>
class Singleton
{
public:
	static Singleton& Get()
	{
		return s_Instance;
	}

	Singleton(Singleton&) = delete; //prevents the copy constructor

	void Function() {}
private:
	Singleton() {}//make constructor private so no one can make multiple instances

	static Singleton s_Instance; //because it's static need an instance outside of class
};


class Random
{
public:

	float Float() { return m_RandomGenerator; }  //this is the meaty function

	static Random& Get() //required
	{
		return r_Instance;
	}

	Random(Random&) = delete; //prevents the copy constructor

	void Function() {}
private:

	float m_RandomGenerator = 0.5f; //pretend this is a random number

	Random() {}//make constructor private so no one can make multiple instances

	static Random r_Instance; //because it's static need an instance outside of class
};





Singleton Singleton::s_Instance;


Random Random::r_Instance;


int main()
{
	Singleton& insance = Singleton::Get();

	Singleton::Get().Function();

	float number = Random::Get().Float();

	//shortcut to not have to call Get()...
	auto& random = Random::Get();
}