#include <vector>
#include <iostream>

std::vector<int> digitize(unsigned long n)
{
	std::vector<int> res;
	if (n == 0) return { 0 };
	while (n > 0)
	{
		res.push_back(n % 10);
		n = n / 10;
	}
	return res;
}

int main()
{
	std::vector<int> test = digitize(1234);
	std::vector<int> test1 = digitize(1230);
	std::vector<int> test2 = digitize(45);
	std::vector<int> test3 = digitize(0);
 	for (int i : test)
		std::cout << i;
	return 0;
}