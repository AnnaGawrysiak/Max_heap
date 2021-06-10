#pragma once
#include <vector>
#include <memory>
#include "Node.h"

class Heap
{
public:
	std::shared_ptr<Node> root;
	std::shared_ptr<Node> create_new_node(int value);
	std::vector<int> vector_representation;
	// current size of a heap
	int size;
	int capacity;
	int find_a_parent(int index);
	int find_left_child(int index);
	int find_right_child(int index);

public:
	Heap();
	void create_heap(std::vector<int> numbers);
	void insert_vec(int value);
	bool is_empty();
	void remove();
	int show_min() const;
};

