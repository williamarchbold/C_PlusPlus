//William Archbold
//Problem Source: leetcode.com

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>

using namespace std;


/**
 * Definition for singly-linked list - provied by LeetCode
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//personal implementation of ListNode
struct ListNode
{
	int val;
	ListNode* next;
	
	ListNode()
	{
		val = 0;
		next = nullptr;
	}

	ListNode(int x)
	{
		val = x;
		next = nullptr;
	};
};



class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		
	// 243
	//+564
	//____
	// 807

	// 18 - l1
	//+ 1  - 12
	//____
	// 19
	int total, ones_digit_value;
	bool carryover = false;

	ListNode* head = nullptr;
	ListNode* current_node = nullptr;
	//for each node pair in the lists (assuming lists are of same length)
	while ((l1 || l2) || carryover)
	{
		//get values from two linked lists at the node
		//add the two values
		total = 0;
		if (carryover)
		{
			total += 1;
			carryover = false;
		}
		if (l1 || l2)
		{
			if (l1)
			{
				total += l1->val;
			}
			if (l2)
			{
				total += l2->val;
			}
				
			carryover = (total >= 10);
			if (carryover)
			{
				total = total % 10;
			}
			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}			
		}
		ListNode* new_node = new ListNode(total);
		if (!head)
		{
			head = new_node;
			current_node = head;
		}
		else
		{
			current_node->next = new_node;
			current_node = current_node->next;
		}
			
	}

	ListNode* answer;
	return head;
}
};

void printList(ListNode* head) {
	while (head)
	{
		cout << head->val;
		head = head->next;
	}
}
int main(int argc, char*argv)
{
	const int length = 3; //given from tested input
	/*// 243
	ListNode one_two(3);
	ListNode one_one(4);
	one_one.next = &one_two;
	ListNode one_zero(2);
	one_zero.next = &one_one;

	// 243
	//+564
	//____
	// 807

	// 564
	ListNode two_two(4);
	ListNode two_one(6);
	two_one.next = &two_two;
	ListNode two_zero(5);
	two_zero.next = &two_one;*/

	ListNode one_zero(5);
	ListNode two_zero(5);

	Solution solution;

	ListNode* answer = solution.addTwoNumbers(&one_zero, &two_zero);
	printList(answer);

	return 0;
}
