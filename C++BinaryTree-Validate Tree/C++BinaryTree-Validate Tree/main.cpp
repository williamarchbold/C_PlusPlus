/*
William Archbold
Problem Source: leetcode.com

Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

	2
   / \
  1   3
Input: [2,1,3]
Output: true
Example 2:
	5
   / \
  1   4
	 / \
	3   6
Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/


using namespace std;


//Definition for a binary tree node provided
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

	//   5
	//	/ \
	//  5  10
	//	  / \
	//	 7 	 12
	//      /
	//     4
	bool isValidBST(TreeNode* root) {

		//look at 1 node at a time
		if (root == nullptr)
			return true;
		if (!isSubTreeValid(root, root->left, false))
		{
			return false;
		}
		if (!isSubTreeValid(root, root->right, true))
		{
			return false;
		}
		if (!isValidBST(root->left))
			return false;
		if (!isValidBST(root->right))
			return false; 
		/*if ((root->left != nullptr) && !(root->left->val < root->val))
			return false;
		if ((root->right != nullptr) && !(root->right->val > root->val))
			return false;
		//recursively look at children of node
		*/

		return true;
	}
	bool isSubTreeValid(TreeNode* root, TreeNode *child_node, bool test_right)
	{
		//test for if root is a leaf
		if (child_node == nullptr)
		{
			return true;
		}
		const bool isValid = (test_right == (root->val < child_node->val));
		if (!isValid)
			return false;
		if (root->val == child_node->val)
			return false;
		/*{
			if (root->val >= child_node->val)
			{
				return false;
			}
		}
		//test right is false so testing to the left
		else
		{
			if (root->val <= child_node->val)
			{
				return false;
			}
		}*/
		if (!isSubTreeValid(root, child_node->left, test_right))
		{
			return false;
		}
		else if (!isSubTreeValid(root, child_node->right, test_right))
		{
			return false;
		}
		return true;
	}
};

int main()
{
	//   5
	//	/ \
	//  4  6
	//	  / \
	//	 3 	
	TreeNode* root = nullptr;
	TreeNode node1(5);
	root = &node1;
	TreeNode node2(4);
	node1.left = &node2;
	TreeNode node3(6);
	root->right = &node3;
	TreeNode node4(3);
	node3.left = &node4;

	Solution solution;
	bool result = solution.isValidBST(root);

	return 0;
}