#include <ncurses.h>

const int MAP_WIDTH = 80;
const int MAP_HEIGHT = 40;
const int STATS_WIDTH = 20;
const int STATS_HEIGHT = 40;
const int ROOM_SIZE_MAX = 10;
const int ROOM_SIZE_MIN = 6;
const int MAX_ROOMS = 30;

void initializeColorPairs() {
	for (int i = COLOR_BLACK; i <= COLOR_WHITE; i++) {
		init_pair(i, i, COLOR_BLACK);
	}
}
