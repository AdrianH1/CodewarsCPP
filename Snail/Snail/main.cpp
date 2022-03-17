#include <vector>
#include <iostream>

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map) {
    bool run = true;
    int i = 0; int j = 0;
    int arrSize = snail_map.size();
    int right = arrSize -1;
    int down = arrSize -1;
    int left = 0;
    int up = 1;
    int posJ = snail_map.size();
    int posI = snail_map.size();
    int lastVal = arrSize * arrSize;
    while (run)
    {
        while (j < right)
        {
            if (snail_map[i][j] != lastVal) {
                std::cout << snail_map[i][j];
                j++;
            } else {
                std::cout << snail_map[i][j];
                run = false; break;
            }
        }
        while (i < down)
        {
            if (snail_map[i][j] != lastVal) {
                std::cout << snail_map[i][j];
                i++;
            } else {
                std::cout << snail_map[i][j];
                run = false; break;
            }
        }
        while (j > left)
        {
            if (snail_map[i][j] != lastVal) {
                std::cout << snail_map[i][j];
                j--;
            } else {
                std::cout << snail_map[i][j];
                run = false; break;
            }

        }
        while (i > up)
        {
            if (snail_map[i][j] != lastVal) {
                std::cout << snail_map[i][j];
                i--;
            } else {
                std::cout << snail_map[i][j];
                run = false; break;
            }
        }
        right -= 1;
        down -= 1;
        left -= 1;
        up -= 1;
    }
    
    return {};
}

int main()
{
    std::vector<std::vector<int>> v;
    std::vector<int> expected;

    //v = { {} };
    //expected = {};
    //snail(v);

    //v = { {1} };
    //expected = { 1 };
    //snail(v);

    //v = { {1,2}, {4,3} };
    //expected = { 1,2,3,4 };
    //snail(v);

    v = { {1,2,3}, {8,9,4}, {7,6,5} };
    expected = { 1,2,3,4,5,6,7,8,9 };
    snail(v);

    v = { {1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7} };
    expected = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    snail(v);
}