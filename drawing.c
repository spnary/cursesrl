#include "drawing.h"

void drawMap(Tile map[MAP_WIDTH][MAP_HEIGHT], WINDOW *mapWin) {
  for (int i = 0; i < MAP_WIDTH; i++) {
    for (int j = 0; j < MAP_HEIGHT; j++) {
      Tile tile = map[i][j];
      printTile(tile, mapWin, i, j);
    }
  }
}

void printTile(Tile tile, WINDOW *win, int x, int y) {
  if (tile.explored) {
    char icon[2];
    icon[0] = tile.icon;
    icon[1] = '\0';
    wattron(win, COLOR_PAIR(tile.colorPair));
    mvwprintw(win, y, x, icon); 
    wattroff(win, COLOR_PAIR(tile.colorPair));
  }
}
