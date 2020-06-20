#include <iostream>
#include <string>

class String
{
private:
	char* m_Buffer; //string of chars
	unsigned int m_Size; //keep track of size

public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1]; //add 1 from null termination 
		//for (int i = 0; i < m_Size; i++)
		//{
		//	m_Buffer[i] = string[i];
		//}
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;  //manually add null termination char at end
	}

	String(const String& other)
		: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()
	{
		delete[] m_Buffer;
	}
	
	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const String& string) //always pass objects by const reference! 
{
	std::cout << string << std::endl;
}

int main()
{
	String string = "William";
	String second = string;

	second[2] = 'a';

	std::cout << string << std::endl;
	std::cout << second << std::endl;
	std::cin.get();
}