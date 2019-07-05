#include "zutils.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> a{4,1,3,2,16,9,10,14,8,7};
	zutils::heap::Heap h(MAX_HEAP);
	h.buildHeap(a);
	h.heapSort();
	h.printHeap();
	return 0;
}