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
	stepTrigger = (rand() % 14) + 30; //  30 to 43 step to trigger battle

}

int BattleMechanics::GetBattleTrigger()
{
	return stepTrigger;
}

void BattleMechanics::BossBattleSetUp(int& bossesBeaten)
{
	if (bossesBeaten == 0)
	{
		LoadBirdo();
		enemySignature = 8;
	}
	else if (bossesBeaten == 1)
	{
		LoadMechaBlooper();
		enemySignature = 9;
	}
	else if (bossesBeaten == 2)
	{
		LoadKingBoo();
		enemySignature = 10;
	}
	enemySignature = -1;
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


void BattleMechanics::UserAttackAnimation(char userChar,double damage, double userBattleHP, int userBattleMP, int userHP, int userMP)
{
	system("cls");
	PrintEnemyIdle();
	PrintUserAttack(userChar, userBattleMP, userHP, userMP, userBattleHP);
	Sleep(300);
	system("cls");
	PrintEnemyAttacked();
	PrintUserIdle(userChar, userBattleMP, userHP, userMP, userBattleHP);
	cout << fixed << setprecision(2) << "\n         " << damage << " DAMAGE DEALT !\n";
}


void BattleMechanics::EnemyTurn(double& userBattleHP, double userJump, double userSpeed, double userDefense,char userChar, int userBattleMP, int userHP, int userMP)
{
	if (userBattleHP != 0 && stats[1] != 0) {
		system("cls");
		EnemyBattleMechanics(userJump, userSpeed, userDefense);
		EnemyBattleLogic();
		PrintEnemyIdle();
		PrintUserIdle(userChar, userBattleMP, userHP, userMP, userBattleHP);
		Sleep(300);
		system("cls");
		PrintEnemyAttack();
		PrintUserIdle(userChar, userBattleMP, userHP, userMP, userBattleHP);
		Sleep(300);
		system("cls");
		PrintEnemyIdle();
		PrintUserAttacked(userChar, userBattleMP, userHP, userMP, userBattleHP);
		cout << fixed << setprecision(2) << "\n        " << damage << " DAMAGE TAKEN !\n";
		Sleep(1050);
	}
}

void BattleMechanics::PlayerTurn(double& userBattleHP, int& userBattleMP, double userPower,
	double userJump, double userFlowerPower, double userSpeed, double userDefense, int userLevel, char userChar,  int userHP, int userMP) 
{
	bool optionSelected = false;
	if (userBattleHP != 0 && stats[1] != 0)   // int battleMP, int userHP, int userMP, double& userBattleHP
	{
		menu.SetUpMenu();
		while (!optionSelected) 
		{
			Sleep(300);
			system("cls");
			PrintEnemyIdle();
			PrintUserIdle(userChar, userBattleMP, userHP, userMP, userBattleHP);
			menu.PrintBattleMenu(attackSelected, spAttackSelected, itemSelected, runSelected);
			optionSelected = menu.GetIfSelected();
		}

		UserBattleLogic(userBattleHP, userBattleMP, userPower, userJump, userFlowerPower, userSpeed, userDefense, userLevel); // may want to add level and xp;

		if (attackSelected)
		{
			UserAttackAnimation(userChar, damage, userBattleHP, userBattleMP,  userHP,  userMP);
			stats[1] = stats[1] - damage;

			if(stats[1] < 0)
			{
				stats[1] = 0;
			}
			

		}

		else if (spAttackSelected)
		{
			UserAttackAnimation(userChar, specialDamage, userBattleHP, userBattleMP, userHP, userMP);
			stats[1] = stats[1] - specialDamage;
			if (stats[1] < 0)
			{
				stats[1] = 0;
			}
		}

		else if (itemSelected)
		{
			//PrintItemMenu();
		}


		else if (runSelected)
		{
			system("cls");
			PrintEnemyIdle();
			PrintUserIdle(userChar, userBattleMP, userHP, userMP, userBattleHP);
			cout << "\n         OH NO! RUN FAILED!\n";
			//ESCAPED!
			//FAILED TO ESCAPE!
		}
		
	}
	
}

void BattleMechanics::BattleTriggered(int map, bool& notGameOver, int userHealthPoints, int userMagicPoints, int userPower, int userJump, int userFlowerPower, int userSpeed, int userDefense,
	double& userBattleHP, int& userBattleMP, int& usercoins, int& userXP, int& userLevel, int& userCoins, char userChar, bool& battleState)
{
	bool playerFirst = false;
	bool win = false;
	bool escape = false;

	BattleSetUp(map);
	SpeedsterGoesFirst(userSpeed, playerFirst);
	if (!playerFirst) {
		while (battleState)
		{
			Sleep(500);
			EnemyTurn(userBattleHP, userJump, userSpeed, userDefense, userChar, userBattleMP, userHealthPoints, userMagicPoints);
			Sleep(500);
			PlayerTurn(userBattleHP, userBattleMP, userPower,
				 userJump, userFlowerPower, userSpeed,  userDefense, userLevel, userChar, userHealthPoints, userMagicPoints);
			if (userBattleHP == 0)
			{
				win = false;
				battleState = false;
			}
			else if (stats[1] == 0)
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
			Sleep(500);
			PlayerTurn(userBattleHP, userBattleMP, userPower,
				userJump, userFlowerPower, userSpeed, userDefense, userLevel, userChar, userHealthPoints, userMagicPoints);
			Sleep(500);
			EnemyTurn(userBattleHP, userJump, userSpeed, userDefense, userChar, userBattleMP, userHealthPoints, userMagicPoints);
			Sleep(500);
			if(userBattleHP == 0)
			{
				win = false;
				battleState = false;
			}
			else if (stats[1] == 0)
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
	{// 7 and 10 are xp and coins respectfully
		userXP = userXP + static_cast<int>(stats[7]);
		userCoins = userCoins + static_cast<int>(stats[10]);
		cout << "\n\n\n\n\n\n\n\                        YOU WIN !\n\n";
		cout << "                        Gained :\n";
		cout << "                        " << static_cast<int>(stats[7]) << " XP \n";
		cout << "                        " << static_cast<int>(stats[10]) << " Coins\n";
		Sleep(5000);
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
	damage = userPower * (15.5 / (15 +  stats[6]));
	specialDamage = userFlowerPower * (19.2 / (15 + stats[6]));
	critDamage = 1.5 * damage;
	specialCrit = 1.5 * specialDamage;
	hitSuccess = 85  + (userSpeed * (5.0 / 7.2 + stats[5]));   // 85 is the hit rate for users
	critSuccess = 45 + (userJump * (5.0 / 5.0 + stats[3])); //45 is the crit rate for users
}

void BattleMechanics::EnemyBattleMechanics(double userJump, double userSpeed, double userDefense)
{//pwr = 2,jp = 3,flw = 4,spd = 5,hitRate = 8, critRate = 9
	damage = stats[2] * (5.5 / (18.0 + userDefense));
	specialDamage = stats[4] * (5.0 / (15.0 + userDefense));
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
	for (int i = 0; i < 11; i++)
	{
		stats[i] = shyGuyStats[i];
	}
}

void BattleMechanics::LoadDesertGoomba( )
{
	for (int i = 0; i < 11; i++)
	{
		stats[i] = desertGoombaStats[i];
	}
}

void BattleMechanics::LoadPokey()
{
	for (int i = 0; i < 11; i++)
	{
		stats[i] = pokeyStats[i];
	}
}
void BattleMechanics::LoadBirdo()
{
	for (int i = 0; i < 11; i++)
	{
		stats[i] = birdoStats[i];
	}
}
void BattleMechanics::LoadCheepCheep()
{
	for (int i = 0; i < 11; i++)
	{
		stats[i] = cheepCheepStats[i];
	}
}
void BattleMechanics::LoadBlooper()
{
	for (int i = 0; i < 11; i++)
	{
		stats[i] = blooperStats[i];
	}
}
void BattleMechanics::LoadMechaBlooper()
{
	for (int i = 0; i < 11; i++)
	{
		stats[i] = mechaBlooperStats[i];
	}
}
void BattleMechanics::LoadCastleGoomba()
{
	for (int i = 0; i < 11; i++)
	{
		stats[i] = castleGoombaStats[i];
	}
}
void BattleMechanics::LoadKoopaTroopa()
{
	for (int i = 0; i < 11; i++)
	{
		stats[i] = koopaTroopaStats[i];
	}
}

void BattleMechanics::LoadBoo()
{
	for (int i = 0; i < 11; i++)
	{
		stats[i] = booStats[i];
	}
}

void BattleMechanics::LoadKingBoo()
{
	for (int i = 0; i < 11; i++)
	{
		stats[i] = kingBooStats[i];
	}
}


void BattleMechanics::PrintEnemyAttack()
{
	if (enemySignature == 0)
	{          //"               " space to take out and add
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
		cout << fixed << setprecision(2) << "                                                      Lvl: 1 SHY GUY      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 1)
	{          //"                                       " space to take out and add
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
		cout << fixed << setprecision(2) << "                                                           Lvl: 1 GOOMBA      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 2)
	{          //"               " space to take out and add
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
		cout << fixed << setprecision(2) << "                                                       Lvl: 2 POKEY      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 3)
	{          
		cout << "                                             ........                     \n";
		cout << "                                             .cxOOOOOc''..                \n";
		cout << "                                              .:xxxxxxxxxd:'.             \n";
		cout << "                                         .'..;dddlccccccccod,             \n";
		cout << "                                       .'dN0d0WWW0dlcccccccc'..'''''.     \n";
		cout << "                                       ;XXKXWNKNWMWkccccccccld0WWWWNd'.   \n";
		cout << "                                       :XOckWOckWMWkccccccld0WMMMMMMWNc   \n";
		cout << "                                       :X0x0WKx0WMWkccccld0WMMMMMMMW0d'   \n";
		cout << "                                       .o0WXKXWMMN0dcc:ckWMMMMMMMMMN:     \n";
		cout << "                                       ..oXOdk0K0xccc::cd0K0000KKKK0c.    \n";
		cout << "                                       .coxOOxolccccccccccccccccccodkk;   \n";
		cout << "                                         .'cxOOxolccccccccccccccccdO0O;   \n";
		cout << "                                           .:dO0OkxxdoccccccccccccdOxl.   \n";
		cout << "                                          .:ox000XWWW0xdlcccccccloxO:     \n";
		cout << "                                         .cxKKKKXNMMMMWW0xddo:;,lOxc.     \n";
		cout << "                                           'ddd0WMMMMMMMMW0dc'. .c.       \n";
		cout << "                                               'oddddddddo'               \n";
		cout << fixed << setprecision(2) << "                                                 Lvl: 3 CHEEP CHEEP   HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 4)
	{           
		cout << "                                                .lkkkkkkkkkkl.              \n";
		cout << "                                               .l0WMMMMMMMMMMW0l.           \n";
		cout << "                                             .c0MMMMMMMMMMMMMMMM0c.         \n";
		cout << "                                           .c0WMMMMMMMMMMMMMMMMMMW0c.       \n";
		cout << "                                         .lOWMMMMMMMMMMMMMMMMMMMMMMNOl.     \n";
		cout << "                                         dWMMMMMWWWWWWWWWWWWWWWWMMMMMWd     \n";
		cout << "                                        .dMMMWKo:llll:;;;;:llll:oKWMMMd.    \n";
		cout << "                                         :ONM0; ,kxxO;    ;Oxxk, ;0MNO:     \n";
		cout << "                                          .cKO' ;KOkK:    :KkOK; 'OKc.      \n";
		cout << "                                            dNO:,cool,....,looc,:ONd        \n";
		cout << "                                            dMMNKKKKXXXXXXXXKKKKNMMd        \n";
		cout << "                                          .c0MMMMMMMMMMMMMMMMMMMMMM0c.      \n";
		cout << "                                      ;kkk0NMMMMMMMMMMMMMMMMMMMMMMMMN0kkk;  \n";
		cout << "                                      :kkk0NMMMMMMMMMMMMMMMMMMMMMMMMN0kkk:  \n";
		cout << "                                          .cKMMMMMMMMMMMMMMMMMMMMMM0c.      \n";
		cout << "                                          .oXWKol0WMMMWXXWMMMW0loKWXo.      \n";
		cout << "                                          .oOo'  'kMWKl,,lKWMk'  'oOo.      \n";
		cout << "                                                 .xMX:    :XMx.             \n";
		cout << "                                                  .;,.    .,;.              \n";
		cout << fixed << setprecision(2) << "                                                      Lvl: 4 BLOOPER HP:  " << stats[1] << "\n";
	}
	else if (enemySignature == 5)
	{           
		cout << "                                                     ..        ..                                  \n";
		cout << "                                                ..  .'c;  ;::cc:'   ..                             \n";
		cout << "                                              ...    .:cc:  coc;.                                  \n";
		cout << "                                             ...   .'. .okc'           .                           \n";
		cout << "                                              .....dKl..lxoll,      ....                           \n";
		cout << "                                             ...,ox0X0Oo'....     .co,...                          \n";
		cout << "                                         ..  .;cokOKXd;;:cccc,    .okoc;.....                      \n";
		cout << "                                       ..,;;;:dOkkOKXl .oOkkOl.   .cxkOd:;;;,..                    \n";
		cout << "                                      .. :OkkOkkkkO00o';dkkkkd,...'  coxkOOO: ..                   \n";
		cout << "                                      .. :kkkkOOkddddddddddddddoooooc;   lxO: ..                   \n";
		cout << "                                      .. :kkkO0Kd....................dXkl:    ..                   \n";
		cout << "                                       ....:xOKXOolllllllllllllllllloOXKOd' ...                    \n";
		cout << "                                         . .;;:::;;;;;;;;;;;;;;;;,;;;:::;;. .                      \n";
		cout << "                                           ..  ..  ';;;;;;;;;;;,.  .     ..                        \n";
		cout << "                                              ....'xXXXXXXXXXXXKl.'. ......                        \n";
		cout << "                                             .. ,ox0XXXXXXXXXXXX0Oo.      ....                     \n";
		cout << "                                       .',.      ,.,d00XXXXXXXXXKl..       ;o;...                  \n";
		cout << "                                      ...,c'       .,lO00000000O;         .,. ..                   \n";
		cout << "                                      .. ':'         .:clcccccc:.             ..                   \n";
		cout << fixed << setprecision(2) << "                                                           Lvl: 5 GOOMBA      HP:  " << stats[1] << "\n";
	}
	else if (enemySignature == 6)
	{
	         // "             /                         "
		cout << "                                         ,kOl.                             \n";
		cout << "                                        'xNMk.                             \n";
		cout << "                                       .:OWMk.',                           \n";
		cout << "                                         cNMk'lOo'                         \n";
		cout << "                                       ..dNMXkk0Oc.                        \n";
		cout << "                                      .;l0WNX0000c.                        \n";
		cout << "                                      :kodK0O00kl.                         \n";
		cout << "                                      :OOo,,ckOo'.  ..;cc;.                \n";
		cout << "                                      ,l,   ,xc;kc .:c;cc;c:.              \n";
		cout << "                                           'ok;,Ko .lo;;;:oo;.             \n";
		cout << "                                         .lkxclol::;;;:oo:;:o;             \n";
		cout << "                                       .;oxOo.dO'.;;;lxxxdl;;.             \n";
		cout << "                                         ..do.dO',do:;cddc;:l,             \n";
		cout << "                                           ,,.dO,,ddxl;;;:lxd;             \n";
		cout << "                                             .dNOc';lc,;;,cl,.             \n";
		cout << "                                             .cKNk;;::;::;::,.             \n";
		cout << "                                            .,.'ldoxKWNNNNWWNl             \n";
		cout << "                                          .,dOdlc' .;ccllllll'             \n";
		cout << "                                         'oxxxxkx;.   .;cccll,             \n";
		cout << "                                         .........     .......             \n";
		cout << fixed << setprecision(2) << "                                                     Lvl: 6 KOOPA    HP:  " << stats[1] << "\n";
	}
	else if (enemySignature == 7)
	{        // "             /                         "
		cout << "                                           ;,ck0OOO0O0Oo;;;          \n";
		cout << "                                         ;d0KKNNNNNNNNNXKKkc,        \n";
		cout << "                                        xd:kKoxNWWWWWWWNNXKxc,       \n";
		cout << "                                       :x0c dO.:XMWWWNXxcc:,l0x:     \n";
		cout << "                                       l0Ko,k0:lNWWWM0ld00d.;0Ol     \n";
		cout << "                                       lOO0KK0KK0XWWWWXNN0o;o0o,     \n";
		cout << "                                       lx:lxlcdo:kWWWWWWNxdKX00d     \n";
		cout << "                                       lx:,;;;;,;kNWWWWWWWWNX00d     \n";
		cout << "                                       ,:ol;;;;;:cxXWWWWWWWWNX0d     \n";
		cout << "                                        oocdxloOdl0WWWWWNXX0xc,      \n";
		cout << "                                          ;loxOKKK0KXXXXKkodc,       \n";
		cout << "                                             'clclccllcll,           \n";
		cout << fixed << setprecision(2) << "                                                       Lvl: 7 BOO    HP:  " << stats[1] << "\n";

	}
	//bosses
	else if (enemySignature == 8)

	{          //"               " space to take out and add
		cout << "                                                  ..                                  \n";
		cout << "                                                 .ld;.     'cc;.                      \n";
		cout << "                                                .co:;;'...:dxdl,.                     \n";
		cout << "                                                .:l;,cc:;;:cclc,.                     \n";
		cout << "                                              .lkkdx0KOkxo:;;;'.                      \n";
		cout << "                                             .'ldc;oOk0KKOxl;,,.                      \n";
		cout << "                                          .',;llc;:llodddol:,..                       \n";
		cout << "                                         .''..':lodxdlc::ccc,.                        \n";
		cout << "                                        .;......,cxO0kdoool:'.                        \n";
		cout << "                                        .;.......:dkkxolodoc,.                        \n";
		cout << "                                        .;'.....':oddolc:::;'                         \n";
		cout << "                                         .;;''';:cc::,'''''.                          \n";
		cout << "                                           ..,;;;,'.'''',,.                           \n";
		cout << "                                              ...'.',;;;,'                            \n";
		cout << "                                               .;ccclc;.                              \n";
		cout << "                                             .,lddolcc,.                              \n";
		cout << "                                        .'...:lol:;::c;.                              \n";
		cout << "                                         .;,':ddc;:ccc;'..                            \n";
		cout << "                                          .:k00dc;;,'''''..,,.                        \n";
		cout << "                                           :0NWN0xl:'.',,,;;.                         \n";
		cout << "                                          .;xKWWNKxc;:odol:.                          \n";
		cout << "                                          ';;lkK0k:':dkxoc'                           \n";
		cout << "                                          'c:;cool:,:lool:.                           \n";
		cout << "                                           ';,''..',,'.....                           \n";
		cout << fixed << setprecision(2) << "                                                       Lvl: 5 BIRDO      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 9)
	{  
		cout << "                                                                                      .,;,,;;,.          \n";
		cout << "                                                                                  .,cdkO0KXXK0d.         \n";
		cout << "                                                                              .':ok00KKKXNNNXKOo.        \n";
		cout << "                                                                        ..;:coO0O000KXNNWNXNNX0Oo.       \n";
		cout << "                                                                  .';ldkO0XXKKKK00KKXWWNXNNNNXK0kl.      \n";
		cout << "                                                             .,:lxOKKXXXXXXXK0OO0KXXXXNNNNNXXKKKOkl.     \n";
		cout << "                                                           'lkOOOOO00KK0OO00kxO0000XNNNNNXXXXKK0Oko,     \n";
		cout << "                                                          .lxxdlllloxkkkkkkddxO0K0KXNXXXXXXXKKK0Okxl.    \n";
		cout << "                                                          .lxoc;,'..',;::ccccoxkO00KKXKKKKKKK00OOkxd:.   \n";
		cout << "                                                           .,:;'.............';:coxkO000000000OOOkxxo.   \n";
		cout << "                                                             ....;oxdc'        ..';coxkOOOOOOOOkxxxdo:.  \n";
		cout << "                                                             .  ,dKNXk:.          ..':odxxxxxxxxxddooc.  \n";
		cout << "                                                            .   .;okdc'      .':c:'...,:lodddddddooool;. \n";
		cout << "                                                           ..    ..''..     .,dKNKd,. ..,:looooooooolll' \n";
		cout << "                                                         .,;,....';:;'..     'oOKOo,.   .',:cllllllllcc. \n";
		cout << "                                                       .,ckkd:',:llc:;'...    .','.    ..;:;;;::cccccc:. \n";
		cout << "                                                      .dkxddo;;cllc::;,.....         ..:oxdl:;,',,;;;,.  \n";
		cout << "                                                      .codxko;;locc::;,',;loc;'.....,:oOK0kdlc:,,'..     \n";
		cout << "                                                    .':c::cl:,':llcc:;';:ldkO0OkxddxkOK0Oxolccc::'       \n";
		cout << "                                             ......,;;;;;;:;,,,,:c:;;;;lddxddxxxk0K0Okkxolccllc:,        \n";
		cout << "                                          .,:clllllllc:::c;'.....'',:lodddddxxxxxxxxdoooooooolc'         \n";
		cout << "                                       .';:::c:::c:cccccclc:;,,',;;;;:cllodddooddxxxxdddoollc,.          \n";
		cout << "                                       ,,;:;::;;;;;:cclllllllllc::c:;'..',:codxdoollcccc:::,.            \n";
		cout << "                                       .'.''''''',;:::::::::ccllllllcc;,;;:;;;lxxollc:;,'..              \n";
		cout << "                                       ,;,,.......';;;::;;:cccllllllllc;',::,.':cllc:;'..                \n";
		cout << "                                       ..,;;;:,..,'.'..',;::::::;::::;'.  ..  ..,::,...                  \n";
		cout << "                                          ......,;;,,''''',;,;,,''''..         .''.                      \n";
		cout << "                                                ..,;;:;,'...                  .                          \n";
		cout << fixed << setprecision(2) << "                                                   Lvl: 8 MECHA BLOOPER HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 10)
	{
			
		cout << "                                               .,'.      .lkc.       .',.                       \n";
		cout << "                                                ..:l;. 'lllclod,   :dc..                        \n";
		cout << "                                                 .o0x:;d0Ol,lKXx::ckXx.                         \n";
		cout << "                                                 .cxkO0KXKo:oKXXXXX0Oo.                         \n";
		cout << "                                                   .;k0KXXK0KXXXXX0:..                          \n";
		cout << "                                                    .',,;;;;;;;;;;,.                            \n";
		cout << "                                                    .:ccccccccccccccc,                          \n";
		cout << "                                               .....lNMMMMMMMMMMMMMMM0;.....                    \n";
		cout << "                                              .oXNXXNWMMMMMMMMMMMMMMMWNXNNK;                    \n";
		cout << "                                            'xOXWMMMMMMMMMMMMMMMMMMMMMMMMMW0ko.                 \n";
		cout << "                                            ;XWXO0NMN0OXMMMMMMMMMMMMMMMMMMMMMO.                 \n";
		cout << "                                          .'lXWk;c0M0c,kWMMMMMMMMMWXKKKKNMMMM0:..               \n";
		cout << "                                         .xNNWWk;cKM0c;kWMMMMMMMWWXc....dWMMMWNNo               \n";
		cout << "                                         .OMMMWN0KNWNK0XWMMMMMMk;;:dkkkkd:lKMMMWo               \n";
		cout << "                                         .OMNOkKWW0k0NWKkONMMMMOcco0MMMWo .OMMMWo               \n";
		cout << "                                         .OM0c;d0Ol,lO0d;c0WMMMMMMMMMNK0o':0MMMWx'.             \n";
		cout << "                                         .OM0c,,;;,,,;;;,c0WMMMMMMMMMO'.dXNWMMMMWN0,            \n";
		cout << "                                         .OW0c,,,,,,,,,,,c0WMMMMMMMMMNOkXMMMMMMMMMX;            \n";
		cout << "                                         .:dxxdc,,,,,,,,,;okKWMMMMMMMMMMMMMMMMMMMMX;            \n";
		cout << "                                            'kKd;,;;;;;:lc;,oNMMMMMMMMMMMMMMMMMMNKO,            \n";
		cout << "                                             .;;;;;;;;;xNKo;dNMMMMMMMMMMMMMMWWWWx..             \n";
		cout << "                                             .,;;;;,lO0XWWX0XWMMMMMMMMMMMMNd;;;;.               \n";
		cout << "                                           ..';;;;;,:ooooxXMMMMMMMMMMXxoool.                    \n";
		cout << "                                          .';;;;;;;;.    .dK000K0000Kd.                         \n";
		cout << "                                          .,;;;;;,,..     ............                          \n";
		cout << "                                          .';,;,;'                                              \n";
		cout << "                                            .....                                               \n";
		cout << fixed << setprecision(2) << "                                                       Lvl: 11 KING BOO  HP:  " << stats[1] << "\n";

	}
}

void BattleMechanics::PrintEnemyAttacked()
{
	if (enemySignature == 0)
	{          //"                                                                      " space to take out and add
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
		cout << fixed << setprecision(2) << "                                                      Lvl: 1 SHY GUY      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 1)
	{
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
		cout << fixed << setprecision(2) << "                                                           Lvl: 1 GOOMBA      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 2)
	{
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
		cout << fixed << setprecision(2) << "                                                       Lvl: 2 POKEY      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 3) {
		      //"                                                                      " 
		cout << "                                                                            ........                     \n";
		cout << "                                                                            .cxOOOOOc''..                \n";
		cout << "                                                                             .:xxxxxxxxxd:'.             \n";
		cout << "                                                                        .'..;dddlccccccccod,             \n";
		cout << "                                                                      .'dN0d0WWW0dlcccccccc'..'''''.     \n";
		cout << "                                                                      ;XXKXWNKNWMWkccccccccld0WWWWNd'.   \n";
		cout << "                                                                      :XOckWOckWMWkccccccld0WMMMMMMWNc   \n";
		cout << "                                                                      :X0x0WKx0WMWkccccld0WMMMMMMMW0d'   \n";
		cout << "                                                                      .o0WXKXWMMN0dcc:ckWMMMMMMMMMN:     \n";
		cout << "                                                                      ..oXOdk0K0xccc::cd0K0000KKKK0c.    \n";
		cout << "                                                                      .coxOOxolccccccccccccccccccodkk;   \n";
		cout << "                                                                        .'cxOOxolccccccccccccccccdO0O;   \n";
		cout << "                                                                          .:dO0OkxxdoccccccccccccdOxl.   \n";
		cout << "                                                                         .:ox000XWWW0xdlcccccccloxO:     \n";
		cout << "                                                                        .cxKKKKXNMMMMWW0xddo:;,lOxc.     \n";
		cout << "                                                                          'ddd0WMMMMMMMMW0dc'. .c.       \n";
		cout << "                                                                              'oddddddddo'               \n";
		cout << fixed << setprecision(2) << "                                                 Lvl: 3 CHEEP CHEEP   HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 4) {
		cout << "                                                                                .lkkkkkkkkkkl.              \n";
		cout << "                                                                               .l0WMMMMMMMMMMW0l.           \n";
		cout << "                                                                             .c0MMMMMMMMMMMMMMMM0c.         \n";
		cout << "                                                                           .c0WMMMMMMMMMMMMMMMMMMW0c.       \n";
		cout << "                                                                         .lOWMMMMMMMMMMMMMMMMMMMMMMNOl.     \n";
		cout << "                                                                         dWMMMMMWWWWWWWWWWWWWWWWMMMMMWd     \n";
		cout << "                                                                        .dMMMWKo:llll:;;;;:llll:oKWMMMd.    \n";
		cout << "                                                                         :ONM0; ,kxxO;    ;Oxxk, ;0MNO:     \n";
		cout << "                                                                          .cKO' ;KOkK:    :KkOK; 'OKc.      \n";
		cout << "                                                                            dNO:,cool,....,looc,:ONd        \n";
		cout << "                                                                            dMMNKKKKXXXXXXXXKKKKNMMd        \n";
		cout << "                                                                          .c0MMMMMMMMMMMMMMMMMMMMMM0c.      \n";
		cout << "                                                                      ;kkk0NMMMMMMMMMMMMMMMMMMMMMMMMN0kkk;  \n";
		cout << "                                                                      :kkk0NMMMMMMMMMMMMMMMMMMMMMMMMN0kkk:  \n";
		cout << "                                                                          .cKMMMMMMMMMMMMMMMMMMMMMM0c.      \n";
		cout << "                                                                          .oXWKol0WMMMWXXWMMMW0loKWXo.      \n";
		cout << "                                                                          .oOo'  'kMWKl,,lKWMk'  'oOo.      \n";
		cout << "                                                                                 .xMX:    :XMx.             \n";
		cout << "                                                                                  .;,.    .,;.              \n";
		cout << fixed << setprecision(2) << "                                                      Lvl: 4 BLOOPER HP:  " << stats[1] << "\n";
	}
	else if (enemySignature == 5) {
		cout << "                                                                                    ..        ..                                  \n";
		cout << "                                                                               ..  .'c;  ;::cc:'   ..                             \n";
		cout << "                                                                             ...    .:cc:  coc;.                                  \n";
		cout << "                                                                            ...   .'. .okc'           .                           \n";
		cout << "                                                                             .....dKl..lxoll,      ....                           \n";
		cout << "                                                                            ...,ox0X0Oo'....     .co,...                          \n";
		cout << "                                                                        ..  .;cokOKXd;;:cccc,    .okoc;.....                      \n";
		cout << "                                                                      ..,;;;:dOkkOKXl .oOkkOl.   .cxkOd:;;;,..                    \n";
		cout << "                                                                     .. :OkkOkkkkO00o';dkkkkd,...'  coxkOOO: ..                   \n";
		cout << "                                                                     .. :kkkkOOkddddddddddddddoooooc;   lxO: ..                   \n";
		cout << "                                                                     .. :kkkO0Kd....................dXkl:    ..                   \n";
		cout << "                                                                      ....:xOKXOolllllllllllllllllloOXKOd' ...                    \n";
		cout << "                                                                        . .;;:::;;;;;;;;;;;;;;;;,;;;:::;;. .                      \n";
		cout << "                                                                          ..  ..  ';;;;;;;;;;;,.  .     ..                        \n";
		cout << "                                                                             ....'xXXXXXXXXXXXKl.'. ......                        \n";
		cout << "                                                                            .. ,ox0XXXXXXXXXXXX0Oo.      ....                     \n";
		cout << "                                                                      .',.      ,.,d00XXXXXXXXXKl..       ;o;...                  \n";
		cout << "                                                                     ...,c'       .,lO00000000O;         .,. ..                   \n";
		cout << "                                                                     .. ':'         .:clcccccc:.             ..                   \n";
		cout << fixed << setprecision(2) << "                                                           Lvl: 5 GOOMBA      HP:  " << stats[1] << "\n";
	}

	else if (enemySignature == 6) {
		cout << "                                                                       ,kOl.                             \n";
		cout << "                                                                      'xNMk.                             \n";
		cout << "                                                                     .:OWMk.',                           \n";
		cout << "                                                                       cNMk'lOo'                         \n";
		cout << "                                                                     ..dNMXkk0Oc.                        \n";
		cout << "                                                                    .;l0WNX0000c.                        \n";
		cout << "                                                                    :kodK0O00kl.                         \n";
		cout << "                                                                    :OOo,,ckOo'.  ..;cc;.                \n";
		cout << "                                                                    ,l,   ,xc;kc .:c;cc;c:.              \n";
		cout << "                                                                         'ok;,Ko .lo;;;:oo;.             \n";
		cout << "                                                                       .lkxclol::;;;:oo:;:o;             \n";
		cout << "                                                                     .;oxOo.dO'.;;;lxxxdl;;.             \n";
		cout << "                                                                       ..do.dO',do:;cddc;:l,             \n";
		cout << "                                                                         ,,.dO,,ddxl;;;:lxd;             \n";
		cout << "                                                                           .dNOc';lc,;;,cl,.             \n";
		cout << "                                                                           .cKNk;;::;::;::,.             \n";
		cout << "                                                                          .,.'ldoxKWNNNNWWNl             \n";
		cout << "                                                                        .,dOdlc' .;ccllllll'             \n";
		cout << "                                                                       'oxxxxkx;.   .;cccll,             \n";
		cout << "                                                                       .........     .......             \n";
		cout << fixed << setprecision(2) << "                                                     Lvl: 6 KOOPA    HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 7) {
		cout << "                                                                         ;,ck0OOO0O0Oo;;;          \n";
		cout << "                                                                       ;d0KKNNNNNNNNNXKKkc,        \n";
		cout << "                                                                      xd:kKoxNWWWWWWWNNXKxc,       \n";
		cout << "                                                                     :x0c dO.:XMWWWNXxcc:,l0x:     \n";
		cout << "                                                                     l0Ko,k0:lNWWWM0ld00d.;0Ol     \n";
		cout << "                                                                     lOO0KK0KK0XWWWWXNN0o;o0o,     \n";
		cout << "                                                                     lx:lxlcdo:kWWWWWWNxdKX00d     \n";
		cout << "                                                                     lx:,;;;;,;kNWWWWWWWWNX00d     \n";
		cout << "                                                                     ,:ol;;;;;:cxXWWWWWWWWNX0d     \n";
		cout << "                                                                      oocdxloOdl0WWWWWNXX0xc,      \n";
		cout << "                                                                        ;loxOKKK0KXXXXKkodc,       \n";
		cout << "                                                                           'clclccllcll,           \n";
		cout << fixed << setprecision(2) << "                                                       Lvl: 7 BOO    HP:  " << stats[1] << "\n";

	}
	//bosses
	else if (enemySignature == 8) {
		cout << "                                                                                  ..                                  \n";
		cout << "                                                                                 .ld;.     'cc;.                      \n";
		cout << "                                                                                .co:;;'...:dxdl,.                     \n";
		cout << "                                                                                .:l;,cc:;;:cclc,.                     \n";
		cout << "                                                                              .lkkdx0KOkxo:;;;'.                      \n";
		cout << "                                                                             .'ldc;oOk0KKOxl;,,.                      \n";
		cout << "                                                                          .',;llc;:llodddol:,..                       \n";
		cout << "                                                                         .''..':lodxdlc::ccc,.                        \n";
		cout << "                                                                        .;......,cxO0kdoool:'.                        \n";
		cout << "                                                                        .;.......:dkkxolodoc,.                        \n";
		cout << "                                                                        .;'.....':oddolc:::;'                         \n";
		cout << "                                                                         .;;''';:cc::,'''''.                          \n";
		cout << "                                                                           ..,;;;,'.'''',,.                           \n";
		cout << "                                                                              ...'.',;;;,'                            \n";
		cout << "                                                                               .;ccclc;.                              \n";
		cout << "                                                                             .,lddolcc,.                              \n";
		cout << "                                                                        .'...:lol:;::c;.                              \n";
		cout << "                                                                         .;,':ddc;:ccc;'..                            \n";
		cout << "                                                                          .:k00dc;;,'''''..,,.                        \n";
		cout << "                                                                           :0NWN0xl:'.',,,;;.                         \n";
		cout << "                                                                          .;xKWWNKxc;:odol:.                          \n";
		cout << "                                                                          ';;lkK0k:':dkxoc'                           \n";
		cout << "                                                                          'c:;cool:,:lool:.                           \n";
		cout << "                                                                           ';,''..',,'.....                           \n";
		cout << fixed << setprecision(2) << "                                                       Lvl: 5 BIRDO      HP:  " << stats[1] << "\n";
	}
	else if (enemySignature == 9)
    {           
                                                       
		cout << "                                                                                                                      .,;,,;;,.          \n";
		cout << "                                                                                                                  .,cdkO0KXXK0d.         \n";
		cout << "                                                                                                              .':ok00KKKXNNNXKOo.        \n";
		cout << "                                                                                                        ..;:coO0O000KXNNWNXNNX0Oo.       \n";
		cout << "                                                                                                  .';ldkO0XXKKKK00KKXWWNXNNNNXK0kl.      \n";
		cout << "                                                                                             .,:lxOKKXXXXXXXK0OO0KXXXXNNNNNXXKKKOkl.     \n";
		cout << "                                                                                           'lkOOOOO00KK0OO00kxO0000XNNNNNXXXXKK0Oko,     \n";
		cout << "                                                                                          .lxxdlllloxkkkkkkddxO0K0KXNXXXXXXXKKK0Okxl.    \n";
		cout << "                                                                                          .lxoc;,'..',;::ccccoxkO00KKXKKKKKKK00OOkxd:.   \n";
		cout << "                                                                                           .,:;'.............';:coxkO000000000OOOkxxo.   \n";
		cout << "                                                                                             ....;oxdc'        ..';coxkOOOOOOOOkxxxdo:.  \n";
		cout << "                                                                                             .  ,dKNXk:.          ..':odxxxxxxxxxddooc.  \n";
		cout << "                                                                                            .   .;okdc'      .':c:'...,:lodddddddooool;. \n";
		cout << "                                                                                           ..    ..''..     .,dKNKd,. ..,:looooooooolll' \n";
		cout << "                                                                                         .,;,....';:;'..     'oOKOo,.   .',:cllllllllcc. \n";
		cout << "                                                                                       .,ckkd:',:llc:;'...    .','.    ..;:;;;::cccccc:. \n";
		cout << "                                                                                      .dkxddo;;cllc::;,.....         ..:oxdl:;,',,;;;,.  \n";
		cout << "                                                                                      .codxko;;locc::;,',;loc;'.....,:oOK0kdlc:,,'..     \n";
		cout << "                                                                                    .':c::cl:,':llcc:;';:ldkO0OkxddxkOK0Oxolccc::'       \n";
		cout << "                                                                             ......,;;;;;;:;,,,,:c:;;;;lddxddxxxk0K0Okkxolccllc:,        \n";
		cout << "                                                                          .,:clllllllc:::c;'.....'',:lodddddxxxxxxxxdoooooooolc'         \n";
		cout << "                                                                       .';:::c:::c:cccccclc:;,,',;;;;:cllodddooddxxxxdddoollc,.          \n";
		cout << "                                                                       ,,;:;::;;;;;:cclllllllllc::c:;'..',:codxdoollcccc:::,.            \n";
		cout << "                                                                       .'.''''''',;:::::::::ccllllllcc;,;;:;;;lxxollc:;,'..              \n";
		cout << "                                                                       ,;,,.......';;;::;;:cccllllllllc;',::,.':cllc:;'..                \n";
		cout << "                                                                       ..,;;;:,..,'.'..',;::::::;::::;'.  ..  ..,::,...                  \n";
		cout << "                                                                          ......,;;,,''''',;,;,,''''..         .''.                      \n";
		cout << "                                                                                ..,;;:;,'...                  .                          \n";
		cout << fixed << setprecision(2) << "                                                   Lvl: 8 MECHA BLOOPER HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 10) 
    {           
		cout << "                                                                            .,'.      .lkc.       .',.                       \n";
		cout << "                                                                             ..:l;. 'lllclod,   :dc..                        \n";
		cout << "                                                                              .o0x:;d0Ol,lKXx::ckXx.                         \n";
		cout << "                                                                              .cxkO0KXKo:oKXXXXX0Oo.                         \n";
		cout << "                                                                                .;k0KXXK0KXXXXX0:..                          \n";
		cout << "                                                                                 .',,;;;;;;;;;;,.                            \n";
		cout << "                                                                                 .:ccccccccccccccc,                          \n";
		cout << "                                                                            .....lNMMMMMMMMMMMMMMM0;.....                    \n";
		cout << "                                                                           .oXNXXNWMMMMMMMMMMMMMMMWNXNNK;                    \n";
		cout << "                                                                         'xOXWMMMMMMMMMMMMMMMMMMMMMMMMMW0ko.                 \n";
		cout << "                                                                         ;XWXO0NMN0OXMMMMMMMMMMMMMMMMMMMMMO.                 \n";
		cout << "                                                                       .'lXWk;c0M0c,kWMMMMMMMMMWXKKKKNMMMM0:..               \n";
		cout << "                                                                      .xNNWWk;cKM0c;kWMMMMMMMWWXc....dWMMMWNNo               \n";
		cout << "                                                                      .OMMMWN0KNWNK0XWMMMMMMk;;:dkkkkd:lKMMMWo               \n";
		cout << "                                                                      .OMNOkKWW0k0NWKkONMMMMOcco0MMMWo .OMMMWo               \n";
		cout << "                                                                      .OM0c;d0Ol,lO0d;c0WMMMMMMMMMNK0o':0MMMWx'.             \n";
		cout << "                                                                      .OM0c,,;;,,,;;;,c0WMMMMMMMMMO'.dXNWMMMMWN0,            \n";
		cout << "                                                                      .OW0c,,,,,,,,,,,c0WMMMMMMMMMNOkXMMMMMMMMMX;            \n";
		cout << "                                                                      .:dxxdc,,,,,,,,,;okKWMMMMMMMMMMMMMMMMMMMMX;            \n";
		cout << "                                                                         'kKd;,;;;;;:lc;,oNMMMMMMMMMMMMMMMMMMNKO,            \n";
		cout << "                                                                          .;;;;;;;;;xNKo;dNMMMMMMMMMMMMMMWWWWx..             \n";
		cout << "                                                                          .,;;;;,lO0XWWX0XWMMMMMMMMMMMMNd;;;;.               \n";
		cout << "                                                                        ..';;;;;,:ooooxXMMMMMMMMMMXxoool.                    \n";
		cout << "                                                                       .';;;;;;;;.    .dK000K0000Kd.                         \n";
		cout << "                                                                       .,;;;;;,,..     ............                          \n";
		cout << "                                                                       .';,;,;'                                              \n";
		cout << "                                                                         .....                                               \n";
		cout << fixed << setprecision(2) << "                                                       Lvl: 11 KING BOO  HP:  " << stats[1] << "\n";
    
	   
    }




}


void BattleMechanics::PrintEnemyIdle()
{
	if (enemySignature == 0)
	{         //"                " space to take out and add
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
		cout << fixed << setprecision(2) << "                                                      Lvl: 1 SHY GUY      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 1)
	{
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
		cout << fixed << setprecision(2) << "                                                           Lvl: 1 GOOMBA      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 2)
	{           
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
		cout << fixed << setprecision(2) << "                                                       Lvl: 2 POKEY      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 3)
	{           
		cout << "                                                              ........                     \n";
		cout << "                                                              .cxOOOOOc''..                \n";
		cout << "                                                               .:xxxxxxxxxd:'.             \n";
		cout << "                                                          .'..;dddlccccccccod,             \n";
		cout << "                                                        .'dN0d0WWW0dlcccccccc'..'''''.     \n";
		cout << "                                                        ;XXKXWNKNWMWkccccccccld0WWWWNd'.   \n";
		cout << "                                                        :XOckWOckWMWkccccccld0WMMMMMMWNc   \n";
		cout << "                                                        :X0x0WKx0WMWkccccld0WMMMMMMMW0d'   \n";
		cout << "                                                        .o0WXKXWMMN0dcc:ckWMMMMMMMMMN:     \n";
		cout << "                                                        ..oXOdk0K0xccc::cd0K0000KKKK0c.    \n";
		cout << "                                                        .coxOOxolccccccccccccccccccodkk;   \n";
		cout << "                                                          .'cxOOxolccccccccccccccccdO0O;   \n";
		cout << "                                                            .:dO0OkxxdoccccccccccccdOxl.   \n";
		cout << "                                                           .:ox000XWWW0xdlcccccccloxO:     \n";
		cout << "                                                          .cxKKKKXNMMMMWW0xddo:;,lOxc.     \n";
		cout << "                                                            'ddd0WMMMMMMMMW0dc'. .c.       \n";
		cout << "                                                                'oddddddddo'               \n";
		cout << fixed << setprecision(2) << "                                                 Lvl: 3 CHEEP CHEEP   HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 4)
	{
		cout << "                                                                   .lkkkkkkkkkkl.              \n";
		cout << "                                                                  .l0WMMMMMMMMMMW0l.           \n";
		cout << "                                                                .c0MMMMMMMMMMMMMMMM0c.         \n";
		cout << "                                                              .c0WMMMMMMMMMMMMMMMMMMW0c.       \n";
		cout << "                                                            .lOWMMMMMMMMMMMMMMMMMMMMMMNOl.     \n";
		cout << "                                                            dWMMMMMWWWWWWWWWWWWWWWWMMMMMWd     \n";
		cout << "                                                           .dMMMWKo:llll:;;;;:llll:oKWMMMd.    \n";
		cout << "                                                            :ONM0; ,kxxO;    ;Oxxk, ;0MNO:     \n";
		cout << "                                                             .cKO' ;KOkK:    :KkOK; 'OKc.      \n";
		cout << "                                                               dNO:,cool,....,looc,:ONd        \n";
		cout << "                                                               dMMNKKKKXXXXXXXXKKKKNMMd        \n";
		cout << "                                                             .c0MMMMMMMMMMMMMMMMMMMMMM0c.      \n";
		cout << "                                                         ;kkk0NMMMMMMMMMMMMMMMMMMMMMMMMN0kkk;  \n";
		cout << "                                                         :kkk0NMMMMMMMMMMMMMMMMMMMMMMMMN0kkk:  \n";
		cout << "                                                             .cKMMMMMMMMMMMMMMMMMMMMMM0c.      \n";
		cout << "                                                             .oXWKol0WMMMWXXWMMMW0loKWXo.      \n";
		cout << "                                                             .oOo'  'kMWKl,,lKWMk'  'oOo.      \n";
		cout << "                                                                    .xMX:    :XMx.             \n";
		cout << "                                                                     .;,.    .,;.              \n";
		cout << fixed << setprecision(2) << "                                                      Lvl: 4 BLOOPER HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 5)
	{           
		cout << "                                                                     ..        ..                                  \n";
		cout << "                                                                ..  .'c;  ;::cc:'   ..                             \n";
		cout << "                                                              ...    .:cc:  coc;.                                  \n";
		cout << "                                                             ...   .'. .okc'           .                           \n";
		cout << "                                                              .....dKl..lxoll,      ....                           \n";
		cout << "                                                             ...,ox0X0Oo'....     .co,...                          \n";
		cout << "                                                         ..  .;cokOKXd;;:cccc,    .okoc;.....                      \n";
		cout << "                                                       ..,;;;:dOkkOKXl .oOkkOl.   .cxkOd:;;;,..                    \n";
		cout << "                                                      .. :OkkOkkkkO00o';dkkkkd,...'  coxkOOO: ..                   \n";
		cout << "                                                      .. :kkkkOOkddddddddddddddoooooc;   lxO: ..                   \n";
		cout << "                                                      .. :kkkO0Kd....................dXkl:    ..                   \n";
		cout << "                                                       ....:xOKXOolllllllllllllllllloOXKOd' ...                    \n";
		cout << "                                                         . .;;:::;;;;;;;;;;;;;;;;,;;;:::;;. .                      \n";
		cout << "                                                           ..  ..  ';;;;;;;;;;;,.  .     ..                        \n";
		cout << "                                                              ....'xXXXXXXXXXXXKl.'. ......                        \n";
		cout << "                                                             .. ,ox0XXXXXXXXXXXX0Oo.      ....                     \n";
		cout << "                                                       .',.      ,.,d00XXXXXXXXXKl..       ;o;...                  \n";
		cout << "                                                      ...,c'       .,lO00000000O;         .,. ..                   \n";
		cout << "                                                      .. ':'         .:clcccccc:.             ..                   \n";
		cout << fixed << setprecision(2) << "                                                           Lvl: 5 GOOMBA      HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 6)
	{           
		cout << "                                                         ,kOl.                             \n";
		cout << "                                                        'xNMk.                             \n";
		cout << "                                                       .:OWMk.',                           \n";
		cout << "                                                         cNMk'lOo'                         \n";
		cout << "                                                       ..dNMXkk0Oc.                        \n";
		cout << "                                                      .;l0WNX0000c.                        \n";
		cout << "                                                      :kodK0O00kl.                         \n";
		cout << "                                                      :OOo,,ckOo'.  ..;cc;.                \n";
		cout << "                                                      ,l,   ,xc;kc .:c;cc;c:.              \n";
		cout << "                                                           'ok;,Ko .lo;;;:oo;.             \n";
		cout << "                                                         .lkxclol::;;;:oo:;:o;             \n";
		cout << "                                                       .;oxOo.dO'.;;;lxxxdl;;.             \n";
		cout << "                                                         ..do.dO',do:;cddc;:l,             \n";
		cout << "                                                           ,,.dO,,ddxl;;;:lxd;             \n";
		cout << "                                                             .dNOc';lc,;;,cl,.             \n";
		cout << "                                                             .cKNk;;::;::;::,.             \n";
		cout << "                                                            .,.'ldoxKWNNNNWWNl             \n";
		cout << "                                                          .,dOdlc' .;ccllllll'             \n";
		cout << "                                                         'oxxxxkx;.   .;cccll,             \n";
		cout << "                                                         .........     .......             \n";
		cout << fixed << setprecision(2) << "                                                     Lvl: 6 KOOPA    HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 7)
	{
		cout << "                                                          ;,ck0OOO0O0Oo;;;          \n";
		cout << "                                                        ;d0KKNNNNNNNNNXKKkc,        \n";
		cout << "                                                       xd:kKoxNWWWWWWWNNXKxc,       \n";
		cout << "                                                      :x0c dO.:XMWWWNXxcc:,l0x:     \n";
		cout << "                                                      l0Ko,k0:lNWWWM0ld00d.;0Ol     \n";
		cout << "                                                      lOO0KK0KK0XWWWWXNN0o;o0o,     \n";
		cout << "                                                      lx:lxlcdo:kWWWWWWNxdKX00d     \n";
		cout << "                                                      lx:,;;;;,;kNWWWWWWWWNX00d     \n";
		cout << "                                                      ,:ol;;;;;:cxXWWWWWWWWNX0d     \n";
		cout << "                                                       oocdxloOdl0WWWWWNXX0xc,      \n";
		cout << "                                                         ;loxOKKK0KXXXXKkodc,       \n";
		cout << "                                                            'clclccllcll,           \n";
		cout << fixed << setprecision(2) << "                                                       Lvl: 7 BOO    HP:  " << stats[1] << "\n";

	}
	//bosses
	else if (enemySignature == 8)
	{          
		cout << "                                                                 ..                                  \n";
		cout << "                                                                .ld;.     'cc;.                      \n";
		cout << "                                                               .co:;;'...:dxdl,.                     \n";
		cout << "                                                               .:l;,cc:;;:cclc,.                     \n";
		cout << "                                                             .lkkdx0KOkxo:;;;'.                      \n";
		cout << "                                                            .'ldc;oOk0KKOxl;,,.                      \n";
		cout << "                                                         .',;llc;:llodddol:,..                       \n";
		cout << "                                                        .''..':lodxdlc::ccc,.                        \n";
		cout << "                                                       .;......,cxO0kdoool:'.                        \n";
		cout << "                                                       .;.......:dkkxolodoc,.                        \n";
		cout << "                                                       .;'.....':oddolc:::;'                         \n";
		cout << "                                                        .;;''';:cc::,'''''.                          \n";
		cout << "                                                          ..,;;;,'.'''',,.                           \n";
		cout << "                                                             ...'.',;;;,'                            \n";
		cout << "                                                              .;ccclc;.                              \n";
		cout << "                                                            .,lddolcc,.                              \n";
		cout << "                                                       .'...:lol:;::c;.                              \n";
		cout << "                                                        .;,':ddc;:ccc;'..                            \n";
		cout << "                                                         .:k00dc;;,'''''..,,.                        \n";
		cout << "                                                          :0NWN0xl:'.',,,;;.                         \n";
		cout << "                                                         .;xKWWNKxc;:odol:.                          \n";
		cout << "                                                         ';;lkK0k:':dkxoc'                           \n";
		cout << "                                                         'c:;cool:,:lool:.                           \n";
		cout << "                                                          ';,''..',,'.....                           \n";
		cout << fixed << setprecision(2) << "                                                       Lvl: 5 BIRDO      HP:  " << stats[1] << "\n";
	}
	else if (enemySignature == 9)
	{
	cout << "                                                                                                      .,;,,;;,.          \n";
	cout << "                                                                                                  .,cdkO0KXXK0d.         \n";
	cout << "                                                                                              .':ok00KKKXNNNXKOo.        \n";
	cout << "                                                                                        ..;:coO0O000KXNNWNXNNX0Oo.       \n";
	cout << "                                                                                  .';ldkO0XXKKKK00KKXWWNXNNNNXK0kl.      \n";
	cout << "                                                                             .,:lxOKKXXXXXXXK0OO0KXXXXNNNNNXXKKKOkl.     \n";
	cout << "                                                                           'lkOOOOO00KK0OO00kxO0000XNNNNNXXXXKK0Oko,     \n";
	cout << "                                                                          .lxxdlllloxkkkkkkddxO0K0KXNXXXXXXXKKK0Okxl.    \n";
	cout << "                                                                          .lxoc;,'..',;::ccccoxkO00KKXKKKKKKK00OOkxd:.   \n";
	cout << "                                                                           .,:;'.............';:coxkO000000000OOOkxxo.   \n";
	cout << "                                                                             ....;oxdc'        ..';coxkOOOOOOOOkxxxdo:.  \n";
	cout << "                                                                             .  ,dKNXk:.          ..':odxxxxxxxxxddooc.  \n";
	cout << "                                                                            .   .;okdc'      .':c:'...,:lodddddddooool;. \n";
	cout << "                                                                           ..    ..''..     .,dKNKd,. ..,:looooooooolll' \n";
	cout << "                                                                         .,;,....';:;'..     'oOKOo,.   .',:cllllllllcc. \n";
	cout << "                                                                       .,ckkd:',:llc:;'...    .','.    ..;:;;;::cccccc:. \n";
	cout << "                                                                      .dkxddo;;cllc::;,.....         ..:oxdl:;,',,;;;,.  \n";
	cout << "                                                                      .codxko;;locc::;,',;loc;'.....,:oOK0kdlc:,,'..     \n";
	cout << "                                                                    .':c::cl:,':llcc:;';:ldkO0OkxddxkOK0Oxolccc::'       \n";
	cout << "                                                             ......,;;;;;;:;,,,,:c:;;;;lddxddxxxk0K0Okkxolccllc:,        \n";
	cout << "                                                          .,:clllllllc:::c;'.....'',:lodddddxxxxxxxxdoooooooolc'         \n";
	cout << "                                                       .';:::c:::c:cccccclc:;,,',;;;;:cllodddooddxxxxdddoollc,.          \n";
	cout << "                                                       ,,;:;::;;;;;:cclllllllllc::c:;'..',:codxdoollcccc:::,.            \n";
	cout << "                                                       .'.''''''',;:::::::::ccllllllcc;,;;:;;;lxxollc:;,'..              \n";
	cout << "                                                       ,;,,.......';;;::;;:cccllllllllc;',::,.':cllc:;'..                \n";
	cout << "                                                       ..,;;;:,..,'.'..',;::::::;::::;'.  ..  ..,::,...                  \n";
	cout << "                                                          ......,;;,,''''',;,;,,''''..         .''.                      \n";
	cout << "                                                                ..,;;:;,'...                  .                          \n";
	cout << fixed << setprecision(2) << "                                                   Lvl: 8 MECHA BLOOPER HP:  " << stats[1] << "\n";

	}
	else if (enemySignature == 10)
	{         
		cout << "                                                             .,'.      .lkc.       .',.                       \n";
		cout << "                                                              ..:l;. 'lllclod,   :dc..                        \n";
		cout << "                                                               .o0x:;d0Ol,lKXx::ckXx.                         \n";
		cout << "                                                               .cxkO0KXKo:oKXXXXX0Oo.                         \n";
		cout << "                                                                 .;k0KXXK0KXXXXX0:..                          \n";
		cout << "                                                                  .',,;;;;;;;;;;,.                            \n";
		cout << "                                                                  .:ccccccccccccccc,                          \n";
		cout << "                                                             .....lNMMMMMMMMMMMMMMM0;.....                    \n";
		cout << "                                                            .oXNXXNWMMMMMMMMMMMMMMMWNXNNK;                    \n";
		cout << "                                                          'xOXWMMMMMMMMMMMMMMMMMMMMMMMMMW0ko.                 \n";
		cout << "                                                          ;XWXO0NMN0OXMMMMMMMMMMMMMMMMMMMMMO.                 \n";
		cout << "                                                        .'lXWk;c0M0c,kWMMMMMMMMMWXKKKKNMMMM0:..               \n";
		cout << "                                                       .xNNWWk;cKM0c;kWMMMMMMMWWXc....dWMMMWNNo               \n";
		cout << "                                                       .OMMMWN0KNWNK0XWMMMMMMk;;:dkkkkd:lKMMMWo               \n";
		cout << "                                                       .OMNOkKWW0k0NWKkONMMMMOcco0MMMWo .OMMMWo               \n";
		cout << "                                                       .OM0c;d0Ol,lO0d;c0WMMMMMMMMMNK0o':0MMMWx'.             \n";
		cout << "                                                       .OM0c,,;;,,,;;;,c0WMMMMMMMMMO'.dXNWMMMMWN0,            \n";
		cout << "                                                       .OW0c,,,,,,,,,,,c0WMMMMMMMMMNOkXMMMMMMMMMX;            \n";
		cout << "                                                       .:dxxdc,,,,,,,,,;okKWMMMMMMMMMMMMMMMMMMMMX;            \n";
		cout << "                                                          'kKd;,;;;;;:lc;,oNMMMMMMMMMMMMMMMMMMNKO,            \n";
		cout << "                                                           .;;;;;;;;;xNKo;dNMMMMMMMMMMMMMMWWWWx..             \n";
		cout << "                                                           .,;;;;,lO0XWWX0XWMMMMMMMMMMMMNd;;;;.               \n";
		cout << "                                                         ..';;;;;,:ooooxXMMMMMMMMMMXxoool.                    \n";
		cout << "                                                        .';;;;;;;;.    .dK000K0000Kd.                         \n";
		cout << "                                                        .,;;;;;,,..     ............                          \n";
		cout << "                                                        .';,;,;'                                              \n";
		cout << "                                                          .....                                               \n";
		cout << fixed << setprecision(2) << "                                                       Lvl: 11 KING BOO  HP:  " << stats[1] << "\n";

	}
}

void BattleMechanics::PrintUserAttack(char userChar, int userBattleMP, int userHP, int userMP, double userBattleHP)
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

		cout << "     MARIO\n";
		cout << fixed << setprecision(2) << "    HP : " << userBattleHP << "  /  " << userHP << "\n";
		cout << "    MP : " << userBattleMP << "  /  " << userMP << "\n";

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

		cout << "     LUIGI\n";
		cout << fixed << setprecision(2) << "    HP : " << userBattleHP << "  /  " << userHP << "\n";
		cout << "    MP : " << userBattleMP << "  /  " << userMP << "\n";
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

		cout << "     TOAD\n";
		cout << fixed << setprecision(2) << "    HP : " << userBattleHP << "  /  " << userHP << "\n";
		cout << "    MP : " << userBattleMP << "  /  " << userMP << "\n";
	}
}

void BattleMechanics::PrintUserAttacked(char userChar, int userBattleMP, int userHP, int userMP, double userBattleHP)
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

		cout << "     MARIO\n";
		cout << fixed << setprecision(2) << "    HP : " << userBattleHP << "  /  " << userHP << "\n";
		cout << "    MP : " << userBattleMP << "  /  " << userMP << "\n";

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

		cout << "     LUIGI\n";
		cout << fixed << setprecision(2) << "    HP : " << userBattleHP << "  /  " << userHP << "\n";
		cout << "    MP : " << userBattleMP << "  /  " << userMP << "\n";
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

		cout << "     TOAD\n";
		cout << fixed << setprecision(2) << "    HP : " << userBattleHP << "  /  " << userHP << "\n";
		cout << "    MP : " << userBattleMP << "  /  " << userMP << "\n";
	}

}

void BattleMechanics::PrintUserIdle(char userChar, int userBattleMP, int userHP, int userMP, double userBattleHP)
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

		cout << "     MARIO\n";
		cout << fixed << setprecision(2) << "    HP : " << userBattleHP << "  /  " << userHP << "\n";
		cout << "    MP : " << userBattleMP << "  /  " << userMP << "\n";

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

		cout << "     LUIGI\n";
		cout << fixed << setprecision(2) << "    HP : " << userBattleHP << "  /  " << userHP << "\n";
		cout << "    MP : " << userBattleMP << "  /  " << userMP << "\n";
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

		cout << "     TOAD\n";
		cout << fixed << setprecision(2) << "    HP : " << userBattleHP << "  /  " << userHP << "\n";
		cout << "    MP : " << userBattleMP << "  /  " << userMP << "\n";
	}

}