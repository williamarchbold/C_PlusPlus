// William Archbold C++ II 01 OCT 2017
// FILE: sequence4.h
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ Item
//     sequence::Item is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//     sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     sequence::DEFAULT_CAPACITY is the initial capacity of a sequence that is
//     created by the default constructor.
//
// CONSTRUCTOR for the sequence class:
//   sequence(size_t initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The sequence has been initialized as an empty sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void resize(size_type new_capacity)
//     Postcondition: The sequence's current capacity is changed to the 
//     new_capacity (but not less that the number of items already on the
//     list). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
//
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry 
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const Item& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   Item current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.
//
// DYNAMIC MEMORY USAGE by the List
//   If there is insufficient dynamic memory, then the following functions
//   throw a BAD_ALLOC exception: The constructors, insert, attach. 

#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib>  // Provides size_t
#include "node2.h"

namespace main_savitch_6B
{
	template <class Item>
	class sequence
	{
	public:
		// TYPEDEFS and MEMBER CONSTANTS
		typedef std::size_t size_type;
		typedef Item value_type;

		// CONSTRUCTORS and DESTRUCTOR
		sequence();
		sequence(const sequence& source);
		~sequence();

		// MODIFICATION MEMBER FUNCTIONS
		void start();
		// Advances the current element
		void advance();
		void insert(const Item& entry);
		void attach(const Item& entry);
		void remove_current();
		void operator =(const sequence& source);

		// CONSTANT MEMBER FUNCTIONS
		size_type size() const { return many_nodes; };
		bool is_item() const;
		Item current() const;
	private:
		size_type many_nodes;
		node<Item> *head_ptr;
		node<Item> *tail_ptr;
		node<Item> *cursor;
		node<Item> *precursor;

		void copy_helper(const sequence& source);
	};
}
#include"sequence4.template"
#endif

