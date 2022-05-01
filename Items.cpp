#include "Items.h"
#include <string>
#include <iostream>
using namespace std;
Items::Items()
{
	redMushroom = 3;
	megaRedMushroom = 0; 
	greenMushroom = 0;
	star = 0;
	powBlock = 0;
}

void Items::PrintMenuItems()
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "	    	   ITEMS" << "\n\n";
	cout << "	    	   RdShrm: " << redMushroom << "\n\n";
	cout << "	    	   MegaRdShrm:    " << megaRedMushroom << "\n\n";
	cout << "	    	   GrnShrm:   " << greenMushroom << "\n\n";
	cout << "	    	   Star:  " << star << "\n\n";
	cout << "	    	   POWBlk:   " << powBlock << "\n\n";
}

void Items::UseRedMushroom()
{
	redMushroom--;
}

void Items::UseMegaRedMushroom()
{
	megaRedMushroom--;
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
