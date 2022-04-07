#include <string>
#include <iostream>

std::string sum_strings(const std::string& a, const std::string& b) {
	std::string as = a;
	std::string bs = b;
	if (as.length() > bs.length())
		std::swap(as, bs);
	reverse(as.begin(), as.end());
	reverse(bs.begin(), bs.end());
	
	std::string result;
	int carry = 0;
	for (int i = 0; i < as.length(); i++)
	{
		int sum = as[i] - '0' + bs[i] - '0' + carry;
		if (sum >= 10)
		{
			carry = 1;
			sum = sum - 10;
			result = std::to_string(sum) + result;
		}
		else
		{
			result = std::to_string(sum) + result;
			carry = 0;
		}
	}

	for (int i = as.length(); i < bs.length(); i++)
	{
		int sum = bs[i] - '0' + carry;
		if (sum >= 10)
		{
			carry = 1;
			sum = sum - 10;
			result = std::to_string(sum) + result;
		}
		else
		{
			result = std::to_string(sum) + result;
			carry = 0;
		}
	}
	
	if (carry != 0)
		result = std::to_string(carry) + result;
	
	return result;
}

std::string Solution_sum_strings(const std::string& a, const std::string& b)
{
	std::string result;
	int carry = 0, n = std::max(a.size(), b.size());
	for (int i = 0; i < n; i++)
	{
		if (i < a.size()) carry += a[a.size() - 1 - i] - '0';
		if (i < b.size()) carry += b[b.size() - 1 - i] - '0';
		result.push_back('0' + carry % 10);
		carry /= 10;
	}
	result.push_back(carry + '0');
	while (result.size() > 1 && result.back() == '0')
		result.pop_back();
	std::reverse(result.begin(), result.end());
	return result;
}

int main()
{
	std::cout << sum_strings("1437881888943592160043", "4037198922468849642806998200"); // , Equals("4037200360350738586399158243"));
	std::cout << sum_strings("123", "49"); // , Equals("172"));
	std::cout << sum_strings("9999", "1111"); // , Equals("11110"));
	std::cout << sum_strings("10", "35679"); // , Equals("35689"));
	std::cout << sum_strings("123", "45"); // , Equals("168"));
	std::cout << sum_strings("12", "456"); // , Equals("468"));
	std::cout << sum_strings("123", "456"); // , Equals("579"));
	std::cout << sum_strings("111111111111111111111111111111", "111111111111111111111111111111"); // , Equals("579"));
	return 0;
}