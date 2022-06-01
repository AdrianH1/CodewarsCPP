#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

bool isValid(unsigned int check[9]);

bool validSolution(unsigned int board[9][9]) {

    unsigned int allowed[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    unsigned int check[9];

    //Check horizontal
    for (int i = 0; i < 9; i++)
    {
        std::copy(std::begin(board[i]), std::end(board[i]), std::begin(check));
        if (!isValid(check))
            return false;
    }

    //Check vertical
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            check[j] = board[j][i];
        }
        if (!isValid(check))
            return false;
    }

    //Check block
    for (int blockC = 0; blockC < 9; blockC += 3)
    {
        for (int blockR = 0; blockR < 9; blockR += 3)
        {
            int pos = 0;
            for (int i = blockR; i < blockR+3; i++)
            {
                for (int j = blockC; j < blockC+3; j++)
                {
                    check[pos] = board[j][i];
                    pos++;
                }
            }
            if (!isValid(check))
                return false;
        }
    }
    return true;
}

bool isValid(unsigned int check[9])
{
    unsigned int allowed[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::sort(check, check + 9);
    if (std::equal(check, check + 9, std::begin(allowed)))
        std::cout << "Arrays are equal.";
    else
        return false;

    return true;
}



int main()
{
    unsigned int example1[9][9] = { {5, 3, 4, 6, 7, 8, 9, 1, 2},
                                    {6, 7, 2, 1, 9, 5, 3, 4, 8},
                                    {1, 9, 8, 3, 4, 2, 5, 6, 7},
                                    {8, 5, 9, 7, 6, 1, 4, 2, 3},
                                    {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                    {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                    {9, 6, 1, 5, 3, 7, 2, 8, 4},
                                    {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                    {3, 4, 5, 2, 8, 6, 1, 7, 9} };

    unsigned int example2[9][9] = { {5, 3, 4, 6, 7, 8, 9, 1, 2},
                                    {6, 7, 2, 1, 9, 0, 3, 4, 8},
                                    {1, 0, 0, 3, 4, 2, 5, 6, 0},
                                    {8, 5, 9, 7, 6, 1, 0, 2, 0},
                                    {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                    {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                    {9, 0, 1, 5, 3, 7, 2, 1, 4},
                                    {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                    {3, 0, 0, 4, 8, 1, 1, 7, 9} };

    validSolution(example1); // , Equals(true));
    validSolution(example2); // , equals(false));
	
	return 0;
}