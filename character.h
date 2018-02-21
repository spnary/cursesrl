
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
} Character;
#endif

int abilityModifier(int score);
