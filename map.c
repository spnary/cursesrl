#include "map.h"

void initializeMap(Tile map[MAP_WIDTH][MAP_HEIGHT]) {
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			Tile tile = { 0, 0, ' '};
			map[i][j] = tile;
		}
	}
}
