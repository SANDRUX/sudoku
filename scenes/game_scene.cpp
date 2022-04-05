#include "../sudoku.hpp"
#include <iostream>
#include <unistd.h>

void update_game_scene(char *board, char *solved, int &game_state, int &counter)
{
    if (counter == 0)
    {
        game_state = 3;
    }

    int i = 0, j = 0;

    char key = GetCharPressed();
    if (key != 0)
    {
        i = GetMousePosition().x / 100;
        j = GetMousePosition().y / 100;

        if (board[i + j * 9] == ' ')
        {
            if (key == solved[i + j * 9])
            {
                board[i + j * 9] = key;

                counter--;
            }
        }
    }
}

void draw_game_scene(const char *board)
{
    ClearBackground(GREEN);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            DrawRectangleLines(i * 100, j * 100, 100, 100, WHITE);
            // DrawRectangle(i * 100 + 10, j * 100 + 10,
            //               (board[i + j * 9] - '0') * 80 / 9, 80, RED);

            char text[2];
            text[0] = board[i + j * 9];
            text[1] = '\0';

            DrawText(text, i * 100 + 30, j * 100 + 15, 80, BLUE);
        }
    }
}