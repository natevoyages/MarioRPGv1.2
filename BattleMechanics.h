#ifndef BATTLEMECHANICS_H
#define BATTLEMECHANICS_H

#include <iostream>
#include <vector>

using namespace std;

class BattleMechanics
{
public:

	BattleMechanics();

	void SetBattleTrigger();

	void BattleSetUp(int map);

	void EnemyTurn(double userBattleHP, double userJump, double userSpeed, double userDefense);

	void PlayerTurn(double userBattleHP, int userBattleMP, double userJump, double userSpeed, double userDefense);

	void BattleTriggered(int map, bool& notGameOver, int userHealthPoints, int userMagicPoints, int userJump, int userFlwrPwr, int userSpeed, int userDefense,
		int& battleHP, int& battleMP, int& usercoins, int& userXP);

	void SpeedsterGoesFirst(int userSpeed, bool& playerFirst);

	void UserBattleLogic(double userBattleHP, int userBattleMP, double userPower, double userJump, double userFlowerPower, double userSpeed, double userDefense);

	void EnemyBattleLogic(double userJump, double userSpeed, double userDefense);

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

	

protected:
	// lvl = 0,hp = 1,pwr = 2,jp = 3,flw = 4,spd = 5,def = 6 ,xpdrop = 7, hitRate = 8, critRate = 9
	int shyGuyStats[10]{1, 40, 5 , 5, 5, 5, 4, 10, 65, 15};  //fix ?

	vector<double> desertGoombaStats{ 1, 39, 6, 6, 4, 5, 6 , 12, 65, 15 };

	vector<double> pokeyStats{ 2, 44, 7, 3, 9, 2, 9, 16, 65, 15 };

	vector<double> birdoStats{ 5, 100, 16, 8, 14, 9, 15, 175, 75, 30 };

	vector<double> cheepCheepStats{ 3, 55, 8, 10, 7, 9, 8, 22, 65, 20 };

	vector<double> blooperStats{ 4, 65, 10, 9, 9, 10, 8, 30, 68, 20 };

	vector<double> mechaBlooperStats{ 8, 150, 19, 13, 14, 8, 17, 550, 79, 33};

	vector<double> castleGoombaStats{ 5, 75, 12, 12, 11, 10, 11 , 45,  65, 19 };

	vector<double> koopaTroopaStats{ 6, 80, 12, 12, 11, 10, 15, 65, 65, 21 };

	vector<double> booStats{ 7, 90, 12, 12, 11, 10, 11, 90, 65, 15, 25 };

	vector<double> kingBooStats{ 11, 275, 25, 20, 28, 19, 18, 2000, 87, 42 };

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

	double battleHP;

	int enemySignature;


};
#endif