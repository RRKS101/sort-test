#include "shuffle.h"
#include "swiftiesort.h"
#include "scopetimer.h"

std::vector<uint32_t> generate_list(size_t num_elements, uint32_t m, uint32_t b, bool include_noise=false)
{
	std::vector<uint32_t> x(num_elements);
	for (size_t i = 0; i < num_elements; ++i)
	{
		uint32_t noise_factor = (rand() % (num_elements * m + b)) + b;
		//x[i] = noise_factor;
		x[i] = m * i + b + noise_factor;
	}
	shuffle_inplace(x);
	return x;
}

void print_vec(const std::vector<uint32_t>& v, size_t start = 0, size_t end = -1)
{
	if (end == -1 || end >= v.size())
		end = v.size();
	if (start == -1 || start >= v.size())
		start = 0;
	printf("[ ");
	for (size_t i = start; i < end; ++i)
	{
		printf("%u", v[i]);
		if ((i + 1) != end) printf(", ");
		else printf(" ]\n");
	}
}
size_t is_sorted(const std::vector<uint32_t>& x)
{
	for (size_t i = 1; i < x.size(); i++)
		if (x[i - 1] > x[i])
			return i;
	return -1;
}


const size_t NUM_ELEMENTS = 1024;
int main()
{
	std::vector<uint32_t> x;
	{
		ScopeTimer t("List Generator");
		x = generate_list(NUM_ELEMENTS, 1, 1);
	}
	printf("Generated unsorted array of length %llu\n", NUM_ELEMENTS);
	

	std::vector<uint32_t> sx;
	{
		ScopeTimer t("Switfie Sort");
		sx = swiftie_sort(x);
	}
	size_t s = is_sorted(sx);
	if (s == -1) printf("Swiftie Sort \033[38;5;10mSucceeded\033[m\n");
	else
	{
		printf("Swiftie Sort \033[38;5;9mFailed\033[m\n");
		printf("\033[38;5;9m  Switfie Sort Failed On Index %llu\033[m\n", s);
		printf("  \033[38;5;9m  ");
		print_vec(sx, s - 3, s + 3);
		printf("\033[m");
	}
	

	{
		ScopeTimer t("Insertion Sort");
		insertion_sort(x);
	}
	if (is_sorted(x) == -1) printf("Insertion Sort \033[38;5;10mSucceeded\033[m\n");
	else printf("Insertion Sort \033[38;5;9mFailed\033[m\n");


	for (size_t i = 0; i < NUM_ELEMENTS; ++i)
	{
		if (sx[i] == x[i]) continue;
		printf("\033[38;5;9mMismatch between swifty sort and insertion sort!\n  ");
		printf("Swiftie Sort: "); 
		print_vec(sx, i - 2, i + 2);
		printf("  Insertion Sort: ");
		print_vec(x, i - 2, i + 2);
		printf("\033[m");
		return -1;
	}
	printf("Both sorts worked.\n");

	return 0;
}