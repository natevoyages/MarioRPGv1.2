#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H
#include <string>

using namespace std;
class PlayerStats
{
public:
	PlayerStats();

	void SetPlayer(string character, char charCharacter, int& lvl, int& hp, int& pwr, int& jmp, int& flwrPwr, int& spd, int& def,
		int xp, int coin, int& statPts , double& userBattleHP, int userBattleMP, int& MP);

	void PrintStats();

	void AddPowerPoint();

	void AddJumpPoint();

	void AddFlowerPowerPoint();

	void AddSpeedPoint();

	void AddDefensePoint();

private:
	string characterName;
	char characterChar;
	int level;
	int healthPoints;
	int magicPoints;
	int power;
	int jump;
	int flowerPower;
	int speed;
	int defense;
	int experiencePoints;
	int coins;
	int statPoints;
	double battleHP;
	int battleMP;
};
#endif