#include <ncurses.h>
#include "object.h"
#include "map.h"

#define MAP_WIDTH 80
#define MAP_HEIGHT 45
void initializeMap(Tile map[MAP_WIDTH][MAP_HEIGHT]);

int main() {
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
	Object player = { 25, 25, '@' };
	Tile map[MAP_WIDTH][MAP_HEIGHT];
	initializeMap(map);
	while(1) {
		clear();
		char icon[2];
		icon[1] = '\0';
		for (int i = 0; i < MAP_WIDTH; i++) {
			for (int j = 0; j < MAP_HEIGHT; j++) {
				icon[0] = map[i][j].icon;
				mvprintw(j, i, icon); 
			}
		}
		icon[0] = player.icon;
		mvprintw(player.y, player.x, icon); 
		refresh();
		int key = getch();

		int exit = handleKey(key, &player);
		if (exit) {
			break;
		}
	}
	endwin();
	return 0;
}

void initializeMap(Tile map[MAP_WIDTH][MAP_HEIGHT]) {
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			Tile tile = { 0, 0, ' '};
			map[i][j] = tile;
		}
	}
}
