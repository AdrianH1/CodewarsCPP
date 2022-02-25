#include <vector>
#include <iostream>

static int chooseBestSum(int t, int k, std::vector<int>& ls)
{

    
}

int main()
{
    std::vector<int> ts = { 50, 55, 57, 58, 60 };
    //[50, 55, 57] , [50, 55, 58], [50, 55, 60], [50, 57, 58], [50, 57, 60], [50, 58, 60], [55, 57, 58], [55, 57, 60], [55, 58, 60], [57, 58, 60]
    chooseBestSum(174, 3, ts); // 173

    ts = { 50, 55, 56, 57, 58 };
    chooseBestSum(163, 3, ts); // 162

    ts = { 50 };
    chooseBestSum(163, 3, ts); // -1


    ts = { 91, 74, 73, 85, 73, 81, 87 };
    chooseBestSum(230, 3, ts); // 228
    chooseBestSum(331, 2, ts); // 178
    chooseBestSum(331, 4, ts); // 331
    chooseBestSum(331, 5, ts); // -1
    chooseBestSum(331, 1, ts); // 91
    chooseBestSum(700, 8, ts); // -1

}