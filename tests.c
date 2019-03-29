#include <glib.h>
#include "utility_tests.h"
#include "weapon_tests.h"

int main(int argc, char *argv[]) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/diceTests/d4", test_d4);
  g_test_add_func("/diceTests/1d6", test_1d6);
  g_test_add_func("/diceTests/3d6", test_3d6);

  g_test_add_func("/weaponTests/ToHit_NoBonus", test_weaponToHit_NoBonus);
  
  return g_test_run();
}
