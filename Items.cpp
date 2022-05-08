#include "Items.h"
using namespace std;
Items::Items()
{
	redMushroom = 5;
	megaRedMushroom = 5; 
	starDust = 5;
	greenMushroom = 5;
	star = 5;
	powBlock = 5;
}

void Items::BattleTabSetUp()
{
	numBattleItemOptions = 4;
	battleItemOptions[0] = "	    	   RedShrm:       ";
	battleItemOptions[1] = "	    	   MegaRdShrm:    ";
	battleItemOptions[2] = "	    	   StarDust:      ";
	battleItemOptions[3] = "	    	   POWBlk:        ";
	
	battleItemQuantity[0] = redMushroom;
	battleItemQuantity[1] =	megaRedMushroom;
	battleItemQuantity[2] = starDust;
	battleItemQuantity[3] = powBlock;
}

void Items::OverWorldSetUp()
{
	 numBattleItemOptions = 6;
	 overworldItemOptions[0] = "	    	   RedShrm:       ";
	 overworldItemOptions[1] = "	    	   MegaRdShrm:    ";
	 overworldItemOptions[2] = "	    	   StarDust:      ";
	 overworldItemOptions[3] = "	    	   GreenShrm:     ";
	 overworldItemOptions[4] = "	    	   Star:          ";
	 overworldItemOptions[5] = "	    	   POWBlk:        ";
	 overworldItemQuantity[0] = redMushroom;
	 overworldItemQuantity[1] = megaRedMushroom;
	 overworldItemQuantity[2] = starDust;
	 overworldItemQuantity[3] = greenMushroom;
	 overworldItemQuantity[4] = star;
	 overworldItemQuantity[5] = powBlock;
	 

}

void Items::PrintMenuItems()
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "	    	      _/_/_/  _/_/_/_/_/  _/_/_/_/  _/      _/    _/_/_/        \n";
	cout << "	    	       _/        _/      _/        _/_/  _/_/  _/            _/ \n";
	cout << "	    	      _/        _/      _/_/_/    _/  _/  _/    _/_/            \n";
	cout << "	    	     _/        _/      _/        _/      _/        _/           \n";
	cout << "	    	  _/_/_/      _/      _/_/_/_/  _/      _/  _/_/_/        _/    \n\n\n\n";


	cout << "	    	   RedShrm:       " << redMushroom << "\n\n";
	cout << "	    	   MegaRdShrm:    " << megaRedMushroom << "\n\n";
	cout << "	    	   StarDust:      " << starDust << "\n\n";
	cout << "	    	   GreenShrm:     " << greenMushroom << "\n\n";
	cout << "	    	   Star:          " << star << "\n\n";
	cout << "	    	   POWBlk:        " << powBlock << "\n\n";

	cout << "	    	   Press 'z' to access inventory   Press 'x' = BACK     \n\n";

}

