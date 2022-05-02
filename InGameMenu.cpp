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


void InGameMenu::PrintMenuBanner() {
	cout << "\n\n\n\n\n\n";
	cout << "	    	      _/      _/                                  \n";
	cout << "	    	     _/_/  _/_/    _/_/    _/_/_/    _/    _/     \n";
	cout << "	    	    _/  _/  _/  _/_/_/_/  _/    _/  _/    _/      \n";
	cout << "	    	   _/      _/  _/        _/    _/  _/    _/       \n";
	cout << "	    	  _/      _/    _/_/_/  _/    _/    _/_/_/        \n\n\n";
}


void InGameMenu::PrintInGameMenu(bool& open, bool& notGameOver, bool& exit)
{
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

	while (select && yMenu == 0 && open)
	{
		menuInput.MenuInput();
		menuInput.MenuInputLogic(yMenu, numMenuOptions, select, open);
		playerStats.PrintStats();

	}
	while (select && yMenu == 1 && open)
	{
		system("cls");
		menuInput.MenuInput();
		menuInput.MenuInputLogic(yMenu, numMenuOptions, select, open);
		items.PrintMenuItems();

	}
	while (select && yMenu == 2 && open)
	{
		system("cls");
		menuInput.MenuInput();
		menuInput.MenuInputLogic(yMenu, numMenuOptions, select, open);
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
		notGameOver = false;
		exit = true;
		open = false;
	
	}
}
