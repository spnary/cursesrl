#include <ncurses.h>

const int MAP_WIDTH = 80;
const int MAP_HEIGHT = 45;

void initializeColorPairs() {
	for (int i = COLOR_BLACK; i <= COLOR_WHITE; i++) {
		init_pair(i, i, COLOR_BLACK);
	}
}
