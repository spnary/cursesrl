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

void drawStats(Character character, WINDOW *statsWin) {
	mvwprintw(statsWin, 1, 1, "HP: %i/%i", character.currentHP, character.maxHP);
	mvwprintw(statsWin, 2, 1, "AC: %i", character.armor->ac);
	mvwprintw(statsWin, 3, 1, "------");
	mvwprintw(statsWin, 4, 1, "Strength: %i", character.strength);
	mvwprintw(statsWin, 5, 1, "Dexterity: %i", character.dexterity);
	mvwprintw(statsWin, 6, 1, "Constitution: %i", character.constitution);
	mvwprintw(statsWin, 7, 1, "Intelligence: %i", character.intelligence);
	mvwprintw(statsWin, 8, 1, "Wisdom: %i", character.wisdom);
	mvwprintw(statsWin, 9, 1, "Charisma: %i", character.charisma);
}
