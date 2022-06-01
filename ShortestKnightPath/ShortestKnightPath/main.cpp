#include <string>
#include <vector>
#include <array>
#include <iostream>

void getNextPosition(std::vector<std::array<char, 2>>& currentPos, std::vector<std::array<char, 2>> &nextPos) {
    for (std::array<char, 2> pos : currentPos)
    {
        nextPos.push_back({ static_cast<char>(pos[0] + 2), static_cast<char>(pos[1] + 1) });
        nextPos.push_back({ static_cast<char>(pos[0] + 1), static_cast<char>(pos[1] + 2) });
        nextPos.push_back({ static_cast<char>(pos[0] - 1), static_cast<char>(pos[1] + 2) });
        nextPos.push_back({ static_cast<char>(pos[0] - 2), static_cast<char>(pos[1] + 1) });
        nextPos.push_back({ static_cast<char>(pos[0] - 2), static_cast<char>(pos[1] - 1) });
        nextPos.push_back({ static_cast<char>(pos[0] - 1), static_cast<char>(pos[1] - 2) });
        nextPos.push_back({ static_cast<char>(pos[0] + 1), static_cast<char>(pos[1] - 2) });
        nextPos.push_back({ static_cast<char>(pos[0] + 2), static_cast<char>(pos[1] - 1) });
    }
}

bool isValidPos(std::array<char, 2> &pos)
{
    if (pos[0] <= 'h' && pos[0] >= 'a' && pos[1] <= '8' && pos[1] >= '1')
        return true;
    else
        return false;
}

int knight(std::string start, std::string finish) {
    std::vector<std::array<char, 2>> currentPos;
    std::vector<std::array<char, 2>> nextPos;
    bool found = false;
    int moves = 0;

    currentPos.push_back({ start[0], start[1] });

    while (!found)
    {
        getNextPosition(currentPos, nextPos);
        moves++;
        currentPos.clear();
        for (std::array<char, 2> p : nextPos)
        {
            if (isValidPos(p))
            {
                if(p[0] == finish[0] && p[1] == finish[1])
                {
                    found = true;
                    return moves;
                }
                currentPos.push_back(p);
            }
        }
        nextPos.clear();
    }
    return 0;
}



int main()
{
    std::cout << knight("g2", "h1") << std::endl; // Equals(4));

    std::cout << knight("a1", "c1") << std::endl; // Equals(2));
    std::cout << knight("a1", "f1") << std::endl; // Equals(3));
    std::cout << knight("a1", "f3") << std::endl; // Equals(3));
    std::cout << knight("a1", "f4") << std::endl; // Equals(4));
    std::cout << knight("a1", "f7") << std::endl; // Equals(5));
	return 0;
}