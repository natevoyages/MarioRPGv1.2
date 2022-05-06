#ifndef OVERWORLD_H
#define OVERWORLD_H
#include "InputConfig.h"
#include "InGameMenu.h"
#include "PlayerStats.h"
#include "Items.h"
#include "BattleMechanics.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
class OverWorld {

public:
	OverWorld();

	bool GetNotGameOver() const;

	void LoadGame();

	void SaveGame();

	void Shop();

	void ExitMapCoordinates();

	void characterTracker();

	void OverWorldPrintLogic();

	void CollisonLogic();

	void PrintOverWorld(char charCharacter, bool& play, bool& notGAMEOVER);

	void IfBattleEncounted();

	void SetUpMap();

	void HomeSetup();

	void NewGameHomeSetup(char charCharacter, string character, int hp, int power, int jump, int flwrPwr,int speed, int defense, double battleHP, int mp, int battleMP);

	void DesertOneSetup();

	void DesertTwoSetup();

	void DesertThreeSetup();

	void ShopOneSetup();

	void SeaFloorOneSetup();

	void SeaFloorTwoSetup();

	void SeaFloorThreeSetup();

	void ShopTwoSetup();

	void CastleOneSetup();

	void CastleTwoSetup();

	void CastleThreeSetup();

	void PrintDesert();

	void PrintSeaFloor();

	void PrintCastle();

	void PrintShopKeep();

	void PrintGameWin();

private:
	InputConfig mapsInput;
	InGameMenu inGame;
	PlayerStats playerStats;
	Items items;
	BattleMechanics battle;
	int xCoordinate;
	int yCoordinate;
	int saveXCoordinate;
	int saveYCoordinate;
	int prevXCoordinate;
	int prevYCoordinate;
	int shopKeepXCoordinate;
	int shopKeepYCoordinate;
	int bossXCoordinate;
	int bossYCoordinate;
	int bedXCoordinate;
	int bedYCoordinate;

	int stepCounter;

	int map;
	int prevMap;

	//
	const int width = 60;
	const int height = 30;
	//
	bool exitMap;
	bool exitMapNorth;
	bool exitMapSouth;
	bool exitMapEast;
	bool exitMapWest;
	//
	bool northOpen;
	bool southOpen;
	bool eastOpen;
	bool westOpen;

	bool menuToggled;
	bool notGameOver;
	char userCharacter;
	string stringCharacter;
	int userLevel;
	int userHealthPoints;
	int userMagicPoints;
	int userPower;
	int userJump;
	int userFlowerPower;
	int userSpeed;
	int userDefense;
	int userEXP;
	int userCoins;
	int userStatPts;
	double userBattleHP;
	int userBattleMP;

	int bossesBeaten;
	
};
#endif