void Items::PrintBattleItemMenuLogic(int& yItemMenu, bool& selectedItem, double& battleHP, int& battleMP, int userHP, int userMP, double& damage, bool& notExit, bool& successfullySelected, bool& itemSelected)
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "	    	      _/_/_/  _/_/_/_/_/  _/_/_/_/  _/      _/    _/_/_/        \n";
	cout << "	    	       _/        _/      _/        _/_/  _/_/  _/            _/ \n";
	cout << "	    	      _/        _/      _/_/_/    _/  _/  _/    _/_/            \n";
	cout << "	    	     _/        _/      _/        _/      _/        _/           \n";
	cout << "	    	  _/_/_/      _/      _/_/_/_/  _/      _/  _/_/_/        _/    \n\n\n\n";

	for(int i = 0; i < numBattleItemOptions; i++)
	{
		if (i == yItemMenu)
		{
			cout << battleItemOptions[i] << " " << battleItemQuantity[i] << "  [*]\n\n";
		}
		else 
		{
			cout << battleItemOptions[i] << " " << battleItemQuantity[i] << "  [ ]\n\n";
		}
	}

	if (yItemMenu == 0 && selectedItem)
	{
		if (overworldItemQuantity[0] == 0)
		{
			cout << "	    	   You posses ZERO of this item\n\n";
			selectedItem = false;
			yItemMenu == 0;
		}
		else if (battleHP == userHP)
		{
			cout << "	    	   HP FULL\n\n";
			selectedItem = false;
			yItemMenu == 0;
		}
		else
		{
			UseRedMushroom(battleHP, userHP);
			cout << "	    	   ITEM USED\n\n";
			itemSelected = false;
			successfullySelected = true;

		}
		Sleep(600);

	}

	if (yItemMenu == 1 && selectedItem)
	{
		if (overworldItemQuantity[1] == 0)
		{
			cout << "	    	   You posses ZERO of this item\n\n";
			selectedItem = false;
			yItemMenu == 1;
		}
		else if (battleHP == userHP)
		{
			cout << "	    	   HP FULL\n\n";
			selectedItem = false;
			yItemMenu == 1;
		}
		else
		{
			UseMegaRedMushroom(battleHP, userHP);
			cout << "	    	   ITEM USED\n\n";
			itemSelected = false;
			successfullySelected = true;
		}
		Sleep(600);
	}
	if (yItemMenu == 2 && selectedItem)
	{
		if (overworldItemQuantity[2] == 0)
		{
			cout << "	    	   You posses ZERO of this item\n\n";
			selectedItem = false;
			yItemMenu == 2;
		}
		else if (battleMP == userMP)
		{
			cout << "	    	   MP FULL\n\n";
			selectedItem = false;
			yItemMenu == 2;
		}
		else
		{
			UseStarDust(battleMP, userMP);
			cout << "	    	   ITEM USED\n\n";
			itemSelected = false;
			successfullySelected = true;
		}
		Sleep(600);
		selectedItem = false;
	}
	if (yItemMenu == 3 && selectedItem)
	{
		if (overworldItemQuantity[5] == 0)
		{
			cout << "	    	   You posses ZERO of this item\n\n";
			selectedItem = false;
			yItemMenu == 3;
		}
		else
		{
			UsePowBlock(damage);
			cout << "	    	   ITEM USED\n\n";
			cout << "	    	   50 DAMAGE DEALT\n";
		
			itemSelected = false;
			successfullySelected = true;
		}
		Sleep(600);
		
	}

	cout << "	    	   Press 'z' = SELECT              Press 'x' = BACK     \n\n";
}

