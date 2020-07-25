//grab a bunch of header files and put them into a compiled format
//everytime i include vector, the preprocessor has to read the whole vector file and all it's includes, parsed, tokenized, compiled
//everytime you change something, you have to recomplie to include the include files
//precompiled header is already parsed because it's in binary format.

//absolutely need precompiled headers if compile time taking minutes

#include "pch.h"

int main()
{
	std::cout << "hello world" << std::endl;
}