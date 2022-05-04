#include "BattleMechanics.h"

BattleMechanics::BattleMechanics()
{
	enemyNum = -1;
	stepTrigger = -1;
	enemySignature = -1;
	battleState = false;
	enemyPowAttack = false;
}

void BattleMechanics::SetBattleTrigger()
{
	srand(time(0));
	stepTrigger = (rand() % 14) + 20; //  20 to 33 step to trigger battle

}

int BattleMechanics::GetBattleTrigger()
{
	return stepTrigger;
}

void BattleMechanics::BattleSetUp(int map)
{
	if (map == 1 || map == 2)
	{
		enemyNum = rand() % 3;
		if (enemyNum == 0)
		{
			LoadShyGuy();
			enemySignature = 0;
		}
		else if (enemyNum == 1)
		{
			LoadDesertGoomba();
			enemySignature = 1;
		}
		else if (enemyNum == 2)
		{
			LoadPokey();
			enemySignature = 2;
		}
	}
	else if( map == 5 || map == 6)
	{
		enemyNum = rand() % 2;
		if (enemyNum == 0)
		{
			LoadCheepCheep();
			enemySignature = 3;
		}
		else if (enemyNum == 1)
		{
			LoadBlooper();
			enemySignature = 4;
		}
	}
	else if (map == 9 || map == 11)
	{
		enemyNum = rand() % 3;
		if (enemyNum == 0)
		{
			LoadCastleGoomba();
			enemySignature = 5;
		}
		else if (enemyNum == 1)
		{
			LoadKoopaTroopa();
			enemySignature = 6;
		}
		else if (enemyNum == 2)
		{
			LoadBoo();
			enemySignature = 7;
		}
	}
	enemyNum = -1;
}

void BattleMechanics::EnemyTurn(double userBattleHP, double userJump, double userSpeed, double userDefense,char userChar)
{
	if (userBattleHP != 0 && stats[1] != 0) {
		system("cls");
		EnemyBattleMechanics(userJump, userSpeed, userDefense);
		EnemyBattleLogic();
		PrintEnemyIdle();
		PrintUserIdle(userChar);
		Sleep(300);
		system("cls");
		PrintEnemyAttack();
		PrintUserAttacked(userChar);
		Sleep(1050);
	}
}

void BattleMechanics::PlayerTurn(double userBattleHP, int userBattleMP, double userPower,
	double userJump, double userFlowerPower, double userSpeed, double userDefense, int userLevel, char userChar)
{
	bool optionSelected = false;
	if (userBattleHP != 0 && stats[1] != 0)
	{
		menu.SetUpMenu();
		while (!optionSelected) 
		{
			system("cls");
			PrintEnemyIdle();
			PrintUserIdle(userChar);
			menu.PrintBattleMenu(attackSelected, spAttackSelected, itemSelected, runSelected);
			optionSelected = menu.GetIfSelected();
		}

		UserBattleLogic(userBattleHP, userBattleMP, userPower, userJump, userFlowerPower, userSpeed, userDefense, userLevel); // may want to add level and xp;

		if (attackSelected)
		{
			system("cls");
			PrintEnemyAttacked();
			PrintUserAttack(userChar);
			cout << "Damage " << damage << "dealt !\n";

		}

		else if (spAttackSelected)
		{
			system("cls");
			PrintEnemyAttacked();
			PrintUserAttack(userChar);
			cout << "Damage " << specialDamage << "dealt !\n";
		}

		else if (itemSelected)
		{
			//PrintItemMenu();
		}


		else if (runSelected)
		{
			//ESCAPED!
			//FAILED TO ESCAPE!
		}
		Sleep(800);
		cout << "\nSTEPSTOTRIGGER:" << stepTrigger; //fix me
	}
}

void BattleMechanics::BattleTriggered(int map, bool& notGameOver, int userHealthPoints, int userMagicPoints, int userPower, int userJump, int userFlowerPower, int userSpeed, int userDefense,
	double& userBattleHP, int& userBattleMP, int& usercoins, int& userXP, int& userLevel, int& userCoins, char userChar)
{
	bool playerFirst = false;
	bool win = false;
	bool escape = false;
	battleState = true;

	BattleSetUp(map);
	SpeedsterGoesFirst(userSpeed, playerFirst);
	if (!playerFirst) {
		while (battleState)
		{
			EnemyTurn(userBattleHP, userJump, userSpeed, userDefense, userChar);
			PlayerTurn(userBattleHP, userBattleMP, userPower,
				 userJump, userFlowerPower, userSpeed,  userDefense, userLevel, userChar);
			if (userBattleHP == 0)
			{
				win = false;
				battleState = false;
			}
			else if (battleHP == 0)
			{
				win = true;
				battleState = false;
			}
			else if (escape)
			{
				battleState = false;
			}
		}
	}
	else
	{
		while (battleState)
		{
			PlayerTurn(userBattleHP, userBattleMP, userPower,
				userJump, userFlowerPower, userSpeed, userDefense, userLevel, userChar);
			EnemyTurn(userBattleHP, userJump, userSpeed, userDefense,userChar);
			if(userBattleHP == 0)
			{
				win = false;
				battleState = false;
			}
			else if (battleHP == 0)
			{
				win = true;
				battleState = false;
			}
			else if (escape)
			{
				battleState = false;
			}
		}
	}
	SetBattleTrigger();
	if (!win && !escape) {
		notGameOver = false;
	}
	else if (win)
	{
		cout << " You win!\n";
		userXP = userXP + static_cast<int>(stats[8]);
		userCoins = userCoins + static_cast<int>(stats[9]);
	}

}

void BattleMechanics::SpeedsterGoesFirst(int userSpeed, bool& playerFirst)
{
	int coinFlip = -1;
	if (stats[5] > userSpeed)
	{
		playerFirst = false;
	}
	else if (stats[5] < userSpeed)
	{
		playerFirst = true;
	}
	else
	{
		coinFlip = rand() % 2;
		if (coinFlip == 0)
		{
			playerFirst = false;
		}
		else if (coinFlip == 1)
		{
			playerFirst = true;
		}
	}
}

