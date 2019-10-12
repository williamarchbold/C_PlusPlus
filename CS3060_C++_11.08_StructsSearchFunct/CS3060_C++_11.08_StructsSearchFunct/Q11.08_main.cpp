#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Customer
{
	string name;
	string address;
	string city;
	string state;
	string zip;
	string phone;
	double balance;
	string lastPay;
};

void getInfo(Customer&);
void showInfo(Customer);
void showSearch(Customer[], string, int);

int main() {
	const int NUM_ACCOUNTS = 20;

	Customer account[NUM_ACCOUNTS];
	
}