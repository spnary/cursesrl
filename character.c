#include "character.h"

int abilityModifier(int score) {
	return (score - 10)/2;
}

int armorClass(Character *character) {
	return character->armor->ac + abilityModifier(character->dexterity);
}
