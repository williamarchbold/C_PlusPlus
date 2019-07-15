// FILE: queueTest.cxx 
// Written by: Steve Kaminski
// A general test program to exercise implementations of the queue class

#include "queue3.h"    // Provides the circular linked-list queue
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "*************************************";
    cout << "\nCSC-161 Homework Seven Solution\n";
    cout << "*************************************";
    // Create a queue and add some values to it
	main_savitch_8C::queue<string> testQueue1;
    testQueue1.push("Testing...");
    testQueue1.push("One...");
    testQueue1.push("Two...");
    testQueue1.push("Three...");
    testQueue1.push("Four...");
    // Demonstrate the the size function works
    cout << "\nNumber of items in first Queue: " << testQueue1.size() << endl;
    // Demonstrate the copy constructor
	main_savitch_8C::queue<string> testQueue2(testQueue1);
    cout << "Number of items in copied Queue: " << testQueue2.size() << endl;
    // Exercise front, pop and empty
    cout << "\nValues in first queue: " << endl;
    while(!testQueue1.empty())
    {
        cout << testQueue1.front();
        testQueue1.pop();
    }
    cout << endl;
    // Exercise the second queue
    for (; testQueue2.size() > 1; testQueue2.pop());
    testQueue2.push("Five...");
    testQueue2.push("Six...");
    testQueue2.push("Seven...");
    testQueue2.push("Eight...");
    cout << "\nUpdated size of second Queue: " << testQueue2.size() << endl;
    cout << "\nValues in second queue: " << endl;
    while(!testQueue2.empty())
    {
        cout << testQueue2.front();
        testQueue2.pop();
    }
    cout << endl << endl;

    cout << "*************************************"<< endl;
    cout << "End of Homework Seven Solution" << endl;
    cout << "*************************************" << endl;
    system("Pause");
}

