#include "Items.h"
using namespace std;
Items::Items()
{
	redMushroom = 3;
	megaRedMushroom = 0; 
	starDust = 0;
	greenMushroom = 0;
	star = 0;
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

}


void Items::UseRedMushroom()
{
	redMushroom--;
}

void Items::UseMegaRedMushroom()
{
	megaRedMushroom--;
}

void Items::UseStarDust()
{
	starDust--;
}

void Items::UseGreenMushroom()
{
	greenMushroom--;
}

void Items::UseStar()
{
	star--;
}

void Items::UsePowBlock()
{
	powBlock--;
}
