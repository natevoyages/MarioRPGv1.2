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

	void PrintBattleItemMenuLogic();

	void PrintOverWorldMenuItemLogic();

	void ShopMenu(int& coins);

	void UseRedMushroom(double& battleHP, int hp);

	void UseMegaRedMushroom(double& battleHP, int hp);

	void UseStarDust(int& battleMP, int mp);

	void UseGreenMushroom(int& hp);

	void UseStar(int& coins);

	void UsePowBlock(double& damage);

	void BuyRedMushroom(int& coins);

	void BuyMegaRedMushroom(int& coins);

	void BuyStarDust(int& coins);

	void BuyGreenMushroom(int& coins);

	void BuyStar(int& coins);

	void BuyPowBlock(int& coins);



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
	int yMenu;

};
#endif