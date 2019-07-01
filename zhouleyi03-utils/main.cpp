#include "zutils.h"
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << zutils::password::vigenerePasswordEncrypt("Helloworld", "abc");
	return 0;
}