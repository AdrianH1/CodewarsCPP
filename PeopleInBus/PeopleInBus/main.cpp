#include <utility>
#include <vector>
#include <iostream>

unsigned int number(const std::vector<std::pair<int, int>>& busStops) {
	int count = 0;
	for (std::pair<int, int> p : busStops)
	{
		count += p.first;
		count -= p.second;
	}
	return count;
}

unsigned int otherSolutionnumber(const std::vector<std::pair<int, int>>& busStops) {
	int passengers = 0;
	for (auto i : busStops)  passengers += i.first - i.second;
	return passengers;
}

int main()
{
	std::vector<std::pair<int, int>> test = { {10,0}, { 3,5 }, { 5,8 } };
	std::vector<std::pair<int, int>> test1 = { {3,0}, {9,1}, {4,8}, {12,2}, {6,1}, {7,8} };
	std::vector<std::pair<int, int>> test2 = { {3,0}, {9,1}, {4,10}, {12,2}, {6,1}, {7,10} };
	std::vector<std::pair<int, int>> test3 = { {0,0}};
	std::vector<std::pair<int, int>> test4 = { {10,0}, {13,0}, {17,40} };
	std::cout << number(test) << std::endl; //5
	std::cout << number(test1) << std::endl; //17
	std::cout << number(test2) << std::endl; //21
	std::cout << number(test3) << std::endl; //0
	std::cout << number(test4) << std::endl; //0
	return 0;

}