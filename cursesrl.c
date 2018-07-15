#include <stdlib.h>
#include <ncurses.h>
#include "object.h"
#include "map.h"
#include "rlconst.h"
#include "drawing.h"
#include "character.h"
#include "armor.h"
#include "utility.h"

void setupScreen() {
        initscr();
        start_color();
        initializeColorPairs();
        keypad(stdscr, TRUE);
        curs_set(0);
        noecho();
        init_pair(9, COLOR_BLACK, COLOR_WHITE);
        wbkgd(stdscr, COLOR_PAIR(9));
}

WINDOW *initializeMapWindow() {
  WINDOW *mapWin = newwin(MAP_HEIGHT, MAP_WIDTH, 0, 0);
  init_pair(10, COLOR_WHITE, COLOR_BLACK);
  wbkgd(mapWin, COLOR_PAIR(10));
  return mapWin;
}

WINDOW *initializeStatsWindow() {
  WINDOW *statsWin = newwin(STATS_HEIGHT, STATS_WIDTH, 0, MAP_WIDTH);
  init_pair(11, COLOR_BLACK, COLOR_CYAN);
  wbkgd(statsWin, COLOR_PAIR(11));
  return statsWin;
}

int main() {
  setupScreen();
  WINDOW *mapWin = initializeMapWindow();
  WINDOW *statsWin = initializeStatsWindow();

        wrefresh(mapWin);
        wrefresh(statsWin);
        refresh();
        Map *map = generateMap();
	Character *pc = generatePC();
        Point startPoint = center(map->rooms[0]);
        Point monsterStart = center(map->rooms[1]);
	Object player = { startPoint.x, startPoint.y, '@', CYAN, pc};
	Object monster = { monsterStart.x, monsterStart.y, 'M', RED, NULL};
	while(1) {
		int sightRadius = 5;
		Point position = {player.x, player.y};
		updateVisibility(map, position, sightRadius);
		werase(mapWin);
		werase(statsWin);
		drawMap(map->tiles, mapWin);
		drawStats(*(player.character), statsWin);
		printObject(player, mapWin);
		printObject(monster, mapWin);
		wrefresh(mapWin);
		wrefresh(statsWin);
		int key = getch();

		int exit = handleKey(key, &player, map->tiles);
		if (exit) {
			break;
		}
		moveObjectTowards(&monster, &player, map->tiles);
	}
	free(map);
	free(pc->armor);
	free(pc);
	endwin();
	free(mapWin);
	free(statsWin);
	return 0;
}
