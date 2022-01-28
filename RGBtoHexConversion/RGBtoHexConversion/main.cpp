#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

class RGBToHex
{
public:
	static std::string rgb(int r, int g, int b)
    {
        int rgb[3] = { r, g, b };
        std::string result;

        for (int i : rgb)
        {
            if (i < 0)
                i = 0;
            else if (i > 255)
                i = 255;

            std::stringstream stream;
            stream << std::hex << i;
            std::string hex(stream.str());

            if (i < 15)
                hex = "0" + hex;

            result.append(hex);
        }
        std::for_each(result.begin(), result.end(), [](char& c) { c = ::toupper(c); });
        std::cout << result << std::endl;
        return result;
    }

    std::string Solutionrgb(int r, int g, int b)
    {
        std::ostringstream oss;
        oss << std::uppercase << std::setfill('0') << std::hex
            << std::setw(2) << (r < 0 ? 0 : r > 255 ? 255 : r)
            << std::setw(2) << (g < 0 ? 0 : g > 255 ? 255 : g)
            << std::setw(2) << (b < 0 ? 0 : b > 255 ? 255 : b);
        return oss.str();
    }
};

int main()
{
    RGBToHex::rgb(0, 0, 0); // Equals("000000"));
    RGBToHex::rgb(1, 2, 3); // Equals("010203"));
    RGBToHex::rgb(255, 255, 255); // Equals("FFFFFF"));
    RGBToHex::rgb(254, 253, 252); // Equals("FEFDFC"));
    RGBToHex::rgb(-20, 275, 125); // Equals("00FF7D"));
}