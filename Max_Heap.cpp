#include <iostream>
#include <vector>
#include <memory>
#include "Heap.h"
#include "Node.h"

int main()
{
    //std::vector<int> myvector = {9, 8, 7, 1, 11, 12, 4, 16, 67, 3, 13, 25};

    Heap max_heap;
    max_heap.insert(1);
    max_heap.insert(2);
    max_heap.insert(3);
    max_heap.insert(4);
    max_heap.insert(5);
    max_heap.insert(6);
    max_heap.insert(7);
    max_heap.insert(8);
    max_heap.insert(9);
    max_heap.insert(10);
    max_heap.insert(11);
    max_heap.insert(12);
    /*max_heap.root = std::make_shared<Node>(Node(1));

    max_heap.root->child_left = std::make_shared<Node>(Node(2));
    max_heap.root->child_right = std::make_shared<Node>(Node(3));

    max_heap.root->child_left->child_left = std::make_shared<Node>(Node(4));
    max_heap.root->child_left->child_right = std::make_shared<Node>(Node(5));
    max_heap.root->child_right->child_left = std::make_shared<Node>(Node(6));
    max_heap.root->child_right->child_right = std::make_shared<Node>(Node(7));

    max_heap.root->child_left->child_left->child_left = std::make_shared<Node>(Node(8));
    max_heap.root->child_left->child_left->child_right = std::make_shared<Node>(Node(9));
    max_heap.root->child_left->child_right->child_left = std::make_shared<Node>(Node(10));
    max_heap.root->child_left->child_right->child_right = std::make_shared<Node>(Node(11));
    max_heap.root->child_right->child_left->child_left = std::make_shared<Node>(Node(12));*/

    max_heap.size = 12;
    max_heap.insert(13);
    std::cout << max_heap.root->child_right->child_left->child_left->data << std::endl;
    std::cout << "size: " << max_heap.size << std::endl;
    //std::cout << "Insert node value: " << max_heap.root->child_right->child_left->child_right->data << std::endl;

    //for (const auto item : myvector)
    //{
      //  max_heap.insert(item);
    //}
    
   /* max_heap.print_heap();
    std::cout << std::endl;
    std::cout << "Root: " << max_heap.top() << std::endl;

    max_heap.pop();
    std::cout << std::endl << std::endl;

    max_heap.print_heap();

    std::cout << std::endl;
    std::cout << "Root: " << max_heap.top() << std::endl;*/

    return 0;
}