#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"

void initializeMap(Map *map){
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			Tile tile = { 1, 1, '#', WHITE, 0};
			map->tiles[i][j] = tile;
		}
	}
}

void addRoomToMap(Room room, Tile tiles[MAP_WIDTH][MAP_HEIGHT]){
	Tile floorTile = { 0, 0, '.', YELLOW, 0};
	for (int i = room.x; i < room.x + room.width; i++) {
		for (int j = room.y; j < room.y + room.height; j++) {
			tiles[i][j] = floorTile;
		}
	}

}

bool roomsIntersect(Room room1, Room room2) {
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
		Tile floorTile = { 0, 0, '.', YELLOW, 0};
		map[i][y] = floorTile;
	}
}

void generateVerticalTunnel(int y1, int y2, int x, Tile map[MAP_WIDTH][MAP_HEIGHT]) {
	int min = y1 < y2 ? y1 : y2;
	int max = y1 > y2 ? y1 : y2;
	for (int j = min; j <= max; j++) {
		Tile floorTile = { 0, 0, '.', YELLOW, 0};
		map[x][j] = floorTile;
	}
}

Room makeRoom(int roomSizeMax, int roomSizeMin){
	int width = rand() % roomSizeMax + roomSizeMin;
	int height = rand() % roomSizeMax + roomSizeMin;
	int x = rand() % (MAP_WIDTH - width - 1 );
	int y = rand() % (MAP_HEIGHT - height - 1);

	Room room = {x, y, width, height};
	return room;
}

bool doesRoomIntersectExistingRooms(Room room, Room rooms[]) {
  bool intersects = false;
	for (int i = 0; i < MAX_ROOMS; i++) {
		if (roomsIntersect(rooms[i], room)) {
			intersects = true;
			break;
		}
	}
	return intersects;
}

void connectRoomWithPreviousRoomInMap(Room newRoom, Room previousRoom, Tile map[MAP_WIDTH][MAP_HEIGHT]) {
	Point newCenter = center(newRoom);	
	Point previousCenter = center(previousRoom);
	if (rand() % 2 == 0) {
		generateHorizontalTunnel(previousCenter.x, newCenter.x, previousCenter.y, map);
		generateVerticalTunnel(previousCenter.y, newCenter.y, newCenter.x, map);
	} else {
 		generateVerticalTunnel(previousCenter.y, newCenter.y, previousCenter.x, map);
	  	generateHorizontalTunnel(newCenter.x, previousCenter.x, newCenter.y, map);
	}
  
}

void generateRooms(int roomSizeMax, int roomSizeMin, Tile map[MAP_WIDTH][MAP_HEIGHT], Room rooms[MAX_ROOMS]){
	srand(time(NULL));
	int roomCount = 0;
	for (int i = 0; i < MAX_ROOMS; i++) {
	  Room room = makeRoom(roomSizeMax, roomSizeMin);
	  bool roomIntersects = doesRoomIntersectExistingRooms(room, rooms);
	  if (!roomIntersects) {
			rooms[roomCount] = room;
			addRoomToMap(room, map);
			if (roomCount > 0) {
  				Room lastRoom = rooms[roomCount-1];
				connectRoomWithPreviousRoomInMap(room, lastRoom, map);
			}
			roomCount++;
		}
	}
}

void updateVisibility(Map *map, Point point, int radius){
	int minX = point.x - radius > 0 ? point.x - radius : 0;
	int maxX = point.x + radius < MAP_WIDTH ? point.x + radius : MAP_WIDTH;
	int minY = point.y - radius > 0 ? point.y - radius : 0;
	int maxY = point.y + radius < MAP_HEIGHT ? point.y + radius : MAP_HEIGHT;

	for (int i = minX; i < maxX; i++){
		for (int j = minY; j < maxY; j++){
			Tile tile = map->tiles[i][j];
			tile.explored = 1;
			map->tiles[i][j] = tile;
		}
	}
}
