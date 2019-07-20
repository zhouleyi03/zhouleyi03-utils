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
		
			-����޸��ڣ�2019/7/20 11ʱ
			������ʹ��KMP�㷨����ָ���ַ����������������Ĵ�����

		*/
		int kmp(const std::string& pattern,const std::string& text)
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

			-����޸��ڣ�2019/7/20 13ʱ
			������ʹ��Sunday�㷨����ָ���ַ���������true������������֮��δ��������

		*/
		bool sunday(const std::string& pattern, const std::string& text)
		{
			std::size_t k = 0;
			std::size_t pattern_length = pattern.size();
			std::vector<std::size_t> pi(58, pattern_length);

			for (std::size_t i = 0; i < pattern.size(); i++)
				pi[pattern[i] - 65] = std::min(pi[pattern[i] - 65], pattern_length - i - 1);

			for (std::size_t j = 0; j < text.size();)
			{
				if (text[j] != pattern[k])
				{
					if (pi[text[j + pattern_length] - 65] != pattern_length)
					{
						j += (pi[text[j + pattern_length] - 65] + 1);
					}
					else
						j += (pattern_length + 1);
					k = 0;
				}
				else
				{
					++k;
					++j;
				}
				if (k == pattern_length - 1)
					return true;
			}
			return false;
		}
	}
}