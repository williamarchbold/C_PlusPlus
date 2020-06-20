//two types of libraries: include (header files) and library (lib)
//static linking = library put into executable. can technically result in faster application .lib
//dynamic library = linked at runtime outside of executable  | ends with .dll or dll.lib (static library used with dll linking all locations of functions to .dll) 

#include <iostream>
#include "GLFW/glfw3.h" //can also use angular brackets instead of quotes	

int main()
{

	int a = glfwInit(); //build will fail with linker error because header file doesn't have definition, which is in library. need to go to settings linker, include library and path
	std::cin.get();
}