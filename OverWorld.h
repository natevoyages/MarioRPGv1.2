#ifndef OVERWORLD_H
#define OVERWORLD_H
#include "InputConfig.h"
#include "InGameMenu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
class OverWorld {

public:
	OverWorld();

	void LoadGame();

	void SaveGame();

	void Shop();

	void ExitMapCoordinates();

	void characterTracker();

	void OverWorldPrintLogic();

	void CollisonLogic();

	void PrintOverWorld(char charCharacter, bool& play, bool& notGAMEOVER);

	void SetUpMap();

	void HomeSetup();

	void NewGameHomeSetup(char charCharacter);

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

private:
	InputConfig mapsInput;
	InGameMenu inGame;
	int saveState[16]; // fix later
	int DesertMap[3]; // will fix later 
	int SeaFloorMap[4]; //
	int BowserCastle[5]; //
	int xCoordinate;
	int yCoordinate;
	int saveXCoordinate;
	int saveYCoordinate;
	int prevXCoordinate;
	int prevYCoordinate;
	int shopKeepXCoordinate;
	int shopKeepYCoordinate;

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
	
};
#endif