void BattleMechanics::UserBattleLogic(double userBattleHP, int userBattleMP, double userPower, double userJump, double userFlowerPower, double userSpeed, double userDefense, int level)
{
	//jp = 3, spd = 5, def = 6;
	damage = userPower * (6.0 / 10.0 + stats[6]);
	specialDamage = userFlowerPower *((7.0 / 8.0 + stats[6]));
	critDamage = 1.5 * damage;
	specialCrit = 1.5 * specialDamage;
	hitSuccess = 85  + (userSpeed * (5.0 / 5.0 + stats[5]));   // 85 is the hit rate for users
	critSuccess = 45 + (userJump * (5.0 / 5.0 + stats[3])); //45 is the crit rate for users
}

void BattleMechanics::EnemyBattleMechanics(double userJump, double userSpeed, double userDefense)
{//pwr = 2,jp = 3,flw = 4,spd = 5,hitRate = 8, critRate = 9
	damage = stats[2] * (5.5 / 10.0 + userDefense);
	specialDamage = stats[4] * ((5.0 / 8.0 + userDefense));
	critDamage = 1.5 * damage;
	specialCrit = 1.5 * specialDamage;
	hitSuccess = stats[8] + (stats[5] * (5.0 / 5.0 + userSpeed));
	critSuccess = stats[9] + (stats[3] * (5.0 / 5.0 + userJump));
}

void BattleMechanics::EnemyBattleLogic()
{
	int coinFlip = -1;
	coinFlip = rand() % 2;
		if (coinFlip == 0)
		{
			enemyPowAttack = true;
		}
		else if (coinFlip == 1)
		{
			enemyPowAttack = false;
		}
}

void BattleMechanics::LoadShyGuy()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = shyGuyStats[i];
	}
}

void BattleMechanics::LoadDesertGoomba( )
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = desertGoombaStats[i];
	}
}

void BattleMechanics::LoadPokey()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = pokeyStats[i];
	}
}
void BattleMechanics::LoadBirdo()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = birdoStats[i];
	}
}
void BattleMechanics::LoadCheepCheep()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = cheepCheepStats[i];
	}
}
void BattleMechanics::LoadBlooper()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = blooperStats[i];
	}
}
void BattleMechanics::LoadMechaBlooper()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = mechaBlooperStats[i];
	}
}
void BattleMechanics::LoadCastleGoomba()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = castleGoombaStats[i];
	}
}
void BattleMechanics::LoadKoopaTroopa()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = koopaTroopaStats[i];
	}
}

void BattleMechanics::LoadBoo()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = booStats[i];
	}
}

void BattleMechanics::LoadKingBoo()
{
	for (int i = 0; i < 10; i++)
	{
		stats[i] = kingBooStats[i];
	}
}


void BattleMechanics::PrintEnemyAttack()
{
	if (enemySignature == 0)
	{          //"               " space to take out and add
		cout << "                                                      Lvl: 1 SHY GUY      HP:  " << stats[2] << "\n";
		cout << "                                          .;ccccc,  ........            \n";
		cout << "                                         ;kNMMMMMKx;...'''''....        \n";
		cout << "                                        .xNXWMWXXNWo............        \n";
		cout << "                                       :k:..dNo..lXX0k,..'''..          \n";
		cout << "                                       oK;  cX:  ;XMMX;.d000x'          \n";
		cout << "                                       oNd::kNx::xNMMX;.:oooc.          \n";
		cout << "                                       oWMMMMMMMMMMMMX; .....           \n";
		cout << "                                       .l0MMWWMMMMWk:;'..'''.           \n";
		cout << "                                        .dNWOcOMMWXc  .......           \n";
		cout << "                                         .;xkdkOOo,..........           \n";
		cout << "                                           .........''.'''...           \n";
		cout << "                                          ..'''''''''''''''.''.         \n";
		cout << "                                          ....................          \n";
		cout << "                                         .''''''''..  .'''''''.         \n";
		cout << "                                         .,,,,,,,,,.  .,,,,,,,.         \n";

	}
	else if (enemySignature == 1)
	{          //"               " space to take out and add
		cout << "                                                           Lvl: 1 GOOMBA      HP:  " << stats[2] << "\n";
		cout << "                                                    .''''''''''.  .             \n";
		cout << "                                               ..    ,ldkkkOdl,    .            \n";
		cout << "                                              ..   ..  :kkkk:  ..   ..          \n";
		cout << "                                               ...,k0:':oooo:.:0k,...           \n";
		cout << "                                             ...,okKKkd:....:dOKKko,'..         \n";
		cout << "                                         .....;dxkOK0;.:xxxx:.;0KOkxd;.....     \n";
		cout << "                                        . ;dddxkkkOK0;.ckkkkc.;OKOkkkxddd;..    \n";
		cout << "                                        . ;kkkkkkkkkkdodkxxxdlokkkkkOkkkk; .    \n";
		cout << "                                        . ;kkkOKx;................;kKOkkk; .    \n";
		cout << "                                         ..':k0X0ollllllllllllllllo0X0kc'..     \n";
		cout << "                                            .',,,'''''''''''''''''',,''.        \n";
		cout << "                                                . .:ollllllllo;  .              \n";
		cout << "                                                .;lOXXXXXXXXXXOo:.              \n";
		cout << "                                              . .,lkKKXXXXXXXXOo;. .            \n";
		cout << "                                         .',.      ,ck0000000Ko.     .,'.       \n";
		cout << "                                        . .c'        ,cllclccl;.       c'. .    \n";
		cout << "                                        .             ..      ..         .      \n";
	}
	else if (enemySignature == 2)
	{          //"               " space to take out and add
		cout << "                                                          Lvl: 2 POKEY      HP:  " << stats[2] << "\n";
		cout << "                                                    .                     \n";
		cout << "                                                   ....                   \n";
		cout << "                                        .          .....                  \n";
		cout << "                                        ....      ...''.      ....        \n";
		cout << "                                        .......,;'.......,;'......        \n";
		cout << "                                         ...;ldxoloolloolodxdc'..         \n";
		cout << "                                         .;oodl'. .:dl;'...:oodl.         \n";
		cout << "                                        .cxxxo' ';..;'  ,,..:xxxo'        \n";
		cout << "                                        ;xxxxl..xNc '. .OK, ;dxxxl.       \n";
		cout << "                                       .cxxxxd, .;..c, .',..lddxxd'       \n";
		cout << "                                       .:odxdoo:'.,lxdl:'.;looxxxd'       \n";
		cout << "                                        ,dxdc.':lodddddddoc;.,dxxc.       \n";
		cout << "                                         ;dxdc. ..;;;;;;'. .,oxxl.        \n";
		cout << "                                          'lxxdc:::::::::::lxxd:.         \n";
		cout << "                                           .'coxddxxxxxxxxdol;.           \n";
		cout << "                                              ..';:cccc::;'.              \n";
	}
	else if (enemySignature == 3)
	{

	}
	else if (enemySignature == 4)
	{

	}
	else if (enemySignature == 5)
	{

	}
	else if (enemySignature == 6)
	{

	}
	else if (enemySignature == 7)
	{

	}
	//bosses
	else if (enemySignature == 8)
	{

	}
	else if (enemySignature == 9)
	{

	}
	else if (enemySignature == 10)
	{

	}
}

