/*
William Archbold
CS 3060 Obj Oriented Programming C++
11 Oct 2019
*/

/*
Write a proram that creates an instance of the Patient class, initialized 
with sample data. Then, create three instances of the Procedure class. Program
should display the patient's information, information on all 3 procedures
and the total charges of the procedures
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Q13.04_Procedure.h"
#include "Q13.04_Patient.h"

using namespace std;

const int NUM_PROCEDURES = 3;

int main()
{
	
	Procedure procedures[NUM_PROCEDURES] = {
		Procedure("Phyiscal Exam", "11 Oct 2019", "Dr. Irvine", 250),
		Procedure("X-ray", "11 Oct 2019", "Dr. Jamison", 500),
		Procedure("Blood Test", "11 Oct 2019", "Dr. Smith", 200)
	};
	
	Patient* patient = new Patient("Mike", "S.", "Rowe", "1270 Main St.", "Col. Springs", "CO", 80906, "719-554-0001", "Greta", "256-843-2272");

	cout << "Name: " << patient->getFirst() << " " << patient->getMiddle() << " " << patient->getLast() << endl
		<< "Addres: " << patient->getAddress() << " " << patient->getCity() << " " << patient->getState() << " " << patient->getZIP() << endl
		<< "Phone number: " << patient->getNumber() << endl
		<< "Emergency contact: " << patient->getEmergencyName() << " @ " << patient->getEmergencyNumber() << endl;

	double total_charges = 0;

	for (int i = 0; i < NUM_PROCEDURES; i++)
	{
		cout << "\nProcedure #" << i + 1;
		
		cout << "\nProcedure name: " << procedures[i].getName();
		cout << "\nDate: " << procedures[i].getDate();
		cout << "\nPractioner: " << procedures[i].getPractitioner();
		cout << "\nCharge : $" << fixed << setprecision(2) << procedures[i].getCharges() << endl;

		total_charges += procedures[i].getCharges();

	}

	cout << "\n\nTotal Charge: $" << fixed << setprecision(2) << total_charges;


	return 0;
}