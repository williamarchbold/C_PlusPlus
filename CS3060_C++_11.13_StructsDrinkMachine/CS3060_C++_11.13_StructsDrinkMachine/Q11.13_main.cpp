/*
William Archbold
CS 3060 Obj Oriented Programming C++
5 Oct 2019
*/

/*
Q11.13 Write a program that has uses a structure to store Drink Name, Drink Cost, 
Number of Drinks in Machine. Program should create an array of five structures with 
initialized data. The program should enter a loop that performs the following steps: 
1. display a list of drinks
2. give user option to quit or pick a drink
3. if user selects a drink, he/she will enter amount of money that will be inserted in the machine
4. The program will display amount of chnage that will be returned and deduct 1 from number of drinks
for that type
5. If user selects a sold out drink, display a message
6. Repeat loop until user quits. 
*/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int VARIETY = 5;

enum Drinks {COLA, ROOT_BEER, LEMON_LIME, GRAPE_SODA, CREAM_SODA};

struct Drink
{
	string name;
	double cost;
	int stock;

	Drink(){}
	
	Drink(string title, float price, int inventory) {
		this->name = title;
		this->cost = price;
		this->stock = inventory;
	}
};

int MakeSelection();
void CalculateChange(Drink* drinks[], int selection);


int main(int argc, char* argv[]) 
{

	Drink* selections[VARIETY];

	
	selections[COLA] = new Drink("Cola", .75, 20);
	selections[ROOT_BEER] = new Drink("Root Beer", .75, 20);
	selections[LEMON_LIME] = new Drink("Lemon Lime", .75, 20);
	selections[GRAPE_SODA] = new Drink("Grape Soda", .80, 20);
	selections[CREAM_SODA] = new Drink("Cream Soda", .80, 20);

	bool proceed = true;

	while (proceed)
	{
		cout << setw(15) << left << "Item" << setw(8) << left << "Price" << setw(8) << left << "Stock" << endl;
		int i = 1;
		for (Drink* drink : selections)
		{
			cout << i << ". " << setw(12) << drink->name << setw(8) << setprecision(2) << drink->cost << setw(5) << drink->stock << endl;
			i++;
		}

		int selection = MakeSelection();
		
		if (selection == -1)
		{
			proceed = false;
			continue;
		}

		if (selections[selection-1]->stock == 0)
		{
			cout << "Sold out of " << selections[selection - 1]->name << "!";
			continue;
		}

		CalculateChange(selections, selection);
		

		selections[selection - 1]->stock--;
	}
	

	return 0;
}


int MakeSelection()
{
	int selection;
	cout << "\nPlease select which numbered menu item you want or -1 to quit: ";
	cin >> selection;
	while (selection < -1 || selection == 0 || selection > 5)
	{
		cout << "\nPlease select which numbered menu item you want or -1 to quit: ";
		cin >> selection;
	}
	return selection;
}


void CalculateChange(Drink* drinks[], int selection) 
{
	double inserted_bill;
	cout << "Please type the amount of money that will be inserted into the machine: ";
	cin >> inserted_bill;
	while (inserted_bill < .8)
	{
		cout << "Please type the amount of money that will be inserted into the machine: ";
		cin >> inserted_bill;
	}
	double change = inserted_bill - drinks[selection - 1]->cost;
	cout << "\n\nYour change will be : $" << setprecision(4) << change << endl << endl;
}