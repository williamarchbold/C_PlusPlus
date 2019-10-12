#include <iostream>
using namespace std;

//Global constants
const int SIZE = 80;
const int MIN = 6;
//Function prototypes
void displayRequirements();
void displayResul(char[]);
bool isValid(char[]);
bool hasLength(char[]);
bool hasLower(char[]);
bool hasUpper(char[]);
bool hasDigit(char[]);

int main()
{
	char cstring[SIZE];

	
	
	cin.getline(cstring, SIZE);

	//

	return 0;
}


void displayRequirements()
{
	//Display password requirements
	cout << "\nPlease input a" << MIN << "character password with at least 1 uppercase character, 1 lowercase character and 1 digit:"; 
}

void displayResul(char str[])
{

	// Determine if password is valid
	if (isValid(str)) {
		cout << "Password is valid";
	}
	else
	{
		cout << "The password is invalid.\n";
		if (!hasLength(str)) {
			cout << "It should be at least" << MIN << "characters";
		}
	}
}

bool isValid(char str[])
{
	bool status = false;

	if (hasLength(str) && hasLower(str) && hasUpper(str) && hasDigit(str))
	{
		status = true;
	}

	return status;
}

bool hasLength(char str[])
{
	bool status = false;
	int count = 0;
	//Count each character in teh string until the null terminator is reached
	while (*str != '\0') {
		count++;

		//go to next character
		*str++;
	}
	// Determine if the char counter
	//variable is greater than or equal to 
	//min number of chars
	if (count >= MIN) {
		status = true;
	}
	return status;
}

bool hasLower(char str[]) {
	bool status = false;
	int count = 0;

	while (*str != '\0' && count == 0) {
		if (islower(*str))
		{

		}
	}

}

bool hasUpper(char[])
{
	bool status = false;
	int count = 0;

	while (*str != '\0' && cont == 0) {
		if (isupper(*str)) {
			count++
		}
		else
		{
			//If not, go to the next character
			*str++;
		}
	}
	return false;
}

bool hasDigit(char[])
{
	return false;
}

