#include <ncurses.h>
#include "object.h"
#include "map.h"
#include "rlconst.h"

int main() {
	initscr();
	start_color();
	initializeColorPairs();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
	init_pair(9, COLOR_BLACK, COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR(9));
	WINDOW *mapWin = newwin(MAP_HEIGHT, MAP_WIDTH, 0, 0);
	init_pair(10, COLOR_WHITE, COLOR_BLACK);
	wbkgd(mapWin, COLOR_PAIR(10));
	wborder(mapWin, '|','|','-','-','+','+','+','+');
	wrefresh(mapWin);
	refresh();
	Object player = { 25, 25, '@', CYAN};
	Tile map[MAP_WIDTH][MAP_HEIGHT];
	initializeMap(map);
	generateRooms(MAX_ROOMS, ROOM_SIZE_MAX, ROOM_SIZE_MIN, map);
	while(1) {
		wclear(mapWin);
		for (int i = 0; i < MAP_WIDTH; i++) {
			for (int j = 0; j < MAP_HEIGHT; j++) {
				Tile tile = map[i][j];
				printTile(tile, mapWin, i, j);
			}
		}
		printObject(player, mapWin);
		wrefresh(mapWin);
		int key = getch();

		int exit = handleKey(key, &player, map);
		if (exit) {
			break;
		}
	}
	endwin();
	return 0;
}

