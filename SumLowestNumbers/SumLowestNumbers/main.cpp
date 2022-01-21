#include <vector>
#include <iostream>
#include <algorithm>

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    std::sort(numbers.begin(), numbers.end());
    return numbers[0] + numbers[1];
}

int main()
{
    std::cout << sumTwoSmallestNumbers({ 5, 8, 12, 22, 19 }); // 12
    return 0;
}