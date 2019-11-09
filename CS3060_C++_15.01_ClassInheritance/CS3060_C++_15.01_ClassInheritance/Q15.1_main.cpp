/*
William Archbold
CS 3060 Obj Oriented Programming C++
12 Oct 2019
*/

/* Q15.1 Write an ProductionWorker class that inherits from an Employee class*/
#include "ProductionWorker.h"

#include <iostream>

using namespace std;

int main()
{
	ProductionWorker * worker_one = new ProductionWorker("Mike", 128, "03Mar2019", 1, 25.4);
	worker_one->setHireDate("05Mar2019");

}