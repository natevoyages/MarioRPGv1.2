#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <string>
using namespace std;

class Characters {

public:
	void PrintMario();

	void PrintLuigi();

	void PrintToad();
	
	void SetCharacter(string character);

	string GetCharacter();

private:
	string characterName;
	char characterChar;
	int level;
	int strength;
	int jump;
	int flowerPower;
	int speed;
	int experiencePoints;
	int coins;
	int statPoints;

};
#endif
