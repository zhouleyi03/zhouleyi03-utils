#include "zutils.h"
#include <iostream>

int main()
{
	std::string s_t("helloworld");
	std::string s_p("llowo");
	bool result = zutils::string::kmp(s_p, s_t);
	if (result)
		std::cout << "Pattern occurs!" << std::endl;
	else
		std::cout << "Pattern doesn't occur." << std::endl;
	return 0;
}