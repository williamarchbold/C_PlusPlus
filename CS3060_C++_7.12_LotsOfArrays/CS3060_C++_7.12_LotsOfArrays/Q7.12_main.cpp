/*
William Archbold
CS 3060 Obj Oriented Programming C++
14 Sep 2019
*/

/*
Q7.12 Write a program that uses an array of string objects to hold the five students' names,
an array of five characters to hold the five students' grades, five arrays of four doubles
to hold each student's set of test scores. 
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_SCORES = 4;

void getNamesAndScores(string names[NUM_STUDENTS], double scores[NUM_STUDENTS][NUM_SCORES]);
void getAveragesAndGrades(const string names[NUM_STUDENTS], char grades[NUM_STUDENTS], const double scores[NUM_STUDENTS][NUM_SCORES]);
char calcGrade(double);

int main(int argc, char* argv[])
{
	string names[NUM_STUDENTS];
	char grades[NUM_STUDENTS];
	double scores[NUM_STUDENTS][NUM_SCORES];

	getNamesAndScores(names, scores);

	getAveragesAndGrades(names, grades, scores);

	return 0;
}

void getNamesAndScores(string names[NUM_STUDENTS], double scores[NUM_STUDENTS][NUM_SCORES])
{
	for (int current_student = 0; current_student < NUM_STUDENTS; current_student++)
	{
		cout << "\n\nPlease enter student " << current_student + 1 << "'s name: ";
		cin >> names[current_student];
		double score; 
		for (int current_score = 0; current_score < NUM_SCORES; current_score++)
		{
			cout << "\nPlease enter " << names[current_student] 
				<< "'s test " << current_score + 1 
				<< " score: ";
			cin >> score;
			while (score < 0)
			{
				cout << "\nInvalid. Please enter " << names[current_student]
					<< "'s test " << current_score + 1
					<< " score: ";
				cin >> score;
			}
			scores[current_student][current_score] = score;
		}
	}
}

void getAveragesAndGrades(const string names[NUM_STUDENTS], char grades[NUM_STUDENTS], const double scores[NUM_STUDENTS][NUM_SCORES])
{
	for (int current_student = 0; current_student < NUM_STUDENTS; current_student++)
	{
		double total_points = 0;
		for (int current_score = 0; current_score < NUM_SCORES; current_score++)
		{
			total_points += scores[current_student][current_score];
		}

		grades[current_student] = calcGrade(total_points);

		cout << "\nStudent " << names[current_student] << "'s average was " << setprecision(2) << fixed 
			<< total_points / NUM_SCORES
			<< ", which equates to grade " << grades[current_student] << endl;
	}
}

char calcGrade(double total_score)
{
	int average_score = total_score / NUM_SCORES;
	

	switch (average_score / 10)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			return 'F';
		case 6:
			return 'D';
		case 7:
			return 'C';
		case 8:
			return 'B';
		default:
			return 'A';
	};
}
