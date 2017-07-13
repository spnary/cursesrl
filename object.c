#include <ncurses.h>
#include "object.h"

void moveObject(Object *obj, Tile map[MAP_WIDTH][MAP_HEIGHT],  int x, int y) {
       if (!map[obj->x + x][obj->y + y].blocked) {
		obj->x += x;
		obj->y += y;
       }
}

int handleKey(int key, Object *obj, Tile map[MAP_WIDTH][MAP_HEIGHT]) {
	switch(key) {
		case KEY_UP:
			moveObject(obj, map, 0, -1); 
			return 0;
				
		case KEY_DOWN:
			moveObject(obj, map, 0, 1);
			return 0;
		case KEY_LEFT:
			moveObject(obj, map, -1, 0);
				return 0;
		case KEY_RIGHT:
			moveObject(obj, map, 1, 0);
				return 0;

		default:
				return 1;
	}
}
