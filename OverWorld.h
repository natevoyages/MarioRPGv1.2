#ifndef OVERWORLD_H
#define OVERWORLD_H
#include "InputConfig.h"
#include "InGameMenu.h"
#include "PlayerStats.h"
#include "windows.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class OverWorld {

public:
	OverWorld();

	void SaveGame();

	void characterTracker();

	void OverWorldPrintLogic();

	void CollisonLogic();

	void HomeSetup(char charCharacter);

	void HomeSetup();

	void PrintDesert();

	void DesertOneSetup();

	void PrintOverWorld(char charCharacter, bool& play);

	void SetUpMap(int loadMap);

private:
	InputConfig mapsInput;
	InGameMenu inGame;
	PlayerStats playerStats;

	int xCoordinate;
	int yCoordinate;
	int saveXCoordinate;
	int saveYCoordinate;
	int prevXCoordinate;
	int prevYCoordinate;

	int map;

	// exit coordinates

	int bottomExitXCoordinateOne; 
	int bottomExitXCoordinateTwo;

	int topExitXCoordinateOne;
	int topExitXCoordinateTwo;

	int leftExitYCoordinateOne;
	int leftExitYCoordinateTwo;

	int rightExitYCoordinateOne;
	int rightExitYCoordinateTwo;
	//
	const int width = 60;
	const int height = 30;
	bool newMap;
	bool exitMap;
	bool exitMapSouth;
	bool exitMapNorth;
	bool exitMapEast;
	bool exitMapWest;
	//
	bool menuToggled;
	bool notGameOver;
	char userCharacter;
	
};
#endif