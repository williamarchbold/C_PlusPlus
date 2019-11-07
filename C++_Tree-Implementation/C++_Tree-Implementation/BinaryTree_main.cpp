//William Archbold
//based off of 
//https://www.youtube.com/watch?v=H5JubkIy_p8&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=26

struct Node
{
	int data; 
	Node* left;
	Node* right;

	Node(int x)
	{
		data = x;
		left = nullptr;
		right = nullptr;
	}
};

#include <algorithm>
#include <iomanip>

using namespace std;

Node* Insert(Node * &root, int x);
void InsertNode(int x);
void Insert(Node* &root, Node* &new_node);
bool Search(Node * &root, int x);
Node* FindMin(Node * & root);
Node* FindMax(Node * & root);
int FindHeight(Node * & root);
bool isBinarySearchTree(Node* root);
bool isBstUtility(Node * root, int min_value, int max_value);
Node* Delete(struct Node *root, int data);

int main()
{
	Node* rootPtr = nullptr;
	Insert(rootPtr, 10);
	Insert(rootPtr, 8);
	Insert(rootPtr, 6);
	Insert(rootPtr, 9);
	Insert(rootPtr, 5);
	Insert(rootPtr, 15);
	Insert(rootPtr, 11);
	Insert(rootPtr, 12);
	Node* min_node = FindMin(rootPtr);
	int height = FindHeight(rootPtr);
	rootPtr = Delete(rootPtr, 15);
	return 0;
}

Node * Insert(Node * &root, int x)
{
	//base case
	if (root == nullptr)
	{
		Node* new_node = new Node(x);
		root = new_node;
	}
	else if (root->data >= x)
	{
		root->left = Insert(root->left, x);
	}
	else if (root->data < x)
	{
		root->right = Insert(root->right, x);
	}
	
	return root;
}

void InsertNode(int x)
{
	Node* node = new Node(x);

}

void Insert(Node *& root, Node *& new_node)
{
	if (root == nullptr)
	{
		root = new_node;
	}
	else if (root->data >= new_node->data)
	{
		Insert(root->left, new_node->data);
	}
	else if (root->data < new_node->data)
	{
		Insert(root->right, new_node);
	}
}

bool Search(Node *& root, int x)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == x)
	{
		return true;
	}
	else if (x <= root->data) 
	{
		return Search(root->left, x);
	}
	else
	{
		return Search(root->right, x);
	};
}

Node* FindMin(Node *& root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->left == nullptr)
	{
		return root;
	}
	else
	{
		return FindMin(root->left);
	}

}

Node* FindMax(Node *& root)
{

	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->right == nullptr)
	{
		return root;
	}
	else
	{
		return FindMax(root->right);
	}

}

int FindHeight(Node *& root)
{
	if (root == nullptr)
	{
		return -1; // minus one because ptr is at 1 level below the leaf
	}
	return max(FindHeight(root->left), FindHeight(root -> right)) + 1; //height starts at 0 goes to 1,2,3,4
}

bool isBinarySearchTree(Node * root)
{
	return isBstUtility(root, INT_MIN, INT_MAX);
}

bool isBstUtility(Node * root, int min_value, int max_value)
{
	if (root == nullptr)
	{
		return true;
	}
	if (root->data <= min_value && root->data > max_value 
		&& isBstUtility(root->left, min_value, root->data)
		&& isBstUtility(root->right, root->data, max_value))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Node * Delete(Node * root, int data)
{
	if (root == nullptr)
	{
		return root;
	}
	else if (data < root->data) 
	{
		root->left = Delete(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = Delete(root->right, data);
	}
	else //found data
	{
		//Case 1: no child
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}//Case 2: 1 child
		else if (root->left == nullptr)
		{
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr)
		{
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		else //case 3: two children
		{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}			
	return root;
}
