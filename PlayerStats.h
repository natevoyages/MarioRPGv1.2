#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H
#include <string>
#include <windows.h>

using namespace std;
class PlayerStats
{
public:
	PlayerStats();

	void TransferPlayer(string character, char iconCharacter, int& lvl, int& userHP, int& pwr, int& jmp, int& flwrPwr, int& spd, int& def, int xp, int coin, int& statPts, double& userBattleHP, int userBattleMP, int& userMP);

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

	void LevelUpStats();

	void LevelUp(int experiencePoints);

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
	int eXPThresholds[10]{ 60, 200, 450, 1000, 1240, 2000, 3000, 6000, 10000, 18000 };
};
#endif