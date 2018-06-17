#include <time.h>
#include <stdlib.h>

int rollDice(int count, int sides) {
    int total = 0;
    for (int i=0; i<count; i++) {
       int roll = rand() % sides + 1;
        total += roll;
    }
    return total;
}

void generateStats(int stats[6]) {
    srand(time(NULL));
    for (int i=0; i<6; i++) {
        stats[i] = rollDice(3, 6);
    }
}
