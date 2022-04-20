#include "../sudoku.hpp"

void update_menu_scene(Rectangle textBox, bool mouseOnText, char *name, int framesCounter, int &letterCount, int &game_state, time_t &seconds)
{
    if (CheckCollisionPointRec(GetMousePosition(), textBox))
        mouseOnText = true;
    else
        mouseOnText = false;

    if (mouseOnText)
    {
        // Set the window's cursor to the I-Beam
        SetMouseCursor(MOUSE_CURSOR_IBEAM);

        // Get char pressed (unicode character) on the queue
        int key = GetCharPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0)
        {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
            {
                name[letterCount] = (char)key;
                name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
                letterCount++;
            }

            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            letterCount--;
            if (letterCount < 0)
                letterCount = 0;
            name[letterCount] = '\0';
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            seconds = (60 * atoi(name)) + (time(NULL));
            SetMouseCursor(MOUSE_CURSOR_ARROW);
            game_state = 1;
        }
    }
    else
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    if (mouseOnText)
        framesCounter++;
    else
        framesCounter = 0;
}

void draw_menu_scene(int framesCounter, Rectangle textBox, const char *name, const bool mouseOnText)
{
    ClearBackground(BLUE);

    DrawText("Enter minutes: ", 350, 140, 20, PINK);

    DrawRectangleRec(textBox, LIGHTGRAY);
    if (mouseOnText)
        DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
    else
        DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

    DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

    if (mouseOnText)
    {
        if (strlen(name) < MAX_INPUT_CHARS)
        {
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
        }
    }
}
