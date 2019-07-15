// CSC-161 Homework Nine - Complete Solution
// William Archbold
// FILE: bag6.template
// -------------------------------------------------------------------------
// This is a partial implementation of the bag template class from Section
// 10.5 of "Data Structures and Other Objects Using C++". The parts marked
// with ***STUDENT WORK*** are left as a project for CSC-161 Computer Science II
// students.
// -------------------------------------------------------------------------
// TEMPLATE CLASS IMPLEMENTED: bag<Item> (see bag6.h for documentation)
// INVARIANT of the ADT:
//   root_ptr is the root pointer of a binary search tree that contains the
//   bag's items.

#include <cassert>
#include <cstdlib>

namespace main_savitch_10
{
	template <class Item>
	void bst_remove_max(binary_tree_node<Item>*& root_ptr, Item& removed)
		// Precondition: root_ptr is a root pointer of a non-empty binary 
		// search tree.
		// Postcondition: The largest item in the binary search tree has been
		// removed, and root_ptr now points to the root of the new (smaller) 
		// binary search tree. The reference parameter, removed, has been set 
		// to a copy of the removed item.
	{
		/***STUDENT WORK***
		** This recursive function should be implemented by the student, as
		** discussed on page 523 of the third edition of the textbook.
		*/

		// root is the biggest element
		if (root_ptr->right() == NULL) {
			removed = root_ptr->data();

			binary_tree_node<Item>* max = root_ptr;
			root_ptr = root_ptr->left();
			delete max;
			return;
		}

		// normal 
		binary_tree_node<Item>* cursor = root_ptr;
		while (cursor->right()->right() != NULL) {
			cursor = cursor->right();
		}
		removed = cursor->right()->data();

		binary_tree_node<Item>* max = cursor->right();
		cursor->set_right(max->left());
		delete max;
	}

	template <class Item>
	bool bst_remove(binary_tree_node<Item>*& root_ptr, const Item& target)
		// Precondition: root_ptr is a root pointer of a binary search tree 
		// or may be NULL for an empty tree).
		// Postcondition: If target was in the tree, then one copy of target
		// has been removed, and root_ptr now points to the root of the new 
		// (smaller) binary search tree. In this case the function returns true.
		// If target was not in the tree, then the tree is unchanged (and the
		// function returns false).
	{
		binary_tree_node<Item> *oldroot_ptr;

		if (root_ptr == NULL)
		{   // Empty tree
			return false;
		}

		if (target < root_ptr->data())
		{   // Continue looking in the left subtree
			return bst_remove(root_ptr->left(), target);
		}

		if (target > root_ptr->data())
		{   // Continue looking in the right subtree
			return bst_remove(root_ptr->right(), target);
		}

		if (root_ptr->left() == NULL)
		{   // Target was found and there is no left subtree, so we can
			// remove this node, making the right child be the new root.
			oldroot_ptr = root_ptr;
			root_ptr = root_ptr->right();
			delete oldroot_ptr;
			return true;
		}

		// If code reaches this point, then we must remove the target from
		// the current node. We'll actually replace this target with the
		// maximum item in our left subtree.
		bst_remove_max(root_ptr->left(), root_ptr->data());
		return true;
	}

	template <class Item>
	typename bag<Item>::size_type bst_remove_all(binary_tree_node<Item>*& root_ptr, const Item& target)
		// Precondition: root_ptr is a root pointer of a binary search tree 
		// or may be NULL for an empty tree).
		// Postcondition: All copies of target have been removed from the tree
		// has been removed, and root_ptr now points to the root of the new 
		// (smaller) binary search tree. The return value tells how many copies
		// of the target were removed.
	{
		/** STUDENT WORK - complete this function
		** Note: This implementation is similar to bst_remove, except that
		** all occurrences of the target must be removed, and the return
		** value is the number of copies that were removed.
		*/

		int count = 0;
		while (bst_remove(root_ptr, target)) {
			count++;
		}
		return count;

		binary_tree_node<Item> *oldroot_ptr;


		if (root_ptr == NULL)
		{   // Empty tree
			//return many;
		}

		if (target < root_ptr->data())
		{   // Continue looking in the left subtree
			/* STUDENT WORK */
		}

		if (target > root_ptr->data())
		{   // Continue looking in the right subtree
			/* STUDENT WORK */
		}

		if (root_ptr->left() == NULL)
		{   // Target was found and there is no left subtree, so we can
			// remove this node, making the right child be the new root.
			oldroot_ptr = root_ptr;
			root_ptr = root_ptr->right();
			delete oldroot_ptr;
			return 1;
		}

		// If code reaches this point, then we must remove the target from
		// the current node. We'll actually replace this target with the
		// maximum item in our left subtree. We then continue
		// searching for more copies of the target to remove.
		// This continued search must start at the current root (since
		// the maximum element that we moved up from our left subtree
		// might also be a copy of the target).
		/* STUDENT WORK */
	}

