/*
THIS IS QUESTION 26 on the FINAL

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
	ProductionWorker * worker_one = new ProductionWorker("Mike", "Johnson", 'M', 123, "March 2019", 1, 15.25);
	worker_one->setHireDate("November 1917");

	worker_one->DisplayInfo();

	return 0;
}