#pragma once
#define MAX_HEAP false
#define MIN_HEAP true
#include <vector>
#include <iostream>
#include <utility>

namespace zutils
{
	namespace heap
	{
		class Heap
		{
		public:
			Heap(int _mode = MAX_HEAP) :mode(_mode) {}
			void buildHeap(const std::vector<int>& arr)
			{
				heap_arr = std::move(arr);
				max_index = heap_arr.size() - 1;
				for (int i = max_index / 2; i >= 0; i--)
					heapify(i);
			}
			void heapify(const int &index)
			{
				std::size_t left = getLeftChild(index);
				std::size_t right = getRightChild(index);
				std::size_t largest = 0;
				if (left <= max_index && ((heap_arr[left] > heap_arr[index]) ^ mode))
					largest = left;
				else
					largest = index;
				if (right <= max_index && ((heap_arr[right] > heap_arr[largest]) ^ mode))
					largest = right;
				if (largest != index)
				{
					heap_arr[largest] ^= heap_arr[index];
					heap_arr[index] ^= heap_arr[largest];
					heap_arr[largest] ^= heap_arr[index];
					heapify(largest); 
				}
			}
			int addNode(const int& val)
			{
				++max_index;
				heap_arr.push_back(val);
				if (getParent(max_index) != 0)
					heapify(getParent(max_index));
			}
			void printHeap()
			{
				for (const auto& obj : heap_arr)
					std::cout << obj << " ";
			}
			inline std::size_t getLeftChild(const std::size_t& index) { return (index << 1) + 1; }
			inline std::size_t getRightChild(const std::size_t& index) { return (index << 1) + 2; }
			inline std::size_t getParent(const std::size_t& index) { return (index-1) >> 1; }
		private:
			bool mode = false;
			std::size_t max_index = -1;
			std::vector<int> heap_arr;
		};
	}
}