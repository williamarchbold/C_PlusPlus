//William Archbold
//Problem Source: leetcode.com

/*Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.
Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
nput: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
*/




#include <iostream>

using namespace std;

struct ListNode
{
	ListNode* next = nullptr;
	int value = 0;
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		int length = 0;
		ListNode *p = head; //set p to point to what head points to; address of what head points to stored
							//in p. 
		if (p==nullptr)
		{
			return nullptr;
		}
		do 
		{
			length++;
			p = p->next;
		} while (p);

		if (length == 0)
			return head;
		length /= 2;
		int i = 0; //counter to get to length
		//move p back to beginning to start moving to middle 
		p = head;
		while (p->next)
		{
			if (i == length)
			{
				break;
			}
			else
			{
				++i;
				p = p->next;
			}
		}
		return p;
	}
};

int main()
{
	const int length = 6; //compiler needs to know size at compile time
	ListNode array[length];
	for (size_t i = 0; i < length; i++)
	{
		array[i].value = i + 1;
		if (i < length-1)
		{
			array[i].next = &array[i + 1]; //Listnode pointer points to next Listnode. set pointer value to address of next thing in array
		}
	}

	Solution solution;
	ListNode* middleNode = solution.middleNode(&array[0]); // equivalent to (array) 

	if (middleNode)
	{
		cout << middleNode->value; 
	}
	else
	{
		cout << "NULL";
	}

	return 0;
}