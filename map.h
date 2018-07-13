#include <ncurses.h>
#include "rlconst.h"

#ifndef __MAP
#define __MAP
typedef struct point {
	int x;
	int y;
} Point;

typedef struct tile {
	int blocked;
	int blockSight;
	char icon;
	ColorPair colorPair;
	int explored;
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

void generateRooms(int roomSizeMax, int roomSizeMin, Tile map[MAP_WIDTH][MAP_HEIGHT], Room rooms[MAX_ROOMS]);
Point center(Room room); 
void updateVisibility(Tile map[MAP_WIDTH][MAP_HEIGHT], Point point, int radius);
