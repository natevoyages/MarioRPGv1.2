#include "StartMenu.h"
#include "OverWorld.h"
#include "NewGAme.h"
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std; 


int main()
{
	bool programRunning = true;


	while(programRunning)
	{
		bool play = true;
		bool startNewGame = false;
		bool resumeGame = false;
		bool notGameOver = true;
		StartMenu start;
		OverWorld overWorld;
	ifstream load;
	load.open("save.dat");
	if (load.fail()) {
		while (play)
		{
			start.TitleScreen();
			start.TitleMenu(play, startNewGame, programRunning);
			if (startNewGame)
			{
				NewGame newGame;
				newGame.CharacterSelect();
				newGame.NewGameDialouge();
				overWorld.NewGameHomeSetup(newGame.GetCharacterChar(), newGame.GetCharacterString(), newGame.GetHP(), newGame.GetPower(), newGame.GetJump(), newGame.GetFlwrPwr(), newGame.GetSpeed(), newGame.GetDefense(), newGame.GetBattleHP(), newGame.GetMP(), newGame.GetBattleMP());
				while (notGameOver) 
				{
					overWorld.PrintOverWorld(newGame.GetCharacterChar(), play, notGameOver);
					play = overWorld.GetNotGameOver();
					notGameOver = overWorld.GetNotGameOver();
				}
			}
		}
	}
	else if (!(load.fail()))
	{
		load.close();
		while (play)
		{
			start.SetResumeStartMenu();
			start.TitleScreen();
			start.TitleMenu(play, startNewGame, resumeGame, programRunning);
			if (startNewGame)
			{
				NewGame newGame;
				newGame.CharacterSelect();
				newGame.NewGameDialouge();
				overWorld.NewGameHomeSetup(newGame.GetCharacterChar(), newGame.GetCharacterString(), newGame.GetHP(), newGame.GetPower(), newGame.GetJump(), newGame.GetFlwrPwr(), newGame.GetSpeed(), newGame.GetDefense(), newGame.GetBattleHP(), newGame.GetMP(), newGame.GetBattleMP());
				while (notGameOver)
				{
					overWorld.PrintOverWorld(newGame.GetCharacterChar(), play, notGameOver);
					play = overWorld.GetNotGameOver();
					notGameOver = overWorld.GetNotGameOver();
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

	}

	}
	return 0;
}