// FILE: pqueue2.cpp
// William Archbold
// IMPLEMENTS: PriorityQueue (See pqueue2.h for documentation.)
// IMPLEMENTED BY: Michael Main (main@colorado.edu)
// Modified by Steve Kaminski (steve.kaminski@frontrange.edu)

// INVARIANT for the PriorityQueue Class:
//   1. The member variable many_items is the number of items in the
//      PriorityQueue.
//   2. The items themselves are stored in the member variable heap,
//      which is a partially filled array organized to follow the usual
//      heap storage rules from Chapter 11 of the class notes.
// NOTE: Private helper functions are implemented at the bottom of this
// file along with their precondition/postcondition contracts.
 
#include <cassert>    // Provides assert function
#include <iostream>  // Provides cin, cout
#include <iomanip>   // Provides setw
#include <cmath>      // Provides log2
#include "pqueue2.h"

#include <memory>
using namespace std;

PriorityQueue::PriorityQueue( )
{
	// To be completed by the student
	many_items = 0;

	//memset
	memset(heap, 0, sizeof(OneItemInfo) * CAPACITY);
}

void PriorityQueue::insert(const Item& entry, unsigned int priority)
{

	if (many_items < CAPACITY - 1)
	{
		//place new item in the first available location
		heap[many_items + 1].data = entry;
		heap[many_items + 1].priority = priority;
		many_items++;
		
		//while the new entry's parent is less than the new entry, swap entry with parent
		int i = many_items;
		while (i > 1 && (parent_priority(i) < heap[i].priority))
		{
			swap_with_parent(i);
 			i = parent_index(i);
		}
	}
	else
	{
		cout << "Not enough space to insert entry.";
	}


}

PriorityQueue::Item PriorityQueue::get_front( )
{
	if (this->is_empty()) throw "size( ) <= 0";

	//Copy the entry at the root of the heap to the variable that is used to
	//return a value
	OneItemInfo Temp;
	Temp.data = heap[1].data;
	Temp.priority = heap[1].priority;
	
	//Copy the last entry in the deepest level to the root and then take this 
	//last noe out of the tree. 
	heap[1].data = heap[many_items].data;
	heap[1].priority = heap[many_items].priority;
	many_items--; 
	
	//while out of place entry is less than one of its children, 
	//swap theout of place entry with its highest child
	int i = 1;
	while (heap[i].priority < big_child_priority(i))
	{
		i = big_child_index(i);
		swap_with_parent(i);
	}

	return Temp.data;
}

bool PriorityQueue::is_leaf(size_t i) const
// Precondition: (i < many_items)
// Postcondition: If heap[i] has no children in the heap, then the function
// returns true. Otherwise the function returns false.
{
	if (i * 2 >= many_items)
		return true;
	else
		return false;
}

size_t PriorityQueue::parent_index(size_t i) const
// Precondition: (i > 0) && (i < many_items)
// Postcondition: The return value is the index of the parent of heap[i].
{
	if (i % 2 == 0)
	{
		//even 
		return i / 2;
	}
	else
	{
		//odd
		return (i - 1) / 2;
	}
}

unsigned int PriorityQueue::parent_priority(size_t i) const
// Precondition: (i > 0) && (i < many_items)
// Postcondition: The return value is the priority of the parent of heap[i].
{
	
	return heap[parent_index(i)].priority;

}

size_t PriorityQueue::big_child_index(size_t i) const
// Precondition: !is_leaf(i)
// Postcondition: The return value is the index of one of heap[i]'s children.
// This is the child with the larger priority.
{
	if ((i*2)+1 > many_items) // does it exist?
	{
		return i * 2;
	}
	else
	{
		if (heap[i * 2].priority < heap[i * 2 + 1].priority)
			return i * 2 + 1;
		else
		{
			return i * 2;
		}
	}
}

unsigned int PriorityQueue::big_child_priority(size_t i) const
// Precondition: !is_leaf(i)
// Postcondition: The return value heap[big_child_index(i)].priority
{
	return  heap[big_child_index(i)].priority;
}

void PriorityQueue::swap_with_parent(size_t i)
// Precondition: (i > 0) && (i < many_items)
// Postcondition: heap[i] has been swapped with heap[parent_index(i)]
{
	std::swap(heap[i], heap[parent_index(i)]);
}

size_t integerLog2(size_t arg) {
	size_t logarithm = 0;
	while (arg >>= 1) ++logarithm;
	return logarithm;
}

void putSpaces(int spaces, std::ostream& str = std::cout) {
	while (spaces--)
		str << ' ';
}

void PriorityQueue::print_tree(const char message[ ], size_t i) const
// Postcondition: If the message is non-empty, then that has been written
// to cout. After the message, the portion of the heap with root at node
// node i has been written to the screen. Each node's data is indented
// 4*d, where d is the depth of the node.
// NOTE: The default argument for message is the empty string, and the
// default argument for i is zero. For example, to print the entire
// tree of a PriorityQueue p, with a message of "The tree:", you can call:
//     p.print_tree("The tree:");
// This call uses i=0, which prints the whole tree.
{
	
	if (i == 0) i = 1;

	if (message)
		std::cout << message << std::endl;

	putSpaces(4 * integerLog2(i));
	std::cout << heap[i].data << "(priority " << heap[i].priority << ")" << endl;

	if (!(is_leaf(i))) {
		print_tree(nullptr, i * 2);
		print_tree(nullptr, i * 2 + 1);
	}
}