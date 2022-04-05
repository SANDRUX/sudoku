#include "../sudoku.hpp"

void draw_win_game_scene()
{
    ClearBackground(YELLOW);

    DrawText("You won the game!", 50, 50, 80, BLUE);
}