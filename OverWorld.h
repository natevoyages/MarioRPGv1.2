#ifndef OVERWORLD_H
#define OVERWORLD_H
#include "InputConfig.h"
#include "InGameMenu.h"
#include <iostream>

using namespace std;
class OverWorld {

public:
	OverWorld();

	void OverWorldLogic();

	void OverWorldSetup(char charCharacter);

	void PrintOverWorld(char charCharacter, bool& play);

private:
	InputConfig mapsInput;
	InGameMenu inGame;
	int DesertMap[3]; // will fix later 
	int SeaFloorMap[4]; //
	int BowserCastle[5]; //
	int xCoordinate;
	int yCoordinate;
	const int width = 80;
	const int height = 40;
	bool newMap;
	bool menuToggled;
	bool notGameOver;
	char userCharacter;
	
};
#endif