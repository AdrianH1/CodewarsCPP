#include <string>
#include <iostream>
#include <map>

class RomanHelper {
public:
    std::string to_roman(unsigned int n) {
        std::string roman[4][10] = {
            { "", "M", "MM", "MMM", "MMMM" , "", "", "", "", ""},
            { "", "C", "CC", "CCC", "CD" ,"D" , "DC", "DCC", "DCCC", "CM" },
            { "", "X", "XX", "XXX", "XL" ,"L" , "LX", "LXX", "LXXX", "XC" },
            { "", "I", "II", "III", "IV" ,"V" , "VI", "VII", "VIII", "IX" }
        };
        std::string result;
        int mod = 1000;
        int val = 0;
        int pos = 0;
        while (n > 0)
        {
            val = n / mod;
            if (val != 0)
                result.append(roman[pos][val]);
            n = n % mod;
            mod = mod / 10;
            pos++;
        }
        return result;
    }
    int from_roman(std::string rn) {
        std::map<char, int> roman;
        roman.insert({ 'I', 1 });
        roman.insert({ 'V', 5 });
        roman.insert({ 'X', 10 });
        roman.insert({ 'L', 50 });
        roman.insert({ 'C', 100 });
        roman.insert({ 'D', 500 });
        roman.insert({ 'M', 1000 });
        int size = rn.size();
        int result = 0;
        for (int i = 0; i < size; i++)
        {
            if (roman[rn[i]] >= roman[rn[i + 1]])
                result += roman[rn[i]];
            else
                result -= roman[rn[i]];
        }
        return result;
    }
} RomanNumerals;

int main()
{
    RomanNumerals.to_roman(1666); // Equals("MDCLXVI"));
    RomanNumerals.to_roman(1000); // Equals("M"));
    RomanNumerals.to_roman(4); // Equals("IV"));
    RomanNumerals.to_roman(1); // Equals("I"));
    RomanNumerals.to_roman(9); // Equals("IX"));
    RomanNumerals.to_roman(1990); // Equals("MCMXC"));
    RomanNumerals.to_roman(2008); // Equals("MMVIII"));
    RomanNumerals.to_roman(3999); // Equals("MMMCMXCIX"

    RomanNumerals.from_roman("MCMXC"); // Equals(1990));
    RomanNumerals.from_roman("XXI"); // Equals(21));
    RomanNumerals.from_roman("XIX"); // Equals(19));
    RomanNumerals.from_roman("I"); // Equals(1));
    RomanNumerals.from_roman("IX"); // Equals(9));
    RomanNumerals.from_roman("IV"); // Equals(4));
    RomanNumerals.from_roman("MMVIII"); // Equals(2008));
    RomanNumerals.from_roman("MDCLXVI"); // Equals(1666));

}