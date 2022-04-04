#pragma once

#include <raylib.h>
#include <string.h>

#define MAX_INPUT_CHARS 2

void draw_menu_scene(int, Rectangle, const char *, const bool);
void update_menu_scene(Rectangle, bool, char *, int, int &);
void game_scene();
void game_over_scene();