void BattleMechanics::PrintEnemyAttacked()
{
	if (enemySignature == 0)
	{          //"               " space to take out and add
		cout << "                                                       Lvl: 1 SHY GUY      HP:  " << stats[2] << "\n";
		cout << "                                                                         .;ccccc,  ........            \n";
		cout << "                                                                        ;kNMMMMMKx;...'''''....        \n";
		cout << "                                                                       .xNXWMWXXNWo............        \n";
		cout << "                                                                      :k:..dNo..lXX0k,..'''..          \n";
		cout << "                                                                      oK;  cX:  ;XMMX;.d000x'          \n";
		cout << "                                                                      oNd::kNx::xNMMX;.:oooc.          \n";
		cout << "                                                                      oWMMMMMMMMMMMMX; .....           \n";
		cout << "                                                                      .l0MMWWMMMMWk:;'..'''.           \n";
		cout << "                                                                       .dNWOcOMMWXc  .......           \n";
		cout << "                                                                        .;xkdkOOo,..........           \n";
		cout << "                                                                          .........''.'''...           \n";
		cout << "                                                                         ..'''''''''''''''.''.         \n";
		cout << "                                                                         ....................          \n";
		cout << "                                                                        .''''''''..  .'''''''.         \n";
		cout << "                                                                        .,,,,,,,,,.  .,,,,,,,.         \n";

	}
	else if (enemySignature == 1)
	{
		cout << "                                                           Lvl: 1 GOOMBA      HP:  " << stats[2] << "\n";
		cout << "                                                                                   .''''''''''.  .             \n";
		cout << "                                                                              ..    ,ldkkkOdl,    .            \n";
		cout << "                                                                             ..   ..  :kkkk:  ..   ..          \n";
		cout << "                                                                              ...,k0:':oooo:.:0k,...           \n";
		cout << "                                                                            ...,okKKkd:....:dOKKko,'..         \n";
		cout << "                                                                        .....;dxkOK0;.:xxxx:.;0KOkxd;.....     \n";
		cout << "                                                                       . ;dddxkkkOK0;.ckkkkc.;OKOkkkxddd;..    \n";
		cout << "                                                                       . ;kkkkkkkkkkdodkxxxdlokkkkkOkkkk; .    \n";
		cout << "                                                                       . ;kkkOKx;................;kKOkkk; .    \n";
		cout << "                                                                        ..':k0X0ollllllllllllllllo0X0kc'..     \n";
		cout << "                                                                           .',,,'''''''''''''''''',,''.        \n";
		cout << "                                                                               . .:ollllllllo;  .              \n";
		cout << "                                                                               .;lOXXXXXXXXXXOo:.              \n";
		cout << "                                                                             . .,lkKKXXXXXXXXOo;. .            \n";
		cout << "                                                                        .',.      ,ck0000000Ko.     .,'.       \n";
		cout << "                                                                       . .c'        ,cllclccl;.       c'. .    \n";
		cout << "                                                                       .             ..      ..         .      \n";
	}
	else if (enemySignature == 2)
	{
		cout << "                                                       Lvl: 2 POKEY      HP:  " << stats[2] << "\n";
		cout << "                                                                                   .                     \n";
		cout << "                                                                                  ....                   \n";
		cout << "                                                                       .          .....                  \n";
		cout << "                                                                       ....      ...''.      ....        \n";
		cout << "                                                                       .......,;'.......,;'......        \n";
		cout << "                                                                        ...;ldxoloolloolodxdc'..         \n";
		cout << "                                                                        .;oodl'. .:dl;'...:oodl.         \n";
		cout << "                                                                       .cxxxo' ';..;'  ,,..:xxxo'        \n";
		cout << "                                                                       ;xxxxl..xNc '. .OK, ;dxxxl.       \n";
		cout << "                                                                      .cxxxxd, .;..c, .',..lddxxd'       \n";
		cout << "                                                                      .:odxdoo:'.,lxdl:'.;looxxxd'       \n";
		cout << "                                                                       ,dxdc.':lodddddddoc;.,dxxc.       \n";
		cout << "                                                                        ;dxdc. ..;;;;;;'. .,oxxl.        \n";
		cout << "                                                                         'lxxdc:::::::::::lxxd:.         \n";
		cout << "                                                                          .'coxddxxxxxxxxdol;.           \n";
		cout << "                                                                             ..';:cccc::;'.              \n";
	}
	else if (enemySignature == 3) {

	}
	else if (enemySignature == 4) {

	}
	else if (enemySignature == 5) {

	}
	else if (enemySignature == 6) {

	}
	else if (enemySignature == 7) {

	}
	//bosses
	else if (enemySignature == 8) {

	}
	else if (enemySignature == 9) {

	}
	else if (enemySignature == 10) {

	}
}


