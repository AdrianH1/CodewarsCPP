#include <string>
#include <iostream>

std::string abbrevName(std::string name)
{
	int space = name.find(" ", 0);
	std::string res = char(toupper(name[0])) + std::string(".") + char(toupper(name[space + 1]));
	return res;
}

int main ()
{
	std::cout << abbrevName("Sam Harris") << std::endl; // S.H
	std::cout << abbrevName("adrian hugentobler"); // A.H
	return 0;
}