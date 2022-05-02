#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <string>
using namespace std;

class Characters {

public:
	void PrintMario();

	void PrintLuigi();

	void PrintToad();
	

private:
	string characterName;
	char characterChar;
	int level;
	int power;
	int jump;
	int flowerPower;
	int speed;
	int defense;
	int experiencePoints;
	int coins;
	int statPoints;

};
#endif
