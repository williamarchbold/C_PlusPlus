#pragma once

#ifndef ROOMCARPET_H
#define ROOMCARPET_H

#include "RoomDimension.h"

class RoomCarpet
{
private:
	
	RoomDimension room_size;
	double cost_per_sq_foot;

public:
	void SetCostPerSqFoot(double cost) { cost_per_sq_foot = cost;  }
	void SetRoomSize(FeetInches length, FeetInches width) { room_size.setLength(length); room_size.setWidth(width); }

	RoomDimension setSize();

	double getCarpetCost() 
	{
		return room_size.getArea() * cost_per_sq_foot;
	}

};


#endif