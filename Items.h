#ifndef ITEMS_H
#define ITEMS_H
#include "InputConfig.h"
#include <windows.h>
#include <string>
#include <iostream>

using namespace std;
class Items
{
public:
	Items();

	void BattleTabSetUp();

	void OverWorldSetUp();

	void PrintMenuItems();

	void BattleItemMenuLogic();

	void OverWorldMenuItemLogic();

	void UseRedMushroom();

	void UseMegaRedMushroom();

	void UseStarDust();

	void UseGreenMushroom();

	void UseStar();

	void UsePowBlock();



private:
	InputConfig menuInput;
	int redMushroom;
	int megaRedMushroom;
	int starDust;
	int star;
	int greenMushroom;
	int powBlock;
	int itemYmenu;
	bool  selected;
    bool itemTabOpen;
	int numBattleItemOptions;
	int numOverWorldItemOptions;
	string battleItemOptions[4];
	string overworldItemOptions[6];

};
#endif