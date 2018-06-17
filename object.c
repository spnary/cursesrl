#include "object.h"

void moveObject(Object *obj, Tile map[MAP_WIDTH][MAP_HEIGHT],  int x, int y) {
	Tile tile = map[obj->x + x][obj->y + y];
       if (!tile.blocked) {
		obj->x += x;
		obj->y += y;
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
