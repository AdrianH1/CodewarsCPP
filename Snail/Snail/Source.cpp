#include <vector>
#include <iostream>

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map) {
    bool run = true;
    int i = 0; int j = 0;
    int arrSize = snail_map.size();
    while (run)
    {
        while (j < arrSize - 1)
        {
            std::cout << snail_map[i][j];
            j++;
        }
        while (i < arrSize - 1)
        {
            std::cout << snail_map[i][j];
            i++;
        }
        while (j > 0)
        {
            std::cout << snail_map[i][j];
            j--;
        }
        while (i > 1)
        {
            std::cout << snail_map[i][j];
            i--;
        }
        while (j < arrSize - 2)
        {
            std::cout << snail_map[i][j];
            j++;
        }
        while (i < arrSize - 2)
        {
            std::cout << snail_map[i][j];
            i++;
        }
        while (j > 0)
        {
            std::cout << snail_map[i][j];
            j--;
        }
    }

    return {};
}