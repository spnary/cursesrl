#include <ncurses.h>
#include "rlconst.h"

#ifndef __MAP
#define __MAP

typedef enum {
  wall,
  floor
} TileType;

typedef struct point {
	int x;
	int y;
} Point;

typedef struct tile {
	int blocked;
	int blockSight;
	TileType type;
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

Map *generateMap();
Point center(Room room); 
void updateVisibility(Map *map, Point point, int radius);
