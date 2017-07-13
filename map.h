#include "rlconst.h"

#ifndef __MAP
#define __MAP
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
#endif

void initializeMap(Tile map[MAP_WIDTH][MAP_HEIGHT]); 
void addRoomToMap(Room room, Tile map[MAP_WIDTH][MAP_HEIGHT]);
