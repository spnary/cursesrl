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

typedef struct map {
  Tile tiles[MAP_WIDTH][MAP_HEIGHT];
  Room rooms[MAX_ROOMS];
} Map;

#endif

void initializeMap(Map *map);
void generateRooms(int roomSizeMax, int roomSizeMin, Tile map[MAP_WIDTH][MAP_HEIGHT], Room rooms[MAX_ROOMS]);
Point center(Room room); 
void updateVisibility(Map *map, Point point, int radius);
