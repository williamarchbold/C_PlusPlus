/*
William Archbold
CS 3060 Obj Oriented Programming C++
14 Sep 2019
*/

/*
Q7.03 Write a program that has 2 arrays. One array to store the names of five salsas. 
The user will fill in the values of the second array to represent number of jars sold for each
type. Display salsa type, total sales, highest and lowest selling products. 
*/

/* Pseudocode 
1. Create list of 5 salsas
2. Get the user to input the sales of each salsa
3. Calculate which salsa was highest and lowest seller
4. Display all results back to user
*/

#include <iostream>
#include <string>

using namespace std;

const int NUM_SALSAS = 5;

void getSales(const string[NUM_SALSAS], int[NUM_SALSAS]);
void displaySales(const string[NUM_SALSAS], const int[NUM_SALSAS]);
int calculateHighest(const int[NUM_SALSAS]);
int calculateLowest(const int[NUM_SALSAS]);

int main(int argc, char *argv[])
{
	
	string salsas[NUM_SALSAS] = { "mild", "medium", "sweet", "hot", "zesty" };
	int sales[NUM_SALSAS];
	
	getSales(salsas, sales);

	displaySales(salsas, sales);

	return 0;
}

void getSales(const string salsas[NUM_SALSAS], int sales[NUM_SALSAS])
{
	int sale = 0;
	for (int i = 0; i < NUM_SALSAS; i++) {
		cout << "\nPlease enter number of sales for " << salsas[i] << ": ";
		cin >> sale;
		while (sale < 0)
		{
			cout << "\nInvalid input. Please enter number of sales for " << salsas[i] << ": ";
			cin >> sale;
		}
		sales[i] = sale;
	}
}

void displaySales(const string salsas[NUM_SALSAS], const int sales[NUM_SALSAS])
{
	cout << "\nSALES DATA";
	for (int i = 0; i < NUM_SALSAS; i++) {
		cout << endl << salsas[i] << ": " << sales[i];
	}

	int best = calculateHighest(sales);
	int worst = calculateLowest(sales);

	cout << "\nHighest Seller: " << salsas[best]
		<< "\nLowest Seller: " << salsas[worst] << endl;
}

int calculateHighest(const int sales[NUM_SALSAS])
{
	int best_index = 0; 
	int best_sell = sales[0];

	for (int i = 1; i < NUM_SALSAS; i++)
	{
		if (sales[i] > best_sell)
		{
			best_index = i;
			best_sell = sales[i];
		}
	}

	return best_index;
}

int calculateLowest(const int sales[NUM_SALSAS])
{
	int worst_index = 0;
	int worst_sell = sales[0];

	for (int i = 1; i < NUM_SALSAS; i++)
	{
		if (sales[i] < worst_sell)
		{
			worst_index = i;
			worst_sell = sales[i];
		}
	}

	return worst_index;
}
