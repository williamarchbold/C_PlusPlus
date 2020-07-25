#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string GetName() //auto is useful if change the return type.
{
	return "Cherno";
}

class Device {};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}
};

int main()
{
	int a = 5;
	auto b = a; //hover over and it shows b is an int

	auto c = GetName();

	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	for (std::vector<std::string>::iterator it = strings.begin(); //alternatively could use auto
		it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}

	using DeviceMap = const std::unordered_map<std::string, std::vector<Device*>>&; //alternate to auto that is less ambiguous

	DeviceManager dm;
	DeviceMap devices = dm.GetDevices();

	std::cin.get();
}