void BattleMechanics::PrintEnemyIdle()
{
	if (enemySignature == 0)
	{          //"               " space to take out and add
		cout << "                                                       Lvl: 1 SHY GUY      HP:  " << stats[2] << "\n";
		cout << "                                                          .;ccccc,  ........            \n";
		cout << "                                                         ;kNMMMMMKx;...'''''....        \n";
		cout << "                                                        .xNXWMWXXNWo............        \n";
		cout << "                                                       :k:..dNo..lXX0k,..'''..          \n";
		cout << "                                                       oK;  cX:  ;XMMX;.d000x'          \n";
		cout << "                                                       oNd::kNx::xNMMX;.:oooc.          \n";
		cout << "                                                       oWMMMMMMMMMMMMX; .....           \n";
		cout << "                                                       .l0MMWWMMMMWk:;'..'''.           \n";
		cout << "                                                        .dNWOcOMMWXc  .......           \n";
		cout << "                                                         .;xkdkOOo,..........           \n";
		cout << "                                                           .........''.'''...           \n";
		cout << "                                                          ..'''''''''''''''.''.         \n";
		cout << "                                                          ....................          \n";
		cout << "                                                         .''''''''..  .'''''''.         \n";
		cout << "                                                         .,,,,,,,,,.  .,,,,,,,.         \n";

	}
	else if (enemySignature == 1)
	{
		cout << "                                                           Lvl: 1 GOOMBA      HP:  " << stats[2] << "\n";
		cout << "                                                                    .''''''''''.  .             \n";
		cout << "                                                               ..    ,ldkkkOdl,    .            \n";
		cout << "                                                              ..   ..  :kkkk:  ..   ..          \n";
		cout << "                                                               ...,k0:':oooo:.:0k,...           \n";
		cout << "                                                             ...,okKKkd:....:dOKKko,'..         \n";
		cout << "                                                         .....;dxkOK0;.:xxxx:.;0KOkxd;.....     \n";
		cout << "                                                        . ;dddxkkkOK0;.ckkkkc.;OKOkkkxddd;..    \n";
		cout << "                                                        . ;kkkkkkkkkkdodkxxxdlokkkkkOkkkk; .    \n";
		cout << "                                                        . ;kkkOKx;................;kKOkkk; .    \n";
		cout << "                                                         ..':k0X0ollllllllllllllllo0X0kc'..     \n";
		cout << "                                                            .',,,'''''''''''''''''',,''.        \n";
		cout << "                                                                . .:ollllllllo;  .              \n";
		cout << "                                                                .;lOXXXXXXXXXXOo:.              \n";
		cout << "                                                              . .,lkKKXXXXXXXXOo;. .            \n";
		cout << "                                                         .',.      ,ck0000000Ko.     .,'.       \n";
		cout << "                                                        . .c'        ,cllclccl;.       c'. .    \n";
		cout << "                                                        .             ..      ..         .      \n";
	}
	else if (enemySignature == 2)
	{
		cout << "                                                       Lvl: 2 POKEY      HP:  " << stats[2] << "\n";
		cout << "                                                                    .                     \n";
		cout << "                                                                   ....                   \n";
		cout << "                                                        .          .....                  \n";
		cout << "                                                        ....      ...''.      ....        \n";
		cout << "                                                        .......,;'.......,;'......        \n";
		cout << "                                                         ...;ldxoloolloolodxdc'..         \n";
		cout << "                                                         .;oodl'. .:dl;'...:oodl.         \n";
		cout << "                                                        .cxxxo' ';..;'  ,,..:xxxo'        \n";
		cout << "                                                        ;xxxxl..xNc '. .OK, ;dxxxl.       \n";
		cout << "                                                       .cxxxxd, .;..c, .',..lddxxd'       \n";
		cout << "                                                       .:odxdoo:'.,lxdl:'.;looxxxd'       \n";
		cout << "                                                        ,dxdc.':lodddddddoc;.,dxxc.       \n";
		cout << "                                                         ;dxdc. ..;;;;;;'. .,oxxl.        \n";
		cout << "                                                          'lxxdc:::::::::::lxxd:.         \n";
		cout << "                                                           .'coxddxxxxxxxxdol;.           \n";
		cout << "                                                              ..';:cccc::;'.              \n";
	}
	else if (enemySignature == 3)
	{

	}
	else if (enemySignature == 4)
	{

	}
	else if (enemySignature == 5)
	{

	}
	else if (enemySignature == 6)
	{

	}
	else if (enemySignature == 7)
	{

	}
	//bosses
	else if (enemySignature == 8)
	{

	}
	else if (enemySignature == 9)
	{

	}
	else if (enemySignature == 10)
	{

	}
}

