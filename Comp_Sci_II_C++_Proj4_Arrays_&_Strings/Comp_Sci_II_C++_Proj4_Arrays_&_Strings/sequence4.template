#ifndef H_SEQUENCE4_TEMPLATE_H
#define H_SEQUENCE4_TEMPLATE_H

//Willliam Archbold C++ II 30 SEP 2017

//INVARIANT OF CLASS 'sequence4.h'
//1. Head pointer must point to the first node in the set of links or point to null if there are no items in the set of links
//2. Tail pointer must point to the last node in the set of links or point to null if there are no items in the set of links   
//3. The cursor will point to the current item in the set if a current item is selected
//4. The precursor will point to the node prior to the current node unless the current item points to the head pointer in
//   which case the precursor will point to null
//5. Many_nodes is the number of nodes in the set of links



#include <ostream>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "node2.h"
#include "sequence4.h"


namespace main_savitch_6B
{
	//CONSTRUCTORS
	template <class Item>
	sequence<Item>::sequence()
	{
		head_ptr = nullptr;
		tail_ptr = nullptr;
		cursor = nullptr;
		many_nodes = 0;
	}

	template <class Item>
	sequence<Item>::sequence(const sequence& source)
	{
		copy_helper(source);
	}

	//DESTRUCTORS
	template <class Item>
	sequence<Item>::~sequence()
	{
		list_clear(head_ptr);
		many_nodes = 0;
	}


	//CONSTANT MEMBER FUNCTIONS

	template <class Item>
	Item sequence<Item>::current() const
	{
		return cursor->data();
	}

	template <class Item>
	bool sequence<Item>::is_item() const
	{
		return cursor != nullptr;
	}

	template <class Item>
	void sequence<Item>::copy_helper(const sequence& source)
	{
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;

		cursor = nullptr;
		precursor = nullptr;

		for (node<Item> *source_ptr = source.head_ptr,
			*target_ptr = head_ptr;

			source_ptr != nullptr;

			source_ptr = source_ptr->link(),
			target_ptr = target_ptr->link())
		{
			if (source_ptr == source.cursor)
			{
				cursor = target_ptr;
				break;
			}
			precursor = target_ptr;
		}
	}

	
	//MODIFICATION MEMBER FUNCTIONS
	
	template <class Item>
	void sequence<Item>::start()
	{
		cursor = head_ptr;
		precursor = NULL;
	}

	template <class Item>
	void sequence<Item>::advance()
	{
		precursor = cursor;
		cursor = cursor->link();
	}

	template <class Item>
	void sequence<Item>::insert(const Item& entry)
	{
		//if there are no items in sequence
		if (many_nodes == 0)
		{
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;
			tail_ptr = head_ptr;
			precursor = nullptr;
		}


		else
		{
			//If there was no current item, then the new entry 
			// has been inserted at the front of the sequence.
			if (cursor == nullptr) {
				start();
			}

			// beginning of the sequence
			if (precursor == nullptr) {
				list_head_insert(head_ptr, entry);
				head_ptr->set_link(cursor);
				cursor = head_ptr;
			}
			// A new copy of entry has been inserted in the sequence
			// before the current item. the newly
			// inserted item is now the current item of the sequence.
			else {
				list_insert(precursor, entry);
				precursor->link()->set_link(cursor);
				cursor = precursor->link();
			}
		}
		++many_nodes;
	}


	template <class Item>
	void sequence<Item>::attach(const value_type& entry)
	{
		// Empty list special case
		if (many_nodes == 0) {
			list_head_insert(cursor, entry);
			head_ptr = cursor;
			tail_ptr = cursor;
		}
		// Cursor pointing past the end
		else if (cursor == nullptr)
		{
			list_insert(tail_ptr, entry);
			precursor = tail_ptr;
			tail_ptr = tail_ptr->link();
			cursor = tail_ptr;
		}
		// Regular attach
		else
		{
			list_insert(cursor, entry);
			advance();
			if (tail_ptr->link() != nullptr)
			{
				tail_ptr = cursor;
			}
		}
		many_nodes++;
	}

	
	template <class Item>
	void sequence<Item>::remove_current()
	{
		// If there's no current element, do nothing
		if (!is_item())
			return;

		// Remove from the middle
		if (head_ptr != cursor) {
			list_remove(precursor);
			cursor = precursor->link();
		}
		// Remove the first element
		else {
			head_ptr = cursor->link();
			delete cursor;
			cursor = head_ptr;
		}
		// If removed last item
		if (cursor == nullptr)
		{
			tail_ptr = precursor;
		}

		many_nodes--;
	}

	//OPERATORS

	template <class Item>
	void sequence<Item>::operator =(const sequence& source)
	{

		if (this == &source)
		{
			return;
		}

		list_clear(this->head_ptr);

		copy_helper(source);
	}
}
#endif