#include <string>
#include <iostream>

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
        return 0;
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

    RomanNumerals.from_roman("XXI"); // Equals(21));
    RomanNumerals.from_roman("I"); // Equals(1));
    RomanNumerals.from_roman("IX"); // Equals(9));
    RomanNumerals.from_roman("IV"); // Equals(4));
    RomanNumerals.from_roman("MMVIII"); // Equals(2008));
    RomanNumerals.from_roman("MDCLXVI"); // Equals(1666));

    int i = 1234;
    int mod = std::pow(10, std::to_string(i).length() - 1);
    int j = i % 1000;
    std::cout << j << ", ";
    j = i / 1000;
    std::cout << j << std::endl;

    i = i % 1000;
    j = i % 100;
    std::cout << j << ", ";
    j = i / 100;
    std::cout << j << std::endl;

    i = i % 100;
    j = i % 10;
    std::cout << j << ", ";
    j = i / 10;
    std::cout << j << std::endl;

    i = i % 10;
    j = i % 1;
    std::cout << j << ", ";
    j = i / 1;
    std::cout << j << std::endl;
}