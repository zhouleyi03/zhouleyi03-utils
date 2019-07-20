#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace zutils
{
	namespace string
	{
		/*
		
			-最后修改于：2019/7/20 11时
			描述：使用KMP算法搜索指定字符串，返回true则搜索到，反之则未搜索到。

		*/
		bool kmp(const std::string& pattern,const std::string& text)
		{
			std::vector<int> pi(pattern.size(), 0);
			std::size_t k = 0;
			std::size_t pattern_length = pattern.size();

			pi.push_back(0);
			for (std::size_t i = 1; i < pattern_length; i++)
			{
				while (k > 0 && pattern[k] != pattern[i])
					k = pi[k - 1];
				if (pattern[k] == pattern[i])
					++k;
				pi[i] = k;
			}

			k = 0;
			for (std::size_t j = 0; j < text.size(); j++)
			{
				if (text[j] == pattern[k])
					++k;
				else
					k = pi[k + 1];
				if (k == pattern_length - 1)
					return true;
			}
			return false;
		}
	}
}