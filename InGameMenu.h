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

	void PrintMenuBanner();

	void PrintInGameMenu(bool& open, bool& play, bool& newMap);


private:
	InputConfig menuInput;
	PlayerStats playerStats;
	Items items;
	bool select;
	int yMenu;
	int numMenuOptions;
	string menuOptions[5];
};
#endif