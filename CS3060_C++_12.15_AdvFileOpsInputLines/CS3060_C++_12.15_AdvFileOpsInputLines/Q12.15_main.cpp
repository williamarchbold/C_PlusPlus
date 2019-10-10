/*
William Archbold
CS 3060 Obj Oriented Programming C++
9 Oct 2019
*/

/*
Q12.15 Write a program that reads a file, text.txt's contents and calculate 
the average number of words per sentence. The text in the file is stored
as one sentence per line. 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int total_words = 0, total_lines = 0;
	string input;
	fstream file;
	file.open("text.txt", ios::in);
	if (file.fail())
	{
		cout << "Failed to open file!\n";
	}
	else 
	{
		while (getline(file, input)) 
		{
			cout << input << endl;

			total_lines++;

			int spaces = 0;

			for (int i = 0; i < input.length(); i++)
			{
				if (isspace(input.at(i)))
					spaces++;
			}
			total_words += spaces + 1;
			cout << "Line: " << total_lines << "\nWords: " << spaces + 1 << endl;
		}
		double average = total_words / total_lines;
		cout << "\n\nTotal words: " << total_words;
		cout << "\nTotal lines: " << total_lines;
		cout << "\nAverage words per line: " << setprecision(2) << average;
	}

	file.close();

	return 0;
}

