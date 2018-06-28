#include "object.h"
#include <stdlib.h>

void moveObject(Object *obj, Tile map[MAP_WIDTH][MAP_HEIGHT],  int x, int y) {
	Tile tile = map[obj->x + x][obj->y + y];
       if (!tile.blocked) {
		obj->x += x;
		obj->y += y;
       }
}

void moveObjectTowards(Object *obj, Object *towardsObject, Tile map[MAP_WIDTH][MAP_HEIGHT]){
	int axis = rand() % 2; // flip a coin on whether to move horizontally or vertically
	int horizontalDistance = towardsObject->x - obj->x;
	int verticalDistance = towardsObject->y - obj->y;
	if (horizontalDistance == 1) {
		axis = 1;
	}
	if (verticalDistance == 1) {
		axis = 0;
	}
	if (horizontalDistance == 1 && verticalDistance == 1) {
		return;
	}
	if ( axis == 0 ) {
		if (horizontalDistance > 0) {
			moveObject(obj, map, 1, 0);
		} else {
			moveObject(obj, map, -1, 0);
		}
	} else {
		if (verticalDistance > 0) {
			moveObject(obj, map, 0, 1);
		} else {
			moveObject(obj, map, 0, -1);
		}
	}
}

int handleKey(int key, Object *obj, Tile map[MAP_WIDTH][MAP_HEIGHT]) {
	switch(key) {
		case 'k':
		case KEY_UP:
			moveObject(obj, map, 0, -1);
			return 0;
		case 'j':
		case KEY_DOWN:
			moveObject(obj, map, 0, 1);
			return 0;
		case 'h':
		case KEY_LEFT:
			moveObject(obj, map, -1, 0);
				return 0;
		case 'l':
		case KEY_RIGHT:
			moveObject(obj, map, 1, 0);
				return 0;
		case 'q':
				return 1;
		default:
				return 0;
	}
}

void printObject(Object obj, WINDOW *win) {
	char icon[2];
	icon[0] = obj.icon;
	icon[1] = '\0';
	wattron(win, COLOR_PAIR(obj.colorPair));
	mvwprintw(win, obj.y, obj.x, icon); 
	wattroff(win, COLOR_PAIR(obj.colorPair));
}
