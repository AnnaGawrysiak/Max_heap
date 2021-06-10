#include <iostream>
#include <vector>
#include "Heap.h"

int main()
{
    std::vector<int> myvector = {9, 8, 7, 1, 11, 12, 4};

    Heap max_heap;

    for (const auto item : myvector)
    {
        max_heap.insert_vec(item);
    }

    std::vector<int> myvector2 = max_heap.vector_representation;

    for (const auto item : myvector2)
    {
        std::cout << item << " ";
    }

    return 0;
}

