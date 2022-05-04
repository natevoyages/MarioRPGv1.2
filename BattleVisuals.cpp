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

	void BattleVisuals::PrintUserAttack(char userChar)
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

	void BattleVisuals::PrintUserAttacked(char userChar)
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

	void BattleVisuals::PrintUserIdle(char userChar)
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
