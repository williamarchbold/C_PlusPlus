/*
William Archbold
CS 3060 Obj Oriented Programming C++
27 Sep 2019
*/

/*
Q11.11 Write a program that has a MonthlyBudget structure designed to hold 
expense categories. The program should pass the structure to a function 
that asks the user to enter the amounts spent in each budget category during
a month. The program should then pass the structure to a function that
displays a report indicating the amount over or under in each category as well
as the net over/under. 
*/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



struct MonthlyBudget
{
	float housing = 500, utilities = 150, household_expenses = 65,
		transportation = 50, food = 250, medical = 30, insurance = 100,
		entertainment = 150, clothing = 75, miscellaneous = 50;
};

string expense_list[] = { "housing", "utilities", "household expenses", "transportation",
"food", "medical", "insurance", "entertainment", "clothing", "miscellaneous" };

const int NUM_EXPENSES = 10;

void getExpenses(MonthlyBudget* budget);
void getBalance(MonthlyBudget *my_expenses, MonthlyBudget* budget);

int main(int argc, char* arv[])
{
	MonthlyBudget my_expenses;
	MonthlyBudget set_budget; 
	
	getExpenses(&my_expenses);
	
	getBalance(&my_expenses, &set_budget);

	return 0;
}

void getExpenses(MonthlyBudget* expenses)
{
	int i = 0;
	cout << "\nPlease enter " << expense_list[i] << " expenses: $";
	cin >> expenses->housing;
	cout << "\nPlease enter " << expense_list[++i] << " expenses: $";
	cin >> expenses->utilities;
	cout << "\nPlease enter " << expense_list[++i] << " expenses: $";
	cin >> expenses->household_expenses;
	cout << "\nPlease enter " << expense_list[++i] << " expenses: $";
	cin >> expenses->transportation;
	cout << "\nPlease enter " << expense_list[++i] << " expenses: $";
	cin >> expenses->food;
	cout << "\nPlease enter " << expense_list[++i] << " expenses: $";
	cin >> expenses->medical;
	cout << "\nPlease enter " << expense_list[++i] << " expenses: $";
	cin >> expenses->insurance;
	cout << "\nPlease enter " << expense_list[++i] << " expenses: $";
	cin >> expenses->entertainment;
	cout << "\nPlease enter " << expense_list[++i] << " expenses: $";
	cin >> expenses->clothing;
	cout << "\nPlease enter " << expense_list[++i] << " expenses: $";
	cin >> expenses->miscellaneous;
}

void getBalance(MonthlyBudget * my_expenses, MonthlyBudget * budget)
{
	cout << "\n\nExpense Name\t\t" << "Budget" << setw(10) << "Expense" << setw(19) << "Difference\n\n";

	int i = 0;

	cout << setprecision(2) << fixed 
		 << expense_list[i] << "\t\t\t$" << budget->housing << "\t $" << my_expenses->housing << setw(10) << "$" << budget->housing - my_expenses->housing << endl;
	cout << expense_list[++i] << "\t\t$" << budget->utilities << "\t $" << my_expenses->utilities << setw(10) << "$" << budget->utilities - my_expenses->utilities << endl;
	cout << expense_list[++i] << "\t$" << budget->household_expenses << "\t $" << my_expenses->household_expenses << setw(10) << "$" << budget->household_expenses - my_expenses->household_expenses << endl;
	cout << expense_list[++i] << "\t\t$" << budget->transportation << "\t $" << my_expenses->transportation << setw(10) << "$" << budget->transportation - my_expenses->transportation << endl;
	cout << expense_list[++i] << "\t\t\t$" << budget->food << "\t $" << my_expenses->food << setw(10) << "$" << budget->food - my_expenses->food << endl;
	cout << expense_list[++i] << "\t\t\t$" << budget->medical << "\t $" << my_expenses->medical << setw(10) << "$" << budget->medical - my_expenses->medical << endl;
	cout << expense_list[++i] << "\t\t$" << budget->insurance << "\t $" << my_expenses->insurance << setw(10) << "$" << budget->insurance - my_expenses->insurance << endl;
	cout << expense_list[++i] << "\t\t$" << budget->entertainment << "\t $" << my_expenses->entertainment << setw(10) << "$" << budget->entertainment - my_expenses->entertainment << endl;
	cout << expense_list[++i] << "\t\t$" << budget->clothing << "\t $" << my_expenses->clothing << setw(10) << "$" << budget->clothing - my_expenses->clothing << endl;

	cout << "Total\t\t\t$" << budget->housing + budget->utilities + budget->household_expenses + budget->transportation + budget->food
		+ budget->medical + budget->insurance + budget->entertainment + budget->clothing;

	cout << " $" << my_expenses->housing + my_expenses->utilities + my_expenses->household_expenses + my_expenses->transportation + my_expenses->food
		+ my_expenses->medical + my_expenses->insurance + my_expenses->entertainment + my_expenses->clothing;

	cout << setw(10) << "$" << (budget->housing - my_expenses->housing) + (budget->utilities - my_expenses->utilities) + (budget->household_expenses - my_expenses->household_expenses)
		+ (budget->transportation - my_expenses->transportation) + (budget->food - my_expenses->food) + (budget->medical - my_expenses->medical)
		+ (budget->insurance - my_expenses->insurance) + (budget->entertainment - my_expenses->entertainment) + (budget->clothing - my_expenses->clothing);
}


