#include <iostream>
#include <vector>
#include <string>

std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
    bool winner = false;
    int round = 0;
    int column;
    char player;
    const int COLUMNS = 7;
    const int ROWS = 6;
    char gameboard[COLUMNS][ROWS];
    std::fill(gameboard[0], gameboard[0] + COLUMNS * ROWS, '0');

    while (!winner)
    {
	    // Split Command String
        column = pieces_position_list.at(round)[0] - 65;
        pieces_position_list.at(round)[2] == 'R' ? player = 'R' : player = 'Y';

        //Drop Piece
        for (int i = ROWS-1; i >= 0; i--)
        {
            if (gameboard[column][i] == '0')
            {
                gameboard[column][i] = player;
                break;
            }
        }

        //Check Winner rows
        for (int i = 0; i < ROWS; i++)
        {
            int countR = 0;
            int countY = 0;
            for (int j = 0; j < COLUMNS; j++)
            {
                if (gameboard[j][i] == 'R')
                {
                    countR++;
                    if (countR == 4)
                        return "Red";
                    countY = 0;
                }
                else if (gameboard[j][i] == 'Y')
                {
                    countY++;
                    if (countY == 4)
                        return "Yellow";
                    countR = 0;
                }
                else if (gameboard[j][i] == '0')
                {
                    countR = 0;
                    countY = 0;
                }
            }
        }

        //Check Winner columns
        for (int i = 0; i < COLUMNS; i++)
        {
            int countR = 0;
            int countY = 0;
            for (int j = 0; j < ROWS; j++)
            {
                if (gameboard[i][j] == 'R')
                {
                    countR++;
                    if (countR == 4)
                        return "Red";
                    countY = 0;
                }
                else if (gameboard[i][j] == 'Y')
                {
                    countY++;
                    if (countY == 4)
                        return "Yellow";
                    countR = 0;
                }
                else if (gameboard[j][i] == '0')
                {
                    countR = 0;
                    countY = 0;
                }
            }
        }

        //Check Winner diagonal left-to-right
        int startC = 0;
        int startR = 3;
        int diag = 0;
        while (diag < 6)
        {
            int col = startC;
            int row = startR;
            int countR = 0;
            int countY = 0;
            while (row >= 0)
            {
                if (gameboard[col][row] == 'R')
                {
                    countR++;
                    if (countR == 4)
                        return "Red";
                    countY = 0;
                }
                else if (gameboard[col][row] == 'Y')
                {
                    countY++;
                    if (countY == 4)
                        return "Yellow";
                    countR = 0;
                }
                else if (gameboard[col][row] == '0')
                {
                    countR = 0;
                    countY = 0;
                }
                row--;
                col++;
            }

            if (startR < 5)
            {
                startR++;
            }
            else if (startC < 3)
            {
                startC++;
            }
            else
                break;
        }

        //check Winner diagonal right-to-left
        startC = 6;
        startR = 3;
        diag = 0;
        while (diag < 6)
        {
            int col = startC;
            int row = startR;
            int countR = 0;
            int countY = 0;
            while (row >= 0)
            {
                if (gameboard[col][row] == 'R')
                {
                    countR++;
                    if (countR == 4)
                        return "Red";
                    countY = 0;
                }
                else if (gameboard[col][row] == 'Y')
                {
                    countY++;
                    if (countY == 4)
                        return "Yellow";
                    countR = 0;
                }
                else if (gameboard[col][row] == '0')
                {
                    countR = 0;
                    countY = 0;
                }
                row--;
                col--;
            }

            if (startR < 5)
            {
                startR++;
            }
            else if (startC > 3)
            {
                startC--;
            }
            else
                break;
        }

        round++;
        if (round == 42 || round == pieces_position_list.size())
            return "Draw";
    }
    return "";
}


int main()
{

    who_is_winner({
        "E_Yellow",
        "E_Red",
        "B_Yellow",
        "A_Red",
        "A_Yellow",
        "B_Red",
        "F_Yellow",
        "D_Red",
        "F_Yellow",
        "G_Red",
        "G_Yellow",
        "F_Red",
        "F_Yellow",
        "G_Red",
        "D_Yellow",
        "F_Red",
        "F_Yellow",
        "C_Red"
        }); //, Equals("Red"));

    //who_is_winner({
    //    "A_Red",
    //    "A_Yellow",
    //    "A_Red",
    //    "B_Red",
    //    "B_Red",
    //    "B_Yellow",
    //    "B_Red",
    //    "C_Yellow",
    //    "C_Red",
    //    "C_Red",
    //    "C_Yellow",
    //    "C_Red",
    //    "D_Red",
    //    "D_Red",
    //    "D_Yellow",
    //    "D_Red",
    //    "D_Red",
    //    "D_Red"
    //    }); //, Equals("Red"));

    //who_is_winner({
    //"A_Red",
    //"A_Red",
    //"A_Red",
    //"A_Red"
    //    }); //, Equals("Red"));

    //who_is_winner({
    //"A_Red",
    //"B_Red",
    //"C_Yellow",
    //"D_Red",
    //"E_Yellow",
    //"F_Red",
    //"G_Red",
    //"A_Red",
    //"B_Red",
    //"C_Red",
    //"D_Red",
    //"E_Yellow",
    //"F_Red",
    //"G_Red"
    //    }); //, Equals("Red"));

    //who_is_winner({
    //    "A_Red",
    //    "B_Yellow",
    //    "A_Red",
    //    "B_Yellow",
    //    "A_Red",
    //    "B_Yellow",
    //    "G_Red",
    //    "B_Yellow"
    //    }); //, Equals("Yellow"));

    who_is_winner({
        "C_Yellow",
        "B_Red",
        "B_Yellow",
        "E_Red",
        "D_Yellow",
        "G_Red",
        "B_Yellow",
        "G_Red",
        "E_Yellow",
        "A_Red",
        "G_Yellow",
        "C_Red",
        "A_Yellow",
        "A_Red",
        "D_Yellow",
        "B_Red",
        "G_Yellow",
        "A_Red",
        "F_Yellow",
        "B_Red",
        "D_Yellow",
        "A_Red",
        "F_Yellow",
        "F_Red",
        "B_Yellow",
        "F_Red",
        "F_Yellow",
        "G_Red",
        "A_Yellow",
        "F_Red",
        "C_Yellow",
        "C_Red",
        "G_Yellow",
        "C_Red",
        "D_Yellow",
        "D_Red",
        "E_Yellow",
        "D_Red",
        "E_Yellow",
        "C_Red",
        "E_Yellow",
        "E_Red"
        });// , Equals("Yellow"));
}