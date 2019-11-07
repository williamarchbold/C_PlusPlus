//William Archbold
//Hashing Implementation 10/26/2019
//implementation of https://www.geeksforgeeks.org/c-program-hashing-chaining/

#include <iostream>
#include <list>
using namespace std;

class Hash
{

	int BUCKET; //no of buckets
	list<int> *table; //pointer to a future dynamically allocated array

public:
	Hash(int b);

	void InsertItem(int key);
	void DeleteItem(int key);
	int HashFunction(int x);
	void DisplayHash();

};

Hash::Hash(int b) //parameter will be size of bucket
{
	BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::InsertItem(int key)
{
	int index = HashFunction(key);
	table[index].push_back(key); //push_back inserts at end of list 
									//at that index
}

void Hash::DeleteItem(int key)
{
	int index = HashFunction(key);
	list<int>::iterator i;
	for  (i = table[index].begin(); i != table[index].end(); i++)
	{
		if (*i == key)
			break;
	}

	if (i != table[index].end())
	{
		table[index].erase(i);
	}
}

int Hash::HashFunction(int x)
{
	return (x % BUCKET);
}

void Hash::DisplayHash()
{
	for (int i = 0; i < BUCKET; i++)
	{
		cout << i; 
		for (auto x : table[i]) //for every linked list node in table at index i
		{
			cout << " --> " << x;
		}
		cout << endl;
	}
}

int main()
{
	int a[] = { 15, 11, 27, 8, 12 };
	int n = sizeof(a) / sizeof(a[0]);

	Hash h(7); //7 # of buckets in hash table
	for (int i = 0; i < n; i++)
	{
		h.InsertItem(a[i]);
	}

	h.DisplayHash();

	return 0;
}

