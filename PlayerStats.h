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

	double GetPlayerBattleHP() const;

	int GetPlayerHP() const;

	int GetPlayerBattleMP() const;

	int GetPlayerMP() const;

	int GetPowStat() const;

	int GetJmpStat() const;

	int GetFpwStat() const;

	int GetSpdStat() const;

	int GetDefStat() const;

	void PrintStats();

	void AddPowerPoint();

	void AddJumpPoint();

	void AddFlowerPowerPoint();

	void AddSpeedPoint();

	void AddDefensePoint();

	void UseRedMushroom(int& redMushroom);

	void UseMegaRedMushroom(int& megaRedMushroom);

	void UseStarDust(int& starDust);

	void UseGreenMushroom(int& greenMushroom);

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