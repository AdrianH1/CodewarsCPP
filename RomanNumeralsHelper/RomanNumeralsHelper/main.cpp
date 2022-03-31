#include <string>
#include <iostream>
#include <math.h>

class RomanHelper {
public:
    std::string to_roman(unsigned int n) {
        std::string result;
        int mod = std::pow(10, std::to_string(n).length()-1);
        int val = 0;
        while (n > 0)
        {
            val = n / mod;
            switch (mod)
            {
            case 1000:
                for (int i = 0; i < val; i++)
                    result.push_back('M'); break;
            case 100:
                if (val == 5)
                {
                    result.push_back('D');
                    break;
                }
                else if (val == 9)
                {
                    result.push_back('C');
                    result.push_back('M');
                    break;
                }
                else if (val > 5 && val != 9)
                {
                    result.push_back('D');
                    for (int i = 0; i < val-5; i++)
                        result.push_back('C');
                    break;
                }
                else if (val < 5)
                {
                    for (int i = 0; i < val; i++)
                        result.push_back('C');
                    break;
                }
            case 10:
                if (val == 5)
                {
                    result.push_back('L');
                    break;
                }
                else if (val == 9)
                {
                    result.push_back('X');
                    result.push_back('C');
                    break;
                }
                else if (val > 5 && val != 9)
                {
                    result.push_back('L');
                    for (int i = 0; i < val - 5; i++)
                        result.push_back('X');
                    break;
                }
                else if (val == 4)
                {
                    for (int i = 0; i < val; i++)
                        result.push_back('X');
                        result.push_back('L');
                    break;
                }
                else if (val < 4)
                {
                    for (int i = 0; i < val; i++)
                        result.push_back('X');
                    break;
                }
            case 1:
                if (val == 5)
                {
                    result.push_back('V');
                    break;
                }
                else if (val == 9)
                {
                    result.push_back('I');
                    result.push_back('X');
                    break;
                }
                else if (val > 5 && val != 9)
                {
                    result.push_back('V');
                    for (int i = 0; i < val - 5; i++)
                        result.push_back('I');
                    break;
                }
                else if (val == 4)
                {
                    result.push_back('I');
                    result.push_back('V');
                    break;
                }
                else if (val < 4)
                {
                    for (int i = 0; i < val; i++)
                        result.push_back('I');
                    break;
                }
            default:
                break;
            }
            n = n % mod;
            mod = mod / 10;

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