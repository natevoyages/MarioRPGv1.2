#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H
#include <string>
#include <windows.h>

using namespace std;
class PlayerStats
{
public:
	PlayerStats();

	void SetPlayer(double& userBattleHP, int& userBattleMP);
	//sets player battlHP and battleMP after a battle

	void SetPlayer(string character, char charCharacter, int& lvl, int& hp, int& pwr, int& jmp, int& flwrPwr, int& spd, int& def,
		int xp, int coin, int& statPts , double& userBattleHP, int userBattleMP, int& MP);
	//sets stats and character info 

	double GetPlayerBattleHP() const;
	// returns PlayerBattleHP

	int GetPlayerHP() const;
	// returns PlayerHP

	int GetPlayerBattleMP() const;
	// returns PlayerBattleMP

	int GetPlayerMP() const;
	// returns PlayerMP

	int GetPowStat() const;
	// returns PowStat

	int GetJmpStat() const;
	// returns JmpStat

	int GetFpwStat() const;
	// returns FlowerpowerStat

	int GetSpdStat() const;
	// returns speedstat

	int GetDefStat() const;
	// returns def stat

	int GetLevel() const;
	// returns player level


	void PrintStats();
	// prints player stats

	void UseRedMushroom(int& redMushroom);
	//Uses RedMushroom
    //player gains 15 battlehp

	void UseMegaRedMushroom(int& megaRedMushroom);
	//Uses MegaRedMushroom
    //player gains 50 battlehp

	void UseStarDust(int& starDust);
	//Uses StarDust
    //player gains 10 battlehp

	void UseGreenMushroom(int& greenMushroom);  
	// add 1 HP permantly to hp cap and heals player completly

	void LevelUpStats();
	//adds to stat totals for each level up

	void LevelUp(int experiencePoints);
	// checks if xp is passed level threshold and prints level up
	// checks if player current level is less than or equal to new level

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