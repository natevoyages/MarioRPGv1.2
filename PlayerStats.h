#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H
#include <string>

using namespace std;
class PlayerStats
{
public:
	PlayerStats();

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
	int experiencePoints;
	int coins;
	int statPoints;
};
#endif