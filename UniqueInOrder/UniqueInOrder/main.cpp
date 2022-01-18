#include <string>
#include <vector>
#include <iostream>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable) {
	//your code here
	std::vector<T> result;
	T tmp = iterable[0];
	result.push_back(tmp);
	for (T t : iterable)
	{
		if (t != tmp)
			result.push_back(t);
		tmp = t;
	}
	return result;
}
std::vector<char> uniqueInOrder(const std::string& iterable) {
	//your code here
	std::vector<char> result;
	char tmp = '-';
	for (int i = 0; i < iterable.length(); i++)
	{
		if (iterable[i] != tmp)
			result.push_back(iterable[i]);
		tmp = iterable[i];
	}
	return result;
}

template <typename T> std::vector<T> SolutionuniqueInOrder(const std::vector<T>& iterable) {
	std::vector<T> result;
	for (const auto& c : iterable) if (result.empty() || c != result.back()) result.push_back(c);
	return result;
}

std::vector<char> SolutionuniqueInOrder(const std::string& iterable) {
	std::vector<char> result;
	for (auto c : iterable) if (result.empty() || c != result.back()) result.push_back(c);
	return result;
}

int main()
{
	std::vector<char> test = uniqueInOrder("aaddff");
	std::vector<char> test2 = uniqueInOrder({ 0,0,1,1,3 });
	for (char c : test)
		std::cout << c;

	for (int i : test2)
		std::cout << i;
	return 0;
}