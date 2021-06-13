#include "Heap.h"
#include <utility>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <cmath>

	std::shared_ptr<Node> Heap::create_new_node(int value)
	{
		std::shared_ptr<Node> ptr_node = std::make_shared<Node>(Node(value));

		return ptr_node;
	}

	void Heap::insert(int value)
	{
		//Insert the new key at the end
		if (root == nullptr)
		{
			root = create_new_node(value);
			size++;
			return;
		}
		 
		int first_empty_space_index = size + 1;
		int level = 0;
		int nr_of_higher_level_nodes = 1;
		while (nr_of_higher_level_nodes < first_empty_space_index)
		{
			level++;
			nr_of_higher_level_nodes += pow(2, level);
		}
		// 13 to 1101
		std::vector<int> binary;
		while (value != 0)
		{
			binary.push_back(value % 2);
			value = value / 2;
		}

		std::reverse(binary.begin(), binary.end());

		std::shared_ptr<Node> curr = root;

		for (int i = (binary.size() - level); i < binary.size(); i++)
		{
			if (i == (binary.size() - 1) && binary.at(i) == 1)
			{
				curr->child_right = create_new_node(value);
				std::cout << " I go right and create a new node" << std::endl;
				size++;
				return;
			}
			else if (i == (binary.size() - 1) && binary.at(i) == 0)
			{
				curr->child_left = create_new_node(value);
				std::cout << "I go left and create a new node" << std::endl;
				size++;
				return;
			}

			if (binary.at(i) == 1)
			{
				curr = curr->child_right;
				std::cout << " I go right ";
			}
			else
			{
				curr = curr->child_left;
				std::cout << "I go left ";
			}
		}
	}

	Heap::Heap()
	{
		root = nullptr;
	}

	bool Heap::is_empty()
	{
		if (root == nullptr)
			return true;

		return false;
	}
	//
	//int Heap::top()
	//{
	//	try
	//	{
	//		if (size == 0)
	//			throw std::out_of_range(" Index is out of range.");
	//
	//		return heap.at(0);
	//
	//	}
	//	catch(const std::out_of_range& oor)
	//	{
	//		std::cout << std::endl << "Exception identification: " << oor.what();
	//	}
	//}
	//
	//// Function to remove an element with the highest priority (present at the root)
	//void Heap::pop()
	//{
	//	if (size == 0)
	//		return;
	//	else if (size == 1)
	//	{
	//		heap.pop_back();
	//		size--;
	//		return;
	//	}
	//	else
	//	{ 
	//		// replace the root of the heap with the last element
	//		// of the vector
	//		heap[0] = std::move(heap.back());
	//		heap.pop_back();
	//		size--;
	//		// Maintain heap shape. call heapify-down on the root node
	//		heapify_down(0);
	//
	//		return;
	//	}
	//}
	//
	//void Heap::heapify_down(int index)
	//{
	//	int left_child = find_left_child(index);
	//	int right_child = find_right_child(index);
	//	int largest = index;
	//
	//	// compare `heap[index]` with its left and right child
	//		// and find the largest value
	//	if (left_child < size)
	//		if(heap.at(left_child) > heap.at(index))
	//			largest = left_child;
	//
	//	if (right_child < size)
	//		if(heap.at(right_child) > heap.at(index))
	//			largest = right_child;
	//
	//	// swap with a child having greater value and
	//	// call heapify-down on the child
	//	if (largest != index)
	//	{
	//		std::swap(heap[index], heap[largest]);
	//		heapify_down(largest);
	//	}
	//
	//}
	//
	//void Heap::print_heap()
	//{
	//	int level = 0;
	//	int nr_of_items_on_every_level = pow(2, level);
	//	int nr_of_item = 0;
	//
	//	for (int i = 0; i < size; i++)
	//	{
	//		std::cout << heap.at(i) << " ";
	//		nr_of_item++;
	//
	//		if( nr_of_item >= nr_of_items_on_every_level)
	//		{
	//			std::cout << std::endl;
	//			level++;
	//			nr_of_items_on_every_level = pow(2, level);
	//			nr_of_item = 0;
	//		}
	//
	//	}
	