#include <ncurses.h>
#include "rlconst.h"
#include "map.h"
#include "character.h"
#include <stdbool.h>

#ifndef __OBJECT
#define __OBJECT
typedef struct object {
	int x;
	int y;
	char *icon;
	ColorPair colorPair;
	Character *character;
} Object;
#endif

void moveObjectTowards(Object *obj, Object *towardsObject, Tile map[MAP_WIDTH][MAP_HEIGHT]);
void moveObject(Object *obj, Tile map[MAP_WIDTH][MAP_HEIGHT],  int x, int y); 
bool handleKey(int key, Object *obj, Tile map[MAP_WIDTH][MAP_HEIGHT]);
void printObject(Object obj, WINDOW *win);
void freeObject(Object *obj);
