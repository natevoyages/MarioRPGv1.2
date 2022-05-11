//File: MarioRPGv1.2.exe
//Name: Allan Romo & Jaime Pereda
//Date: 05/11/2022
//Course: CompSci 1
//Description:   Proof of concept for a mario RPG game on the comand line
//               Players choose a character and go through the overworld fighting enemies
//               fighting bosses and buying items
//               if the player battle hp is 0 the player is issued a game over and returns to the title screen
//               either to choose a new game, continue, or quit depending if game was save
// 
//Usage:  Entertainment value for average gamer and mario fan alike
//        

#include "InGameMenu.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

InGameMenu::InGameMenu()
{
	SetUpMenu();
}
void InGameMenu::SetUpMenu() 
{
	select = false;
	yMenu = 0;
	numMenuOptions = 4;
	menuOptions[0] = "STATUS    ";
	menuOptions[1] = "ITEMS     ";
	menuOptions[2] = "GAME INFO ";
	menuOptions[3] = "QUIT GAME ";
}

void InGameMenu::PrintGameInfo() 
{
	cout << "\n\n\n\n\n\n";

	cout << "	    	      _/_/_/  _/      _/  _/_/_/_/    _/_/        \n";
	cout << "	    	        _/    _/_/    _/  _/        _/    _/  _/  \n";
	cout << "	    	       _/    _/  _/  _/  _/_/_/    _/    _/       \n";
	cout << "	    	      _/    _/    _/_/  _/        _/    _/        \n";
	cout << "	    	   _/_/_/  _/      _/  _/          _/_/    _/     \n\n\n";



	cout << "	    	  'S':                Save Point\n\n";
	cout << "	    	  'b':                Bed\n\n";
	cout << "	    	  'k':                Shop Keep\n\n";
	cout << "	    	  'B':                Boss\n\n";
	cout << "	          '__' and '|':       Exits\n\n";
	cout << "	    	  'M' or 'L' or 'T':  Your Character";

}

void InGameMenu::PrintMenuBanner() {
	cout << "\n\n\n\n\n\n";
	cout << "	    	      _/      _/                                  \n";
	cout << "	    	     _/_/  _/_/    _/_/    _/_/_/    _/    _/     \n";
	cout << "	    	    _/  _/  _/  _/_/_/_/  _/    _/  _/    _/      \n";
	cout << "	    	   _/      _/  _/        _/    _/  _/    _/       \n";
	cout << "	    	  _/      _/    _/_/_/  _/    _/    _/_/_/        \n\n\n";
}


void InGameMenu::PrintInGameMenu(bool& open, bool& notGameOver, bool& newMap , PlayerStats& playerStats, Items& items, int& stepCounter)
{
	int menuStep = stepCounter;
	Sleep(150);
		system("cls");
		PrintMenuBanner();
		menuInput.MenuInput();
		menuInput.MenuInputLogic(yMenu, numMenuOptions, select, open);
		for (int i = 0; i < numMenuOptions; i++)
		{
			cout << "	    	    	 " << menuOptions[i];

			if (yMenu == i)
			{
				cout << "   [*]\n";
			}
			else
			{
				cout << "   [ ]\n";
			}
			cout << "\n\n";
		}
		cout << "\n\n\n	    	  'z' = SELECT  'x' = BACK    SPACE = EXIT";

	while (select && yMenu == 0 && open)
	{
		Sleep(150);
		menuInput.MenuInput();
		menuInput.MenuInputLogic(yMenu, numMenuOptions, select, open);
		playerStats.PrintStats();

	}
	while (select && yMenu == 1 && open)
	{
		bool selectedItem = false;
		bool itemUse = false;
		int yItemMenu = 0;
		Sleep(150);
		system("cls");
		menuInput.MenuInput();
		menuInput.ItemMenuInputLogic (yItemMenu, numMenuOptions, select, open, selectedItem, itemUse);
		items.PrintMenuItems();
		while (itemUse) {
			items.OverWorldSetUp();
			menuInput.MenuInput();
			menuInput.ItemMenuInputLogic(yItemMenu, items.GetNumOptions() , select, open, selectedItem, itemUse);
			items.PrintOverWorldMenuItemLogic(yItemMenu, selectedItem, playerStats, menuStep);
		}
	}
	while (select && yMenu == 2 && open)
	{
		Sleep(150);
		system("cls");
		menuInput.MenuInput();
		menuInput.MenuInputLogic(yMenu, numMenuOptions, select, open);
		PrintGameInfo();
	}
	while (select && yMenu == 3 && open)
	{
		system("cls");
		cout << "\n\n\n\n";
		cout << "_/_/_/_/_/  _/                            _/          _/      _/                    \n";
		cout << "   _/      _/_/_/      _/_/_/  _/_/_/    _/  _/        _/  _/    _/_/    _/    _/   \n";
		cout << "  _/      _/    _/  _/    _/  _/    _/  _/_/            _/    _/    _/  _/    _/    \n";
		cout << " _/      _/    _/  _/    _/  _/    _/  _/  _/          _/    _/    _/  _/    _/     \n";
		cout << "_/      _/    _/    _/_/_/  _/    _/  _/    _/        _/      _/_/      _/_/_/      \n";
		cout << "\n\n\n\n";
		cout << "    _/_/_/_/                        _/_/_/    _/                      _/                      _/\n";
		cout << "   _/        _/_/    _/  _/_/      _/    _/  _/    _/_/_/  _/    _/      _/_/_/      _/_/_/  _/ \n";
		cout << "  _/_/_/  _/    _/  _/_/          _/_/_/    _/  _/    _/  _/    _/  _/  _/    _/  _/    _/  _/  \n";
		cout << " _/      _/    _/  _/            _/        _/  _/    _/  _/    _/  _/  _/    _/  _/    _/       \n";
		cout << "_/        _/_/    _/            _/        _/    _/_/_/    _/_/_/  _/  _/    _/    _/_/_/  _/    \n";
		cout << "                                                             _/                      _/         \n";
		cout << "                                                        _/_/                    _/_/            \n";
		Sleep(1500);
		notGameOver = false;
		newMap = true;
		open = false;

	
	}
	stepCounter = menuStep;
}
