#include <iostream>
#include <vector>
#include <algorithm>


class Same {
public:

    static bool comp(std::vector<int>& a, std::vector<int>& b) {
        for (int i : a)
        {
            auto it = std::find(b.begin(), b.end(), std::pow(i, 2));
            //If element was found
            if (it != b.end())
            {
                int index = it - b.begin();
                b.erase(b.begin()+index);
            }
        }
        if (b.size() == 0)
            return true;
        else 
            return false;
    }

    bool BestPracticeComp(std::vector<int> a, std::vector<int> b) {
        for (auto& v : a) {
            v = v * v;
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        return a == b;
    }
};

int main() 
{
    std::vector<int> a = { -121, 1440, 191, 161, 19, 144, 195, 11 };
    std::vector<int> b = { 121, 14641, 2073600, 36481, 25921, 361, 20736, 38025 };
    std::vector<int> aa = { 2,2,3 };
    std::vector<int> bb = { 4,9,9 };
    Same s;
    std::cout << " Result: " << s.comp(aa, bb);
    return 0;
}