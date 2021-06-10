#pragma once
#include <vector>
#include "Node.h"

class Heap
{
public:
	std::shared_ptr<Node> root;
	std::vector<int> vector_representation;
	// current size of a heap
	int size;
	int capacity;
	int find_a_parent(int index);
	int find_left_child(int index);
	int find_right_child(int index);

public:
	Heap();
	void insert(int value);
	bool is_empty();
	void remove();
	void pop();
	void heapify_down(int index);

};

