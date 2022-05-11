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
	//Prints title screen banner

	void PrintStartMenu();
	//Print start Menu

	void TitleScreen();
	// holds loop condition for titlescreen to be displayed

	void TitleMenu(bool& play, bool& startNewGame, bool& programRunning);
	//if no save data titlemenu

	void TitleMenu(bool& play, bool& startNewGame, bool& resumeGame, bool& programRunning);
	//save data is true, title menu

	void SetResumeStartMenu();
	//sets menu variables to display resume correctly

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