#ifndef BATTLEMECHANICS_H
#define BATTLEMECHANICS_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include "BattleMenu.h"

using namespace std;

class BattleMechanics
{
public:

	BattleMechanics();

	void SetBattleTrigger();

	int GetBattleTrigger();

	void BattleSetUp(int map);

	void UserAttackAnimation(char userChar, double damage, double battleHP, int battleMP, int HP, int MP);

	void EnemyTurn(double& userBattleHP, double userJump, double userSpeed, double userDefense, char userChar, int userBattleMP, int userHP, int userMP);

	void PlayerTurn(double& userBattleHP, int& userBattleMP, double userPower, double userJump, double userFlowerPower, double userSpeed,
		double userDefense, int level, char userChar, int userHP, int userMP);

	void BattleTriggered(int map, bool& notGameOver, int userHealthPoints, int userMagicPoints, int userPower, int userJump, int userFlwrPwr, int userSpeed, int userDefense,
		double& battleHP, int& battleMP, int& usercoins, int& userXP, int& userLevel, int& userCoins, char userChar, bool& battleState);

	void SpeedsterGoesFirst(int userSpeed, bool& playerFirst);

	void UserBattleLogic(double userBattleHP, int userBattleMP, double userPower, double userJump, double userFlowerPower, double userSpeed,
		double userDefense, int level);

	void EnemyBattleMechanics(double userJump, double userSpeed, double userDefense);

	void EnemyBattleLogic();

	void LoadShyGuy();

	void LoadDesertGoomba();

	void LoadPokey();

	void LoadBirdo();

	void LoadCheepCheep();

	void LoadBlooper();

	void LoadMechaBlooper();

	void LoadCastleGoomba();

	void LoadKoopaTroopa();

	void LoadBoo();

	void LoadKingBoo();

	void PrintEnemyAttack();

	void PrintEnemyAttacked();

	void PrintEnemyIdle();

	void PrintUserAttack(char userChar, int battleMP, int userHP, int userMP, double userBattleHP);

	void PrintUserAttacked(char userChar, int battleMP, int userHP, int userMP, double userBattleHP);

	void PrintUserIdle(char userChar, int battleMP, int userHP, int userMP, double userBattleHP);

	

private:
	BattleMenu menu;

	// lvl = 0,hp = 1,pwr = 2,jp = 3,flw = 4,spd = 5,def = 6 ,xpdrop = 7, hitRate = 8, critRate = 9
	double shyGuyStats[10]{1, 40, 8 , 5, 5, 5, 4, 10, 65, 5};  //fix crit rates and coin drops

	double desertGoombaStats[10]{ 1, 39, 9, 6, 4, 5, 6 , 12, 65, 5 };

	double pokeyStats[10]{ 2, 44, 10, 3, 9, 2, 9, 16, 65, 10 };

	double birdoStats[10]{ 5, 100, 19, 8, 14, 9, 15, 500, 75, 100 };

	double cheepCheepStats[10]{ 3, 55, 12, 10, 7, 9, 8, 22, 65, 18 };

	double blooperStats[10]{ 4, 65, 10, 13, 9, 10, 8, 30, 68, 22 };

	double mechaBlooperStats[10]{ 8, 150, 27, 13, 14, 8, 22, 2000, 79, 300};

	double castleGoombaStats[10]{ 5, 75, 16, 12, 11, 10, 11 , 45,  65, 19 };

	double koopaTroopaStats[10]{ 6, 80, 17, 12, 11, 10, 15, 65, 65, 21 };

	double booStats[10]{7, 90, 20, 12, 11, 10, 11, 90, 65, 15,};

	double kingBooStats[10]{11, 275, 32, 20, 28, 19, 25, 10000, 87, 42};

	double stats[10];

	double damage;

	double critDamage;

	double specialDamage;

	double specialCrit;

	double escapeSucess;
	
	double hitSuccess;

	double critSuccess;

	int stepTrigger;

	int enemyNum;

	bool battleState;

	bool enemyPowAttack;

	double battleHP;

	int enemySignature;

	bool attackSelected;

	bool spAttackSelected;

	bool itemSelected;

	bool runSelected;


};
#endif