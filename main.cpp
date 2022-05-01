#include "StartMenu.h"
#include "Maps.h"
#include "NewGAme.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std; // this may be polluting the global namespace


int main()
{
	bool play = true;
	bool startNewGame = false;
	bool resumeGame = false;
	StartMenu start;
	Maps map;
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
				map.PrintMap();
				play = false;
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
				map.PrintMap();
				play = false;
			}
			else if (resumeGame)
			{
				system("cls");
				cout << "RESUMEEEE";
			}
		}
		return 0;
	}
}