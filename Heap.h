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
	std::tuple<int, int> find_first_empty_space_index_and_its_level();
	int find_last_node_level();
	std::vector<int> to_binary(int number);
	void heapify_up(std::shared_ptr<Node> source);
	void heapify_down(std::vector<std::shared_ptr<Node>> path);
	// current size of a heap
	int size;

public:
	Heap();
	void insert(int value);
	bool is_empty();
	void pop();
	int top();
	void print_heap();
};

