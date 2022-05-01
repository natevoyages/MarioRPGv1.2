#ifndef NEWGAME_H
#define NEWGAME_H

#include "Characters.h"
#include "InputConfig.h"
#include <string>
using namespace std;
class NewGame
{
public:
	NewGame();

	void CharacterSelect();

	void NewGameDialouge();

	void SetCharacterChar(char characterChar);

	char GetCharacterChar();

private:
	Characters select;
	InputConfig newGameInput;
	bool charSelect;
	int yCharSelect;
	bool enterNotPressed;
	const int numCharacters = 3;
	char selectedCharacterChar;
	char charCharacters[3];
	string characters[3];
	string charactersCap[3];
	string selectedCharacter;
	string characterCap;
};
#endif
