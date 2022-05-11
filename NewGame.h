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
	//menu that selects character for game

	void NewGameDialouge();
	//game start dialough based on who you chose

	char GetCharacterChar() const;
	//returns character icon for overworld

	string GetCharacterString() const;
	//returns character name

	int GetHP() const;
	// returns HP

	int GetMP() const;
	// returns MP

	int GetPower() const;
	// returns Power

	int GetJump() const;
	// returns Jump

	int GetFlwrPwr() const;
	// returns FlowerPower

	int GetSpeed() const;
	// returns Speed

	int GetDefense() const;
	// returns defense

	int GetBattleHP() const;
	// returns battleHP

	int GetBattleMP() const;
	// returns battleHP
private:
	Characters select;
	InputConfig newGameInput;
	bool charSelect;
	int yCharSelect;
	bool enterNotPressed;
	const int numCharacters = 3;  //stats stored in arrays for each character based on number assigned
	int healthPoints[3];
	int power[3];
	int jump[3];
	int flowerPower[3];
	int speed[3];
	int defense[3];
	char selectedCharacterChar;   // values stored in arrays for each character based on number assigned
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
	int magicPoints;
	double  selectBattleHP;
	int battleMP;
};
#endif
