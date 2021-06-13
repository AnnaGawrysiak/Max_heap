#include "Node.h"

Node::Node(int value)
{
	data = value;
	child_left = nullptr;
	child_right = nullptr;
}

Node::Node()
{
	child_left = nullptr;
	child_right = nullptr;
}