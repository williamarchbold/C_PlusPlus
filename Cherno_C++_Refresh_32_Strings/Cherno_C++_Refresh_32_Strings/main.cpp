#include <iostream>

int main()
{
	const char* name = "William"; //c way. strings are immutable so added const keyword


	//string ends with null termination character

	char name2[2] = { 'h', 'i' };

	std::cout << name2 << std::endl;  //this will result in hi plus a bunch of "cc"'s in the memory which manifest as stack guards to console

	char name3[3] = { 'h', 'i', 0 };

	std::cout << name3 << std::endl;

	//c++ uses a template class for strings that is made of chars as the source primitive datatype. should be using std::string 

	char name4[] = "cherno";

	std::cout << name4 << std::endl;

	const char name5[7] = "Cherno"; // String literal equivalent of "Cherno\0" which is different than "Cherno0". 
	std::cout << "Cherno" << strlen(name5) << std::endl; //only counts characters up to /0

	char name6[] = "William";

	name6[0] = 'B';

	const char* name7 = u8"William"; //char 1 byte per char
	const wchar_t* name8 = L"William"; //2 bytes
	const char16_t* name9 = u"William";//2 bytes
	const char32_t* name10 = U"Cherno";//


	std::cin.get();
}