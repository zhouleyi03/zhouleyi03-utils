#pragma once
#include <iostream>
#include <string>

namespace zutils
{
	namespace other
	{
		namespace
		{
			std::string getLCS(const std::string &l, const std::string &r)
			{
				int begin = 0;
				std::string result;
				for (int i = 0; i < l.size(); i++)
					for (int j = begin; j < r.size(); j++)
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
		}
	}
}