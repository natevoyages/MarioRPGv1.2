#ifndef INGAMEMENU_H
#define INGAMEMENU_H
#include "PlayerStats.h"
#include "InputConfig.h"
#include "Items.h"
#include <string>


using namespace std;


class InGameMenu
{
public:
	InGameMenu();

	void SetUpMenu();
	// sets up variables for gameMenu 

	void PrintGameInfo();
	//prints game info

	void PrintMenuBanner();
	//Prints Menu Banner

	void PrintInGameMenu(bool& open, bool& play, bool& newMap, PlayerStats& playerStats, Items& items, int& stepCounter);
	//Prints menu with option in a for loop that moves the cursor based on ymenu coordinates from user input

private:
	InputConfig menuInput;
	bool select;
	int yMenu;
	int numMenuOptions;
	string menuOptions[4];
};
#endif