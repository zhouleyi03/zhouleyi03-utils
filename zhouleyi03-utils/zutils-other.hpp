#pragma once
#include <iostream>
#include <string>

namespace zutils
{
	namespace other
	{
		/*  ID: 0x04

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

		/*  ID: 0x05

			-最后修改于 2019/7/1
			说明：求出最长公共子序列的常用算法。

		*/
		std::string getLcsUniversal(const std::string& l, const std::string& r)
		{

		}
	}
}