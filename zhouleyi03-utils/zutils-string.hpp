#pragma once
#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>

namespace zutils
{
	namespace string
	{
		/*
		
			-最后修改于：2019/7/20 11时
			描述：使用KMP算法搜索指定字符串，返回搜索到的次数。

		*/
		std::size_t kmp(const std::string& pattern,const std::string& text)
		{
			std::vector<std::size_t> pi(pattern.size(), 0);
			std::size_t k = 0;
			std::size_t searched_times = 0;
			std::size_t pattern_length = pattern.size();

			pi.push_back(0);
			for (std::size_t i = 1; i < pattern_length; i++)
			{
				while (k != 0 && pattern[k] != pattern[i])
					k = pi[k - 1];
				if (pattern[k] == pattern[i])
					++k;
				pi[i] = k;
			}

			k = 0;
			for (std::size_t j = 0; j < text.size(); j++)
			{
				while (k != 0 && pattern[k] != text[j])
					k = pi[k - 1];
				if (pattern[k] == text[j])
					++k;
				if (k == pattern_length)
				{
					++searched_times;
					k = 0;
				}
			}
			return searched_times;
		}

		/*

			-最后修改于：2019/7/20 13时
			描述：使用Sunday算法搜索指定字符串，返回true则搜索到，反之则未搜索到。

		*/
		std::size_t sunday(const std::string& pattern, const std::string& text)
		{
			std::size_t k = 0;
			std::size_t pattern_length = pattern.size();
			std::vector<std::size_t> pi(58, pattern_length);
			std::size_t searched_times = 0;

			for (std::size_t i = 0; i < pattern.size() - 1; i++)
				pi[pattern[i] - 65] = std::min(pi[pattern[i] - 65], pattern_length - i - 1);

			std::size_t inital_val = 0;
			for (std::size_t j = 0; j < text.size();)
			{
				if (text[j] != pattern[k])
				{
					if (pi[text[j + 1] - 65] != pattern_length)
					{
						inital_val += pi[text[j + 1] - 65];
						j = inital_val;
					}
					else
						j += 1;
					k = 0;
				}
				else
				{
					++k;
					++j;
				}
				if (k == pattern_length - 1)
				{
					k = 0;
					++searched_times;
				}
			}
			return searched_times;
		}
	}
}