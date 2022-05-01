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
	StartMenu start;
	OverWorld map;
	ifstream in_file;
	in_file.open("save.txt");
	if (in_file.fail()) {
		while (play)
		{
			start.TitleScreen();
			start.TitleMenu(play, startNewGame);
			if (startNewGame)
			{
				NewGame newGame;
				newGame.CharacterSelect();
				newGame.NewGameDialouge();
				map.PrintOverWorld(newGame.GetCharacterChar(),play);
			}
		}
	}
	else if( !(in_file.fail()) )
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
				map.PrintOverWorld(newGame.GetCharacterChar(), play);
			}
			else if (resumeGame)
			{
				system("cls");
				cout << "RESUMEEEE";
			}
			play = false;
		}
		return 0;
	}
}