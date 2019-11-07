//William Archbold
//21 October 2019
//based off of Data Structures mycodeschool
//https://www.youtube.com/watch?v=MuwxQ2IB8lQ&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=16

#include <iostream>

using namespace std;

struct Node //4 bytes for data 4 bytes for next address total 8 bytes
{
	int data;
	Node* next;

	Node(int x) 
	{
		data = x;
		next = nullptr
	}
};

void Push(Node* &head, int x);
void Pop(Node* &head);
int Top(Node* const &head);
bool IsEmpty(Node* const &head);

int main()
{
	return 0;
}

void Push(Node * & head, int x)
{
	Node* new_node = new Node(x);
	if (IsEmpty(head))
	{
		head = new_node;
	}
	else
	{
		new_node = head;
		head = new_node;
	}
}

void Pop(Node * & head)
{
	Node* temp_ptr;
	if (IsEmpty(head))
	{
		cout << "\n Empty stack!\n";
	}
	else
	{
		temp_ptr = head;
		head = head->next;
		delete temp_ptr;
	}
}

int Top(Node * const & head)
{
	if (IsEmpty(head))
	{
		cout << "\n Empty stack!\n";
		return -1;
	}
	else
	{
		return head->data;
	}
}

bool IsEmpty(Node * const & head)
{
	if (head)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
