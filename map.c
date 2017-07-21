#include <stdlib.h>
#include "map.h"

void initializeMap(Tile map[MAP_WIDTH][MAP_HEIGHT]) {
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			Tile tile = { 1, 1, '#', WHITE};
			map[i][j] = tile;
		}
	}
}

void addRoomToMap(Room room, Tile map[MAP_WIDTH][MAP_HEIGHT]){
	Tile floorTile = { 0, 0, '.', YELLOW};
	for (int i = room.x; i < room.x + room.width; i++) {
		for (int j = room.y; j < room.y + room.height; j++) {
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

Point center(Room room) {
	int centerX = room.x + room.width/2;
	int centerY = room.y + room.height/2;
	Point centerPoint = {centerX, centerY};
	return centerPoint;
}

void generateHorizontalTunnel(int x1, int x2, int y, Tile map[MAP_WIDTH][MAP_HEIGHT]){
	int min = x1 < x2 ? x1 : x2;
	int max = x1 > x2 ? x1 : x2;
	for (int i = min; i <= max; i++) {
		Tile floorTile = { 1, 1, '.', YELLOW};
		map[i][y] = floorTile;
	}
}

void generateVerticalTunnel(int y1, int y2, int x, Tile map[MAP_WIDTH][MAP_HEIGHT]) {
	int min = y1 < y2 ? y1 : y2;
	int max = y1 > y2 ? y1 : y2;
	for (int j = min; j <= max; j++) {
		Tile floorTile = { 1, 1, '.', YELLOW};
		map[x][j] = floorTile;
	}
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
			rooms[roomCount] = room;
			if (roomCount > 0) {
				Point newCenter = center(room);	
				Room lastRoom = rooms[roomCount-1];
				Point lastCenter = center(lastRoom);
				generateHorizontalTunnel(lastCenter.x, newCenter.x, lastCenter.y, map);
				generateVerticalTunnel(lastCenter.y, newCenter.y, newCenter.y, map);
			}
			roomCount++;
		}

	}
	for (int i = 0; i < roomCount; i++) {
		addRoomToMap(rooms[i], map);
	}
}
