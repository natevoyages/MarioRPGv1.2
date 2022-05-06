#include "Items.h"
using namespace std;
Items::Items()
{
	redMushroom = 3;
	megaRedMushroom = 0; 
	starDust = 0;
	greenMushroom = 0;
	star = 1;
	powBlock = 0;
}

void Items::BattleTabSetUp()
{
	numBattleItemOptions = 4;
	battleItemOptions[0] = "	    	   RedShrm:       ";
	battleItemOptions[1] = "	    	   MegaRdShrm:    ";
	battleItemOptions[2] = "	    	   StarDust:      ";
	battleItemOptions[3] = "	    	   POWBlk:        ";
	yMenu = 0;
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
	 yMenu = 0;
	 

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
	cout << "	    	   StarDust:      " << star << "\n\n";
	cout << "	    	   GreenShrm:     " << greenMushroom << "\n\n";
	cout << "	    	   Star:          " << star << "\n\n";
	cout << "	    	   POWBlk:        " << powBlock << "\n\n";

	cout << "	    	   Press 'z' to access inventory   Press 'x' = BACK     \n\n";

}

void Items::PrintBattleItemMenuLogic()
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
		if (i == yMenu) 
		{
			cout << battleItemOptions[i] << "   [*]\n\n";
		}
		else 
		{
			cout << battleItemOptions[i] << "   [ ]\n\n";
		}
	}

	cout << "	    	   Press 'z' = SELECT              Press 'x' = BACK     \n\n";
}

void Items::PrintOverWorldMenuItemLogic()
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
		if (i == yMenu)
		{
			cout << overworldItemOptions[i] << "   [*]\n\n";
		}
		else
		{
			cout << overworldItemOptions[i] << "   [ ]\n\n";
		}
	}
	cout << "	    	   Press 'z' = SELECT              Press 'x' = BACK     \n\n";
}

void Items::ShopMenu(int& coins) {

}


void Items::UseRedMushroom(double& battleHP, int hp)
{
	redMushroom--;
	if ((hp - battleHP) >= 15)
	{
		battleHP += 15;
	}
	else
	{
		battleHP = hp;
	}
}

void Items::UseMegaRedMushroom(double& battleHP, int hp)
{
	megaRedMushroom--;
	if ((hp - battleHP) >= 50)
	{
		battleHP += 50;
	}
	else
	{
		battleHP = hp;
	}
}

void Items::UseStarDust(int& battleMP, int mp)
{
	starDust--;
	if ((mp - battleMP) >= 15) {
		battleMP += 10;
	}
	else
	{
		battleMP = mp;
	}
}




void Items::UseGreenMushroom(int& hp)
{
	greenMushroom--;
	hp++;
}

void Items::UseStar(int& stepCount)
{
	star--;
	stepCount = 0;
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
