#pragma once
#include <iostream>
#include <string>

namespace zutils
{
	namespace other
	{
		/*  ID: 0x04

			-����޸��� 2019/7/1
			˵�����������������С�

		*/
		// ���������������е��㷨�����Լ�д�ģ����ܺ�����ѧ���е����һ����������ʱ����һЩС���⣬���¡�
		// �����ʹ��getLcsUniversal()������һ���Ƚ�ͨ�õ�������������е��㷨�� -2019/4/30 16:55
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

			-����޸��� 2019/7/1
			˵�����������������еĳ����㷨��

		*/
		std::string getLcsUniversal(const std::string& l, const std::string& r)
		{
			return " ";
		}
	}
}