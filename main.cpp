#include "StartMenu.h"
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

	while (play)
	{
		start.TitleScreen();
		start.TitleMenu(play, startNewGame, resumeGame);
		if (startNewGame)
		{
			NewGame newGame;
			newGame.CharacterSelect();
		}
		else if (resumeGame) {
			cout << "RESUMEEEE";
		}
	}
	return 0;
}


