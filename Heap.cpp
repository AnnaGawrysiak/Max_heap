#include "Heap.h"
#include <utility>
#include <iostream>
#include <stdexcept>


int Heap::find_a_parent(int index)
{
	return static_cast<int>((index-1)/2);
}

int Heap::find_left_child(int index)
{
	return (2*index)+1;
}

int Heap::find_right_child(int index)
{
	return (2*index)+2;
}
std::vector<int> Heap::get_vector_representation() const
{
	return vector_representation;
}
void Heap::insert(int value)
{
	size++;
	//Insert the new key at the end
	int i = size - 1;
	vector_representation.push_back(value);

	// Fix the min heap property. Move up until value >= parent or root
	while (i != 0 && vector_representation.at(i) >= vector_representation.at(find_a_parent(i)))
	{
		std::swap(vector_representation.at(i), vector_representation.at(find_a_parent(i)));
		i = find_a_parent(i);
	}
}

bool Heap::is_empty()
{
	if (size == 0)
		return true;

	return false;
}

Heap::Heap()
{
	size = 0;
}

void Heap::remove()
{
}

int Heap::top()
{
	try
	{
		if (size == 0)
			throw std::out_of_range(" Index is out of range.");

		return vector_representation.at(0);

	}
	catch(const std::out_of_range& oor)
	{
		std::cout << std::endl << "Exception identification: " << oor.what();
	}
}

// Function to remove an element with the highest priority (present at the root)
void Heap::pop()
{
	if (size == 0)
		return;
	else if (size == 1)
	{
		vector_representation.pop_back();
		size--;
		return;
	}
	else
	{ 
		// replace the root of the heap with the last element
		// of the vector
		vector_representation[0] = std::move(vector_representation.back());
		vector_representation.pop_back();
		size--;
		// Maintain heap shape. call heapify-down on the root node
		heapify_down(0);

		return;
	}
}

void Heap::heapify_down(int index)
{
	int left_child = find_left_child(index);
	int right_child = find_right_child(index);
	int largest = index;

	// compare `vector_representation[index]` with its left and right child
		// and find the largest value
	if (left_child < size)
		if(vector_representation.at(left_child) > vector_representation.at(index))
			largest = left_child;

	if (right_child < size)
		if(vector_representation.at(right_child) > vector_representation.at(index))
			largest = right_child;

	// swap with a child having greater value and
	// call heapify-down on the child
	if (largest != index)
	{
		std::swap(vector_representation[index], vector_representation[largest]);
		heapify_down(largest);
	}

}