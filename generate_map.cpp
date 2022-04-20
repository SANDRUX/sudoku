#include "sudoku.hpp"

void generate_map(int board[9][9])
{
again:
    int x = 0, y = 0;
    for (int i = 0; i < 9; i++)
    {
        memset(board[i], 0, sizeof(int) * 9);
    }
    bool status = false;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::vector<int> candidates(9);
            for (int k = 0; k < 9; k++)
            {
                candidates[k] = k + 1;
            }
            random_shuffle(candidates.begin(), candidates.end());
            for (int temp : candidates)
            {
                for (int k = 0; k < j; k++)
                {
                    if (temp == board[i][k])
                    {
                        status = true;
                        break;
                    }
                }
                for (int m = 0; m < i; m++)
                {
                    if (temp == board[m][j])
                    {
                        status = true;
                        break;
                    }
                }

                x = (i / 3) * 3;
                y = (j / 3) * 3;

                for (int r = x; r < x + 3; r++)
                {
                    for (int l = y; l < y + 3; l++)
                    {
                        if (r < i || (r == i && l < j))
                        {
                            if (temp == board[r][l])
                            {
                                status = true;
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                if (status == true)
                {
                    status = false;
                    continue;
                }
                board[i][j] = temp;
                break;
            }
            if (board[i][j] == 0)
            {
                goto again;
                return;
            }
        }
    }
}