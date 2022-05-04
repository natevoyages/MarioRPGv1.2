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
	BattleMenu();

	void SetUpMenu();

	void PrintBattleMenu(bool& attackSelected, bool& spAttackSelected, bool& itemSelected, bool& runSelected);

	bool GetIfSelected();
private:
	InputConfig menuInput;
	bool select;
	bool itemTabOpen;
	int yMenu;
	int numBattleOptions;
	string battleOptions[4];
};


#endif
