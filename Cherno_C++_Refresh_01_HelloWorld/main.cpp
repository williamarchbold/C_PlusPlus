#include <iostream> //angle brackets are rarely relative to current file
#include "Log.h" //quotes are usually use to indicate files relative to current file
				//c std library use brackets and .h ex: <stdlib.h> ...c++ do not


int main() { //main assumes return 0. no other function can do that

	int i = 0;
	bool condition = true;
	for ( ; condition; ) {
		Log("hello world");
		i++;
		if (!(i < 5)) {
			condition = false;
		}
	}
	i = 0;
	while (i < 5)
	{
		Log("hellooo while");
		i++;
	}

	do {
		Log("do while");
	} while (condition);

	std::cin.get();
}