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

	cout << "	    	   Press 'z' to access inventory        \n\n";

}

void Items::BattleItemMenuLogic()
{
}

void Items::OverWorldMenuItemLogic()
{
}


void Items::UseRedMushroom()
{
	redMushroom--;
	/*if ((HP - battleHP) >= 15)
	{
		battleHP += 15;
	}
	else
	{
		battleHP = HP;
	}*/
}

void Items::UseMegaRedMushroom()
{
	megaRedMushroom--;
	/*if ((HP - battleHP) >= 50)
{
	battleHP += 50;
}
else
{
	battleHP = HP;
}*/
}

void Items::UseStarDust()
{
	starDust--;
	/*if ((MP - battleMP) >= 15)
{
	battleMP += 15;
}
else
{
	battleMP = MP;
}*/
}

void Items::UseGreenMushroom()
{
	greenMushroom--;
	//HP++;
}

void Items::UseStar()
{
	star--;
	//stepCount -= 300;
}

void Items::UsePowBlock()
{
	powBlock--;
	//damage = 50;
}

void Items::BuyRedMushroom()
{
	redMushroom++;
	//coins -= 20;
}

void Items::BuyMegaRedMushroom()
{
	megaRedMushroom++;
	//coins -= 100;
}

void Items::BuyStarDust()
{
	starDust++;
	//coins -= 40;
}

void Items::BuyGreenMushroom()
{
	greenMushroom++;
	//coins -= 1500;
}

void Items::BuyStar()
{
	star++;
	//coins -= 300
}

void Items::BuyPowBlock()
{
	powBlock++;
	//coins -= 800
}