void BattleMechanics::PrintUserAttack(char userChar)
{
	if (userChar == 'M')
	{          //"               " space to take out and add
		cout << "                                 .........             \n";
		cout << "                              ..',,,,,,,,,'..          \n";
		cout << "                           ..',;;,,,,,,,,,;;'.         \n";
		cout << "                          .,;,,,,,,;,,,,,,,,,.         \n";
		cout << "                        .',,,,,,,,,,,,,,,,,,;'.        \n";
		cout << "                       .,;,,,,,,,,,,,,,,,,,,;'.......  \n";
		cout << "                      .,;;;;,,;,,,,,,,,,,,,,,..,;;,;,..\n";
		cout << "                     ..''',,,,,,,,,,,,,,,,,'..''''.... \n";
		cout << "                  ..'''',,,,,,,,,,,,,,,,,'''...        \n";
		cout << "                 .,;,,,,,,,,,,,,,;,,;;,'':dd'':;;,..   \n";
		cout << "                .,;,,;,,,,,,,,,,',;;,...,d0OccO000Od;. \n";
		cout << "                 .,,,,,,,;;;,,'.:xkkl..'.'lo:oO00000k, \n";
		cout << "                  ...''''''....'x0kddc'.':,...cxO000k, \n";
		cout << "                     .......''..x0Okodxoxk;.....,dOd;. \n";
		cout << "                    ..'''''''..,xOOxxO000o.........    \n";
		cout << "                     ..''''''''...;:lxkO00k;....       \n";
		cout << "                     ..''...'''''...:xxdl:'.           \n";
		cout << "                            .......'....               \n";
		cout << "                           .......',..'..              \n";
		cout << "                         .....''..,,..,;,..            \n";
		cout << "                         ....'''..,,..',;::,'.         \n";
		cout << "                        ..''''''...'..;dk0KK0k;        \n";
		cout << "                      ....''''''''. .:k0KKKKKKOl.      \n";
		cout << "                     .,..'''''''''....o0KKK0KKO0k,     \n";
		cout << "                     ,x:..''''''''....oKKXkcxKl:0x.    \n";
		cout << "                     ,Ox'.'''''''.. ':l0KK0loKkd0x.    \n";
		cout << "                     .:kx;....''''. .lx0XKKKKKK0d,     \n";
		cout << "                       .'.............:dkOOOkdl,.      \n";
		cout << "                         ..'''....''''..'''''..        \n";
		cout << "                         ',,;,..',,,,,,,;,,,;;'.       \n";
		cout << "                         .,,;,..,;,,,,,,,,,,,;'.       \n";
		cout << "                         ........',,,,,,,,,,,'.        \n";
		cout << "                                  ..........           \n";

		cout << "    HP : " << /*HealthPoints*/ "\n";
		cout << "    MP : " << /*MagicPoints*/ "\n";

	}
	else if (userChar == 'L')
	{
		cout << "                                .....'''...            \n";
		cout << "                             ..';:::::::::;.           \n";
		cout << "                           .';::::::::::::::'          \n";
		cout << "                          .;::::::::::::::::,.         \n";
		cout << "                        .';:::::::::::::::::,.         \n";
		cout << "                        ':::::::::::::::::::'.,,''.    \n";
		cout << "                       .,;;;:::::::::::::::,,;::::;.   \n";
		cout << "                   ...',,;;;:::::::::::::;'.''''...    \n";
		cout << "                  .,:::::::::::::::::::;,cl,..         \n";
		cout << "                 .,:::::::::::::::::;,.'o0x'..         \n";
		cout << "                  .;::::::::::;,,c:'...'d0k;;oddoc'    \n";
		cout << "                   ..'',,,,,,'.'oOkd:''.,d0xxO0000k:   \n";
		cout << "                     ..........:OOdol,..'oo,;x000O0o.  \n";
		cout << "                     .'''''''..;k0dcloccxo. .'lxO0x,   \n";
		cout << "                     .''''''''..ckxdxO000c......;;.    \n";
		cout << "                      .''''''''..'codO000d.....        \n";
		cout << "                      ..''''''''..lOOO000O:  .         \n";
		cout << "                      .''...'...,oO00000x:.            \n";
		cout << "                            .,coO000Oxo;.              \n";
		cout << "                             ,olclll;.                 \n";
		cout << "                            ..'....'.                  \n";
		cout << "                          ...........''.               \n";
		cout << "                          .....'.'. .;:;'.             \n";
		cout << "                         .....''.'. .,;;;'.            \n";
		cout << "                         .''''''.....,ldxkxdc.         \n";
		cout << "                       ...'''''''...cOKXXKKXKd.        \n";
		cout << "                      .'..'''''''...:kKKKKXKKKx'       \n";
		cout << "                     .lc..'''''''.. ,OXKKxxXOoOk.      \n";
		cout << "                     .xl..''''''..;:cOXKKl;OO:dK:      \n";
		cout << "                     .lo..''''''..lkdkKKKOk0K000;      \n";
		cout << "                       ....''''''.';lOKXXXXXKko;       \n";
		cout << "                           ...''''...';:cc::,.         \n";
		cout << "                          .............                \n";
		cout << "                         .'',....''''','.....          \n";
		cout << "                        .,,,'..'''''',,;;;;,,.         \n";
		cout << "                        .;,;'.';,;;;;,;;;;,,;.         \n";
		cout << "                        .';;,..',,,,,,,,,,,,'.         \n";
		cout << "                         .,,,..'::;;;:ccccc:'          \n";
		cout << "                      .......           \n";

		cout << "    HP : " << /*HealthPoints*/"\n";
		cout << "    MP : " << /*MagicPoints*/"\n";
	}
	else if (userChar == 'T')
	{
		cout << "                                 ..............'.                \n";
		cout << "                             ..'',,,,,,,,,,,,.;O0dl,.            \n";
		cout << "                         ...',,,,,,,,,,,,,,,''lKXXNXOo,.         \n";
		cout << "                       .o0o'',,,,,,,,,,'''';cxKXXXXXXN0:.        \n";
		cout << "                     .:OXXKxl:;,,,,,;;:llox0XXXXXXXXXO:'''.      \n";
		cout << "                    .oKXXXXXXK0OkkOO0KXXNNXXXXXXXXXN0c',,,'.     \n";
		cout << "                   .lXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXNk,',,,,,.    \n";
		cout << "                   .;xKXXXXXXXXXNXK0OOO00KXNXXXXXXXNk,',,,,,,.   \n";
		cout << "                  .','oKXXXXXXKkoc:;,,,;;:cokKXXXXXN0c',,,,,,.   \n";
		cout << "                  .',';kNXXXKx:,',,,,,,,,,,'':dKXXXXXO:',,,,,'   \n";
		cout << "                  .,,,'oXXXKo'',,,,,,,,,,,,,,,':0NXXXX0o,'',,.   \n";
		cout << "                  .',,'lXXXx'',,,,,,,,,,,,,,,,,'lXXXXXXXOdl:;.   \n";
		cout << "                   .,,'dXXXl.,,,,,,,,,,,,,,,,,,.:0NXXXXXXXXKc    \n";
		cout << "                    .':0NXNx'',,,,,,,,,,,,,,,,,.lKNXXXXXXX0c.    \n";
		cout << "                     'kNXXXKo'',,,,,,,,,,,,,,,.;ONXXXXXX0o'      \n";
		cout << "                     .,dKXXXXx:'.'',,,,,,,''',l0XXXNXKkc'        \n";
		cout << "                        'cx0XNXOdl::;,,;;;:lx0NXX0ko:'.          \n";
		cout << "                           .,:ldxkOOkkkkkkkkdoc:,'...            \n";
		cout << "                                 .',,,,''''''',:codc.            \n";
		cout << "                                 .':lddooolodxkkxl,.             \n";
		cout << "                          ..     .. .';,,,,,,;;;....             \n";
		cout << "                        .lddolllo:...,,,,,,,,,,,'..;'.           \n";
		cout << "                        .;ldxkxd:..,,,,,,,,,,,,,,,..;;.          \n";
		cout << "                           '::'..',,,,,,,,,,,,,,,,,..,.          \n";
		cout << "                                .,,;,,,,,,,,,,,;,,,..            \n";
		cout << "                                 ';,,,,,''',,,,;;;,.             \n";
		cout << "                                 .lkOOkkkkkkkdc;,'..             \n";
		cout << "                               .''';cloddxxdc'..',,,,..          \n";
		cout << "                              .;;;;;,'..     .;:;;;;;;.          \n";
		cout << "                              ...'''''..     .'''',''..          \n";


		cout << "    HP : " << /*HealthPoints*/ "\n";
		cout << "    MP : " << /*MagicPoints*/  "\n";
	}
}

