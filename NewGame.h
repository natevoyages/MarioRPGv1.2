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

	char GetCharacterChar() const;

	string GetCharacterString() const;

	int GetHP() const;

	int GetPower() const;

	int GetJump() const;

	int GetFlwrPwr() const;

	int GetSpeed() const;

	int GetDefense() const;

private:
	Characters select;
	InputConfig newGameInput;
	bool charSelect;
	int yCharSelect;
	bool enterNotPressed;
	const int numCharacters = 3;
	int healthPoints[3];
	int power[3];
	int jump[3];
	int flowerPower[3];
	int speed[3];
	int defense[3];
	char selectedCharacterChar;
	char charCharacters[3];
	string characters[3];
	string charactersCap[3];
	string selectedCharacter;
	string characterCap;
	int selectHealthPoints;
	int selectPower;
	int selectJump;
	int selectFlowerPower;
	int selectSpeed;
	int selectDefense;
};
#endif
