#include <stdlib.h>
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
	Tile wallTile = {1, 1, '#', WHITE};
	for (int i = room.x; i < room.x + room.width; i++) {
		map[i][room.y] = wallTile;
		map[i][room.y+room.height-1] = wallTile; 
	}
	for (int j = room.y; j < room.y + room.height; j++) {
		map[room.x][j] = wallTile;
		map[room.x + room.width-1][j] = wallTile;
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
	wattron(win, COLOR_PAIR(tile.colorPair));
	mvwprintw(win, y, x, icon); 
	wattroff(win, COLOR_PAIR(tile.colorPair));
}

int roomsIntersect(Room room1, Room room2) {
	return (room1.x <= room2.x + room2.width-1) && (room1.x + room1.width-1  >= room2.x) &&
		(room1.y <= room2.y + room2.height-1) && (room1.y + room1.height-1 >= room2.y);
}

void generateRooms(int maxRooms, int roomSizeMax, int roomSizeMin, Tile map[MAP_WIDTH][MAP_HEIGHT]){
	Room rooms[maxRooms];
	int roomCount = 0;
	for (int i = 0; i < maxRooms; i++) {
		int w = rand() % roomSizeMax + roomSizeMin;
		int h = rand() % roomSizeMax + roomSizeMin;
		int x = rand() % (MAP_WIDTH - w - 1 );
		int y = rand() % (MAP_HEIGHT - h - 1);

		Room room = {x, y, w, h};
		int failed = 0;
		for (int j = 0; j < maxRooms; j++) {
			if (roomsIntersect(rooms[j], room)) {
				failed = 1;
				break;
			}
		}		
		if (!failed) {
			addRoomToMap(room, map);
			rooms[roomCount] = room;
			roomCount++;
		}

	}
}
