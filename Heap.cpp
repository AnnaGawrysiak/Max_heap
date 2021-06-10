#include "Heap.h"
#include <memory>
#include <utility>

std::shared_ptr<Node> Heap::create_new_node(int value)
{
	std::shared_ptr<Node> ptr_node = std::make_shared<Node>(Node(value));

	return ptr_node;
}

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

//void Heap::insert(int value)
//{
//	std::shared_ptr<Node> curr = root;
//
//	if(!curr->child_left)
//	{
//		create_new_node(value);
//	}
//	else if(!curr->child_right)
//	{
//		create_new_node(value);
//	}
//
//}

void Heap::insert_vec(int value)
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

//void Heap::create_heap(std::vector<int> numbers)
//{
//	if (numbers.empty())
//		return;
//
//	root = create_new_node(numbers.at(0));
//
//	for (const auto& item : numbers)
//	{
//		if (root->data < item)
//		{
//			search_new_place(root->data);
//			root = create_new_node(item);
//		}
//	}
//
//}

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

int Heap::show_min() const
{
	if (root)
		return root->data;
	else
		return -1;
}
