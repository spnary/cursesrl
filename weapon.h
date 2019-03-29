#ifndef __WEAPON
#define __WEAPON
typedef struct weapon {
  int numberOfDice;
  int diceSides;
  int toHitBonus;
  int damageBonus;
} Weapon;
#endif

int attack(Weapon *weapon);
