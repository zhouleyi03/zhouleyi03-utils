#include "zutils.h"
#include <iostream>

int main()
{
	std::string s_t("abababaca");
	std::string s_p("ababaca");
	int result = zutils::string::kmp(s_p, s_t);
	std::cout << result<<" time(s)";
	return 0;
}