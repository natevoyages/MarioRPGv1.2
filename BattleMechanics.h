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
	//sets the steps needed to start a battle encounter

	int GetBattleTrigger();
	// Returns stepTrigger variable

	void BattleSetUp(int map, int& bossesBeaten);
	// sets up enemies and bosses based on map and bosses beaten


	void UserAttackAnimation(char userChar, double damage, double userBattleHP, int userBattleMP, int userHP, int userMP);
	// animates user attacks on enemies


	void EnemyTurn(double& userBattleHP, double userJump, double userSpeed, double userDefense, char userChar, int userBattleMP, int userHP, int userMP, bool& escape);
	// enemy attemps an attack or special attack hits or misses 
	////if battleHP is 0 then win is triggered and player continues onto the OverWorld



	void PlayerTurn(double& userBattleHP, int& userBattleMP, double userPower, double userJump, double userFlowerPower, double userSpeed, double userDefense,
		int userLevel, char userChar, int userHP, int userMP, Items& battleItems, bool& playerTurnOver, bool& escape);
	// battleMenu class is activated and bools used are determed to execute the following:
	// user attemps an attack or special attack hits or misses 
	// uses an item or attempts to run away (Boss battles will signal you cannot run away)
	//if battleHP is 0 then GameOver is triggered




	void BattleTriggered(int map, bool& notGameOver, int userHealthPoints, int userMagicPoints, int userPower, int userJump, int userFlowerPower, int userSpeed,
		int userDefense, double& userBattleHP, int& userBattleMP, int& usercoins, int& userXP, int& userLevel, int& userCoins, char userChar, bool& battleState, Items& items, PlayerStats& playerStats, int& bossesBeaten);
	//sets battle state for bosses and enemies
	// add boss beaten if player successfully beat a boss


	void CritChance(double& critSucess, bool success);
	// sets if a crit is successfully set for battle


	void HitChance(double& hitSuccess, bool& success);
	// sets if a hit is successfully set for battle

	void RunAwayChance(double& escapeSuccess, bool& success);
	// sets if a run is successfully set for battle


	void SpeedsterGoesFirst(int userSpeed, bool& playerFirst);
	// determines who goes first in battle based on who has a higher speed stat
	// if both stats are equal then 50/50 chance is set to determine who goes first


	void UserBattleLogic(double userBattleHP, int userBattleMP, double userPower, double userJump, double userFlowerPower, double userSpeed,
		double userDefense, int level);
	// determine user's damage, specialdamage, crit damage for regular and specal, critrates, escaperates, hitrates. 


	void EnemyBattleMechanics(double userJump, double userSpeed, double userDefense);
	// determine enemy's damage, specialdamage, crit damage for regular and specal, critrates, hitrates.


	void EnemyBattleLogic();
	//determines by coin flip if enemy will use regular attack or special attack


	             // Loaded enemies are read from an array of elements for stats set to 
	             //a for loop based on the num of elements

	void LoadShyGuy();
	// Loads ShyGuy stats


	void LoadDesertGoomba();
	// Loads DesertGoomba stats and enemy signature

	void LoadPokey();
	// Loads Pokey stats and enemy signature


	void LoadBirdo();
	// Loads Boss: Birdo stats and enemy signature

	void LoadCheepCheep();
	// Loads CheepCheep stats and enemy signature

	void LoadBlooper();
	// Loads Blooper stats and enemy signature

	void LoadMechaBlooper();
	// Loads Boss: MechaBlooper stats and enemy signature

	void LoadCastleGoomba();
	// Loads CastleGoomba stats and enemy signature

	void LoadKoopaTroopa();
	// Loads KoopaTroopa stats and enemy signature

	void LoadBoo();
	// Loads Boo stats and enemy signature

	void LoadKingBoo();
	// Loads Boss: KingBoo stats and enemy signature
	

	                              //frames for battles

	void PrintEnemyAttack();
	//Prints Enemy lunging forward

	void PrintEnemyAttacked();
	//Prints Enemy recoiling backwards

	void PrintEnemyIdle();
	//Prints Enemy idle


	void PrintUserAttack(char userChar, int battleMP, int userHP, int userMP, double userBattleHP);
	//Prints user lunging forward

	void PrintUserAttacked(char userChar, int battleMP, int userHP, int userMP, double userBattleHP);
	//Prints user recoiling backwards

	void PrintUserIdle(char userChar, int battleMP, int userHP, int userMP, double userBattleHP);
	//Prints user idle




private:
	BattleMenu menu;

	InputConfig battleInput;

	// array of stats for enemies with each element meaning:
	// lvl = 0,hp = 1,pwr = 2,jp = 3,flw = 4,spd = 5,def = 6 ,xpdrop = 7, hitRate = 8, critRate = 9, coins = 10

	double shyGuyStats[11]{ 1, 40, 8 , 5, 5, 5, 4, 5, 65, 15, 3 };  

	double desertGoombaStats[11]{ 1, 39, 9, 6, 4, 5, 6 , 8, 65, 15, 5 };

	double pokeyStats[11]{ 2, 44, 10, 3, 9, 2, 9, 13, 65, 15 , 8 };

	double birdoStats[11]{ 5, 100, 19, 8, 14, 9, 15, 500, 75, 30 , 300 };

	double cheepCheepStats[11]{ 3, 55, 12, 10, 7, 9, 8, 22, 65, 20 , 20 };

	double blooperStats[11]{ 4, 65, 10, 13, 9, 10, 8, 28, 68, 20 , 23 };

	double mechaBlooperStats[11]{ 8, 150, 27, 13, 14, 8, 22, 2000, 79, 33 , 750 };

	double castleGoombaStats[11]{ 5, 75, 16, 12, 11, 10, 11 , 45,  65, 19 , 36 };

	double koopaTroopaStats[11]{ 6, 80, 17, 12, 11, 10, 15, 50, 65, 21 , 41 };

	double booStats[11]{ 7, 90, 20, 12, 11, 10, 11, 70, 65, 15, 49 };

	double kingBooStats[11]{ 11, 275, 32, 20, 28, 19, 25, 8000, 87, 42 , 1500 };

	// where enemy stats are loaded in for battle
	double stats[11];

	double damage;

	double critDamage;

	double specialDamage;

	double specialCrit;

	double escapeSucess;

	double hitSuccess;

	double critSuccess;

	//battle encounter for steps
	int stepTrigger;
	
	//used in maps to determine which enemy will spawn based on random number
	int enemyNum;

	bool enemyPowAttack;

	// determines what sprites will be chosen for enemies/bosses
	int enemySignature;

	// bools for battle
	bool attackSelected;

	bool spAttackSelected;

	bool itemSelected;

	bool runSelected;

	bool userSuccessHit;

	bool userSuccessCrit;



};
#endif