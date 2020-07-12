//https://www.youtube.com/watch?v=L-hnA82JsEM


#include <iostream>
#include <stdio.h>
#include <sqlite3.h>

static int createDB(const char* s);
static int createTable(const char* s);
static int insertData(const char* s);

int main()
{
	const char* dir = "$(SolutionDir)\\STUDETS.db";
	sqlite3* DB;
	createDB(dir);
	createTable(dir);
	insertData(dir);
}

static int createDB(const char* s)
{
	sqlite3* DB;
	int exit = 0;

	exit = sqlite3_open(s, &DB);
	
	sqlite3_close(DB);

	return 0;
}

static int createTable(const char* s)
{
	sqlite3* DB;

	std::string sql = "CREATE TABLE IF NOT EXISTS GRADES("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"NAME		TEXT NOT NULL, "
		"LNAME		TEXT NOT NULL, "
		"AGE		INT NOT NULL, "
		"ADDRESS	CHAR(50), "
		"NAME		TEXT NOT NULL, "
		"GRADE		CHAR(1) );";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		char* messageError;

		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

		if (exit != 0) {
			std::cerr << "Error Create Table" << std::endl;
		}
		else
			std::cout << "Table created Successfully" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return 0;
}

int insertData(const char* s)
{
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);

	std::string sql("INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Alice', 'Chapa', 35, 'Tampa', 'A');"
		"INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Bob', 'Lee', 35, 'Dallas', 'B');"
		"INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Fred', 'Cooper', 20, 'New York', 'A');"
	);

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(messageError);
	}

	return 0;
}

