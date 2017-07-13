#include "map.h"

void initializeMap(Tile map[MAP_WIDTH][MAP_HEIGHT]) {
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			Tile tile = { 0, 0, ' '};
			map[i][j] = tile;
		}
	}
}

void addRoomToMap(Room room, Tile map[MAP_WIDTH][MAP_HEIGHT]){
	Tile wallTile = {1, 1, '#', MAGENTA };
	for (int i = room.x; i < room.x + room.width; i++) {
		map[i][room.y] = wallTile;
		map[i][room.y+room.height-1] = wallTile; 
	}
	for (int j = room.y; j < room.y + room.height; j++) {
		map[room.x][j] = wallTile;
		map[room.x + room.height-1][j] = wallTile;
	}
	Tile floorTile = { 0, 0, '.', YELLOW};
	for (int i = room.x+1; i < room.x + room.width -1; i++) {
		for (int j = room.y+1; j < room.y + room.height -1; j++) {
			map[i][j] = floorTile;
		}
	}

}

void printTile(Tile tile, WINDOW *win, int x, int y) {
	char icon[2];
	icon[0] = tile.icon;
	icon[1] = '\0';
	attron(COLOR_PAIR(tile.colorPair));
	mvwprintw(win, y, x, icon); 
	attroff(COLOR_PAIR(tile.colorPair));
}
