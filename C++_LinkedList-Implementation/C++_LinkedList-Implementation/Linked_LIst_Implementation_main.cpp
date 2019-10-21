//William Archbold
//14 October 2019
//based off of Data Structures mycodeschool
//https://www.youtube.com/watch?v=vcQIFT79_50&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=6&t=0s


#include <iostream>

using namespace std;

struct Node //4 bytes for data 4 bytes for next address total 8 bytes
{
	int data;
	Node* next;
};

struct Doubly_Node //12 bytes per node
{
	int data;
	Doubly_Node* next;
	Doubly_Node* previous;
};


void Insert(Node* &head, int x); //Node* Insert(Node* head, int x); return head
void Insert(Node* &head, int data, int n);
void Delete(Node* &head, int n);
void Reverse(Node* &head);
Node* ReverseRecursively(Node* head);
void Print(Node* head); //void Print(Node* head)
void PrintRecursively(Node* head);
void PrintReverseRecursively(Node* head);

Doubly_Node* GetNewNode(int x);
void InsertAtHead(Doubly_Node* &head, int x);
void InsertAtTail(Doubly_Node* &head, int x);
void PrintDoublyLinkedList(Doubly_Node* const &head);
void PrintDoublyLinkedListBackwards(Doubly_Node* const &head);

int main()
{
	Node* head_one = nullptr;

	Doubly_Node* doubly_head_one = nullptr;
	InsertAtHead(doubly_head_one, 1);
	InsertAtHead(doubly_head_one, 2);
	InsertAtHead(doubly_head_one, 3);
	InsertAtHead(doubly_head_one, 4);
	InsertAtHead(doubly_head_one, 5);
	InsertAtTail(doubly_head_one, 6);

	PrintDoublyLinkedList(doubly_head_one);

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

void Reverse(Node *& head)
{
	Node* current, *previous, *next;
	current = head;
	previous = nullptr;
	
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}

Node* ReverseRecursively(Node* head)
{
	if (head->next == NULL)
	{
		return head;
	}
	Node* new_location_of_head = ReverseRecursively(head->next);
	Node* p = head->next; //can also do head->next->next = head;
	p->next = head;
	head->next = nullptr;
	return new_location_of_head;
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

void PrintRecursively(Node * head)
{
	if (head)
	{
		cout << head->data << " ";
		PrintRecursively(head->next);
	}
	else
	{
		cout << endl;
	}
	
}

void PrintReverseRecursively(Node * head)
{
	if (head)
	{
		PrintReverseRecursively(head->next);
		cout << head->data << " ";
	}
	else
	{
		cout << endl;
	}
}

Doubly_Node * GetNewNode(int x)
{
	Doubly_Node* node = new Doubly_Node();
	node->data = x;
	node->next = nullptr;
	node->previous = nullptr;
	return node;
}

void InsertAtHead(Doubly_Node* &head, int x)
{
	Doubly_Node* temp = GetNewNode(x);
	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head->previous = temp;
		head = temp;
	}
}

void InsertAtTail(Doubly_Node *& head, int x)
{
	Doubly_Node* new_node = GetNewNode(x);
	if (head == nullptr)
	{
		head = new_node;
	}
	else
	{
		Doubly_Node* temp_ptr = head;
		while (temp_ptr->next)
		{
			temp_ptr = temp_ptr->next;
		}
		temp_ptr->next = new_node;
		new_node->previous = temp_ptr;
	}
	

}

void PrintDoublyLinkedList(Doubly_Node* const &head)
{
	Doubly_Node* node_ptr = head;
	cout << "\nList Forward: ";
	while (node_ptr)
	{
		cout << node_ptr->data << " ";
		node_ptr = node_ptr->next;
	}
	cout << endl;
}

void PrintDoublyLinkedListBackwards(Doubly_Node * const & head)
{
	Doubly_Node* node_ptr = head;
	if (node_ptr == nullptr) return;
	while (node_ptr->next)
	{
		node_ptr->next;
	}
	cout << endl << "List backwards: ";
	while (node_ptr)
	{
		cout << node_ptr->data << " ";
		node_ptr = node_ptr->next;
	}
	cout << endl;
}
