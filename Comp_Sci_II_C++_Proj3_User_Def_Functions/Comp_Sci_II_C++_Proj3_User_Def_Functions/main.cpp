#include "sequence3.h"
#include <vector>
#include <iostream>

bool checkSequence(main_savitch_5::sequence& s, std::vector<double> reference) {
	//int sz = test.size();
	//double e = test[1];

	if (s.size() != reference.size()) {
		return false;
	}

	s.start();
	for (int i = 0; i < s.size(); i++)
	{
		if (s.current() != reference[i]) {
			return false;
		}
		s.advance();
	}

	return true;

	/*
	for (int i = 0; i < reference.size(); i++) {
		cout << reference[i];
	}
	for (std::vector<double>::iterator it = reference.begin(); it != reference.end(); it++) {
		cout << *it;
	}
	*/

}

void testAttach() {
	main_savitch_5::sequence s;
	std::vector<double> v;

	for (int x = 0; x < 10; ++x) {
		s.attach(x);
		v.push_back(x);
	}

	std::cout << std::boolalpha << checkSequence(s, v);
}

void testInsert() {
	main_savitch_5::sequence s;
	std::vector<double> v;

	for (int i = 0; i < 10; i++)
	{
		s.insert(i);
		v.push_back(i);
	}

	std::reverse(v.begin(), v.end());
	std::cout << std::boolalpha << checkSequence(s, v);
}

int main()
{

	main_savitch_5::sequence will;

	will.insert(5);
	will.attach(4);
	will.start();
	will.advance();

	




	return 0;
}