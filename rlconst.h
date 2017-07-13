const int MAP_WIDTH;
const int MAP_HEIGHT;

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
