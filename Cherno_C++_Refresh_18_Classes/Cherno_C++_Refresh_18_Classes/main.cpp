#include <iostream>


class Player { //default classes members are private.. struct default is all public

public:
	int x, y;
	int speed;

	void Move(int xa, int ya) {
		x += xa * speed;
		y += ya * speed;
	}
};

//structs exist to maintain backwards compatibility with C	

//could write #define struct Class .... but creates possible private public problems
//structs don't handle inheritance well	like classes do. will get a warning of weird inheritance 
//use structs for very very basic things 

class Log {
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
private:
	int m_LogLevel = LogLevelInfo;
public:
	void SetLevel(int level) {
		m_LogLevel = level;
	}

	void Error(const char* message) {
		if (m_LogLevel >= LogLevelError)
			std::cout << "[ERROR]:" << message << std::endl;
	}

	void Warn(const char* message) {
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[WARNING]:" << message << std::endl;
	}

	void Info(const char* message) {
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[INFO]:" << message << std::endl;
	}

};

struct Entity
{
	static int x, y;

	void Print() { //bad idea to make this class static. if make static, best to move to outside class
		std::cout << x << ", " << y << std::endl;
	}

};

static void Print(Entity e) {
	std::cout << e.x << ", " << e.y << std::endl;
}

int Entity::x;
int Entity::y; //syntatically better way to set attributes


int s_variable = 10; //this variable is in the Static.cpp file. unless one is other is static, will get a linker error. need to add extern 	 

extern int s_variable_two; 

extern int s_variable_three; 

int main() {

	std::cout << s_variable_three << std::endl;

	Player player;
	player.Move(1, -1);

	Entity e;
	e.x = 2; //not written correctly because these will just be modified a few lines down. 
	e.y = 3; //not unique to class instance named e

	Entity e_one;
	Entity::x = 5;
	Entity::y = 7;

	e.Print();
	e_one.Print();

	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.Warn("hello");
	std::cin.get();
}