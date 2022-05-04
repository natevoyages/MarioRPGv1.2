#include "BattleVisuals.h"

void BattleVisuals::PrintEnemyAttack(int enemySignature)
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
		cout << "                //                                        Lvl: 2 POKEY      HP:  " << stats[2] << "\n";
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

void BattleVisuals::PrintEnemyAttacked(int enemySignature)
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


	void BattleVisuals::PrintEnemyIdle(int enemySignature)
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
		cout << "                                                       Lvl: 2 POKEY      HP:  " << stats[2] <<  "\n";
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
