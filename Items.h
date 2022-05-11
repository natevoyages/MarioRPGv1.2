#ifndef ITEMS_H
#define ITEMS_H
#include "InputConfig.h"
#include "PlayerStats.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
class Items
{
public:
	Items();

	void BattleTabSetUp();
	//sets variables for battle item menu


	void OverWorldSetUp();
	//sets variables for over world item menu

	void ShopSetup();
	//sets variables for shop item menu


	void PrintMenuItems();
	//print menu items from a for loop

	void PrintBattleItemMenuLogic(int& yItemMenu, bool& selectedItem, double& battleHP, int& battleMP, int userHP, int userMP, double& damage, bool& notExit, bool& successfullySelected, bool& itemSelected);
	//determine by bools and ymenu coordinates what user will attempt to use
	//if conditions are not satifactory (no item or full HP or MP ) item not used


	void UseRedMushroom(double& battleHP, int healthPoints);
	//Use RedMushroom 
	//player gains 15 battlehp

	void UseMegaRedMushroom(double& battleHP, int healthPoints);
	//Uses MegaRedMushroom
	//player gains 50 battlehp

	void UseStarDust(int& battleMP, int magicPoints);
	//Use StarDust 
	//player gains 10 battlemp

	void PrintOverWorldMenuItemLogic(int& yItemMenu, bool& selectedItem, PlayerStats& playerStats, int& menuStep);
	//determine by bools and ymenu coordinates what user will attempt to use
	//if conditions are not satifactory (no item or full HP or MP  or if can not be used outside of battle) item not used

	void ShopMenu(int& yItemMenu, bool& selectedItem, int& coins, bool& Exit);
	//determine by bools and ymenu coordinates what user will attempt to buy
	// will not succeed if not enough coins for purchase

	int GetNumOptions() const;
	//return number of menuOptions

	void UseStar(int& coins);
	//uses Star
	//steps are set to -300

	void UsePowBlock(double& damage);
	//use POWblock
	//deal 50 dmg to enemy guarenteed

	void BuyRedMushroom(int& coins);
	//Buys RedMushroom

	void BuyMegaRedMushroom(int& coins);
	//Buys MegaRedMushroom

	void BuyStarDust(int& coins);
	// Buys StarDust

	void BuyGreenMushroom(int& coins);
	//Buys GreenMushroom

	void BuyStar(int& coins);
	//Buys GreenMushroom

	void BuyPowBlock(int& coins);
	//Buys PowBlock



private:
	InputConfig menuInput;
	int redMushroom;
	int megaRedMushroom;
	int starDust;
	int star;
	int greenMushroom;  // when used in overWorld adds 1 HP permently to health cap
	int powBlock;
	int itemYmenu;
	bool  selected;
    bool itemTabOpen;
	int numBattleItemOptions;
	int numOverWorldItemOptions;        //used arrays to hold these values for items
	string battleItemOptions[4];
	int battleItemQuantity[4];
	string overworldItemOptions[6];
	int overworldItemQuantity[6];
	int overworldItemPrice[6];
	string stringPrice[6];

};
#endif