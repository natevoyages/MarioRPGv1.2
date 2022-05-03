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
	bool notGameOver = true;
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
				overWorld.NewGameHomeSetup(newGame.GetCharacterChar());
				while (notGameOver) 
				{
					overWorld.PrintOverWorld(newGame.GetCharacterChar(), play, notGameOver);
				}
				play = false;
			}
		}
	}
	else if( !(load.fail()) )
	{
		load.close();
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
				overWorld.NewGameHomeSetup(newGame.GetCharacterChar());
				while (notGameOver)
				{
					overWorld.PrintOverWorld(newGame.GetCharacterChar(), play, notGameOver);
				}
			}
			else if (resumeGame)
			{
				overWorld.LoadGame();
				while (notGameOver)
				{
					overWorld.SetUpMap();
					play = overWorld.GetNotGameOver();
					notGameOver = overWorld.GetNotGameOver();
				}
			}
		}
		return 0;
	}
}