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
	//returns if the game has ended to main

	void Shop(int& coins);
	//opens Shopmenu and starts shopmenu logic

	void LoadGame();
	//loads stats, coins, xp, character and levels, and which map saved at
	// items are not loaded for testing purposes

	void SaveGame();
	//loads stats, coins, xp, character and levels, and which map saved at
	//items are not loaded for testing purposes

	void BedRest();
	//player sleeps and regains HP and MP to max


	void ExitMapCoordinates();
	// based on bool the spawn for character icon is determined when leaving a map

	void characterTracker();
	// tracks where character is and saves previous coordinates in case of collision is triggered
	// prevent loop of bosses/ save locations / bed / or shopkeeps

	void OverWorldPrintLogic();
	//determines if icons that are printed and the boundries of map and exits

	void CollisonLogic();
	//determines if boss battle/save/shop/rest starts when icons meet
	// also when collision x an y coordinates equal previous coordinates

	void PrintOverWorld(char charCharacter, bool& play, bool& notGAMEOVER);
	//Prints Overworld for newGame start

	void IfBattleEncounted();
	//sets battlestates for boss battles and enemy spawns
	// enemy spawns are based on if steps meet step threshold from battle mechanics
	// boss triggered from collision logic

	void SetUpMap();
	//determines paths for maps in the overworld up to 12 maps 13th map == gameWIN

	void SetStats();
	//sets stats from playerStats class

	void HomeSetup();
	//variables values set for home

	void NewGameHomeSetup(char charCharacter, string character, int hp, int power, int jump, int flwrPwr,int speed, int defense, double battleHP, int mp, int battleMP);
	// new game home set up variables

	void DesertOneSetup();
	// set variable to print Desert One map

	void DesertTwoSetup();
	// set variable to print Desert Two map

	void DesertThreeSetup();
	// set variable to print Desert Three map

	void ShopOneSetup();
	// set variable  to print ShopOne map

	void SeaFloorOneSetup();
	// set variable to print SeaFloorOne map

	void SeaFloorTwoSetup();
	// set variable to print SeaFloorTWo map

	void SeaFloorThreeSetup();
	// set variable to print SeaFloorThree map

	void ShopTwoSetup();
	// set variable  to print ShopTwo map

	void CastleOneSetup();
	// set variable to print CastleOne map

	void CastleTwoSetup();
	// set variable to print CastleTwo map

	void CastleThreeSetup();
	// set variable to print CastleThree map

	void PrintDesert();
	//Prints Desert zone image

	void PrintSeaFloor();
	//Prints Sea Floor zone image

	void PrintCastle();
	//Prints Castle zone image

	void PrintShopKeep();
	//Prints Castle zone image

	void PrintGameWin();
	//Prints Win screen image

	void PrintGameOver();
	//Prints GameOver image

private:
	InputConfig mapsInput;
	InGameMenu inGame;
	PlayerStats playerStats;
	Items items;
	BattleMechanics battle;

	// int values for coordinates for the overwold logic

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
	// tracks maps 
	int map;
	int prevMap;   //used so that zones are printed out when going back to an old zone


	// map dimensions
	const int width = 60;
	const int height = 30;
	
	// maps exited 

	bool exitMap;
	bool exitMapNorth;
	bool exitMapSouth;
	bool exitMapEast;
	bool exitMapWest;
	
	// map exit openings
	bool northOpen;
	bool southOpen;
	bool eastOpen;
	bool westOpen;
	bool menuToggled;
	bool notGameOver;

	char userCharacter;
	string stringCharacter;
	// player stats
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

	bool bossTriggered;

	int bossesBeaten;

};
#endif