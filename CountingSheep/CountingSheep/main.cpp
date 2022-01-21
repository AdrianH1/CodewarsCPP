#include <vector>
#include <iostream>

using namespace std;

int count_sheep(vector<bool> arr)
{
	int count = 0;
	for (bool b : arr)
	{ 
		if (b == true)
			count++;
	}
	return count;
}

int SolutionCountSheep(vector<bool> arr)
{
	return std::count(arr.cbegin(), arr.cend(), true);
}

int main()
{
    vector<bool> test = { true, true, true, false,true, true, true, true,true, false, true, false,true, false, false, true,true, true, true, true,false, false, true, true };
	std::cout << count_sheep(test); // 17
	std::cout << SolutionCountSheep(test); // 17
	return 0;
}