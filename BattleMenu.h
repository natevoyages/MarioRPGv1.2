#ifndef BATTLEMENU_H
#define BATTLEMENU_H

#include "InputConfig.h"
#include <string>
#include <windows.h>
#include <iostream>

using namespace std;
class BattleMenu
{
public:
	void SetUpMenu();

	void PrintBattleMenu(bool& attackSelected, bool& spAttackSelected, bool& itemSelected, bool& runSelected);

	bool GetIfSelected();
private:
	InputConfig menuInput;
	bool select;
	bool itemTabOpen;
	int xMenu;
	int yMenu;
	int numXMenuOptions;
	int numYMenuOptions;

	string menuOptions[4];
};


#endif
