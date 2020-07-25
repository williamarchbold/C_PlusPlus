#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
	using namespace std::literals::chrono_literals;

	std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;

	while (!s_Finished)
	{
		std::cout << "Working" << std::endl;
		std::this_thread::sleep_for(1s); //give commands to the current thread
	}
}

int main()
{
	std::thread worker(DoWork);

	std::cin.get();

	s_Finished = true;

	worker.join; //main thread wait for worker thread to finish and rejoin back to main before main continues working
	std::cout << "Finished" << std::endl;
	std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;

	std::cin.get();

}