void BattleMechanics::PrintUserAttacked(char userChar)
{
	if (userChar == 'M')
	{          //"               " space to take out and add
		cout << "  .........             \n";
		cout << ".',,,,,,,,,'..          \n";
		cout << ";;,,,,,,,,,;;'.         \n";
		cout << ",,,,;,,,,,,,,,.         \n";
		cout << ",,,,,,,,,,,,,;'.        \n";
		cout << ",,,,,,,,,,,,,;'.......  \n";
		cout << ",,,,,,,,,,,,,,..,;;,;,..\n";
		cout << ",,,,,,,,,,,,'..''''.... \n";
		cout << ",,,,,,,,,,'''...        \n";
		cout << ",,;,,;;,'':dd'':;;,..   \n";
		cout << ",',;;,...,d0OccO000Od;. \n";
		cout << ".:xkkl..'.'lo:oO00000k, \n";
		cout << "'x0kddc'.':,...cxO000k, \n";
		cout << ".x0Okodxoxk;.....,dOd;. \n";
		cout << ",xOOxxO000o.........    \n";
		cout << "...;:lxkO00k;....       \n";
		cout << "''...:xxdl:'.           \n";
		cout << "....'....               \n";
		cout << "...',..'..              \n";
		cout << "'..,,..,;,..            \n";
		cout << "'..,,..',;::,'.         \n";
		cout << "'...'..;dk0KK0k;        \n";
		cout << "'''. .:k0KKKKKKOl.      \n";
		cout << "'''....o0KKK0KKO0k,     \n";
		cout << "'''....oKKXkcxKl:0x.    \n";
		cout << "''.. ':l0KK0loKkd0x.    \n";
		cout << "'''. .lx0XKKKKKK0d,     \n";
		cout << ".......:dkOOOkdl,.      \n";
		cout << "...''''..'''''..        \n";
		cout << ".',,,,,,,;,,,;;'.       \n";
		cout << ".,;,,,,,,,,,,,;'.       \n";
		cout << "..',,,,,,,,,,,'.        \n";
		cout << "   ..........           \n";

		cout << "    HP : " << /*HealthPoints*/ "\n";
		cout << "    MP : " << /*MagicPoints*/ "\n";

	}
	else if (userChar == 'L')
	{          //"               " space to take out and add               
		cout << " .....'''...            \n";
		cout << "';:::::::::;.           \n";
		cout << ":::::::::::::'          \n";
		cout << ":::::::::::::,.         \n";
		cout << ":::::::::::::,.         \n";
		cout << ":::::::::::::'.,,''.    \n";
		cout << "::::::::::::,,;::::;.   \n";
		cout << "::::::::::;'.''''...    \n";
		cout << "::::::::;,cl,..         \n";
		cout << ":::::;,.'o0x'..         \n";
		cout << ",,c:'...'d0k;;oddoc'    \n";
		cout << "'oOkd:''.,d0xxO0000k:   \n";
		cout << ":OOdol,..'oo,;x000O0o.  \n";
		cout << ";k0dcloccxo. .'lxO0x,   \n";
		cout << ".ckxdxO000c......;;.    \n";
		cout << "..'codO000d.....        \n";
		cout << "'..lOOO000O:  .         \n";
		cout << ".,oO00000x:.            \n";
		cout << "oO000Oxo;.              \n";
		cout << "lclll;.                 \n";
		cout << "....'.                  \n";
		cout << "......''.               \n";
		cout << "'.'. .;:;'.             \n";
		cout << "'.'. .,;;;'.            \n";
		cout << "'.....,ldxkxdc.         \n";
		cout << "''...cOKXXKKXKd.        \n";
		cout << "''...:kKKKKXKKKx'       \n";
		cout << "''.. ,OXKKxxXOoOk.      \n";
		cout << "'..;:cOXKKl;OO:dK:      \n";
		cout << "'..lkdkKKKOk0K000;      \n";
		cout << "''.';lOKXXXXXKko;       \n";
		cout << "'''...';:cc::,.         \n";
		cout << "........                \n";
		cout << "..''''','.....          \n";
		cout << "'''''',,;;;;,,.         \n";
		cout << ";,;;;;,;;;;,,;.         \n";
		cout << "',,,,,,,,,,,,'.         \n";
		cout << "'::;;;:ccccc:'          \n";
		cout << "      .......           \n";

		cout << "    HP : " << /*HealthPoints*/"\n";
		cout << "    MP : " << /*MagicPoints*/"\n";
	}
	else if (userChar == 'T')
	{          //"               " space to take out and add
		cout << "  ..............'.                \n";
		cout << "'',,,,,,,,,,,,.;O0dl,.            \n";
		cout << ",,,,,,,,,,,,,''lKXXNXOo,.         \n";
		cout << ",,,,,,,,'''';cxKXXXXXXN0:.        \n";
		cout << ",,,,,;;:llox0XXXXXXXXXO:'''.      \n";
		cout << "OkkOO0KXXNNXXXXXXXXXN0c',,,'.     \n";
		cout << "XXXXXXXXXXXXXXXXXXXXNk,',,,,,.    \n";
		cout << "XNXK0OOO00KXNXXXXXXXNk,',,,,,,.   \n";
		cout << "koc:;,,,;;:cokKXXXXXN0c',,,,,,.   \n";
		cout << ",',,,,,,,,,,'':dKXXXXXO:',,,,,'   \n";
		cout << ",,,,,,,,,,,,,,,':0NXXXX0o,'',,.   \n";
		cout << ",,,,,,,,,,,,,,,,'lXXXXXXXOdl:;.   \n";
		cout << ",,,,,,,,,,,,,,,,.:0NXXXXXXXXKc    \n";
		cout << ",,,,,,,,,,,,,,,,.lKNXXXXXXX0c.    \n";
		cout << ",,,,,,,,,,,,,,,.;ONXXXXXX0o'      \n";
		cout << "'.'',,,,,,,''',l0XXXNXKkc'        \n";
		cout << "Odl::;,,;;;:lx0NXX0ko:'.          \n";
		cout << "dxkOOkkkkkkkkdoc:,'...            \n";
		cout << "  .',,,,''''''',:codc.            \n";
		cout << "  .':lddooolodxkkxl,.             \n";
		cout << "  .. .';,,,,,,;;;....             \n";
		cout << "lo:...,,,,,,,,,,,'..;'.           \n";
		cout << "d:..,,,,,,,,,,,,,,,..;;.          \n";
		cout << "..',,,,,,,,,,,,,,,,,..,.          \n";
		cout << " .,,;,,,,,,,,,,,;,,,..            \n";
		cout << "  ';,,,,,''',,,,;;;,.             \n";
		cout << "  .lkOOkkkkkkkdc;,'..             \n";
		cout << ".''';cloddxxdc'..',,,,..          \n";
		cout << ";;;;;,'..     .;:;;;;;;.          \n";
		cout << "..'''''..     .'''',''..          \n";


		cout << "    HP : " << /*HealthPoints*/ "\n";
		cout << "    MP : " << /*MagicPoints*/  "\n";
	}

}

