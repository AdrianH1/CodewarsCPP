#include <cassert>
#include <iostream>

#include <string>
bool solution(std::string const& str, std::string const& ending) {
    int s = str.size();
    for (int i = ending.size()-1; i >= 0; i--)
    {
        if (ending.at(i) != str.at(s - 1))
        {
            return false;
        }
        s--;
    }
    return true;
}

int main()
{
    //std::string test = "asdf";
    //int size = test.size();
    //std::cout << test;
    //std::cout << size;
    //std::cout << test.at(size-1);

    std::cout << solution("abcde", "cde"); //true
    std::cout << solution("abcde", "abc"); //false
    std::cout << solution("abc", ""); //true
    std::cout << solution("sumo", "omo"); //false
    return 0;
}
