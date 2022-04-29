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

private:
	Characters select;
	InputConfig newGameInput;
	bool charSelect;
	int yCharSelect;
	const int numCharacters = 3;
	string characters[3];
};
#endif
