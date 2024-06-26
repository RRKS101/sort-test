#pragma once
#include <vector>


// Takes a reference to an array and shuffles its elements in-place.
template <typename T>
void shuffle_inplace(std::vector<T>& x)
{
	for (size_t i = 0; i < x.size() * 2; ++i)
	{
		size_t idx_a = rand() % x.size();
		size_t idx_b = rand() % x.size();
		T tmp = x[idx_a];
		x[idx_a] = x[idx_b];
		x[idx_b] = tmp;
	}
}