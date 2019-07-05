#include "zutils.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> a{1,2,3,4,5};
	zutils::heap::Heap h(MAX_HEAP);
	h.buildHeap(a);
	h.printHeap();
	return 0;
}