#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took: " <<  ms << std::endl;
	}
};

void Function()
{
	Timer timer;

	for (int i = 0; i < 100; i++) {
		std::cout << "hello std::endl" << std::endl;
	}
}

void Function2()
{
	Timer timer;

	for (int i = 0; i < 100; i++) {
		std::cout << "hello \n";
	}
}

int main()
{
	using namespace std::literals::chrono_literals; //provides the "s" 

	auto start = std::chrono::high_resolution_clock::now();

	std::this_thread::sleep_for(1s); 

	auto end = std::chrono::high_resolution_clock::now();	

	std::chrono::duration<float> duration = end - start;

	std::cout << duration.count() << "sec" << std::endl;


	Function();

	Function2();

	std::cin.get();
}
