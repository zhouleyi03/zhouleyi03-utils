#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <future>
#include <type_traits>

namespace zutils
{
	namespace other
	{
		/*

			-最后修改于 2019/7/1
			说明：求出最长公共子序列。

		*/
		// 这个求最长公共子序列的算法是我自己写的，可能和你们学的有点儿不一样，而且有时候会出一些小问题，见谅。
		// 你可以使用getLcsUniversal()，这是一个比较通用的求最长公共子序列的算法。 -2019/4/30 16:55
		std::string getLcs(const std::string& l, const std::string& r)
		{
			int begin = 0;
			std::string result;
			for (std::size_t i = 0; i < l.size(); i++)
				for (std::size_t j = begin; j < r.size(); j++)
				{
					if (l[i] == r[j])
					{
						begin = j;
						result.push_back(l[i]);
						break;
					}
				}
			return result;
		}

		/*

			-最后修改于 2019/7/1
			说明：求出最长公共子序列的常用算法。

		*/
		std::string getLcsUniversal(const std::string& l, const std::string& r)
		{
			return "";
		}

		/*

			-最后修改于 2019/7/27
			说明：使用多线程的求和函数。

		*/
		int mt_accumulate_aux(const std::vector<int>& nums, const int& begin, const int& length)
		{
			int result = 0;
			for (int i = begin; i < length+begin; i++)
				result += nums[i];
			return result;
		}
		int mt_accumulate(const std::vector<int>& nums)
		{
			std::vector<std::future<int>> futures;
			int result = 0;
			int supported_concurrency_num = static_cast<int>(std::thread::hardware_concurrency());
			if (supported_concurrency_num == 0)
				supported_concurrency_num = 4;
			int per_num = static_cast<int>(nums.size()) / supported_concurrency_num;
			if (per_num == 0)
			{
				for (int i = 0; i < static_cast<int>(nums.size()); i++)
					result += nums[i];
				return result;
			}
			int startpos = 0;
			for (int i = 1; i < supported_concurrency_num; i++)
			{
				futures.emplace_back(std::async(std::launch::async, mt_accumulate_aux, std::ref(nums), std::ref(startpos), std::ref(per_num)));
				result += futures[i - 1].get();
				startpos += per_num;
			}
			result += mt_accumulate_aux(nums, startpos, static_cast<int>(nums.size()) - startpos);
			return result;
		}
	}
}