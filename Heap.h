#pragma once
#include <vector>
#include "Node.h"

class Heap
{
public:
	std::shared_ptr<Node> root;
	std::shared_ptr<Node> left_child;
	std::shared_ptr<Node> right_child;
	std::shared_ptr<Node> create_new_node(int value);
	// current size of a heap
	int size;

public:
	Heap();
	void insert(int value);
	bool is_empty();
	//void pop();
	//int top();
	//void heapify_down(int index);
	//void print_heap();

};

