//William Archbold

#include <iostream>
#include <string>


using namespace std;

int string_conversion(string, int value = 0);


int main()
{
	string input;
	cout << "Enter a string number:";
	cin >> input;
	cout << endl;
	cout << "Your input: " << input << " is " << string_conversion(input) << endl;

	system("pause");

	return 0;
}


int string_conversion(string Str, int value)
{
	//Precondition: Str is a valid string input.
	//Postcondition: string_conversion returns an int to the stack
	bool Negate = false;


	if (!(value == 0 && (Str[0] == '0' || Str[0] == ' ')))
	{
		
		value *= 10;

		int tmpValue = Str[0] - 48;

		//find out if first digit isn't an integer
		if (tmpValue < 0 || tmpValue > 9)
		{
		if ((Str[0] == '-' || Str[0] == '+') && value == 0)
		{
			if (Str[0] == '-')
			{
				Negate = true;
			}
		}
		else
		{
			std::cout << "ERROR, Not a number starting at" << Str << std::endl;
			return 0;
		}
		}
		else
		{
			value += tmpValue;
		}
	}

	if (Str.length() == 1)
	{
		return value;
	}
	else
	{
		if (Negate == true)
		{
			return -string_conversion(Str.substr(1), value);
		}
		else
		{
			return string_conversion(Str.substr(1), value);
		}
	}

	return value;
}