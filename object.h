#include "rlconst.h"
#include "map.h"

#ifndef __OBJECT
#define __OBJECT
typedef struct object {
	int x;
	int y;
	char icon;
} Object;
#endif

void moveObject(Object *obj, Tile map[MAP_WIDTH][MAP_HEIGHT],  int x, int y); 
int handleKey(int key, Object *obj, Tile map[MAP_WIDTH][MAP_HEIGHT]);
