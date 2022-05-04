#ifndef BATTLEMECHANICS_H
#define BATTLEMECHANICS_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "BattleMenu.h"

using namespace std;

class BattleMechanics
{
public:

	BattleMechanics();

	void SetBattleTrigger();

	int GetBattleTrigger();

	void BattleSetUp(int map);

	void EnemyTurn(double userBattleHP, double userJump, double userSpeed, double userDefense, char userChar);

	void PlayerTurn(double userBattleHP, int userBattleMP, double userPower, double userJump, double userFlowerPower, double userSpeed,
		double userDefense, int level, char userChar);

	void BattleTriggered(int map, bool& notGameOver, int userHealthPoints, int userMagicPoints, int userPower, int userJump, int userFlwrPwr, int userSpeed, int userDefense,
		double& battleHP, int& battleMP, int& usercoins, int& userXP, int& userLevel, int& userCoins, char userChar);

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

	void PrintUserAttack(char userChar);

	void PrintUserAttacked(char userChar);

	void PrintUserIdle(char userChar);

	

protected:
	BattleMenu menu;

	// lvl = 0,hp = 1,pwr = 2,jp = 3,flw = 4,spd = 5,def = 6 ,xpdrop = 7, hitRate = 8, critRate = 9
	double shyGuyStats[10]{1, 40, 5 , 5, 5, 5, 4, 10, 65, 15};  //fix ?

	double desertGoombaStats[10]{ 1, 39, 6, 6, 4, 5, 6 , 12, 65, 15 };

	double pokeyStats[10]{ 2, 44, 7, 3, 9, 2, 9, 16, 65, 15 };

	double birdoStats[10]{ 5, 100, 16, 8, 14, 9, 15, 175, 75, 30 };

	double cheepCheepStats[10]{ 3, 55, 8, 10, 7, 9, 8, 22, 65, 20 };

	double blooperStats[10]{ 4, 65, 10, 9, 9, 10, 8, 30, 68, 20 };

	double mechaBlooperStats[10]{ 8, 150, 19, 13, 14, 8, 17, 550, 79, 33};

	double castleGoombaStats[10]{ 5, 75, 12, 12, 11, 10, 11 , 45,  65, 19 };

	double koopaTroopaStats[10]{ 6, 80, 12, 12, 11, 10, 15, 65, 65, 21 };

	double booStats[10]{7, 90, 12, 12, 11, 10, 11, 90, 65, 15,};

	double kingBooStats[10]{11, 275, 25, 20, 28, 19, 18, 2000, 87, 42};

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