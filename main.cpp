#include <iostream>
#include <vector>
#include "Heap.h"

int main()
{
    std::vector<int> myvector = { 9, 8, 7, 1, 11, 12, 4 };

    Heap max_heap;

    for (const auto item : myvector)
    {
        max_heap.insert(item);
    }

 
    max_heap.print();

    std::cout << std::endl;

    max_heap.pop();

    max_heap.print();

    std::cout << " Root: " << max_heap.top() << std::endl;

    Heap max_heap2;

    std::cout << "Is max_heap2 empty? " << max_heap2.is_empty() << std::endl;

    return 0;
}

