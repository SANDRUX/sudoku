#pragma once

#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define MAX_INPUT_CHARS 2

void draw_menu_scene(int, Rectangle, const char *, const bool);
void update_menu_scene(Rectangle, bool, char *, int, int &, int &, time_t &);
void draw_game_scene(const char *);
void update_game_scene(char *, char *, int &, int &);
void draw_game_over_scene();
void draw_win_game_scene();