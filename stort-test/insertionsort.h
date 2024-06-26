#pragma once
#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& x)
{
    for (int step = 1; step < x.size(); step++) {
        int key = x[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (j != -1 && key < x[j]) {
            x[j + 1] = x[j];
            --j;
        }
        x[j + 1] = key;
    }
}