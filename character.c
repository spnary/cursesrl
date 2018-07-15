#include <stdlib.h>
#include "character.h"
#include "utility.h"

int abilityModifier(int score) {
	return (score - 10)/2;
}

int armorClass(Character *character) {
	return character->armor->ac + abilityModifier(character->dexterity);
}

Character *generatePC() {
  Armor *leatherArmor = malloc(sizeof(Armor));
  *leatherArmor = (Armor){ 11, "Leather" };
  int stats[6]; 
  generateStats(stats);
  Character *pc = malloc(sizeof(Character));
  *pc  =(Character){ 10, 10, stats[0], stats[1], stats[2], stats[3], stats[4], stats[5], leatherArmor};
  return pc;
}

void freeCharacter(Character *character) {
  free(character->armor);
  free(character);
}
