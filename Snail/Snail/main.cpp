#include <vector>
#include <iostream>

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map) {
    if (snail_map[0].empty()) { return {}; }
    std::vector<int> result;
    int i = 0; int j = 0;
    int arrSize = snail_map.size();
    int right = arrSize -1;
    int down = arrSize -1;
    int left = 0;
    int up = 1;
    int count = 1;
    int lastVal = arrSize * arrSize;
    while (true)
    {
        if (count == lastVal)
        {
            result.push_back(snail_map[i][j]);
            return result;
        }
        //Snail goes right
        while (j < right)
        {
            if (count != lastVal) {
                result.push_back(snail_map[i][j]);
                count++;
                j++;
            }
        }
        //Snail goes down
        while (i < down)
        {
            if (count != lastVal) {
                result.push_back(snail_map[i][j]);
                count++;
                i++;
            }
        }
        //Snail goes left
        while (j > left)
        {
            if (count != lastVal) {
                result.push_back(snail_map[i][j]);
                count++;
                j--;
            }
        }
        //Snail goes up
        while (i > up)
        {
            if (count != lastVal) {
                result.push_back(snail_map[i][j]);
                count++;
                i--;
            }
        }
        right -= 1;
        down -= 1;
        left += 1;
        up += 1;
    }
}

int main()
{
    std::vector<std::vector<int>> v;
    std::vector<int> expected;
    std::vector<int> result;;

    v = { {758, 881, 89, 39, 164, 862, 406, 465, 995} , {83, 126, 696, 428, 477, 870, 861, 984, 96} , {483, 749, 699, 832, 967, 688, 329, 69, 451} , {7, 790, 494, 572, 734, 360, 623, 527, 253} , {656, 211, 256, 631, 714, 103, 124, 604, 532} , {102, 129, 579, 461, 333, 687, 181, 97, 499} , {290, 523, 46, 709, 790, 14, 179, 509, 10} , {838, 427, 853, 529, 896, 85, 327, 857, 336} , {829, 218, 481, 860, 205, 942, 820, 132, 311} };
    result = snail(v);
    expected = { 1,2,3,4,5,6,7,8,9 };

    v = { {} };
    result = snail(v);
    expected = {};

    v = { {1} };
    result = snail(v);
    expected = { 1 };

    v = { {1,2}, {4,3} };
    result = snail(v);
    expected = { 1,2,3,4 };

    v = { {1,2,3}, {8,9,4}, {7,6,5} };
    result = snail(v);
    expected = { 1,2,3,4,5,6,7,8,9 };

    v = { {1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7} };
    result = snail(v);
    expected = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
}