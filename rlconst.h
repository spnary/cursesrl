#define MAP_WIDTH 80
#define MAP_HEIGHT 40
#define MAX_ROOMS 30
const int ROOM_SIZE_MAX;
const int ROOM_SIZE_MIN;
const int STATS_WIDTH;
const int STATS_HEIGHT;

#ifndef __COLORPAIRS
#define __COLORPAIRS
typedef enum {
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE
} ColorPair;
#endif

void initializeColorPairs();

