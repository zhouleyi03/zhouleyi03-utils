#include "zutils.h"
#include <iostream>

int main()
{
	std::string s_t("abababacaabababaca");
	std::string s_p("ababaca");
	std::size_t result = zutils::string::sunday(s_p, s_t);
	std::cout << std::endl;
	std::cout << result;
	return 0;
}