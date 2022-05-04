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

	void PrintGameInfo();

	void PrintMenuBanner();

	void PrintInGameMenu(bool& open, bool& play, bool& newMap, PlayerStats& playerStats, Items& items);


private:
	InputConfig menuInput;
	bool select;
	int yMenu;
	int numMenuOptions;
	string menuOptions[4];
};
#endif