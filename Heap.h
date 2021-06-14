#pragma once
#include <vector>
#include <tuple>
#include "Node.h"


class Heap
{
private:
	std::shared_ptr<Node> root;
	std::shared_ptr<Node> left_child;
	std::shared_ptr<Node> right_child;
	std::shared_ptr<Node> create_new_node(int value);
	std::vector<int> to_binary(int number);
	// current size of a heap
	int size;

public:
	Heap();
	void insert(int value);
	bool is_empty();
	void pop();
	int top();
	std::tuple<int, int> find_first_empty_space_index_and_its_level();
	//void heapify_down(int index);
	void print_heap();
	void heapify_up(std::shared_ptr<Node> source);
};

