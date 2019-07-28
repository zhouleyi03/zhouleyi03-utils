#include "zutils-other.hpp"

int main()
{
	std::vector<int> x;
	for (int i = 0; i < 101; i++)
		x.push_back(i);
	std::cout << "Expected result: 5050" << std::endl;
	std::cout << "Actual result: "<<zutils::other::mt_accumulate(x);
	return 0;
}