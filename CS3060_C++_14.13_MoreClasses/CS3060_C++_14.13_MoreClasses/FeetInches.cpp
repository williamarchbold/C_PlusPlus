// Implementation file for the FeetInches class provided in textbook 
#include <cstdlib> //needed for abs value
#include "FeetInches.h"

void FeetInches::Simplify()
{
	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
}

FeetInches FeetInches::operator + (const FeetInches &right)
{
	FeetInches temp;

	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.Simplify();
	return temp;
}

FeetInches FeetInches::operator - (const FeetInches &right)
{
	FeetInches temp;

	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.Simplify();
	return temp;
}

//this was not part of the textbook but added for the assignment by William Archbold
FeetInches FeetInches::operator * (const FeetInches &right)
{
	FeetInches temp;

	/*int totalInches = getTotalInches() * right.getTotalInches();
	temp.inches = totalInches;
	temp.Simplify();
	*/
	int total_feet = getFeet() * right.getFeet();
	int total_inches = getInches() * right.getInches();

	temp.setFeet(total_feet);
	temp.setInches(total_inches);
	temp.Simplify();
	return temp;
}

double FeetInches::operator * (const double operand)
{
	double result = feet * operand;
	result += (inches / 12.0) * operand;
	return result;
}

istream & operator >> (istream &in, FeetInches &feetInches)
{
	in >> feetInches.feet >> feetInches.inches;
	return in;
}