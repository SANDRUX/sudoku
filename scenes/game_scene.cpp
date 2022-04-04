#include "../sudoku.hpp"

void update_game_scene(char * board)
{
    if (IsMouseButtonPressed(0))
    {
        int i = 0, j = 0;

        i = GetMousePosition().x / 100;
        j = GetMousePosition().y / 100;

        int value = GetCharPressed();

        board[i + j * 9] = value;    
    }
}

void draw_game_scene(const char * board)
{
    ClearBackground(BLACK);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            DrawRectangleLines(i * 100, j * 100, 100, 100, WHITE);
            DrawText(&board[i + j * 9], i * 100 + 10, j * 100 + 10, 80, BLUE);
        }
    }
}