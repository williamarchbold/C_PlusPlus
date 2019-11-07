//William Archbold
//B Tree Implementation based off of
//https://www.geeksforgeeks.org/introduction-of-b-tree-2/

#include <iostream>

using namespace std;

class Node
{
	int* key_array; //array of keys
	int t;	//minimum degree (defines range of number of keys)
	Node** children; //array of child pointers to other nodes
	int num_keys; 
	bool is_leaf; //true when node is a leaf; otherwise false

public:
	Node(int min_degree, bool leaf);

	void Traverse();

	Node* Search(int k); //function to search a subtree for the key 

	void InsertNonFull(int k);

	void SplitChild(int i, Node* y);

friend class BTree;
};

class BTree
{
	Node* root; //pointer to root node
	int t; //min degree

public: 
	//Constructor 
	BTree(int degree)
	{
		root = nullptr; t = degree;
	}

	void Traverse()
	{
		if (root != nullptr)
			root->Traverse();
	}

	Node* Search(int k)
	{
		return (root == nullptr) ? NULL : root->Search(k);
	}

	void Insert(int k);
};
	
Node::Node(int min_degree, bool leaf)
{
	t = min_degree; is_leaf = leaf; //copy the min degree and leaf property
	
	//allocate property for max number of possible keys and child pointers
	key_array = new int[2 * t - 1];
	children = new Node*[2 * t];

	//initialize number of keys to zero 
	num_keys = 0;
}

void Node::Traverse()
{
	//n keys and n+1 children, traverse through n keys and first n children 
	int i;
	for (i = 0; i < num_keys; i++)
	{
		//if this is not a leaf, then before printing key[i], 
		//traverse the subtree rooted with child [i]
		if (is_leaf == false)
		{
			children[i]->Traverse();
		}
	}
}

Node * Node::Search(int k)
{
	//find the first key greater than or equal to k 
	int i = 0;
	while (i < num_keys && k > key_array[i])
	{
		i++;
	}
	//if found key is equal to k, return this node; 
	if (key_array[i] == k)
	{
		return this;
	}
	//if the key is not found and this is a leaf node
	else if (is_leaf)
	{
		return nullptr;
	}
	else
	{
		return children[i]->Search(k);
	}
}

//utility function to split child y of this node
//note that y must be full when this function is called
void Node::SplitChild(int i, Node * y)
{
	//create new node that will store (t-1) keys of y
	Node* z = new Node(y->t, y->is_leaf);
	z->num_keys = t - 1;

	//copy the last (t-1) keys of y to z
	for (int i = 0; i < t-1; i++)
	{
		z->key_array[i] = y->key_array[i + t];
	}

	//copy last t children of y to z
	if (y->is_leaf == false)
	{
		for (int i = 0; i < t; i++)
		{
			z->children[i] = y->children[i + t];
		}
	}
	//reduce the number of keys in y
	y->num_keys = t - 1;

	//since this node is going to have a new child, 
	//create space of new child
	for (int j = num_keys; j >= i+1; j--)
	{
		children[j + 1] = children[j];
	}

	//link new child to this node
	children[i + 1] = z; 

	//One key of y will move to this node. Find location of 
	//new key and move all greater keys one space ahead
	for (int j = 0; j >= i; j--)
	{
		key_array[j + 1] = key_array[j];
	}

	//Copy the middle of key y to this node
	key_array[i] = y->key_array[t - 1];

	//Increment count of keys in this node
	n = n + 1; 
}

void BTree::Insert(int k)
{
	//if tree is empty
	if (root == nullptr)
	{
		//allocate memory for root
		root = new Node(t, true);
		root->key_array[0] = k; //insert key
		root->num_keys = 1; 
	}
	else //if tree isn't empty
	{
		//if root is full then tree will grow in height
		if (root->num_keys == 2*t -1 )
		{
			//allocate memory for a new root
			Node* s = new Node(t, false);

			//make old root child of new root
			s->children[0] = root;

			s->s
		}

	}
}
