#include "../sudoku.hpp"
#include <iostream>
#include <unistd.h>

void update_game_scene(char *board)
{
    int i = 0, j = 0;

    char key = GetCharPressed();
    if (key != 0)
    {
        i = GetMousePosition().x / 100;
        j = GetMousePosition().y / 100;

        if (board[i + j * 9] == ' ')
        {
            board[i + j * 9] = key;
        }
    }
    // if (IsMouseButtonPressed(0))
    // {
    //     i = GetMousePosition().x / 100;
    //     j = GetMousePosition().y / 100;

    //     char key = GetCharPressed();

    //     if (key != 0)
    //     {
    //         if (board[i + j * 9] == ' ')
    //         {
    //             board[i + j * 9] = key;
    //         }
    //     }

    //     // do
    //     // {
    //     //     key = GetCharPressed();
    //     // } while (key);

    //     // if (board[i + j * 9] != ' ')
    //     // {
    //     //     return;
    //     // }
    // }

    // char key = GetCharPressed();
    // if (board[i + j * 9] == ' ')
    // {
    //     board[i + j * 9] = key;
    //     printf("%c", board[i + j * 9]);
    //     fflush(stdout);
    // }

    // board[i + j * 9] = key;

    // Check if more characters have been pressed on the same frame
    // while (key > 0)
    // {
    //     // NOTE: Only allow keys in range [32..125]
    //     if ((key >= 32) && (key <= 125) && (board[i + j * 9] == ' '))
    //     {
    //         board[i + j * 9] = key;
    //     }

    //     key = GetCharPressed(); // Check next character in the queue
    // }
}

void draw_game_scene(const char *board)
{
    ClearBackground(BLACK);

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