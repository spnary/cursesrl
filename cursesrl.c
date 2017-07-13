#include <ncurses.h>
#include "object.h"
#include "map.h"
#include "rlconst.h"

int main() {
	initscr();
	WINDOW *win = stdscr;
	start_color();
	initializeColorPairs();
	keypad(win, TRUE);
	curs_set(0);
	noecho();
	Object player = { 25, 25, '@', CYAN};
	Tile map[MAP_WIDTH][MAP_HEIGHT];
	initializeMap(map);
	Room room = {20, 20, 10, 10 };
	addRoomToMap(room, map);
	while(1) {
		clear();
		for (int i = 0; i < MAP_WIDTH; i++) {
			for (int j = 0; j < MAP_HEIGHT; j++) {
				Tile tile = map[i][j];
				printTile(tile, win, i, j);
			}
		}
		printObject(player, win);
		refresh();
		int key = getch();

		int exit = handleKey(key, &player, map);
		if (exit) {
			break;
		}
	}
	endwin();
	return 0;
}

