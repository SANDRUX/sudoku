#pragma once

#define _OPEN_SYS_ITOA_EXT

#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_INPUT_CHARS 2

void draw_menu_scene(int, Rectangle, const char *, const bool);
void update_menu_scene(Rectangle, bool, char *, int, int &, int &, time_t &);
void draw_game_scene(const char *);
void update_game_scene(char *, char *, int &, int &);
void draw_game_over_scene();
void draw_win_game_scene();
void generate_map(int[9][9]);
void fill_with_zeros(int[9][9], int &);