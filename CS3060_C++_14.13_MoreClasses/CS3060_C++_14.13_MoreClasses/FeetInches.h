#pragma once

#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>

using namespace std;

// This class is provided in textbook on page 844 but required for homework assignment
// The FEETINCHES class holds distances or measurements expressed in feet and inches

class FeetInches
{
private:
	int feet;
	int inches;
	void Simplify(); //Defined in FeetInches.cpp

public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		Simplify();
	}

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
	}

	//Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	int getTotalInches() const
	{
		return feet * 12 + inches;
	}

	// Overloaded operator functions
	FeetInches operator + (const FeetInches &);
	FeetInches operator - (const FeetInches &);
	FeetInches operator * (const FeetInches &);
	double operator * (const double operand);
	friend istream & operator >> (istream &in, FeetInches &feetInches);
};

#endif
