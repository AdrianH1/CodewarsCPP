#include <vector>
#include <iostream>

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    if (input.empty())
        return {};
    int sum = 0;
    int count = 0;
    std::vector<int> res;
    for (int i : input)
    {
        if (i > 0)
            count++;
        else if (i < 0)
            sum += i;
    }
    res.push_back(count);
    res.push_back(sum);
    return res;
}

int main()
{
    std::vector<int> test = countPositivesSumNegatives({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15 }); //10, -65
    for (int i : test)
        std::cout << i;
}