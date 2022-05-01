#include "PlayerStats.h"
#include <iostream>
#include <string>

using namespace std;

PlayerStats::PlayerStats()
{
	characterName = "Mario";
    characterChar = 'M';
	level = 3;
	healthPoints = 25;
	power = 15;
	jump = 13;
	flowerPower = 10;
	speed = 9;
	experiencePoints = 0;
    coins = 0;
	statPoints = 3;
}

void PlayerStats::PrintStats()
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "	    	   " << characterName << " [" << characterChar << "]\n\n";
	cout << "	    	   LEVEL: " << level << "\n\n";
	cout << "	    	   HP:    " << healthPoints << "\n\n";
	cout << "	    	   PWR:   " << power << "\n\n";
	cout << "	    	   JUMP:  " << jump << "\n\n";
	cout << "	    	   SPD:   " << speed << "\n\n";
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
