#include "BattleMenu.h"

using namespace std;

BattleMenu::BattleMenu()
{
	SetUpMenu();
}

void BattleMenu::SetUpMenu()
{
	select = false;
	itemTabOpen = false;
	yMenu = 0;

	numBattleOptions = 4;

	battleOptions[0] = "ATTACK  ";
	battleOptions[1] = "SPECIAL ";
	battleOptions[2] = "ITEM    ";
	battleOptions[3] = "RUN     ";
}


void BattleMenu::PrintBattleMenu(bool& attackSelected, bool& spAttackSelected, bool& itemSelected, bool& runSelected)
{
	attackSelected = false;
	spAttackSelected = false;
	itemSelected = false;
	runSelected = false;
	menuInput.MenuInput();
    menuInput.BattleInputLogic( yMenu, numBattleOptions, select,  itemTabOpen);

	for (int i = 0; i < numBattleOptions; i++)
	{
			cout << "	    	  " << battleOptions[i];

			if (yMenu == i)
			{
				cout << "   [*]\n";
			}
			else
			{
				cout << "   [ ]\n";
			}
	}

	cout << "\n\n	    	  'z' = SELECT  'x' = BACK";

	if (select && yMenu == 0)
	{
		attackSelected = true;


	}
	if (select && yMenu == 1)
	{
		spAttackSelected = true;


	}
	if (select && yMenu == 2)
	{
		/*itemTabOpen = true;
		itemMenu.SetUp();
	    while(itemTabOpen)
		{
			system("cls");
			menuInput.itempMenu();

		}*/
	
		itemSelected = true;

	}
	if (select && yMenu == 3)
	{
		runSelected = true;

	}

}

bool BattleMenu::GetIfSelected()
{
	return select;
}
