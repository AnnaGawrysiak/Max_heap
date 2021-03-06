#include <iostream>
#include <vector>
#include "Heap.h"

int main()
{
    std::vector<int> myvector = {9, 8, 7, 1, 11, 12, 4};

    Heap max_heap;

    for (const auto item : myvector)
    {
        max_heap.insert(item);
    }

    std::vector<int> myvector2 = max_heap.get_vector_representation();

    for (const auto item : myvector2)
    {
        std::cout << item << " ";
    }

    std::cout << std::endl;

    max_heap.pop();

    std::vector<int> myvector3 = max_heap.get_vector_representation();

    for (const auto item : myvector3)
    {
        std::cout << item << " ";
    }

    std::cout << " Root: " << max_heap.top() << std::endl;

    Heap max_heap2;

    std::cout << " Root: " << max_heap2.top() << std::endl;

    return 0;
}

