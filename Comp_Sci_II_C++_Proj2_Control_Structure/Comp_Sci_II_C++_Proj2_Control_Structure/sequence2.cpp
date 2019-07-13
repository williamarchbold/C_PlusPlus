//Willliam Archbold C++ II 10 SEP 2017

//INVARIANT OF CLASS 'sequence2.h'
//1. The number of items in the sequence is the value of the member variable used
//2. The actual items of the sequence are stored in a partially filled array, which is a dynamic array that's 
//   pointed to by the member variable called data. 
//3. The total size of the dynamic array is the value of hte member variable capacity. 
//4. The current item in the array is accessed by the member variable current_index.


#include <ostream>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "sequence2.h"

using namespace std;

namespace main_savitch_4
{
	const sequence::size_type sequence::DEFAULT_CAPACITY;

	void sequence::start()
	{
		if (used > 0) 		current_index = 0;
	}

	bool sequence::is_item() const
	{
		return current_index < used;
	}
	
	void sequence::advance()
	{
		if (is_item()) current_index++;
		
		else cout << "No valid current item" << endl;
	}

	sequence::value_type sequence::current() const
	{
		return data[current_index];
	}

	sequence::size_type sequence::size() const
	{
		return used;
	}

	void sequence::insert(const value_type& entry)
	{	
		if (size() == capacity)
		{
			sequence::resize(used * 1.1);
		}

		if (!is_item())
		{
			current_index = 0;
		}

		for (size_type i = used; i > current_index; --i)
		{
			data[i] = data[i - 1];
		}

		data[current_index] = entry;
		used++;
	}

	void sequence::attach(const value_type& entry)
	{
		if (size() == capacity)
		{
			sequence::resize(used * 1.1);
		}

		advance();

		for (size_type i = used; i > current_index; --i)
		{
			data[i] = data[i - 1];
		}

		data[current_index] = entry;
		used++;
	}

	void sequence::remove_current()
	{
		if (is_item())
		{
			for (size_type i = current_index; i < used; i++)
			{
				data[i] = data[i + 1];
			}
			data[used - 1] = 0;
			used--;
		}
		else
		{
			cout << "No items to remove!" << endl;
		}
	}

	void sequence::resize(size_type new_capacity)
	{
		value_type *larger_array;

		if (new_capacity == capacity)
			return;

		if (new_capacity < used)
			new_capacity = used;

		larger_array = new value_type[new_capacity];
		copy(data, data + used, larger_array);
		delete[] data;
		data = larger_array;
		capacity = new_capacity;
	}

	void sequence::operator =(const sequence& source)
	{
		if (this == &source)
		{
			return;
		}

		if (capacity != source.capacity)
		{
			delete[] this->data;
			data = new value_type[source.capacity];

			capacity = source.capacity;
		}

		used = source.used;
		copy(source.data, source.data + used, data);
		current_index = source.current_index;
	}

	sequence::sequence(sequence::size_type initial_capacity)
	{
		data = new value_type[initial_capacity];
		capacity = initial_capacity;
		used = 0;
		current_index = 0;
	}

	sequence::sequence(const sequence& source)
	{
		data = new value_type[source.capacity];
		capacity = source.capacity;
		used = source.used;
		current_index = source.current_index;
		copy(source.data, source.data + used, data);
	}

	sequence::~sequence()
	{
		delete[] data;
	}
}
