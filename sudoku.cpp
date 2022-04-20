#include "sudoku.hpp"

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 1000;

    SetTraceLogLevel(LOG_NONE);

    srand(time(NULL));

    char name[MAX_INPUT_CHARS + 1] = "\0"; // NOTE: One extra space required for null terminator char '\0'

    bool mouseOnText = false;

    int framesCounter = 0;
    int letterCount = 0;

    // int temp[81];
    //  = {3, 0, 6, 5, 0, 8, 4, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 0, 0, 0, 0, 3, 1, 0, 0, 3, 0, 1, 0, 0, 8, 0, 9, 0, 0, 8, 6, 3, 0, 0, 5, 0, 5, 0, 0, 9, 0, 6, 0, 0, 1, 3, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 7, 4, 0, 0, 5, 2, 0, 6, 3, 0, 0};
    // int temp2[81];
    //  = {3, 1, 6, 5, 7, 8, 4, 9, 2, 5, 2, 9, 1, 3, 4, 7, 6, 8, 4, 8, 7, 6, 2, 9, 5, 3, 1, 2, 6, 3, 4, 1, 5, 9, 8, 7, 9, 7, 4, 8, 6, 3, 1, 2, 5, 8, 5, 1, 7, 9, 2, 6, 4, 3, 1, 3, 8, 9, 4, 7, 2, 5, 6, 6, 9, 2, 3, 5, 1, 8, 7, 4, 7, 4, 5, 2, 8, 6, 3, 1, 9};

    int solved_int[9][9];
    int unsolved_int[9][9];

    generate_map(solved_int);

    for (int i = 0; i < 9; i++)
    {
        memcpy(unsolved_int[i], solved_int[i], sizeof(int) * 9);
    }

    int counter = 0;

    fill_with_zeros(unsolved_int, counter);

    char board[81];
    char solved[81];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (unsolved_int[i][j] == 0)
            {
                board[i * 9 + j] = ' ';
            }
            else
            {
                board[i * 9 + j] = unsolved_int[i][j] + '0';
            }
            solved[i * 9 + j] = solved_int[i][j] + '0';
        }
    }

    int game_state = 0;

    time_t seconds;

    InitWindow(screenWidth, screenHeight, "sudoku");
    Rectangle textBox = {screenWidth / 2.0f - 100, 180, 225, 50};

    SetTargetFPS(60); // Set our game to run at 10 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch (game_state)
        {
        case 0:
            update_menu_scene(textBox, mouseOnText, name, framesCounter, letterCount, game_state, seconds);
            break;

        case 1:
            if (time(NULL) >= seconds)
            {
                game_state = 2;
            }
            update_game_scene(board, solved, game_state, counter);
            break;
        }

        // printf("time(NULL): %d seconds: %d", time(NULL), seconds);
        // fflush(stdout);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        switch (game_state)
        {
        case 0:
            draw_menu_scene(framesCounter, textBox, name, mouseOnText);
            break;

        case 1:
            draw_game_scene(board);
            // char sec[2];
            // sec[0] = (int)(time(NULL) - seconds) + '0';
            // sec[1] = '\0';
            // printf("%c", sec[0]);
            // fflush(stdout);
            // DrawText(sec, 420, 920, 80, RED);
            char sec[10];
            // sec[0] = (static_cast<int>(clock() / CLOCKS_PER_SEC) - seconds) + '0';

            DrawText(std::to_string(seconds - time(NULL)).c_str(), 420, 920, 80, RED);
            break;

        case 2:
            draw_game_over_scene();
            break;

        case 3:
            draw_win_game_scene();
            break;
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Check if any key is pressed
// NOTE: We limit keys check to keys between 32 (KEY_SPACE) and 126
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126))
        keyPressed = true;

    return keyPressed;
}