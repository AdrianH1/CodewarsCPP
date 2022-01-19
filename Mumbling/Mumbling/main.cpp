#include <string>
#include <iostream>

class Accumul
{
public:
    static std::string accum(const std::string& s)
    {
        int count = 1;
        std::string res = "";
        for (char c : s) 
        {
            for (int i = 0; i < count; i++)
                if (i == 0)
                    res += toupper(c);
                else 
                    res += tolower(c);
            if (count != s.size())
                res += "-";
            count++;
        }
        return res;
    }

    static std::string BestPraciteAccum(const std::string& s) {
        std::string result;
        for (int i = 0; i < s.length(); i++) {
            result.append("-");
            result.append(std::string(1, toupper(s[i])));
            result.append(std::string(i, tolower(s[i])));
        }
        return result.substr(1, result.length());
    }
};

int main()
{
    Accumul a;
    std::cout << a.accum("abcd") << std::endl; //-> "A-Bb-Ccc-Dddd"
    std::cout << a.accum("RqaEzty") << std::endl; //-> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
    std::cout << a.accum("cwAt") << std::endl; //-> "C-Ww-Aaa-Tttt"
    return 0;
}