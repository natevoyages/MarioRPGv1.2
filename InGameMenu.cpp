#include "InGameMenu.h"
#include "InputConfig.h"
#include <iostream>
#include <string>

using namespace std;

InGameMenu::InGameMenu()
{
	select = false;
	yMenu = 0;
	numMenuOptions = 5;
	menuOptions[0] = "STATUS    ";
	menuOptions[1] = "ITEMS     ";
	menuOptions[2] = "GAME INFO ";
	menuOptions[3] = "SAVE      ";
	menuOptions[4] = "QUIT GAME ";
}

void InGameMenu::MenuSetUp()
{
	select = false;
	yMenu = 0;
}

void InGameMenu::PrintMenuBanner() {
	cout << "\n\n\n\n\n\n";
	cout << "	    	       __  __________   ____  __   \n";
	cout << "	    	      /  |/  / ____/ | / / / / / _ \n";
	cout << "	    	     / /|_/ / __/ /  |/ / / / / (_)\n";
	cout << "	    	    / /  / / /___/ /|  / /_/ / _   \n";
	cout << "	    	   /_/  /_/ _____ / _ /\____/ (_)  \n\n\n";
}


void InGameMenu::PrintInGameMenu(bool& open)
{
		system("cls");
		PrintMenuBanner();
		menuInput.MenuInput();
		menuInput.MenuInputLogic(yMenu, numMenuOptions, select);
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

	if (select && yMenu == 0)
	{
		system("cls");
		

	}
	else if (select && yMenu == 1)
	{
		system("cls");

	}
	else if (select && yMenu == 2)
	{
		system("cls");
	}
	else if (select && yMenu == 3)
	{
		system("cls");
	}
	else if (select && yMenu == 4)
	{
		system("cls");
	}
	else if (select && yMenu == 5)
	{
		system("cls");
	}

}
