#include <iostream> //angle brackets are rarely relative to current file
#include "Log.h" //quotes are usually use to indicate files relative to current file
				//c std library use brackets and .h ex: <stdlib.h> ...c++ do not
void Log(const char* message) {
	std::cout << message << std::endl;
}

int main() { //main assumes return 0. no other function can do that

	int variable = 9; //int 4 bytes large -2.1b -> +2.1b
	unsigned int other = 40; 
	//char 1 byte short 2 byte int 4 byte long 4 byte usually can add unsigned to any of these
	//float decimal value occupying 4 bytes of data
	float var = 5.5f; //would have been a double unless i appended 'f' after number
	double var_two = 5.5;
	//boolian = 1 byte of data. memory only addresses bytes not bits so waste other bits. 
		//can trick byte by storing 8 bools in one byte
	std::cout << variable << std::endl;
	variable = 20;
	std::cout << sizeof(var_two) << std::endl;
	InitLog();
	Log("hello world");
	std::cin.get(); //.get waits until we press enter

}