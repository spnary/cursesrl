#include <ncurses.h>
#include "object.h"
#include "map.h"
#include "rlconst.h"
#include "drawing.h"

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
	Tile map[MAP_WIDTH][MAP_HEIGHT];
	initializeMap(map);
	Room rooms[MAX_ROOMS];
	generateRooms(ROOM_SIZE_MAX, ROOM_SIZE_MIN, map, rooms);
	Point startPoint = center(rooms[0]);
	Object player = { startPoint.x, startPoint.y, '@', CYAN};
	while(1) {
		int sightRadius = 5;
		Point position = {player.x, player.y};
		updateVisibility(map, position, sightRadius);
		wclear(mapWin);
		drawMap(map, mapWin);
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

