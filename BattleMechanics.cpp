#include "BattleMechanics.h"

BattleMechanics::BattleMechanics()
{
	enemyNum = -1;
	stepTrigger = 999;
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
		}
		else if (enemyNum == 1)
		{
			LoadDesertGoomba();
		}
		else if (enemyNum == 2)
		{
			LoadPokey();
		}
	}
	else if( map == 5 || map == 6)
	{
		enemyNum = rand() % 2;
		if (enemyNum == 0)
		{
			LoadCheepCheep();
		}
		else if (enemyNum == 1)
		{
			LoadBlooper();
		}
	}
	else if (map == 9 || map == 11)
	{
		enemyNum = rand() % 3;
		if (enemyNum == 0)
		{
			LoadCastleGoomba();
		}
		else if (enemyNum == 1)
		{
			LoadKoopaTroopa();
		}
		else if (enemyNum == 2)
		{
			LoadBoo();
		}
	}
	enemyNum = -1;
}

void BattleMechanics::BattleTriggered(int map, bool& notGameOver)
{
	while(battleState)
	{
		BattleSetUp(map);
		
	}
	SetBattleTrigger();
}

void BattleMechanics::EnemyAttackLogic(double userDefense, double userSpeed, double userJump)
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
