#include "NewGame.h"
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;
// to push it 

NewGame::NewGame()
{
	charSelect = false;
	enterNotPressed = true;
	yCharSelect = 0;
	//character Names
	characters[0] = "Mario";
	characters[1] = "Luigi";
	characters[2] = "Toad";
	charactersCap[0] = "MARIO";
	charactersCap[1] = "LUIGI";
	charactersCap[2] = "TOAD";
	charCharacters[0] = 'M';
	charCharacters[1] = 'L';
	charCharacters[2] = 'T';
	//character stats
	healthPoints[0] = 60;
	healthPoints[1] = 60;
	healthPoints[2] = 70;
	power[0] = 15;
	power[1] = 13;
	power[2] = 10;
	jump[0] = 12;
	jump[1] = 15;
	jump[2] = 10;
	flowerPower[0] = 13;
	flowerPower[1] = 12;
	flowerPower[2] = 10;
	speed[0] = 10;
	speed[1] = 10;
	speed[2] = 10;
	defense[0] = 10;
	defense[1] = 10;
	defense[2] = 10;
}

void NewGame::CharacterSelect()
{
	while (!charSelect) {
		Sleep(150);
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
		cout << "\n\n        'w' = UP     's' = DOWN       \n";
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
		selectedCharacterChar = charCharacters[0];
		selectHealthPoints = healthPoints[0];
		selectPower = power[0];
		selectJump = jump[0];
		selectFlowerPower = flowerPower[0];
		selectSpeed = speed[0];
		selectDefense = defense[0];
		selectBattleHP = static_cast<double>(healthPoints[0]);
	}
	else if (charSelect && yCharSelect == 1)
	{
		system("cls");
		select.PrintLuigi();
		cout << "     You have chosen Luigi!\n";
		selectedCharacter = characters[1];
		characterCap = charactersCap[1];
		selectedCharacterChar = charCharacters[1];
		selectHealthPoints = healthPoints[1];
		selectPower = power[1];
		selectJump = jump[1];
		selectFlowerPower = flowerPower[1];
		selectSpeed = speed[1];
		selectDefense = defense[1];
		selectBattleHP = static_cast<double>(healthPoints[1]);
	}
	else if (charSelect && yCharSelect == 2)
	{
		system("cls");
		select.PrintToad();
		cout << "     You have chosen Toad!\n";
		selectedCharacter = characters[2];
		characterCap = charactersCap[2];
		selectedCharacterChar = charCharacters[2];
		selectHealthPoints = healthPoints[2];
		selectPower = power[2];
		selectJump = jump[2];
		selectFlowerPower = flowerPower[2];
		selectSpeed = speed[2];
		selectDefense = defense[2];
		selectBattleHP = static_cast<double>(healthPoints[2]);
	}
	magicPoints = 18;
	battleMP = 18.0;

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


char NewGame::GetCharacterChar() const
{
	return selectedCharacterChar;
}
string NewGame::GetCharacterString() const
{
	return selectedCharacter;
}

int NewGame::GetHP() const
{
	return selectHealthPoints;
}

int NewGame::GetMP() const
{
	return magicPoints;
}

int NewGame::GetPower() const
{
	return selectPower;
}

int NewGame::GetJump() const
{
	return selectJump;
}

int NewGame::GetFlwrPwr() const
{
	return selectFlowerPower;
}

int NewGame::GetSpeed() const
{
	return selectSpeed;
}

int NewGame::GetDefense() const
{
	return selectDefense;
}


int NewGame::GetBattleHP() const
{
	return selectBattleHP;
}

int NewGame::GetBattleMP() const
{
	return battleMP;
}
