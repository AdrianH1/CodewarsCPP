#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

std::string disemvowel(const std::string& str) {
    std::vector<char> vowels= { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    std::string result = str;
    for (char c : str)
    {
        if (std::find(vowels.begin(), vowels.end(), c) != vowels.end())
            result.erase(std::remove(result.begin(), result.end(), c), result.end());
    }
    return result;
}

int main()
{
    std::cout << disemvowel("This website is for losers LOL!");
    //Ths wbst s fr lsrs LL!
    return 0;
}