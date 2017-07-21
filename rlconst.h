const int MAP_WIDTH;
const int MAP_HEIGHT;
const int ROOM_SIZE_MAX;
const int ROOM_SIZE_MIN;
const int MAX_ROOMS;

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

