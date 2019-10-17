//William Archbold
//14 October 2019
//based off of Data Structures mycodeschool
//https://www.youtube.com/watch?v=vcQIFT79_50&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=6&t=0s


#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};


void Insert(Node* &head, int x); //Node* Insert(Node* head, int x); return head
void Insert(Node* &head, int data, int n);
void Delete(Node* &head, int n);
void Print(Node* head); //void Print(Node* head)

int main()
{
	Node* head_one = nullptr;
	
	Insert(head_one, 2);
	Insert(head_one, 1);
	Delete(head_one, 2);
	Print(head_one);

	return 0;
}

void Insert(Node* &head, int x)
{
	Node* new_node = new Node();
	new_node->data = x;
	new_node->next = nullptr; 
	
	if (head != nullptr)
	{
		new_node->next = head; //point temp's new node to what head points to
	}
	head = new_node; //head now points to what temp points to which is the new first now



}

void Insert(Node* &head, int data, int n)
{
	//if no elements in list, call Insert(x)
	if (head == nullptr)
	{
		cout << "\nList is empty. Inserting at head...\n";
		Insert(head, data);
		return;
	}
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;

	if (n == 1)
	{
		new_node->next = head;
		head = new_node;
		return;
	}
	Node* temp1 = head;
	//say n is 4. i=1,temp1 pts to node 2, i=2, temp1 pts to node3
	for (int i = 0; i < n-2; i++) //start at first node go to n-1 nodes
	{
		temp1 = temp1->next; 
	}
	new_node->next = temp1->next; //new node now points to what node 3 points to
	temp1->next = new_node; //node 3 now points to new node



	
}

void Delete(Node *& head, int n)
{
	Node* temp_previous = head;
	

	if (n == 1)
	{
		head = temp_previous->next;
		delete temp_previous;
		return;
	}

	//n = 5. i=0,temp_pre pts to 2
	for (int i = 0; i < n - 2; i++)
	{
		if (temp_previous->next!=nullptr)
		{
			temp_previous = temp_previous->next;
		}
		else
		{
			cout << "\nNo node at element " << n << endl;
			return;
		}
	}
	if (temp_previous->next !=nullptr)
	{
		Node* temp_current = temp_previous->next;
		temp_previous->next = temp_current->next;
		temp_current->next = nullptr;
		delete temp_current;
	}
	else
	{
		cout << "\nNo node at element " << n << endl;
		return;
	}
}

void Print(Node* head)
{
	Node* temp = head; //use temp because we don't want to loose head
	printf("\nList is: ");
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
