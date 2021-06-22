#include "Heap.h"
#include <utility>
#include <memory>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <tuple>
#include <limits>

	std::shared_ptr<Node> Heap::create_new_node(int value)
	{
		std::shared_ptr<Node> ptr_node = std::make_shared<Node>(Node(value));

		return ptr_node;
	}

	std::tuple<int, int> Heap::find_first_empty_space_index_and_its_level()
	{
		int first_empty_space_index = size + 1;
		int level = 0;
		int nr_of_higher_level_nodes = 1;
		while (nr_of_higher_level_nodes < first_empty_space_index)
		{
			level++;
			nr_of_higher_level_nodes += pow(2, level);
		}

		return std::make_tuple(first_empty_space_index, level);
	}

	int Heap::find_last_node_level()
	{
		int level = 0;
		int nr_of_higher_level_nodes = 1;
		while (nr_of_higher_level_nodes < size)
		{
			level++;
			nr_of_higher_level_nodes += pow(2, level);
		}

		return level;
	}

	std::vector<int> Heap::to_binary(int number)
	{
		std::vector<int> binary;

		while(number != 0)
		{
			binary.push_back(number % 2);
			number= number / 2;
		}

		std::reverse(binary.begin(), binary.end());

		return binary;
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
		
		auto [first_empty_space_index, level] = find_first_empty_space_index_and_its_level();

		std::vector<int> binary = to_binary(first_empty_space_index);

		std::shared_ptr<Node> curr = root;

		for (int i = (binary.size() - level); i < binary.size(); i++)
		{
			if (i == (binary.size() - 1) && binary.at(i) == 1)
			{
				curr->child_right = create_new_node(value);
				if (curr->data < curr->child_right->data)
					std::swap(curr->data, curr->child_right->data);
				//std::cout << " I go right and create a new node" << std::endl;
				size++;
				return;
			}
			else if (i == (binary.size() - 1) && binary.at(i) == 0)
			{
				curr->child_left = create_new_node(value);
				if (curr->data < curr->child_left->data)
					std::swap(curr->data, curr->child_left->data);
				//std::cout << "I go left and create a new node" << std::endl;
		
				size++;
				return;
			}

			if (binary.at(i) == 1)
			{
				if (curr->data < value)
					std::swap(curr->data, value);
				curr = curr->child_right;
				//std::cout << " I go right ";
			}
			else
			{
				if (curr->data < value)
					std::swap(curr->data, value);
				curr = curr->child_left;
				//std::cout << "I go left ";
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
	

	std::shared_ptr<Node> Heap::top()
	{
		if (size == 0)
			return nullptr;
		else
			return root;
	}
	
	//// Function to remove an element with the highest priority (present at the root)
	void Heap::pop()
	{
		if (size == 0)
			return;
		else if (size == 1)
		{
			root = nullptr;
			size--;
			return;
		}
		else
		{ 
			int last_node_index = size;
			int level = find_last_node_level();

			std::vector<int> binary = to_binary(size);
			std::vector<std::shared_ptr<Node>> path;

			std::shared_ptr<Node> curr = root;
			path.push_back(curr);

			for (int i = (binary.size() - level); i < binary.size(); i++)
			{
				if (i == (binary.size() - 1) && binary.at(i) == 1)
				{
					root->data = std::move(curr->child_right->data);
					curr->child_right = nullptr;
					size--;
					heapify_down(path);
					return;
				}
				else if (i == (binary.size() - 1) && binary.at(i) == 0)
				{
					root->data = std::move(curr->child_left->data);
					curr->child_left = nullptr;
					size--;
					heapify_down(path);
					return;
				}

				if (binary.at(i) == 1)
				{
					curr = curr->child_right;
					path.push_back(curr);
				}
				else
				{
					curr = curr->child_left;
					path.push_back(curr);
				}
			}
			// Maintain heap shape. call heapify-down on the root node
			//heapify_down(path);

			return;
		}
	}
	
	void Heap::heapify_down(std::vector<std::shared_ptr<Node>>& path)
	{
		for (int i = 0; i < path.size() -1; i++)
		{
			if (path.at(i)->data < path.at(i + 1)->data)
				std::swap(path.at(i)->data, path.at(i + 1)->data);
			
		}
	}

void Heap::print_heap()
{	
	if (root == nullptr)
		return;

	std::shared_ptr<Node> source = root;
	std::queue<std::shared_ptr<Node> > myqueue;
	myqueue.push(source);
	// whenever an item touches a queue we mark it as seen
	std::map<std::shared_ptr<Node>, bool> discovered;
	discovered[source] = true;
	int levels = 0;

	while (!myqueue.empty())
	{
		// calculate the total number of nodes at the current level
		int size = myqueue.size();

		while(size--)
		{
			std::shared_ptr<Node> curr = myqueue.front();
			std::cout << curr->data << " ";
			myqueue.pop();

			if (curr->child_left != nullptr && discovered[curr->child_left] == false)
			{
				// mark it as discovered and enqueue it
				discovered[curr->child_left] = true;
				myqueue.push(curr->child_left);
			}

			if (curr->child_right != nullptr && discovered[curr->child_right] == false)
			{
				discovered[curr->child_right] = true;
				myqueue.push(curr->child_right);
			}
		}
		std::cout << std::endl;
		levels++;
	}


	
}
	