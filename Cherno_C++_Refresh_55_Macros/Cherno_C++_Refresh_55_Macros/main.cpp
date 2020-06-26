#include <iostream>
#include <string>


#define WAIT std::cin.get();  //bad usae of prepocessor directives if difined in other files
#define OPEN_CURLY {

#ifdef PR_DEBUG
#define LOG(x) std::cout << x << std::endl //this grayed otu if switch to release mode
#else
#define LOG(x)
#endif

int main()
OPEN_CURLY
//	std::cin.get();
	LOG(5);
	WAIT
}