void BattleMechanics::PrintUserIdle(char userChar)
{
	if (userChar == 'M')
	{          //"               " space to take out and add
		cout << "                  .........             \n";
		cout << "               ..',,,,,,,,,'..          \n";
		cout << "            ..',;;,,,,,,,,,;;'.         \n";
		cout << "           .,;,,,,,,;,,,,,,,,,.         \n";
		cout << "         .',,,,,,,,,,,,,,,,,,;'.        \n";
		cout << "        .,;,,,,,,,,,,,,,,,,,,;'.......  \n";
		cout << "       .,;;;;,,;,,,,,,,,,,,,,,..,;;,;,..\n";
		cout << "      ..''',,,,,,,,,,,,,,,,,'..''''.... \n";
		cout << "   ..'''',,,,,,,,,,,,,,,,,'''...        \n";
		cout << "  .,;,,,,,,,,,,,,,;,,;;,'':dd'':;;,..   \n";
		cout << " .,;,,;,,,,,,,,,,',;;,...,d0OccO000Od;. \n";
		cout << "  .,,,,,,,;;;,,'.:xkkl..'.'lo:oO00000k, \n";
		cout << "   ...''''''....'x0kddc'.':,...cxO000k, \n";
		cout << "      .......''..x0Okodxoxk;.....,dOd;. \n";
		cout << "     ..'''''''..,xOOxxO000o.........    \n";
		cout << "      ..''''''''...;:lxkO00k;....       \n";
		cout << "      ..''...'''''...:xxdl:'.           \n";
		cout << "             .......'....               \n";
		cout << "            .......',..'..              \n";
		cout << "          .....''..,,..,;,..            \n";
		cout << "          ....'''..,,..',;::,'.         \n";
		cout << "         ..''''''...'..;dk0KK0k;        \n";
		cout << "       ....''''''''. .:k0KKKKKKOl.      \n";
		cout << "      .,..'''''''''....o0KKK0KKO0k,     \n";
		cout << "      ,x:..''''''''....oKKXkcxKl:0x.    \n";
		cout << "      ,Ox'.'''''''.. ':l0KK0loKkd0x.    \n";
		cout << "      .:kx;....''''. .lx0XKKKKKK0d,     \n";
		cout << "        .'.............:dkOOOkdl,.      \n";
		cout << "          ..'''....''''..'''''..        \n";
		cout << "          ',,;,..',,,,,,,;,,,;;'.       \n";
		cout << "          .,,;,..,;,,,,,,,,,,,;'.       \n";
		cout << "          ........',,,,,,,,,,,'.        \n";
		cout << "                   ..........           \n";

		cout << "    HP : " << /*HealthPoints*/ "\n";
		cout << "    MP : " << /*MagicPoints*/ "\n";

	}
	else if (userChar == 'L')
	{
		cout << "                 .....'''...            \n";
		cout << "              ..';:::::::::;.           \n";
		cout << "            .';::::::::::::::'          \n";
		cout << "           .;::::::::::::::::,.         \n";
		cout << "         .';:::::::::::::::::,.         \n";
		cout << "         ':::::::::::::::::::'.,,''.    \n";
		cout << "        .,;;;:::::::::::::::,,;::::;.   \n";
		cout << "    ...',,;;;:::::::::::::;'.''''...    \n";
		cout << "   .,:::::::::::::::::::;,cl,..         \n";
		cout << "  .,:::::::::::::::::;,.'o0x'..         \n";
		cout << "   .;::::::::::;,,c:'...'d0k;;oddoc'    \n";
		cout << "    ..'',,,,,,'.'oOkd:''.,d0xxO0000k:   \n";
		cout << "      ..........:OOdol,..'oo,;x000O0o.  \n";
		cout << "      .'''''''..;k0dcloccxo. .'lxO0x,   \n";
		cout << "      .''''''''..ckxdxO000c......;;.    \n";
		cout << "       .''''''''..'codO000d.....        \n";
		cout << "       ..''''''''..lOOO000O:  .         \n";
		cout << "       .''...'...,oO00000x:.            \n";
		cout << "             .,coO000Oxo;.              \n";
		cout << "              ,olclll;.                 \n";
		cout << "             ..'....'.                  \n";
		cout << "           ...........''.               \n";
		cout << "           .....'.'. .;:;'.             \n";
		cout << "          .....''.'. .,;;;'.            \n";
		cout << "          .''''''.....,ldxkxdc.         \n";
		cout << "        ...'''''''...cOKXXKKXKd.        \n";
		cout << "       .'..'''''''...:kKKKKXKKKx'       \n";
		cout << "      .lc..'''''''.. ,OXKKxxXOoOk.      \n";
		cout << "      .xl..''''''..;:cOXKKl;OO:dK:      \n";
		cout << "      .lo..''''''..lkdkKKKOk0K000;      \n";
		cout << "        ....''''''.';lOKXXXXXKko;       \n";
		cout << "            ...''''...';:cc::,.         \n";
		cout << "           .............                \n";
		cout << "          .'',....''''','.....          \n";
		cout << "         .,,,'..'''''',,;;;;,,.         \n";
		cout << "         .;,;'.';,;;;;,;;;;,,;.         \n";
		cout << "         .';;,..',,,,,,,,,,,,'.         \n";
		cout << "          .,,,..'::;;;:ccccc:'          \n";
		cout << "                      .......           \n";

		cout << "    HP : " << /*HealthPoints*/"\n";
		cout << "    MP : " << /*MagicPoints*/"\n";
	}
	else if (userChar == 'T')
	{
		cout << "                  ..............'.                \n";
		cout << "              ..'',,,,,,,,,,,,.;O0dl,.            \n";
		cout << "          ...',,,,,,,,,,,,,,,''lKXXNXOo,.         \n";
		cout << "        .o0o'',,,,,,,,,,'''';cxKXXXXXXN0:.        \n";
		cout << "      .:OXXKxl:;,,,,,;;:llox0XXXXXXXXXO:'''.      \n";
		cout << "     .oKXXXXXXK0OkkOO0KXXNNXXXXXXXXXN0c',,,'.     \n";
		cout << "    .lXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXNk,',,,,,.    \n";
		cout << "    .;xKXXXXXXXXXNXK0OOO00KXNXXXXXXXNk,',,,,,,.   \n";
		cout << "   .','oKXXXXXXKkoc:;,,,;;:cokKXXXXXN0c',,,,,,.   \n";
		cout << "   .',';kNXXXKx:,',,,,,,,,,,'':dKXXXXXO:',,,,,'   \n";
		cout << "   .,,,'oXXXKo'',,,,,,,,,,,,,,,':0NXXXX0o,'',,.   \n";
		cout << "   .',,'lXXXx'',,,,,,,,,,,,,,,,,'lXXXXXXXOdl:;.   \n";
		cout << "    .,,'dXXXl.,,,,,,,,,,,,,,,,,,.:0NXXXXXXXXKc    \n";
		cout << "     .':0NXNx'',,,,,,,,,,,,,,,,,.lKNXXXXXXX0c.    \n";
		cout << "      'kNXXXKo'',,,,,,,,,,,,,,,.;ONXXXXXX0o'      \n";
		cout << "      .,dKXXXXx:'.'',,,,,,,''',l0XXXNXKkc'        \n";
		cout << "         'cx0XNXOdl::;,,;;;:lx0NXX0ko:'.          \n";
		cout << "            .,:ldxkOOkkkkkkkkdoc:,'...            \n";
		cout << "                  .',,,,''''''',:codc.            \n";
		cout << "                  .':lddooolodxkkxl,.             \n";
		cout << "           ..     .. .';,,,,,,;;;....             \n";
		cout << "         .lddolllo:...,,,,,,,,,,,'..;'.           \n";
		cout << "         .;ldxkxd:..,,,,,,,,,,,,,,,..;;.          \n";
		cout << "            '::'..',,,,,,,,,,,,,,,,,..,.          \n";
		cout << "                 .,,;,,,,,,,,,,,;,,,..            \n";
		cout << "                  ';,,,,,''',,,,;;;,.             \n";
		cout << "                  .lkOOkkkkkkkdc;,'..             \n";
		cout << "                .''';cloddxxdc'..',,,,..          \n";
		cout << "               .;;;;;,'..     .;:;;;;;;.          \n";
		cout << "               ...'''''..     .'''',''..          \n";


		cout << "    HP : " << /*HealthPoints*/ "\n";
		cout << "    MP : " << /*MagicPoints*/  "\n";
	}

}