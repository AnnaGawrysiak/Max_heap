#include "Heap.h"
#include <utility>
#include <iostream>


int Heap::find_a_parent_index(int index)
{
	return (index - 1) / 2;
}

int Heap::find_left_child_index(int index)
{
	return (2 * index) + 1;
}

int Heap::find_right_child_index(int index)
{
	return (2 * index) + 2;
}

void Heap::insert(int value)
{
	size++;
	//Insert the new key at the end
	int i = size - 1;
	vector_representation.push_back(value);

	int& child_data = vector_representation.at(i);
	int& parent_data = vector_representation.at(find_a_parent_index(i)); // jesli jest ciezka funkcja przypisuj do zmiennej

	// Fix the min heap property. Move up until value >= parent or root
	while (i != 0 && child_data >= parent_data)
	{
		if (child_data >= parent_data)
			std::swap(child_data, parent_data); 

		i = find_a_parent_index(i);
		child_data = vector_representation.at(i);
		parent_data = vector_representation.at(find_a_parent_index(i));
	}
}

bool Heap::is_empty()
{
	return (size == 0 ? true : false);
}

Heap::Heap() : size{ 0 }
{
}

void Heap::remove()
{
}

int Heap::top()
{
	return vector_representation.at(0);
}

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
	int left_child = find_left_child_index(index);
	int right_child = find_right_child_index(index);
	int largest = index;

	// compare `vector_representation[index]` with its left and right child
		// and find the largest value
	if (left_child < size)
		if (vector_representation.at(left_child) > vector_representation.at(index))
			largest = left_child;

	if (right_child < size)
		if (vector_representation.at(right_child) > vector_representation.at(index))
			largest = right_child;

	// swap with a child having greater value and
	// call heapify-down on the child
	if (largest != index)
	{
		std::swap(vector_representation[index], vector_representation[largest]);
		heapify_down(largest);
	}

}

void Heap::print()
{
	for (const auto item : vector_representation)
	{
		std::cout << item << " ";
	}
}