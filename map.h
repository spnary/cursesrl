#include <ncurses.h>
#include "rlconst.h"

#ifndef __MAP
#define __MAP
typedef struct tile {
	int blocked;
	int blockSight;
	char icon;
	ColorPair colorPair;
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
void printTile(Tile tile, WINDOW *win, int x, int y);
void generateRooms(int maxRooms, int roomSizeMax, int roomSizeMin, Tile map[MAP_WIDTH][MAP_HEIGHT]);
int roomsIntersect(Room room1, Room room2);
