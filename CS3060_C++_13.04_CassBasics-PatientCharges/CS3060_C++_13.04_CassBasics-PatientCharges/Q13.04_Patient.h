/*
William Archbold
CS 3060 Obj Oriented Programming C++
11 Oct 2019
*/

/*
Q13.04 Write a class named Patient that has member variables for the following data: 
First name, middle name, last name
Address, city, state, ZIP code
Phone number
Name and phone number of emergency contact
*/
#pragma once
#ifndef PATIENT_H
#define PATIENT_H

#include <string>

using namespace std;

class Patient
{
private:
	string first_name;
	string middle_name;
	string last_name;

	string address;
	string city;
	string state;
	int zip;

	string phone_number;

	string emergency_name;
	string emergency_number;

public:

	//Constructors
	Patient()
	{ first_name = " "; middle_name = " "; last_name = " ";
	address = " "; city = " "; state = " "; zip = 00000; 
	phone_number = "0000000000"; emergency_name = " "; 
	emergency_number = "0000000000"; }

	Patient(string first, string middle, string last, string adr, string cit, 
		string st, int zi, string number, string e_name, string e_number)
	{	first_name = first; middle_name = middle; last_name = last; address = adr; 
		city = cit; state = st; zip = zi; phone_number = number; emergency_name = e_name; 
		emergency_number = e_number;}

	//Accessor functions
	string getFirst()
	{ return first_name; }

	string getMiddle()
	{ return middle_name; }

	string getLast()
	{ return last_name; }

	string getAddress()
	{ return address; }

	string getCity()
	{ return city; }

	string getState()
	{ return state; }

	int getZIP()
	{ return zip; }

	string getNumber()
	{ return phone_number; } 

	string getEmergencyName()
	{ return emergency_name; }

	string getEmergencyNumber()
	{ return emergency_number; }

	//Mutator Functions
	void setFirst(string first)
	{ first_name = first; }

	void setMiddle(string middle)
	{ middle_name = middle; }

	void setLast(string last)
	{ last_name = last; }

	void setAddress(string addr)
	{ address = addr; }

	void setCity(string cit)
	{ city = cit; }

	void setState(string sta)
	{ state = sta; }

	void setZIP(int zi)
	{ zip = zi; }

	void setNumber(int num)
	{ phone_number = num; }

	void setEmergencyName(string e_name)
	{ emergency_name = e_name; }

	void setEmergencyNumber(int num)
	{ emergency_number = num; }

};


#endif
