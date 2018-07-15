#include "armor.h"
#ifndef __CHARACTER
#define __CHARACTER
typedef struct character {
	int maxHP;
	int currentHP;
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
	Armor *armor;
} Character;
#endif

int abilityModifier(int score);
int armorClass(Character *character);
Character *generatePC();
