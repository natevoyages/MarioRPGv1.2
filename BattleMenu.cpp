#include "BattleMenu.h"



using namespace std;
void BattleMenu::SetUpMenu()
{
	select = false;
	yMenu = 0;
	xMenu = 0;
	numXMenuOptions = 2;
	numYMenuOptions = 2;
	menuOptions[0] = "ATTACK  ";
	menuOptions[1] = "SPECIAL ";
	menuOptions[2] = "ITEM    ";
	menuOptions[3] = "RUN     ";
}


void BattleMenu::PrintBattleMenu(bool& attackSelected, bool& spAttackSelected, bool& itemSelected, bool& runSelected)
{
	xMenu = 0;
	yMenu = 0;
	numXMenuOptions = 2;
	numYMenuOptions = 2;

	attackSelected = false; 
	spAttackSelected = false;
	itemSelected = false;
	runSelected = false;

	Sleep(150);
	system("cls");
	menuInput.MenuInput();
    menuInput.BattleInputLogic(xMenu, yMenu, numXMenuOptions, numYMenuOptions, select);
	for (int i = 0; i < numYMenuOptions; i++)
	{

		for (int j = 0; j < numXMenuOptions; j++) {

			if (i == 0 && j == 0 && j == xMenu && i == yMenu)
			{
				cout << menuOptions[0] << "  [*]";
			}

			else if (i == 0 && j == 0 && j != xMenu && i != yMenu)
			{
				cout << menuOptions[0] << "  [ ]";
			}

			else if (i == 0 && j == 1 && j == xMenu && i == yMenu)
			{
				cout << "   " << menuOptions[1] << "  [*]\n";
			}
			else if (i == 0 && j == 1 && j != xMenu && i != yMenu)
			{
				cout << "   " << menuOptions[1] << "  [ ]\n";
			}


			else if (i == 1 && j == 0 && j == xMenu && i == yMenu)
			{
				cout << menuOptions[2] << "  [*]";
			}
			else if (i == 1 && j == 0 && j != xMenu && i != yMenu)
			{
				cout << menuOptions[2] << "  [ ]";
			}

			else if (i == 1 && j == 1 && j == xMenu && i == yMenu)
			{
				cout << "   " << menuOptions[3] << "  [*]\n";
			}
			else if (i == 1 && j == 1 && j != xMenu && i != yMenu)
			{
				cout << "   " << menuOptions[3] << "  [ ]\n";
			}

		}

		cout << "\n";
	}

	cout << "\n\n	    	  'z' = SELECT  'x' = BACK";

	if (select && yMenu == 0 && xMenu == 0)
	{
		attackSelected = true;


	}
	if (select && yMenu == 0 && xMenu == 0)
	{
		spAttackSelected = true;


	}
	if (select && yMenu == 0 && xMenu == 0)
	{
		itemSelected = true;

	}
	if (select && yMenu == 0 && xMenu == 0)
	{
		runSelected = true;

	}

}

bool BattleMenu::GetIfSelected()
{
	return select;
}
