#include "NewGame.h"
#include "InputConfig.h"
#include <windows.h>
#include <iostream>

using namespace std;


NewGame::NewGame()
{
	charSelect = false;
	yCharSelect = 0;
	characters[0] = "    Mario";
	characters[1] = "    Luigi";
	characters[2] = "    Toad ";
}

void NewGame::CharacterSelect()
{
	while (!charSelect) {
		system("cls");
		if (yCharSelect == 0)
		{
			select.PrintMario();
		}
		else if (yCharSelect == 1)
		{
			select.PrintLuigi();
		}
		else if (yCharSelect == 2)
		{
			select.PrintToad();
		}
		for (int i = 0; i < numCharacters; i++)
		{
			cout << characters[i];
			if (yCharSelect == i)
			{
				cout << "   [*]\n";
			}
			else
			{
				cout << "   [ ]\n";
			}

		}
		cout << "\n        Press 'space to select\n";
	}
}