	template <class Item>
	bag<Item>::bag()
		// Library facilities used: bintree.h
	{
		root_ptr = NULL;
	}

	template <class Item>
	bag<Item>::bag(const bag<Item>& source)
		// Library facilities used: bintree.h
	{
		root_ptr = tree_copy(source.root_ptr);
	}

	template <class Item>
	bag<Item>::~bag()
		// Header file used: bintree.h
	{
		tree_clear(root_ptr);
	}

	template <class Item>
	typename bag<Item>::size_type bag<Item>::size() const
		// Header file used: bintree.h
	{
		return tree_size(root_ptr);
	}

	template <class Item>
	void bag<Item>::insert(const Item& entry)
		// Header file used: bintree.h
	{
		binary_tree_node<Item> *cursor = root_ptr;
		bool done = false;

		binary_tree_node<Item> *new_node = new binary_tree_node<Item>(entry);

		if (root_ptr == NULL)
		{   // Add the first node of the binary search tree:
			root_ptr = new_node;
			return;
		}

		while (true) {
			if (entry > cursor->data()) {
				if (cursor->right() == NULL) {
					cursor->set_right(new_node);
					break;
				}
				else {
					cursor = cursor->right();
				}
			}
			else {
				if (cursor->left() == NULL) {
					cursor->set_left(new_node);
					break;
				}
				else {
					cursor = cursor->left();
				}
			}

		}
	}

	template <class Item>
	typename bag<Item>::size_type bag<Item>::count(const Item& target) const
	{
		binary_tree_node<Item> *cursor = root_ptr;

		// find our element
		while (cursor != NULL && cursor->data() != target) {
			if (cursor->data() < target) {
				cursor = cursor->right();
			}
			else {
				cursor = cursor->left();
			}
		}

		size_type answer = 0;

		while (cursor != NULL) {
			if (cursor->data() == target) {
				answer += 1;
			}
			
			if (cursor->data() < target) {
				cursor = cursor->right();
			}
			else {
				cursor = cursor->left();
			}
		}

		return answer;
	}

	template <class Item>
	typename bag<Item>::size_type bag<Item>::erase(const Item& target)
	{
		return bst_remove_all(root_ptr, target);
	}

	template <class Item>
	bool bag<Item>::erase_one(const Item& target)
	{
		return bst_remove(root_ptr, target);
	}

	template <class Item>
	void bag<Item>::operator =(const bag<Item>& source)
		// Header file used: bintree.h
	{
		if (root_ptr == source.root_ptr)
			return;
		tree_clear(root_ptr);
		root_ptr = tree_copy(source.root_ptr);
	}

	template <class Item>
	void bag<Item>::operator +=(const bag<Item>& addend)
	{
		if (root_ptr == addend.root_ptr)
		{
			bag<Item> copy = addend;
			insert_all(copy.root_ptr);
		}
		else
			insert_all(addend.root_ptr);
	}

	template <class Item>
	bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
	{
		bag<Item> answer = b1;
		answer += b2;
		return answer;
	}

	template <class Item>
	void bag<Item>::insert_all(binary_tree_node<Item>* addroot_ptr)
		// Precondition: addroot_ptr is the root pointer of a binary search tree that
		// is separate for the binary search tree of the bag that activated this
		// method.
		// Postcondition: All the items from the addroot_ptr's binary search tree
		// have been added to the binary search tree of the bag that activated this
		// method.
	{
		if (addroot_ptr != NULL)
		{
			insert(addroot_ptr->data());
			insert_all(addroot_ptr->left());
			insert_all(addroot_ptr->right());
		}
	}
}
