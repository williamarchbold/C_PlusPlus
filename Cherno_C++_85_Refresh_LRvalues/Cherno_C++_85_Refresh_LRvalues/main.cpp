//L & R values are important for understanding move semantics 
//L = locator values ...sometimes... don't try to define it for yourself
//L is usually on left of equal sign and R is on the right side, but not always true

//Rule 1: cannot take l value reference from an r value. can only have l value ref from l value
//Rule 2: while can't have l value ref of an r value, can have a cosnt l value ref of an r value

#include <iostream>

int GetTen()
{
	return 10;
}

int& GetValue() //l value reference
{
	static int value = 10; //need to store in memory
	return value;
}

void SetValue(int value) //can call with either an l value or an r value
{

}

void SetValue2(int& value)
{

}

void PrintName(std::string& name) //thjis will onl accept L values
{
	std::cout << name << std::endl;
}

void PrintName2(const std::string& name)
{
	std::cout << name << std::endl;
}

void PrintName3(std::string&& name) //this will only accept temporary references aka R value reference. 
{
	std::cout << name << std::endl;
}

//will overload function to tell us when we have an l or r value

void GetLorRValue(std::string& name)
{
	std::cout << "[L value] " << name << std::endl;
}

void GetLorRValue(std::string&& name)
{
	std::cout << "[R value] " << name << std::endl;
}
int main()
{
	int i = 10; //i is location in memory and 10 is a numeric literal 
				//can't say 10 = i; because 10 doesn't have a place in memory
	int a = i; //i is still a L value even on right side 

	int j = GetTen(); //GetTen returns an r value doesn't have to be a numeric literal
			//GetTen() = 5; will not work "expression must be a modifiable lvalue"

	GetValue() = 5; //l value = r value 

	SetValue(i); //called with l value
	SetValue(10); //called with r value (temporary value) used to create an l value
					//
	//SetValue2(10) will give an error because ref must be to an l value ...Rule 1

	const int& b = 10; //Rule 2.. compiler will create a temp variable to store 10 and hide the step


	std::string firstName = "William";
	std::string lastName = "Archbold";
	//            ^            ^
	//           L			   R

	std::string fullName = firstName + lastName;
	//              ^          ^          ^
	//              L          R           R 
	//temporary string is constructed from addtion of those two strings and assigned to fullName

	PrintName(fullName);
	//PrintName(firstName + lastName); will not work because expression isn't an lvalue 

	PrintName2(firstName + lastName); //this will accept temorary objects.. Rule 2

	//PrintName3(fullName); won't work
	PrintName3(firstName + lastName);

	GetLorRValue(fullName);
	GetLorRValue(firstName + lastName);

}