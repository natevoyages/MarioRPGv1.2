#ifndef OVERWORLD_H
#define OVERWORLD_H
#include "InputConfig.h"
#include "InGameMenu.h"
#include <iostream>
#include <fstream>

using namespace std;
class OverWorld {

public:
	OverWorld();

	void SaveGame();

	void OverWorldPrintLogic();

	void CollisonLogic();

	void OverWorldSetup(char charCharacter);

	void PrintOverWorld(char charCharacter, bool& play);

private:
	InputConfig mapsInput;
	InGameMenu inGame;
	int saveState[16];
	int DesertMap[3]; // will fix later 
	int SeaFloorMap[4]; //
	int BowserCastle[5]; //
	int xCoordinate;
	int yCoordinate;
	int saveXCoordinate;
	int saveYCoordinate;
	const int width = 60;
	const int height = 30;
	bool newMap;
	bool menuToggled;
	bool notGameOver;
	char userCharacter;
	
};
#endif