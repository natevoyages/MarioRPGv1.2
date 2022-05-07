#ifndef ITEMS_H
#define ITEMS_H
#include "InputConfig.h"
#include "PlayerStats.h"
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

	void PrintBattleItemMenuLogic(int& yItemMenu, bool& selectedItem, double& battleHP, int& battleMP, int userHP, int userMP, double& damage);

	void PrintOverWorldMenuItemLogic(int& yItemMenu, bool& selectedItem, PlayerStats& playerStats, int& menuStep);

	void ShopMenu(int& coins);

	int GetNumOptions() const;

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
	int battleItemQuantity[4];
	string overworldItemOptions[6];
	int overworldItemQuantity[6];

};
#endif