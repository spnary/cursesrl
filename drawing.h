#include "rlconst.h"
#include "map.h"
#include <ncurses.h>
#include "character.h"
void drawMap(Tile map[MAP_WIDTH][MAP_HEIGHT], WINDOW* mapWin);

void printTile(Tile tile, WINDOW *win, int x, int y);

void drawStats(Character character, WINDOW *statsWin);
