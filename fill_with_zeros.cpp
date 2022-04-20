#include "sudoku.hpp"

void fill_with_zeros(int board[9][9], int &counter)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!(rand() % 3))
            {
                board[i][j] = 0;
                counter++;
            }
        }
    }
}