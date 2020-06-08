#include <iostream>
#include <string>

static int s_Level = 6;
static int s_Speed = 2;

int main()
{
	if (s_Level > 5)
		s_Speed = 10;
	else
		s_Speed = 5;

	s_Speed = s_Level > 5 ? 10 : 5;

	std::string rank = s_Level > 10 ? "Master" : "Beginner";

	std::string otherRank; //construct's empty string object then overrides it with new string object
	if (s_Level > 10)
		otherRank = "Master"; //this is slower than ternary above.
	else
		otherRank = "Beginner";

	s_Speed = s_Level > 5 ? s_Level > 10 ? 15 : 10 : 5; //prints 5 if less than 5; 10 if > 5 & < 10; prints 15 if greater than 10s

	std::cout << s_Speed << std::endl;
	std::cin.get();
}