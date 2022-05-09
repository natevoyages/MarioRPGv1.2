#include "PlayerStats.h"
#include <iostream>
#include <string>

using namespace std;

PlayerStats::PlayerStats()
{
	characterName = "Mario";
    characterChar = 'M';
	level = 0;
	healthPoints = 0;
	power = 0;
	jump = 0;
	flowerPower = 0;
	speed = 0;
	experiencePoints = 0;
    coins = 0;
	statPoints = 0;
}


void PlayerStats::SetPlayer(string character, char iconCharacter, int& lvl, int& userHP, int& pwr, int& jmp, int& flwrPwr, int& spd, int& def,
	int xp, int coin, int& statPts, double& userBattleHP, int userBattleMP, int& userMP)
{
	characterName = character;
    characterChar = iconCharacter;
	level = lvl;
	healthPoints = userHP;
	power = pwr;
	jump = jmp;
	flowerPower = flwrPwr;
	speed = spd;
	defense = def;
	experiencePoints = xp;
	coins = coin;
	statPoints = statPts;
	battleHP = userBattleHP;
	battleMP = userBattleMP;
	magicPoints = userMP;

}

double PlayerStats::GetPlayerBattleHP() const
{
	return battleHP;
}

int PlayerStats::GetPlayerHP() const
{
	return healthPoints;
}

int PlayerStats::GetPlayerBattleMP() const
{
	return battleMP;
}

int PlayerStats::GetPlayerMP() const
{
	return magicPoints;
}

int PlayerStats::GetPowStat() const
{
	return power;
}

int PlayerStats::GetJmpStat() const
{
	return jump;
}

int PlayerStats::GetFpwStat() const
{
	return flowerPower;
}

int PlayerStats::GetSpdStat() const
{
	return speed;
}

int PlayerStats::GetDefStat() const
{
	return defense;
}
int PlayerStats::GetLevel() const
{
	return level;
}

void PlayerStats::PrintStats()
{
	system("cls");
	cout << "\n\n\n\n";

	cout << "      _/_/_/  _/_/_/_/_/    _/_/    _/_/_/_/_/  _/    _/    _/_/_/       \n";
	cout << "   _/            _/      _/    _/      _/      _/    _/  _/            _/\n";
	cout << "    _/_/        _/      _/_/_/_/      _/      _/    _/    _/_/           \n";
	cout << "       _/      _/      _/    _/      _/      _/    _/        _/          \n";
	cout << "_/_/_/        _/      _/    _/      _/        _/_/    _/_/_/        _/   \n\n\n\n";


	cout << "	    	   " << characterName << " [" << characterChar << "]\n\n";
	cout << "	    	   LEVEL: " << level << "\n\n";
	cout << "	    	   HP:    " << battleHP << "  /  " << healthPoints << "\n\n";
	cout << "	    	   MP:    " << battleMP << "  /  " << magicPoints << "\n\n";
	cout << "	    	   PWR:   " << power << "\n\n";
	cout << "	    	   JMP:   " << jump << "\n\n";
	cout << "	    	   FPW:   " << flowerPower << "\n\n";
	cout << "	    	   SPD:   " << speed << "\n\n";
	cout << "	    	   DEF:   " << defense << "\n\n";
	cout << "	    	   EXP:   " << experiencePoints << "\n\n\n";
	cout << "	    	   COINS: " << coins << "\n\n\n";
	cout << "	    	   STAT PTS:  " << statPoints << "\n\n";


}

void PlayerStats::AddPowerPoint()
{
	power++;
	statPoints--;
}

void PlayerStats::AddJumpPoint()
{
	jump++;
	statPoints--;
}

void PlayerStats::AddFlowerPowerPoint()
{
	flowerPower++;
	statPoints--;
}

void PlayerStats::AddSpeedPoint()
{
	speed++;
	statPoints--;
}

void PlayerStats::AddDefensePoint()
{
	defense++;
	statPoints--;
}


void PlayerStats::UseRedMushroom(int& redMushroom)
{
	if ((healthPoints - battleHP) >= 15)
	{
		redMushroom--;
		battleHP += 15;
	}
	else if (battleHP == healthPoints)
	{
		cout << "	    	   HP FULL\n\n";
	}

	else
	{
		redMushroom--;
		battleHP = healthPoints;
	}
}

void PlayerStats::UseMegaRedMushroom(int& megaRedMushroom)
{
	megaRedMushroom--;
	if ((healthPoints - battleHP) >= 50)
	{
		battleHP += 50;
	}
	else if (battleHP == healthPoints)
	{
		cout << "	    	   HP FULL\n\n";
	}
	else
	{
		battleHP = healthPoints;
	}
}

void PlayerStats::UseStarDust(int& starDust)
{
	starDust--;
	if ((magicPoints - battleMP) >= 15) {
		battleMP += 10;
	}
	else
	{
		battleMP = magicPoints;
	}
}

void PlayerStats::UseGreenMushroom(int& greenMushroom)
{
	greenMushroom--;
	healthPoints++;
	battleHP = healthPoints;
}

void PlayerStats::LevelUpStats()
{
	statPoints = statPoints + 3;
	healthPoints = healthPoints + 2;
	magicPoints = magicPoints + 3;
	power = power + 2;
	jump = jump + 2;
	flowerPower =  flowerPower +2;
	speed = speed + 2;
	defense = defense + 1;

	battleHP = healthPoints;
	battleMP = magicPoints;
}

void PlayerStats::LevelUp(int experiencePoints)
{
	int newLevel = 3;
	int numLevelUps = 0;
	for (int i = 0; i < 10; i++)
	{
		if(experiencePoints >= eXPThresholds[i])
		{
			newLevel++;
		}
	}
	while (level < newLevel)
	{
		numLevelUps++;
		system("cls");
		level++;
		cout << "\n\n\n\n            LEVEL UP +" << numLevelUps << "\n\n";

		LevelUpStats();
		Sleep(450);
		system("cls");
		cout << "\n\n\n\n            LEVEL UP \n\n";
		Sleep(200);
	}

}
