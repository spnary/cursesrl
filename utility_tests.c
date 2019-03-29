#include <glib.h>
#include <time.h>
#include <stdlib.h>
#include "utility.h"

void test_d4(){
  srand(time(NULL));
  int roll = rollDice(1, 4);
  g_assert(roll > 0);
  g_assert(roll <= 4);
}

void test_1d6() {
  srand(time(NULL));
  int roll = rollDice(1, 6);
  g_assert(roll > 0);
  g_assert(roll <= 6);
}

void test_3d6() {
  srand(time(NULL));
  int roll = rollDice(3, 6);
  g_assert(roll > 0);
  g_assert(roll <= 18);
}
