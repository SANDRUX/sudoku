#include "../sudoku.hpp"

void draw_game_over_scene()
{
    ClearBackground(RED);

    DrawText("Timeout, game over!", 50, 50, 80, BLUE);
}