#include "rlconst.h"

typedef struct tile {
	int blocked;
	int blockSight;
	char icon;
} Tile;

typedef struct room {
	int x;
	int y;
	int width;
	int height;
} Room;

void initializeMap(Tile map[MAP_WIDTH][MAP_HEIGHT]); 
