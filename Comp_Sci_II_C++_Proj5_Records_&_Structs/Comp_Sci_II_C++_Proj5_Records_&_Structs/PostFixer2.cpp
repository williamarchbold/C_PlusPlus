//William Archbold
//Lesson 6 Homework 
//05 Oct 2017

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cctype>
#include "stack2.h"

using namespace std;

//PROTOTYPES
void evaluateExpression(ifstream& inputFile, main_savitch_7B::stack<double> stack);


int main()
{
	bool expressionOk;
	main_savitch_7B::stack<double> stack;
	ifstream inFile;

	inFile.open("HomeworkSixInput.txt");

	if (!inFile)
	{
		cout << "Cannot open file. Program terminates" << endl;
		return 1;
	}

	ExpressionResult evaluateExpression(Expression e);

	using Expression = std::list<ExpressionToken>;
	using ExpressionToken = std::variant<double, Operator>;
	enum class Operator { PLUS, MINUS, TIMES, DIVIDE };

	while (inFile)
	{
		Expression e = readExpression();
		//evaluateExpression(inFile, stack);
		ExpresionResult r = evaluateExpression(e);
		printExpressionResult(r);
	}


	return 0;
}

void evaluateExpression(ifstream& inputFile, main_savitch_7B::stack<double> stack)
{
	//while not the end of the line
	//if input is a number store in stack
	//read next input
	//if next input is a operation, pull 2 items out of stack


	double number = 0, operand1 = 0, operand2 = 0;
	char ch;
	stringstream text;

	while (inputFile && inputFile.peek() != '\n')
	{
		auto nextCharacter = inputFile.peek();
		if (isdigit(nextCharacter))
		{
			inputFile >> number;

			text << number << ' ';
			stack.push(number);
		}
		else if (strchr("+-*/", nextCharacter))
		{
			inputFile.ignore();
			text << static_cast<char>(nextCharacter) << ' ';

			operand2 = stack.top();
			stack.pop();
			operand1 = stack.top();
			stack.pop();
			switch (nextCharacter)
			{
			case '+': stack.push(operand1 + operand2); break;
			case '-': stack.push(operand1 - operand2); break;
			case '*': stack.push(operand1*operand2); break;
			case '/': stack.push(operand1 / operand2);
			}
		}
		else
		{
			inputFile.ignore();
		}
	}
	inputFile.ignore();
	if (!stack.empty())
	{
		cout << text.str() << "is equal to " << stack.top() << '\n';
	}

	return;
}