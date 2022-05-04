#ifndef BATTLEVISUALS_H
#define BATTLEVISUALS_H
#include <iostream>
#include "BattleMechanics.h"
using namespace std;

class BattleVisuals : public BattleMechanics 
{
public:
	void PrintEnemyAttack(int enemySignature);

	void PrintEnemyAttacked(int enemySignature);

	void PrintEnemyIdle(int enemySignature);

private:


};
#endif
