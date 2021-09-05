// future example
#include <iostream>       // std::cout
#include <vector>
#include <execution>
#include <algorithm>

int main()
{
	int num[] = { 1, 2, 3 };
	std::vector<int> a = { 4, 5, 6 };
	std::mutex m;

	std::for_each(std::execution::par, std::begin(num), std::end(num),
		[&](auto v) {
			std::lock_guard lock(m);
			a.push_back(v); // OK
		});
	for (int i : a)
	{
		printf("%i, ", i);
	}
}