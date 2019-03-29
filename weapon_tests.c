#include <glib.h>
#include "weapon.h"

void test_weaponToHit_NoBonus() {
  Weapon longsword = { 1, 6, 0, 0 };
  int toHit = attack(&longsword);
  g_assert(toHit < 6);
  g_assert(toHit > 0);
}
