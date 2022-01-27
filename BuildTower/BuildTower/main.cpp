#include <iostream>
#include <vector>
#include <string>

class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
        int lvl = 1;
        int base = nFloors + (nFloors - 1);
        int stars = 1;
        int empty = base - 1;
        std::string floor;
        std::vector<std::string> tower;
        do
        {
            int drawStarts = stars;
            floor = "";
            for (int i = 0; i < base; i++)
            {
                if (i < (empty/2) || drawStarts == 0)
                    floor = floor + " ";
                else
                {
                    floor = floor + "*";
                    drawStarts--;
                }
            }
            tower.push_back(floor);
            lvl++;
            stars += 2;
            empty -= 2;
        } while (lvl <= nFloors);
        return tower;
    }
};

int main()
{

        Kata kata;

        std::vector<std::string> expected = { "*" };
        std::vector<std::string> actual = kata.towerBuilder(1);


        expected = { " * ", "***" };
        actual = kata.towerBuilder(2);


        expected = { "  *  ", " *** ", "*****" };
        actual = kata.towerBuilder(3);

    return 0;
}