#include "NewGame.h"
#include <windows.h>
#include <iostream>

using namespace std;


NewGame::NewGame()
{
	charSelect = false;
	enterNotPressed = true;
	yCharSelect = 0;
	characters[0] = "Mario";
	characters[1] = "Luigi";
	characters[2] = "Toad";
	charactersCap[0] = "MARIO";
	charactersCap[1] = "LUIGI";
	charactersCap[2] = "TOAD";
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
			if (i == 2)
			{
				cout << "     " << characters[i] << " ";
			}
			else
			{
				cout << "     " << characters[i];
			}
			if (yCharSelect == i)
			{
				cout << "   [*]\n";
			}
			else
			{
				cout << "   [ ]\n";
			}

		}
		cout << "\n        Press 'Space to select\n";
		newGameInput.UserInput();
		newGameInput.CharSelectInputLogic(yCharSelect, numCharacters, charSelect);
	}
	if (charSelect && yCharSelect == 0)
	{
		system("cls");
		select.PrintMario();
		cout << "     You have chosen Mario!\n";
		selectedCharacter = characters[0];
		characterCap = charactersCap[0];
	}
	else if (charSelect && yCharSelect == 1)
	{
		system("cls");
		select.PrintLuigi();
		cout << "     You have chosen Luigi!\n";
		selectedCharacter = characters[1];
		characterCap = charactersCap[1];
	}
	else if (charSelect && yCharSelect == 2)
	{
		system("cls");
		select.PrintToad();
		cout << "     You have chosen Toad!\n";
		selectedCharacter = characters[2];
		characterCap = charactersCap[2];
	}
	select.SetCharacter(selectedCharacter);
	Sleep(1500);
}

void NewGame::NewGameDialouge()
{
	while (enterNotPressed)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" 
			<< "                      " << selectedCharacter << "..?\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "             Press 'Space' to wake up";
		Sleep(1500);
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" 
			<< "                      " << characterCap << "!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "             Press 'Space' to wake up";
		Sleep(1500);
		
		newGameInput.PressEnterToContinue(enterNotPressed);
	}
}
