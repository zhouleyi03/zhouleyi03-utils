#include "zutils.h"
#include <iostream>
#include <Windows.h>

int main()
{
	std::string s_t("HelloWorldsssssaaskdhjklasfkhkasdjklajsdjjalsflajldksh;lalwjdsssssssssssssssssssssssssssssssssss");
	std::string s_p("oWo");
	DWORD time1 = GetTickCount64();
	bool result = zutils::string::sunday(s_p, s_t);
	std::cout << GetTickCount64() - time1 << std::endl;

	if (result)
		std::cout << "Pattern occurs!" << std::endl;
	else
		std::cout << "Pattern doesn't occur." << std::endl;
	return 0;
}