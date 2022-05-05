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
	cout << "	    	   SPD:   " << speed << "\n\n";
	cout << "	    	   DEF:   " << defense << "\n\n";
	cout << "	    	   EXP:   " << experiencePoints << "\n\n\n";
	cout << "	    	   COINS: " << coins << "\n\n\n";
	cout << "	    	   STAT PTS:  " << statPoints << "\n\n";


}

void PlayerStats::AddPowerPoint()
{
	power++;
}

void PlayerStats::AddJumpPoint()
{
	jump++;
}

void PlayerStats::AddFlowerPowerPoint()
{
	flowerPower++;
}

void PlayerStats::AddSpeedPoint()
{
	speed++;
}

void PlayerStats::AddDefensePoint()
{
	defense++;
}
