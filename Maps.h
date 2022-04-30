#ifndef MAPS_H
#define MAPS_H
#include "InputConfig.h"
#include <iostream>

using namespace std;
class Maps {

public:
	Maps();

	void MapLogic();

	void MapSetup();

	void PrintMap();

private:
	InputConfig mapsInput;
	int DesertMap[3]; // will fix later 
	int SeaFloorMap[4]; //
	int BowserCastle[5]; //
	int xCoordinate;
	int yCoordinate;
	const int width = 80;
	const int height = 40;
	bool newMap;
	bool menuToggled;
	char userCharacter;
	
};
#endif