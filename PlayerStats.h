#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H
#include <string>

using namespace std;
class PlayerStats
{
public:
	PlayerStats();

	void SetPlayer(string character, char charCharacter, int lvl, int hp, int pwr, int jmp, int flwrPwr, int spd, int def,int xp, int coin, int statPts);

	void PrintStats();

	void AddPowerPoint();

	void AddJumpPoint();

	void AddFlowerPowerPoint();

	void AddSpeedPoint();

private:
	string characterName;
	char characterChar;
	int level;
	int healthPoints;
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