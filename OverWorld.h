#ifndef OVERWORLD_H
#define OVERWORLD_H
#include "InputConfig.h"
#include "InGameMenu.h"
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

	void DesertOneSetup();

	void PrintOverWorld(char charCharacter, bool& play);

	void SetUpMap(int map);

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

	int map;

	// exit coordinates

	int bottomExitXCoordinateOne; 
	int bottomExitXCoordinateTwo;
	int bottomExitYCoordinate;
	int topExitXCoordinateOne;
	int topExitXCoordinateTwo;
	int topExitYCoordinate;
	int leftExitXCoordinate;
	int leftExitYCoordinateOne;
	int leftExitYCoordinateTwo;
	int rightExitXCoordinate;
	int rightExitYCoordinateOne;
	int rightExitYCoordinateTwo;
	//
	const int width = 60;
	const int height = 30;
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