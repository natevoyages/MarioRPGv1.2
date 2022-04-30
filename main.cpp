#include "StartMenu.h"
#include "Maps.h"
#include "NewGAme.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std; // this may be polluting the global namespace

int main()
{
	bool play = true;
	bool startNewGame = false;
	bool resumeGame = false;
	StartMenu start;
	Maps map;

	while (play)
	{
		start.TitleScreen();
		start.TitleMenu(play, startNewGame, resumeGame);
		if (startNewGame)
		{
			NewGame newGame;
			newGame.CharacterSelect();
			newGame.NewGameDialouge();
			map.Map();
			play = false;
		}
		else if (resumeGame) {
			cout << "RESUMEEEE";
		}
	}
	return 0;
}


