#ifndef NEWGAME_H
#define NEWGAME_H

#include "Characters.h"
#include <string>
using namespace std;
class NewGame
{
public:
	NewGame();

	void CharacterSelect();

private:
	Characters select;
	bool charSelect;
	int yCharSelect;
	const int numCharacters = 3;
	string characters[3];
};
#endif
