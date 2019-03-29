#include "weapon.h"
#include "utility.h"

int attack(Weapon *weapon){
  int diceRoll = rollDice(weapon->numberOfDice, weapon->diceSides);
  int toHit = diceRoll + weapon->toHitBonus;
  return toHit;
}
