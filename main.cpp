#include "StartMenu.h"
#include "OverWorld.h"
#include "NewGAme.h"
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std; 


int main()
{
	bool play = true;
	bool startNewGame = false;
	bool resumeGame = false;
	int map;
	StartMenu start;
	OverWorld overWorld;

	ifstream load;
	load.open("save.dat");
	if (load.fail()) {
		while (play)
		{
			start.TitleScreen();
			start.TitleMenu(play, startNewGame);
			if (startNewGame)
			{
				NewGame newGame;
				newGame.CharacterSelect();
				newGame.NewGameDialouge();
				overWorld.PrintOverWorld(newGame.GetCharacterChar(),play);
			}
		}
	}
	else if( !(load.fail()) )
	{
		while (play)
		{
			start.SetResumeStartMenu();
			start.TitleScreen();
			start.TitleMenu(play, startNewGame, resumeGame);
			if (startNewGame)
			{
				NewGame newGame;
				newGame.CharacterSelect();
				newGame.NewGameDialouge();
				overWorld.PrintOverWorld(newGame.GetCharacterChar(), play);
			}
			else if (resumeGame)
			{
				load >> map;
				overWorld.SetUpMap(map);
			}
		}
		return 0;
	}
}