#include <string>
#include <vector>
#include <iostream>


class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string>& strarr, int k);
};

std::string LongestConsec::longestConsec(std::vector<std::string>& strarr, int k)
{
    if (strarr.size() == 0 || k > strarr.size() || k <= 0)
        return "";
    std::string result = "";

    if (k == 1)
    {
        for (std::string s : strarr)
            if (s.size() > result.size())
                result = s;
        std::cout << result << std::endl;
        return result;
    }

    for (int i = 0; i < strarr.size(); i++)
    {
    std::string currWord = "";
        for (int j = 0; j < k; j++)
        {
            if (i+j < strarr.size())
            currWord = currWord + strarr.at(i + j);
        }
        if (result.size() < currWord.size())
            result = currWord;
    }
    std::cout << result << std::endl;
    return result;
}


int main()
{

    LongestConsec l;
    std::vector<std::string> arr = { "zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail" };
    l.longestConsec(arr, 2); // "abigailtheta");

    arr = { "tree", "foling", "trashy", "blue", "abcdef", "uvwxyz" };
    //l.longestConsec(arr, 2); // "folingtrashy");
    l.longestConsec(arr, 3); // "treefolingtrashy");


    arr = { "ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh" };
    l.longestConsec(arr, 1); // "oocccffuucccjjjkkkjyyyeehh");
    return 0;
}