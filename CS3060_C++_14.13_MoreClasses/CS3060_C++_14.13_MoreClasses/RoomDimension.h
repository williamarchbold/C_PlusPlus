#pragma once
#ifndef RoomDimensions_H
#define RoomDimensions_H

#include "FeetInches.h"

using namespace std;

class RoomDimension
{
private:

	FeetInches length;
	FeetInches width;

public:

	FeetInches getLength()
	{
		return length;
	}
	FeetInches getWidth()
	{
		return width;
	}
	FeetInches getArea()
	{
		return length*width;
	}

	void setLength(FeetInches l)
	{
		length = l;
	}

	void setWidth(FeetInches w)
	{
		width = w;
	}

};


#endif