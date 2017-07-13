#include <ncurses.h>
#include "object.h"

void moveObject(Object *obj, int x, int y) {
	obj->x += x;
	obj->y += y;
}

int handleKey(int key, Object *obj) {
	switch(key) {
		case KEY_UP:
			moveObject(obj, 0, -1); 
			return 0;
				
		case KEY_DOWN:
			moveObject(obj, 0, 1);
			return 0;
		case KEY_LEFT:
			moveObject(obj, -1, 0);
				return 0;
		case KEY_RIGHT:
			moveObject(obj, 1, 0);
				return 0;

		default:
				return 1;
	}
}