void Items::PrintOverWorldMenuItemLogic(int& yItemMenu, bool& selectedItem, PlayerStats& playerStats, int& menuStep)
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "	    	      _/_/_/  _/_/_/_/_/  _/_/_/_/  _/      _/    _/_/_/        \n";
	cout << "	    	       _/        _/      _/        _/_/  _/_/  _/            _/ \n";
	cout << "	    	      _/        _/      _/_/_/    _/  _/  _/    _/_/            \n";
	cout << "	    	     _/        _/      _/        _/      _/        _/           \n";
	cout << "	    	  _/_/_/      _/      _/_/_/_/  _/      _/  _/_/_/        _/    \n\n\n\n";

	for (int i = 0; i < numBattleItemOptions; i++)
	{
		if (i == yItemMenu)
		{
			cout << overworldItemOptions[i] << " " << overworldItemQuantity[i] << "  [*]\n\n";
		}
		else
		{
			cout << overworldItemOptions[i] << " " << overworldItemQuantity[i] << "  [ ]\n\n";
		}
	}
	cout << "	    	   Press 'z' = SELECT              Press 'x' = BACK     \n\n";
	if (yItemMenu == 0 && selectedItem)
	{
		if (overworldItemQuantity[0] == 0)
		{
			cout << "	    	   You posses ZERO of this item\n\n";
		}
		else if (playerStats.GetPlayerBattleHP() == playerStats.GetPlayerHP())
		{
			cout << "	    	   HP FULL\n\n";
		}
		else
		{
			playerStats.UseRedMushroom(redMushroom);
			cout << "	    	   ITEM USED\n\n";
		}
		Sleep(600);
		selectedItem = false;
	}

	if (yItemMenu == 1 && selectedItem)
	{
		if (overworldItemQuantity[1] == 0)
		{
			cout << "	    	   You posses ZERO of this item\n\n";
		}
		else if (playerStats.GetPlayerBattleHP() == playerStats.GetPlayerHP())
		{
			cout << "	    	   HP FULL\n\n";
		}
		else
		{
			playerStats.UseMegaRedMushroom(megaRedMushroom);
			cout << "	    	   ITEM USED\n\n";
		}
			Sleep(600);
			selectedItem = false;
	}
	if (yItemMenu == 2 && selectedItem)
	{
		if (overworldItemQuantity[2] == 0)
		{
			cout << "	    	   You posses ZERO of this item\n\n";
		}
		else if (playerStats.GetPlayerBattleMP() == playerStats.GetPlayerMP())
		{
			cout << "	    	   MP FULL\n\n";
		}
		else
		{
			playerStats.UseStarDust(starDust);
			cout << "	    	   ITEM USED\n\n";
		}
			Sleep(600);
			selectedItem = false;
	}
	if (yItemMenu == 3 && selectedItem)
		{
			if (overworldItemQuantity[3] == 0)
			{
				cout << "	    	   You posses ZERO of this item\n\n";
			}
			else
			{
				playerStats.UseGreenMushroom(greenMushroom);
				cout << "	    	   ITEM USED\n\n";
			}
			Sleep(600);
			selectedItem = false;
		}
	if (yItemMenu == 4 && selectedItem)
		{
			if (overworldItemQuantity[0] == 0) {
				cout << "	    	   You posses ZERO of this item\n\n";
			}
			else
			{
				UseStar(menuStep);
				cout << "	    	   ITEM USED\n\n";
			}
			Sleep(600);
			selectedItem = false;
		}
	if (yItemMenu == 5 && selectedItem)
		{
			cout << "	    	   CANNOT BE USED OUTSIDE BATTLE\n\n";
			Sleep(600);
			selectedItem = false;
		}

}

void Items::ShopMenu(int& coins) 
{

}

int Items::GetNumOptions() const
{
	return numBattleItemOptions;
}


void Items::UseRedMushroom(double& battleHP, int healthPoints)
{
	if ((healthPoints - battleHP) >= 15)
	{
		redMushroom--;
		battleHP += 15;
	}

	else
	{
		redMushroom--;
		battleHP = healthPoints;
	}
}

void Items::UseMegaRedMushroom(double& battleHP, int healthPoints)
{
	if ((healthPoints - battleHP) >= 50)
	{
		megaRedMushroom--;
		battleHP += 50;
		
	}
	else
	{
		megaRedMushroom--;
		battleHP = healthPoints;
		
	}
}

void Items::UseStarDust(int& battleMP, int magicPoints)
{
	
	if ((magicPoints - battleMP) >= 15) {
		battleMP += 10;
		starDust--;
	}
	else
	{
		starDust--;
		battleMP = magicPoints;

	}
}





void Items::UseStar(int& stepCount)
{
	star--;
	stepCount -= 300;
}

void Items::UsePowBlock(double& damage)
{
	powBlock--;
	damage = 50.0;
}

void Items::BuyRedMushroom(int& coins)
{
	redMushroom++;
	coins -= 20;
}

void Items::BuyMegaRedMushroom(int& coins)
{
	megaRedMushroom++;
	coins -= 100;
}

void Items::BuyStarDust(int& coins)
{
	starDust++;
	coins -= 40;
}

void Items::BuyGreenMushroom(int& coins)
{
	greenMushroom++;
	coins -= 1500;
}

void Items::BuyStar(int& coins)
{
	star++;
	coins -= 300;
}

void Items::BuyPowBlock(int& coins)
{
	powBlock++;
	coins -= 500;
}
