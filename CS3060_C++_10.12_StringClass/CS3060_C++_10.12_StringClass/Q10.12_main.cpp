/*
William Archbold
CS 3060 Obj Oriented Programming C++
27 Sep 2019
*/

/*
Q10.12 Write a program that asks for a password then verifies that it meets the stated criteria: 
1. >= six characters long
2. at least 1 uppercase and 1 lowercase
3. at least 1 digit
*/

#include <iostream>
#include <string>

using namespace std;
bool checkPassword(const string &password);
bool checkLower(const string &password);
bool checkUpper(const string &password);
bool checkForInt(const string &password);
bool checkLength(const string &password);


int main(int argc, char* argv[]) {

	bool valid = false;
	string password;
	while (!valid)
	{
		
		
		cout << "\nPlease input a 6 character password with at least 1 uppercase character, 1 lowercase character and 1 digit: ";

		cin >> password;

		 valid = checkPassword(password);
	}

	cout << "\nPassword set!\n";

	return 0;
}

bool checkPassword(const string & password)
{
	if (checkLength(password)
		& checkForInt(password) 
		& checkLower(password)
		& checkUpper(password))
	{
		return true;
	}
	else
	{
		return false;
	}	
}

bool checkLength(const string &password)
{
	if (!(password.length() >= 6))
	{
		cout << "\nPassword needs to be at least 6 characters.\n";
		return false;
	}
	else
	{
		return true;
	}
	
}

bool checkForInt(const string &password)
{
	bool present = false;
	for (int i = 0; i < password.length(); i++)
	{
		if (isdigit(password[i]))
		{
			present = true;
		}
	}
	if (!present)
	{
		cout << "\nPassword needs at least 1 integer.\n";
	}

	return present;
}

bool checkLower(const string &password) 
{
	bool present = false;
	for (int i = 0; i < password.length(); i++)
	{
		if (islower(password[i]))
		{
			present = true;
		}
	}
	if (!present)
	{
		cout << "\nPassword needs at least 1 lower case letter.\n";
	}
	return present;
}

bool checkUpper(const string &password) 
{
	bool present = false;

	for (int i = 0; i < password.length(); i++)
	{
		if (isupper(password[i]))
		{
			present = true;
		}
	}
	if (!present)
	{
		cout << "\nPassword needs at least 1 upper case letter.\n";
	}
	return present;
}