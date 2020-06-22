//#include "../Engine/Engine.h" //include this to get a link usin relative path
//...but that include looks messy so we want to use absolute paths specifically 
// compiler include paths. so Game Proj ->Properties->C++->General->Additional Include Directories

#include "Engine.h"  //use angular brackets <> if includin somethign outside VS solution

int main()
{
	Engine::PrintMessage();
}



//Add Engine as a Reference to Game so whenever Game is buil, it will build Engine first then Game