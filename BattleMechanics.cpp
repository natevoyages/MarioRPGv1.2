#include "BattleMechanics.h"

BattleMechanics::BattleMechanics()
{
	enemyNum = -1;
	stepTrigger = 999;
	enemySignature = -1;
	battleState = false;
}

void BattleMechanics::SetBattleTrigger()
{
	srand(time(0));
	stepTrigger = rand() % 16 + 20; // 20 to 35 step to trigger battle

}

void BattleMechanics::BattleSetUp(int map)
{
	if (map == 1 || map == 2)
	{
		enemyNum = rand() % 3;
		if (enemyNum == 0)
		{
			LoadShyGuy();
			enemySignature = 0;
		}
		else if (enemyNum == 1)
		{
			LoadDesertGoomba();
			enemySignature = 1;
		}
		else if (enemyNum == 2)
		{
			LoadPokey();
			enemySignature = 2;
		}
	}
	else if( map == 5 || map == 6)
	{
		enemyNum = rand() % 2;
		if (enemyNum == 0)
		{
			LoadCheepCheep();
			enemySignature = 3;
		}
		else if (enemyNum == 1)
		{
			LoadBlooper();
			enemySignature = 4;
		}
	}
	else if (map == 9 || map == 11)
	{
		enemyNum = rand() % 3;
		if (enemyNum == 0)
		{
			LoadCastleGoomba();
			enemySignature = 5;
		}
		else if (enemyNum == 1)
		{
			LoadKoopaTroopa();
			enemySignature = 6;
		}
		else if (enemyNum == 2)
		{
			LoadBoo();
			enemySignature = 7;
		}
	}
	enemyNum = -1;
}

void BattleMechanics::EnemyTurn(double userBattleHP, double userJump, double userSpeed, double userDefense)
{
	EnemyBattleLogic(userJump, userSpeed, userDefense);
	//Print Enemy
}

void BattleMechanics::PlayerTurn(double userBattleHP, int userBattleMP, double userJump, double userSpeed, double userDefense)
{
	UserBattleLogic(userBattleHP, userBattleMP, userJump, userSpeed, userDefense);
}

void BattleMechanics::BattleTriggered(int map, bool& notGameOver, int userHealthPoints, int userMagicPoints, int userJump, int userFlwrPwr,
	int userSpeed, int userDefense, int& userBattleHP, int& userBattleMP, int& usercoins, int& userXP)
{
	bool playerFirst = false;
	bool win = false;

	BattleSetUp(map);
	SpeedsterGoesFirst(userSpeed, playerFirst);
	if (!playerFirst) {
		while (battleState)
		{
			EnemyTurn(userBattleHP, userJump, userSpeed, userDefense);
			PlayerTurn(userBattleHP, userBattleMP, userJump, userSpeed, userDefense);
			if (userBattleHP == 0)
			{
				win = false;
			}
			else if (battleHP == 0)
			{
				win = true;
			}
		}
	}
	else
	{
		while (battleState)
		{
			PlayerTurn(userBattleHP, userBattleMP, userJump, userSpeed, userDefense);
			EnemyTurn(userBattleHP, userJump, userSpeed, userDefense);
			if(userBattleHP == 0)
			{
				win = false;
			}
			else if (battleHP == 0)
			{
				win = true;
			}
		}
	}
	SetBattleTrigger();
	if (!win) {
		notGameOver = false;
	}
}

void BattleMechanics::SpeedsterGoesFirst(int userSpeed, bool& playerFirst)
{
	int coinFlip = -1;
	if (stats[5] > userSpeed)
	{
		playerFirst = false;
	}
	else if (stats[5] < userSpeed)
	{
		playerFirst = true;
	}
	else
	{
		coinFlip = rand() % 2;
		if (coinFlip == 0)
		{
			playerFirst = false;
		}
		else if (coinFlip == 1)
		{
			playerFirst = true;
		}
	}
}

void BattleMechanics::UserBattleLogic(double userBattleHP, int userBattleMP, double userPower, double userJump, double userFlowerPower, double userSpeed, double userDefense)
{
	//jp = 3, spd = 5, def = 6;
	damage = userPower * (10.0 / 10.0 + stats[6]);
	specialDamage = userFlowerPower *((8.0 / 8.0 + stats[6]));
	critDamage = 1.5 * damage;
	specialCrit = 1.5 * specialDamage;
	hitSuccess = 85  + (userSpeed * (5.0 / 5.0 + stats[5]));   // 85 is the hit rate for users
	critSuccess = 45 + (userJump * (5.0 / 5.0 + stats[3])); //45 is the crit rate for users
}

void BattleMechanics::EnemyBattleLogic(double userJump, double userSpeed, double userDefense)
{//pwr = 2,jp = 3,flw = 4,spd = 5,hitRate = 8, critRate = 9
	damage = stats[2] * (10.0 / 10.0 + userDefense);
	specialDamage = stats[4] * ((8.0 / 8.0 + userDefense));
	critDamage = 1.5 * damage;
	specialCrit = 1.5 * specialDamage;
	hitSuccess = stats[8] + (stats[5] * (5.0 / 5.0 + userSpeed));
	critSuccess = stats[9] + (stats[3] * (5.0 / 5.0 + userJump));
}

void BattleMechanics::LoadShyGuy()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = shyGuyStats[i];
	}
}

void BattleMechanics::LoadDesertGoomba( )
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = desertGoombaStats[i];
	}
}

void BattleMechanics::LoadPokey()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = pokeyStats[i];
	}
}
void BattleMechanics::LoadBirdo()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = birdoStats[i];
	}
}
void BattleMechanics::LoadCheepCheep()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = cheepCheepStats[i];
	}
}
void BattleMechanics::LoadBlooper()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = blooperStats[i];
	}
}
void BattleMechanics::LoadMechaBlooper()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = mechaBlooperStats[i];
	}
}
void BattleMechanics::LoadCastleGoomba()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = castleGoombaStats[i];
	}
}
void BattleMechanics::LoadKoopaTroopa()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = koopaTroopaStats[i];
	}
}

void BattleMechanics::LoadBoo()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = booStats[i];
	}
}

void BattleMechanics::LoadKingBoo()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = kingBooStats[i];
	}
}
