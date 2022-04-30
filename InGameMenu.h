#ifndef INGAMEMENU_H
#define INGAMEMENU_H

#include "InputConfig.h"
#include <string>

using namespace std;


class InGameMenu
{
public:
	InGameMenu();

	void MenuSetUp();

	void PrintMenuBanner();

	void PrintInGameMenu(bool& open);


private:
	InputConfig menuInput;
	bool select;
	int yMenu;
	int numMenuOptions;
	string menuOptions[5];
};
#endif