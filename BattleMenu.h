#ifndef BATTLEMENU_H
#define BATTLEMENU_H

#include "InputConfig.h"
#include "Items.h"
#include <string>
#include <windows.h>
#include <iostream>

using namespace std;
class BattleMenu
{
public:
	BattleMenu();

	void SetUpMenu();
	// sets variable need for start of battle menu


	void PrintBattleMenu(bool& attackSelected, bool& spAttackSelected, bool& itemSelected, bool& runSelected);
	// prints battleMenu in a loop based on player input

	bool GetIfSelected();
	//return bool if option was selected

private:
	InputConfig menuInput;
	bool select;
	bool itemTabOpen;            // keeps loop going for battle items
	int yMenu;                  //position in menu
	int numBattleOptions;
	string battleOptions[4];
};


#endif
