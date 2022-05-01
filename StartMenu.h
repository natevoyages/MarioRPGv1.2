#ifndef STARTMENU_H
#define STARTMENU_H

#include "InputConfig.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StartMenu
{
public:

	StartMenu();

	void TitlePrint();

	void PrintStartMenu();

	void TitleScreen();

	void TitleMenu(bool& play, bool& startNewGame);

	void TitleMenu(bool& play, bool& startNewGame, bool& resumeGame);

	void SetResumeStartMenu();

private:
	int yMenu;
	int numOptions;
	bool titleScreen;
	bool titleMenu;
	bool select;
	bool startNewGame;
	bool continueGame;
	InputConfig input;
	string menuOptions[3];
};
#endif