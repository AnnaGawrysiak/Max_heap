#include <iostream>
#include <vector>
#include <memory>
#include "Heap.h"
#include "Node.h"

int main()
{
    std::vector<int> myvector = {9, 8, 7, 1, 11, 12, 4, 16, 67, 3, 13, 25};

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
    max_heap.insert(13);
    
    for (const auto item : myvector)
    {
        max_heap.insert(item);
    }
    max_heap.print_heap();

    std::cout << "top:" << max_heap.top() << std::endl;

    max_heap.pop();
    std::cout << std::endl << std::endl;

    max_heap.print_heap();

    return 0;
}