#pragma once
#include "insertionsort.h"
#include <optional>

template <typename T>
std::pair<const T&, const T&> get_minmax(const std::vector<T>& x)
{
	size_t i_max = 0;
	size_t i_min = 0;
	for (size_t i = 0; i < x.size(); ++i)
	{
		if (x[i] >= x[i_max])
			i_max = i;
		if (x[i] < x[i_min])
			i_min = i;
	}
	return std::make_pair<const T&, const T&>(x[i_min], x[i_max]);
}

template <typename T>
std::vector<T> swiftie_sort(const std::vector<T>& x)
{
	// Step 1. Create a pool and map values of x into it
	// Step 1.1 Find min and max values in array and create a sparse list
	auto [min, max] = get_minmax<T>(x);
	std::vector<std::optional<T>> l(x.size());
	// Step 1.2 Assuming a linear dataset
	try {
		for (size_t i = 0; i < x.size(); ++i)
		{
			// Convert x value into index for pool
			// x = min + (max-min)*t  =>  t = (x-min)/(max-min). t is in [0,1]
			size_t j = (x[i] - min); // [0-1] is not useful as an array index - so we use j = (x-min)

			// If the position is empty, add it, otherwise shuffle right until a spot is found
			if (j >= l.size())
				l.resize(j + 1);
			for (; l[j].has_value(); j++)
				if ((j+1) >= l.size())
					l.resize(j + 2);
			// Now that we have found an index that is empty and is approx. linear
			//	Insert the value
			l[j] = x[i];
		}
	} catch (std::exception& e)
	{ printf("Error: %s\n", e.what()); }
	printf("  [INFO] Swiftie aux. array with size of %llu\n", l.size());

	// Step 2. Remove null elements from the pool and reduce it into an array
	std::vector<T> y;
	y.reserve(x.size());
	try {
		for (size_t i = 0; i < l.size(); ++i)
		{
			if (!l[i].has_value()) continue;
			y.push_back(l[i].value());
		}
	} catch (std::exception& e)
	{ printf("Error: %s\n", e.what()); }

	// Step 3. Perform insertion sort on the reduced pool
	insertion_sort(y);
	return y;
}