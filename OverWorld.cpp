#include "OverWorld.h"



OverWorld::OverWorld()
{
    exitMap = false;
    menuToggled = false;
    notGameOver = true;
    northOpen = false;
    southOpen = false;
    eastOpen = false;
    westOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width / 2;
    yCoordinate = height - 1;
    saveXCoordinate =  0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    bossXCoordinate = 0;
    bossYCoordinate = -1;
    bedXCoordinate = 0;
    bedYCoordinate = -1;
    map = 0;
    bossesBeaten = 0;
    stepCounter = 0;
}
 bool OverWorld::GetNotGameOver() const
 {
     return notGameOver;
 }

void OverWorld::Shop()
{
    bool exit = false;
    xCoordinate = prevXCoordinate;
    yCoordinate = prevYCoordinate;
    system("cls");
    PrintShopKeep();
    Sleep(1500);
    /*while (!exit)
    {
         ShopMenu();


    }*/
}

void OverWorld::ExitMapCoordinates()
{ 
    if (exitMapNorth)
    {
        xCoordinate = width / 2;
        yCoordinate = height - 1;
    }
    else if(exitMapSouth)
    {
        xCoordinate = width / 2;
        yCoordinate = 0;
    }

    else if (exitMapWest)
    {
        xCoordinate = width - 2;
        yCoordinate = height / 2;
    }
    else if (exitMapEast)
    {
        xCoordinate = 1;
        yCoordinate = height / 2;
    }
  
}
void OverWorld::LoadGame()
{
    ifstream load;
    load.open("save.dat");
    if (!(load.fail())) {
        load >> bossesBeaten >> map >> userCharacter >> stringCharacter >> xCoordinate >> yCoordinate >> userLevel >> userHealthPoints >> userPower >> userJump >>
            userFlowerPower >> userSpeed >> userDefense >> userEXP >> userCoins >> userStatPts;
        load.close();
    }
    else
    {
        cout << "\n\n\n\n\n\n\n\n\n\	    	  ERROR: COULD NOT READ SAVE";

    }
    playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
        userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
}

void OverWorld::SaveGame()
{
    string saving[] = { "Saving.", "Saving..", "Saving...","Saving.", "Saving..", "Saving...",
        "Saving.", "Saving..", "Saving...", };
    ofstream save;
    save.open("save.dat");
    save << bossesBeaten << " " << map << " " << userCharacter << " " << stringCharacter << " " << prevXCoordinate << " " << prevYCoordinate
        << " " << userLevel << " " << userHealthPoints << " " << userPower << " " << userJump << " " << userFlowerPower << " "
        <<  userSpeed << " " << userDefense << " " << userEXP << " " << userCoins << " " << userStatPts;
    save.close();
    for (int i = 0; i < 9; i++) 
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\	    	  " << saving[i];
    }
    xCoordinate = prevXCoordinate;
    yCoordinate = prevYCoordinate;
}

void OverWorld::characterTracker()
{
    if (!(xCoordinate == saveXCoordinate && yCoordinate == saveYCoordinate) && 
        !(xCoordinate == shopKeepXCoordinate && yCoordinate == shopKeepYCoordinate))
    {
        prevXCoordinate = xCoordinate;
        prevYCoordinate = yCoordinate;
    }
}


void OverWorld::PrintOverWorld(char charCharacter,bool& play , bool &notGAMEOVER)
{
            map = 0;
            bossesBeaten = 0;
            stepCounter = 0;
        if (!exitMap)
        {
            stepCounter = 0;
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                    userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
            }
        }
        if (exitMapSouth)
        {
            PrintDesert();
            map = 1;
        }
        if (notGameOver && exitMap)
        {
            while (notGameOver)
            {
                exitMap = false;
                SetUpMap();
            }
        }
        if (!notGameOver)
        {
            notGAMEOVER = false;
            play = false;
        }
}

void OverWorld::IfBattleEncounted()
{
    bool battleState = false;

    if (stepCounter >= battle.GetBattleTrigger())
    {
        battleState = true;
        while (battleState)
        {
            battle.BattleTriggered(map, notGameOver, userHealthPoints, userMagicPoints, userPower, userJump, userFlowerPower, userSpeed, userDefense,
                userBattleHP, userBattleMP, userCoins, userEXP, userLevel, userCoins, userCharacter, battleState);
        }
        mapsInput.StepCountReset();
    }
}

void OverWorld::SetUpMap()
{
    if (map == 0)
    {
        HomeSetup();
        while (!exitMap)
        {
            stepCounter = 0;
            OverWorldPrintLogic();
            cout << "\nSTEPS: " << stepCounter << "\n";
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                    userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
            }
        }
        if (exitMapSouth) 
        {
            PrintDesert();
            map = 1;
        }
        ExitMapCoordinates();
    }

    else if (map == 1)        // start of Desert maps
    {
        battle.SetBattleTrigger();
        DesertOneSetup();
        while (!exitMap)
        {

            mapsInput.StepCounter();
            stepCounter = mapsInput.GetStepCount();
            IfBattleEncounted();
            OverWorldPrintLogic();
            cout << "\nSTEPS: " << stepCounter << "\n"; // fix me
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);

            characterTracker();
            CollisonLogic(); 
            inGame.SetUpMenu();
            while (menuToggled)
            {
                playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                    userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
       
            }
        }
        if (exitMapNorth)
        {
            map = 0;
        }
        else if (exitMapSouth)
        {
            map = 2;
        }
        ExitMapCoordinates();

    }

    else if (map == 2)
    {
        battle.SetBattleTrigger();
        DesertTwoSetup();
        while (!exitMap)
        {
            mapsInput.StepCounter();
            stepCounter = mapsInput.GetStepCount();
            IfBattleEncounted();
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);

            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                    userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
            }
        }
        if (exitMapNorth)
        {
            map = 1;
        }
        else if (exitMapWest)
        {
            map = 3;
        }
        else if (exitMapEast)
        {
            map = 4;
        }
        ExitMapCoordinates();
    }

    else if (map == 3)
    {
        DesertThreeSetup();
        while (!exitMap)
        {
            stepCounter = 0;
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                    userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
            }
        }
        if (exitMapNorth)
        {
            PrintSeaFloor();
            map = 5;
        }
        else if (exitMapEast)
        {
            map = 2;
        }
        ExitMapCoordinates();
    }

    else if (map == 4)             // shop
    {
        ShopOneSetup();
        while (!exitMap)
        {
            stepCounter = 0;
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                    userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
            }
        }
        if (exitMapWest)
        {
            map = 2;
        }
        ExitMapCoordinates();
    }

    else if (map == 5)        // start of Sea Floor maps
    {
        SeaFloorOneSetup();
        while (!exitMap)
        {
           
            stepCounter = mapsInput.GetStepCount();
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                    userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
            }
        }
        if (exitMapWest)
        {
            map = 6;
        }
        else if (exitMapSouth)
        {
            PrintDesert();
            map = 3;
        }
        ExitMapCoordinates();
    }

    else if (map == 6)
    {
        SeaFloorTwoSetup();
        while (!exitMap)
        {
            mapsInput.GetStepCount();
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                    userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
            }
        }
        if (exitMapWest)
        {
            map = 7;
        }
        else if (exitMapEast)
        {
            map = 5;
        }
        else if (exitMapSouth)
        {
            map = 8;
        }
        ExitMapCoordinates();
    }

 

    else if (map == 7)
    {
       SeaFloorThreeSetup();
       while (!exitMap)
       {
           stepCounter = 0;
           OverWorldPrintLogic();
           mapsInput.UserInput(menuToggled);
           mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
           characterTracker();
           CollisonLogic();
           inGame.SetUpMenu();
           while (menuToggled)
           {
               playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                   userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
              inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
           }
        }
       if (exitMapNorth)
       {
           PrintCastle();
           map = 9;
       }
       else if(exitMapEast)
       {
           map = 6;
       }
       ExitMapCoordinates();
    }

    else if (map == 8)
    {
        ShopTwoSetup();
        while (!exitMap)
        {
            stepCounter = 0;
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                    userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
            }
        }
        if (exitMapNorth)
        {
            map = 6;
        }
        ExitMapCoordinates();
    }

    else if (map == 9)
    {
       CastleOneSetup();
       while (!exitMap)
       {
           mapsInput.GetStepCount();
           OverWorldPrintLogic();
           mapsInput.UserInput(menuToggled);
           mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
           characterTracker();
           CollisonLogic();
           inGame.SetUpMenu();
           while (menuToggled)
           {
               playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                   userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
               inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
           }
       }

        if (exitMapNorth)
        {
            map = 10;
        }
        else if (exitMapSouth)
        {
            PrintSeaFloor();
            map = 7;
        }
        ExitMapCoordinates();
    }
    
    else if (map == 10)
    {
    CastleTwoSetup();
    while (!exitMap)
    {
        mapsInput.GetStepCount();
        OverWorldPrintLogic();
        mapsInput.UserInput(menuToggled);
        mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
        characterTracker();
        CollisonLogic();
        inGame.SetUpMenu();
        while (menuToggled)
        {
            playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
            inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
        }
    }

        if (exitMapNorth)
        {
            map = 11;
        }
        else if (exitMapSouth)
        {
            map = 9;
        }
        ExitMapCoordinates();
 
    }

    else if (map == 11)
    {
        CastleThreeSetup();
        while (!exitMap)
        {
            stepCounter = 0;
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                playerStats.SetPlayer(stringCharacter, userCharacter, userLevel, userHealthPoints, userPower, userJump,
                    userFlowerPower, userSpeed, userDefense, userEXP, userCoins, userStatPts);
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap, playerStats, items);
            }
        }

        if (exitMapNorth)
        {
            map = 12;
        }
        else if (exitMapSouth)
        {
            map = 10;
        }
        ExitMapCoordinates();
    }

    else if (map == 12)
    {
    system("cls");
    PrintGameWin();
    Sleep(5000);

        notGameOver = false;
    }
}

void OverWorld::OverWorldPrintLogic()
{
    Sleep(100);
    system("cls");
    for (int i = 0; i < width; i++)
    {
        if(northOpen)
        {
            if (i == width / 2 || i == (width / 2) + 1) //exit for map
            {
                cout << "_";
            }
            else
            {
                cout << "#";
            }
        }
        else
        {
            cout << "#";
        }

    }

    cout << "\n";

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (westOpen && !eastOpen)
            {
                if (i == height /2 && j == 0) 
                {
                    cout << "|";
                }
                else if (j == 0 || j == (width - 1))
                {
                    cout << "#";
                }

                else if (i == saveYCoordinate && j == saveXCoordinate)
                {
                    cout << "S";
                }

                else if (i == shopKeepYCoordinate && j == shopKeepXCoordinate)
                {
                    cout << "k";
                }
                else if (i == bossYCoordinate && j == bossXCoordinate)
                {
                    cout << "B";
                }
                else if (i == bedYCoordinate && j == bedXCoordinate)
                {
                    cout << "b";
                }

                else if (i == yCoordinate && j == xCoordinate)
                {
                    cout << userCharacter;
                }
                else
                {
                    cout << " ";
                }
            }

            else if (!westOpen && eastOpen)
            {
                if (i == height / 2 && j == width - 1)
                {
                    cout << "|";
                }
                else if (j == 0 || j == (width - 1))
                {
                    cout << "#";
                }

                else if (i == saveYCoordinate && j == saveXCoordinate)
                {
                    cout << "S";
                }

                else if (i == shopKeepYCoordinate && j == shopKeepXCoordinate)
                {
                    cout << "k";
                }
                else if (i == bossYCoordinate && j == bossXCoordinate)
                {
                    cout << "B";
                }
                else if (i == bedYCoordinate && j == bedXCoordinate)
                {
                    cout << "b";
                }


                else if (i == yCoordinate && j == xCoordinate)
                {
                    cout << userCharacter;
                }
                else
                {
                    cout << " ";
                }
            }

            else if (westOpen && eastOpen)
            {
                if ( (i == height / 2 && j == 0) || (i == height / 2 && j == width - 1) )
                {
                    cout << "|";
                }
                else if (j == 0 || j == (width - 1))
                {
                    cout << "#";
                }

                else if (i == saveYCoordinate && j == saveXCoordinate)
                {
                    cout << "S";
                }

                else if (i == shopKeepYCoordinate && j == shopKeepXCoordinate)
                {
                    cout << "k";
                }
                else if (i == bossYCoordinate && j == bossXCoordinate)
                {
                    cout << "B";
                }
                else if (i == bedYCoordinate && j == bedXCoordinate)
                {
                    cout << "b";
                }

                else if (i == yCoordinate && j == xCoordinate)
                {
                    cout << userCharacter;
                }
                else
                {
                    cout << " ";
                }
            }

            else {
                if (j == 0 || j == (width - 1))
                {
                    cout << "#";
                }

                else if (i == saveYCoordinate && j == saveXCoordinate)
                {
                    cout << "S";
                }

                else if (i == shopKeepYCoordinate && j == shopKeepXCoordinate)
                {
                    cout << "k";
                }
                else if (i == bossYCoordinate && j == bossXCoordinate)
                {
                    cout << "B";
                }
                else if (i == bedYCoordinate && j == bedXCoordinate)
                {
                    cout << "b";
                }


                else if (i == yCoordinate && j == xCoordinate)
                {
                    cout << userCharacter;
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }

    for (int i = 0; i < width; i++) 
    {
        if (southOpen) 
        {
            if (i == width / 2 || i == (width / 2) + 1) //exit for map
            {
                cout << "_";
            }
            else 
            {
                cout << "#";
            }
        }
        else
        {
            cout << "#";
        }
    }

    cout << "\n\n\n\n           'w' = UP                    HOLD SHIFT + DIRECTION = RUN\n";
    cout <<         "'a' = LEFT 's' = DOWN 'd' = RIGHT                PRESS SPACE = MENU";


}

void OverWorld::CollisonLogic()
{
    if(xCoordinate == saveXCoordinate && yCoordinate == saveYCoordinate)
    {
        SaveGame();

    }

    else if (xCoordinate == shopKeepXCoordinate && yCoordinate == shopKeepYCoordinate)
    {
        Shop();
    }

    else if (xCoordinate == bedXCoordinate && yCoordinate == bedYCoordinate)
    {
        //Rest();                                                                             // fix me
        system("cls");
        cout << "RESTING";
            Sleep(1000);
    }

    else if (xCoordinate == bossXCoordinate && yCoordinate == bossYCoordinate)// add second set of coordinates
    {
        //BossBattle();                                                                              // fix me
        system("cls");
        cout << "BOSS BATTLEEEEE";
            Sleep(1000);
    }

    else if ((xCoordinate == width / 2 && yCoordinate == height) || ((xCoordinate == width / 2 + 1) && yCoordinate == height) )
    {
        exitMap = true;
        exitMapSouth = true;

    }
    else if ((xCoordinate == width / 2 && yCoordinate == -1) || ((xCoordinate == width / 2 + 1) && yCoordinate == -1))
    {
        exitMap = true;
        exitMapNorth = true;
    }

    else if (xCoordinate == 0 && yCoordinate == height / 2)
    {
        exitMap = true;
        exitMapWest = true;
    }

    else if (xCoordinate == width - 1 && yCoordinate == height / 2)
    {
        exitMap = true;
        exitMapEast = true;
    }
}
 // Map setups
void OverWorld::NewGameHomeSetup(char charCharacter, string character, int hp, int power, int jump, int flwrPwr, int speed, int defense)  //used for newGame
{
    exitMap = false;
    southOpen = true;
    northOpen = false;
    westOpen = false;
    eastOpen = false;   
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width / 2;
    yCoordinate = height / 2;
    saveXCoordinate = width / 6;  //Makes save icon invisible     saveXCoordinate = 0;
    saveYCoordinate = height - 7; //                              saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    bossXCoordinate = 0;
    bossYCoordinate = -1;
    bedXCoordinate = (width / 2) + 5;
    bedYCoordinate = height / 2;
    userCharacter = charCharacter;
    stringCharacter = character;
    userLevel = 3;
    userHealthPoints = hp;
    userPower = power;
    userJump = jump;
    userFlowerPower = flwrPwr;
    userSpeed = speed;
    userDefense = defense;
    userEXP = 0;
    userCoins = 0;
    userStatPts = 0;
    map = 0;
}
//  map 0
void OverWorld::HomeSetup()
{
    ExitMapCoordinates();
    exitMap = false;
    southOpen = true; // to map 1
    northOpen = false;
    westOpen = false;
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = width / 6;      
    saveYCoordinate = height - 7; 
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    bossXCoordinate = 0;
    bossYCoordinate = -1;
    bedXCoordinate = (width / 2) + 2;
    bedYCoordinate = height / 2;
    map = 0;
}
//  map 1
void OverWorld::DesertOneSetup()
{
    ExitMapCoordinates();
    exitMap = false;
    southOpen = true;// to map 2
    northOpen = true;// back to map 1
    westOpen = false;
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    bossXCoordinate = 0;
    bossYCoordinate = -1;
    bedXCoordinate = 0;
    bedYCoordinate = -1;
    map = 1;
}
//  map 2
void OverWorld::DesertTwoSetup()
{
    ExitMapCoordinates();
    exitMap = false;
    southOpen = false;
    northOpen = true; // back to map 2
    westOpen = true;  //to map 3
    eastOpen = true;  // to shop map 4
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    bossXCoordinate = 0;
    bossYCoordinate = -1;
    bedXCoordinate = 0;
    bedYCoordinate = -1;
    map = 2;
}
//  map 3
void OverWorld::DesertThreeSetup() 
{
    ExitMapCoordinates();
    exitMap = false;
    southOpen = false;
    northOpen = true; // to Sea Floor map 5
    westOpen = false;
    eastOpen = true;  // back to map 2
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    bossXCoordinate = width / 2;
    bossYCoordinate = 0;
    bedXCoordinate = 0;
    bedYCoordinate = -1;
    map = 3;
}
//  map 4
void OverWorld::ShopOneSetup()
{
    ExitMapCoordinates();
    exitMap = false;
    southOpen = false;
    northOpen = false;
    westOpen = true; // back to map 2
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = 8;
    saveYCoordinate = 8;
    shopKeepXCoordinate = width / 2;
    shopKeepYCoordinate = height / 2;
    bossXCoordinate = 0;
    bossYCoordinate = -1;
    bedXCoordinate = 0;
    bedYCoordinate = -1;
    map = 4;
}
//  map 5
void OverWorld::SeaFloorOneSetup()
{
    ExitMapCoordinates();
    exitMap = false;
    southOpen = true;  //back to map 3
    northOpen = false;
    westOpen = true;   // to map 6
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    bossXCoordinate = 0;
    bossYCoordinate = -1;
    bedXCoordinate = 0;
    bedYCoordinate = -1;
    map = 5;
}
//  map 6
void OverWorld::SeaFloorTwoSetup()
{
    ExitMapCoordinates();
    exitMap = false;
    southOpen = true; // to shop map 8
    northOpen = false;
    westOpen = true; // to map 7
    eastOpen = true; // back to map 5
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    bossXCoordinate = 0;
    bossYCoordinate = -1;
    bedXCoordinate = 0;
    bedYCoordinate = -1;
    map = 6;
}

// map 7
void OverWorld::SeaFloorThreeSetup()
{
    ExitMapCoordinates();
    exitMap = false;
    southOpen = false;
    northOpen = true; // to Castle map 9
    westOpen = false;
    eastOpen = true; // back to map 6
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;

    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    bossXCoordinate = 0;
    bossYCoordinate = -1;
    bedXCoordinate = 0;
    bedYCoordinate = -1;
    map = 7;
}
// map 8
void OverWorld::ShopTwoSetup()
{
    ExitMapCoordinates();
    exitMap = false;
    southOpen = false;
    northOpen = true;  // back to map 6
    westOpen = false;
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;                     // can save here
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = 8;
    saveYCoordinate = 8;
    shopKeepXCoordinate = width / 2;
    shopKeepYCoordinate = height / 2;
    map = 8;
}
//map 9
void OverWorld::CastleOneSetup()
{
    exitMap = false;
    southOpen = true;// to map 10
    northOpen = true;// back to map 7
    westOpen = false;
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    map = 9;
}
//map 10
void OverWorld::CastleTwoSetup()
{
    exitMap = false;
    southOpen = true;// to map 11
    northOpen = true;// back to map 9
    westOpen = false;
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = 10;
    saveYCoordinate = 10;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    map = 10;
}
// map 11
void OverWorld::CastleThreeSetup()
{
    exitMap = false;
    southOpen = true;// to endGame
    northOpen = true;// back to map 10
    westOpen = false;
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    map = 11;
}


void OverWorld::PrintDesert()
{
    system("cls");
    cout << "\n\n,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << ",,''''',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << "......,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << "....',,,,,;,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << "...,;,,;,,:cll:,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    cout << "......'''',:c:'',,;;,,;;,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,;;,,,,,,,,,;;;,,,,;,,,,,,,,,;,,;,,,,,,,,\n";
    cout << "  .............';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n";
    cout << "..........,,,,,,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,,'',,,;;;;;;;,,,,'',,;;;;;;;;;;;;;;\n";
    cout << "'',,,,,,,',coc,,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,'......',,;;,'.......';;;;;;;;;;;;;;\n";
    cout << ".',;;;;;;'.....,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,'..............',,;;;;;;;;;;;;;;;\n";
    cout << "',;;;;;;;,''''',;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;''........',;;;;;;;;;;;;;;;;;;;\n";
    cout << "';;;:;;:;,;lol;,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;:;,,'............,;;;;;;;;;;;;;;;;;;\n";
    cout << ".,::;:::;'.'''.,;:::;;::::::::::::::::::::::::::::::::::::::::::::::::::::::::::;;:;,'.................,;:::::::::::::::\n";
    cout << ".';:::::;'.....,;:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::;,......'''...''... ...,::::::::::::::\n";
    cout << ".';:::::;,;clc;,::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::,..','.........',;,... .;:::::::::::::\n";
    cout << ".',::::::'.,;,.,::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::;;;::..........,::::;,..':::::::::::::\n";
    cout << "..';c::c:,.....,::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::c:;....;,....,:::::::;;:::::::::::::\n";
    cout << ".'';llodo:;:c:,;:cc:::::::::::::::::::ccc::::::::::::::::::::::::::ccc::c:::::ccllodolc;..;c:'...;c:::::::::::::::cccccc\n";
    cout << "...;xxdoc,';c;';ccccccccccccc::::ccccllcclooollcccccc:cc:::::::::cloollcccccclodxxdo:;::;:ccc;..':c::::ccc:cc::ccloddxxx\n";
    cout << "...;ooc;;'.....;lccccloollcccccccllloodxxxkkdc:cloddolcc::ccc::cloooollllllodxxxdl:;;:;;;:ccc,..,:lccccccccccclodooodxkk\n";
    cout << "..'';:;;;,,;;;,;clolllllllllllloooddddddddlcc:;;;:coxxdolccccccloooollllodxxdolc:;;;;;;;;;;::,..':llllllllloodoc;'..'':l\n";
    cout << "...',;;;;,,cl:,,;;:loodddddddddxxdddoolll:,'',,;;;;:cldxxdolllloolllooddxxdlc:;;;;;;;;;;;;;;,'..':dddddddddxxl,.........\n";
    cout << ".''',;;;;'.....,;:;;;::cclllcccccccc:;,,,,''''',;;;:;;:ldxkxxxddlcodxxdolc:;,,,,;;;;;;;;;;;;,....,:clllllllc:...........\n";
    cout << ",,,,,;;;;,'...',;;;;;;;;;;;;,,;;;;;;;,,,,,,,,,,,,,;;;;;;:coolool;;cllc:;;;;,,,,,;;;;;;;;;;;;,'',,,;;;;;;;;;;,..''.....'.\n";
    cout << ":::::::::::c:::c:::::::::::cc::::::::::::::::::::::::::::::::::::::::::::::::cc:::::::::c::c:::::::::::::::::::::::c::::\n";
    cout << ":::::::cc:cc::c::ccc::ccccccc::cccccc::::::::::::::::c:::c:ccc:::::cc:::::cc::::cccccccccc:cccc::cc:::cc:cc::cc:c::cc:::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n\n";

    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * D E S E R T   Z O N E * * * * * * * * * * * * * * * * * * * * * * * * *";
    Sleep(2700);
}

void OverWorld::PrintSeaFloor()
{
    system("cls");
    cout << "\n\n                                                                                                                                          ;dxdooo;    \n";
    cout << "                                                                                                                                          cxxxold:    \n";
    cout << ":;,    ;llc;                                                                                                                             'lxxxold:    \n";
    cout << "xxo;  ,oxddo;                                                                                      ,;,                                   'lxddlod;    \n";
    cout << "dddc' ,oxddd:                                           ';:::,                                   ;d0XOd;                                  ,ldddo;     \n";
    cout << "dddc' ,oxddo;                                         'cOXX00kl,                               ,o0NWWNX0x;                                 ,:cc,      \n";
    cout << "ddl;   ;lll:'    ''                                  ;dKWWNNKOK0o,                            ':xK0kk0Kkl;                                ':oodo;     \n";
    cout << ",,,      ''     ;lol;'         ',,,,'              ,o0NWMWNNNKOXW0o,                            :xo;;oxd,                                 cxxdooo,    \n";
    cout << "               ,oxddo;        ;ooc;,,,'          'lONNWMMWNNNN0OKXKx:                          'd00OO0OOl                                'lxxxlod;    \n";
    cout << "               ;dxddd:      ,lxd:'' ,;:;'        ,ldOXXKK00000K0ko;,,                          ,kXXK0KKKl                                'oxxxlod,    \n";
    cout << "               ,oxddo;    ',:okxdoolodddc,         ,x0o;'';oxxxkOx;                            'dXXKOKX0c                                'cddoodc'    \n";
    cout << "                ;lll;'    ;,,lkxxxdl;;codl,       'okoxk;,xkcx0xkx;                             ;oxkxkxc'                                 ':lcl:'     \n";
    cout << "        ''''             ,c:lxxxdddoc;,:odc'      ,x0dxx:;dkxkxkKOc'                              ',,,'                                    ;ccc;      \n";
    cout << "      'lOkxd:'           'loccxOOOkko:lool:'      ,OXXXKKKKKK00KKKO;                                                'looooc,              :dxxddc'    \n";
    cout << "     ;kNNX0OKx;           ,,'cXMMWX0Oko:,,'       'dNXNWNNWNK0KX0KO;                     ''                       ,lkKNWWN0kl,           ,oxxxloo,    \n";
    cout << "    ;xK0OOOO00o,             :OXXKkdkko;          'oNXXNkkNXOOXN0XO,           ',''::'  ,cc'                    'lOKKWMMMMX0X0o,         ,oxxxloo,    \n";
    cout << "   'lOOxxO0K0kxc'       ''',,,;:c:;;;,            'oXXXNk0WXO0NN0Kk,      ',;, ;c:cdo, ;lc'                   ,lONXKWWMMMMWX0XN0d;       'oxdolol'    \n";
    cout << "   :0NNXXX0NXOXO;       ,,;;;;;;;;;,,,             ;OKXNk0WXk0WXKOc'      ,coc:l:cddlc:lc'                  'lONNXKNMMMMMMMWNKXNN0o,      ;odool,     \n";
    cout << "    cOK00OOK00kc        ,;;;;;;;;;;;;,             'lOKNkdK0cdNK0x,       ';lolllddllcldo:'                 ,clldOOOOkkkkkkkk0xc::;'       ',;,'      \n";
    cout << "     ';;;;;,;;,         ,;;;;;;;;;;;;,              ',:l:'ld,:d:,'         ':oooodl,  ';::,                  ':lOXOxxd:';okkkXXkdc,                   \n";
    cout << "                        ,;;;;;;;;;;;;,                                  ';, ',;:odl, ':;'                   ;kXWMWNWMWXKXWMWNWMMWXx,    ' ', ,;' ';'  \n";
    cout << "                        ,;;;;;;;;;;;;,            ',:c:;'               ,lc,cl, :do:':o:,',:'               cKWMMNO0WW0dkNMKxKMWWNk;    ;::,,ll::c;   \n";
    cout << "                        ,;;;;;;;;;;;;,            ;odlcc'                ,clol,''cdolll;,;cc,               ,lkXMWkdKNd ;KXdo0MNOo:'    ';c:ll;;;;,   \n";
    cout << "                        ',,;;;;;;;;,,,          ',;:l:,:,'                 ',:lccldxo:,    ,,                 ,l0WWkdXd :0xlKWKd;        ,cclc::;,'   \n";
    cout << "                         ''                      ;:;clc,,,'                  '':occdo,  ';;'                    ,cl;,c; ':;,cl;          ';:coo;,,'   \n";
    cout << "                                                  ,:lo:;'                 ,:c;':c;cdo; ,ll;                                             ,,,;;lc' ,;'  \n";
    cout << "                               ,;;:cc;;c:;'       ;oollc'                 ,:olcl:cdol:;ll,                                              ,cc,:oc;:c,   \n";
    cout << "                              ,locoxxlldxol:'    ,;:l:;:,'                ',lollcddlloodo;                                               ;::oc,,;;'   \n";
    cout << "                              ',;ldxxdooolc:,'' ';c;clc,,,'                ';looodl,'';clc,                                              ;c:clc:;;'   \n";
    cout << "                                ,cllloxxolooc,'   ,:lo:,'               ';,  ',:ldl, ,:;''''                                              ;:col,'''   \n";
    cout << "     ',;;,                   ',,,;::;;:;,',''     ;loolc,               ,lc,:l, :do:':o:,';c'                         '                ';;;,,lc'';;'  \n";
    cout << ";;;;:loooc;;;;;;;,,,,,,,,,,,,::,''''' '',',,''''',;coc:c,''''''''       ';clol;''cdoloc,,;:c,                     ';,,;''c:' ';;'       ,cc;ll::cc,   \n";
    cout << "lllloddoollllllllllllllllllllc::::::;;clcclcclcccooloollllccccccc:::::c:::clloolclddolc::::cc;;;::;;;,;;;;;,,,,;;;;cllc;ldl:;cl:;,,,,'',,:ccoc;;;:,'''\n";
    cout << "lllllooccoollllllllllclllclllclllcllccllccllcllccllllolcllllccllllllccllllloollodooxoclllllclllllcccllllllcccllollcloddddoloooooolccccclooooodollllcc:\n";
    cout << "lodollolllllllllllcllllclllccllcclllclllccllclolccllcclllcllccllllcllllccloddoldoodxocclodollccccclllllccccclollcccllodddllolllooolccccccooooolcccllll\n";
    cout << "cloooooolcclllllllllcccllcclllccllcclllcclllcclllccllcclllccllccllllccclccodddddldxdooodolccccclllllccccccloolcccccldddddooolloolollccccccloollccccccl\n";
    cout << "lccllllllclcccclllcclllcccllccllllcclllcclllcclllcccllcclllcccclcccllcllcclloddddxdoodddocclllolllccccccloollccccc:coddodxolccclloolclcccc:cooolcccccc\n";
    cout << "lllcclllllccclcccclllccclllcclllcccllllcllllc:clllccllllc:cllcclolllccccccccodddxxlccclddoloolllcccc:clooolcccccc:cllooooolccc:clloollccccc:cllolllccc\n\n\n\n";

    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * S E A  F L O O R  Z O N E * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
    Sleep(2700);
}

void OverWorld::PrintCastle() {
        system("cls");
        cout << "                                                ..                                                ..                                                  \n";
        cout << "                                              .;o:.                                              'lc.                                                 \n";
        cout << "                                              ,ddc.                     ....                     ,odc.                                                \n";
        cout << "                                              ;ddo,                .';:llolc:;'.                .:ddc.                                                \n";
        cout << "                                              ;ddo:.              ,ldxxdooollllc;.              'odoc.                                                \n";
        cout << "                                              ;dddl,             .:loooooollcccc:,             .cxdoc.                                                \n";
        cout << "                                              ,oddol,.  ,clll:;'';lodddxxxddddool:,.,;cllc;.  .:odol:.                                                \n";
        cout << "                                              .looddl:,,oxxxxxxdooodxdddddddddddolloxxxxdol;';lddooc,.                                                \n";
        cout << "                                              .;odddddolododddddddoodddddddddollldddddddooc:ldddool:.                                                 \n";
        cout << "                   ,ol;..'clcc;...,;;.         .codddddlcccclooodddddoddddddolloddddooolcc:codooll:'.        .:oc,..,llc:,...;;;.                     \n";
        cout << "                   ;dxdoodddoolcccc::'          'cllooolc:cc::cloodddodddddddoodddoolc:cc::loollc:,.         .cxxdooddooolccc:::.                     \n";
        cout << "...                .:cccccccccc:::;;,.           .,:cccc::loc,',:clolcloddddocclllc:;;:llc:clc::;'.           ':ccccccccc::::;;'.                     \n";
        cout << "......              ,loddddoolllcc::.              .';;;:lddl;....',',:looolc;,;;,'..'colc;;;;,..              ;ooddddoolllc::;.                      \n";
        cout << "........            'cllllllc::::::;.                .':ldddo:'.......,:cc::;........,loolc;,..                ,clllllccc:::::,.                      \n";
        cout << "........            .;::cc:c:::::;;'.                .codddddol:;;;;:coddooolc::;;:;:ldooolc:'.                .;cc:::::::::;;'                       \n";
        cout << "........            .cxxkkxxxdoolc:,     .,,,;,''''';lddddoddddddddddddddddddddddddddddddooolc:;,,;,'''''..    .lxkkkxxxdollc:'                       \n";
        cout << ".......             .cxkOkxoodoolc:,   .;dxxkxoloollccloolldddoloddddolodddooloddddolodddllllldxxkkdloollc;.   .lxOOkdlodollc:'                       \n";
        cout << ".......             .ckOko'..;oolcc,   .dOOOOkooxxollc:ldocloodocoddodoclooodocoddodocloodocldkkkOOdodolllc,   .lkOkl. .:oolc:'                       \n";
        cout << "..........          .cxOx,   .colc:;'',;lddddolloolcc::lxxooddxxollldxxooddxxxollodxxooodxdlcldddddlcllccc:;''';okkd'   .lolc:'                       \n";
        cout << "............        .cxkx,    :olc:::cllcdkkxxllolllc:cxOOOOOOOOkdldOOOOOOOkkkxlok0OOkkOOOkdccdkOOkxlddoll:::clcokko.   .locc:'                       \n";
        cout << "..............      .cxkkc'..,ldlc:;;:c:lxO00Oddkdool:cdxxxkxxkkxdlokxxxxxxxxxxllxkxxxxxkkkdclxOOOOxoxxolc:;;:::oxkx:'..;ooc::'                       \n";
        cout << "...............   ...cxkOkkkxddolc:;;clcokOOOkddxdoooccoddoloodxxddolodddoolooolllddddoloooolokO00Okoddllc:::cc:lxkOkkxxdolc::,..   ......   .........\n";
        cout << "....................'cxkOkxxdoollc::;clclxO0OOdoxxdoollxkOkxxkOOkOOkxxkOkkkxxxxkkkkkkkkkxxxkxdkOO00kooollc:::clcokOOkxxdollc::,.......................\n";
        cout << "..............,lolc,'cxkkxxxdlcclc:::oddoloxOkdoxxxdoccloxkxooooxOkolooxOkdllooxOkolooxOkdloookOOO0koddlccclolccokOkxxxdlccl::,,clc:;.................\n";
        cout << "..............:k0kdc;cdxdxOkxoccccc:cxOxoc:ldxloxxdolc;:cokxccccdkxlcccokxl::ccokxl:ccokkl:cccdkkkxdlodolcoxxoc:lxxdkOkxoccccc:cxdol:'................\n";
        cout << "..............:k0OkxdxxxkOOkkkxxxxxxxkOkdlcloocclllcc;;cclllclxolllclddlllc:lddlllclddlllclddllddddlclllccoxkkxdxxxkOOkkkxxxxxxxxdol:'................\n";
        cout << "..............;dxxkxxxkxkkxdxkkkkkkxxxxxdccdOkooxdool::clllloxOkdoloxOkdooodxkkdoooxkkdooodkdoxOOOOxodxolcodxkxxxxxxxxxxkkkkkkxddool:'................\n";
        cout << "..............,coooolllloooooolloooolcllc:cdOkddxdoooc:codxxkOOOkkkOOOOOOOOOOOOOkOOOkkkOkkkkddkOOOOkdxxoc:clooolllloooooollooollloll:'................\n";
        cout << "..............;dOOOOkxxxkOOOOkxxkkkkxxxdoccdOOddkxddoc:cldxxkkkOkkkkkOOOOOOkkkOOOkkOkxkOOkkkddkOOkkkdxdlccoxkOOxdxkOOOOOkxxkkkkxxkxo:'................\n";
        cout << "..............;xOOOkl,,,lkOOOOOxc,,;oOOxo:cdOkdoxxxdo::clodxkxxkxxxxxxxkxkkxxxkxxxxxxxxkOkkOxdkOOOOkooolccoxkOxc,,;oOOOOOOd:,,;dOOxl;'................\n";
        cout << "..............;oOOOx'   'xOOkkOo.   ;kOkoccxOkdoxkxdoc;clodxkxxkkkkkxkkxkkkkkkkkkxkkxolxkOOkxdkOO00kooolccldkOo.   ;kOOkkOl.  .cOOxo:'................\n";
        cout << "..............:xOOOx;...;kOOkkOd'. .:OOxoccdxxooxxddoc;clodxkdoddoodoooodooddodddoodocldkkkOxodkkkkdoodolcoxkOd'. .:OOOkkOo....lOOkdc'................\n";
        cout << "..............:xOOOkxollxOOOOkkkdoloxOkxdcclolcclllcc;;:lodxkdddlccllllllllllllllcodocldkOOOxllddddlclllccoxkOkdlloxOOOOkkkdolokOkxdc'................\n";
        cout << ". ............:dxxxxxddddxxxxddddxxddxxdoccdkkooxdoll:;:clodxxkkolllllllcclllllcloxOxlcoxxxxdoxOOOOxodxolcodxxxdddddxxxxddddxxddxxdo:'................\n";
        cout << "..............,loolllcccllllllccclllllllc:cdOkodxdoooc,,,,,;:okkolllccllcc:::lc:coxOxc;;;;;::lxOOOOkdddlccllllllcccllllllccclllclllc;'................\n";
        cout << "..............,oxkkxdoodxxxkxdoodxxdooddl:cdOOddkddoo:':occo:;dkolllcldlc:::coo:coxOx:,lo:lo;:xOO00kddolccdxxkxdoodxxkkxdooxxxdooddl:'................\n";
        cout << ".........   ..;x00OOOOOOOOOOOOOOOOOOOOOkdccdOOdoxxxdl;,coxdoc;lkollllllllllclllcldxOd;;ldddo:;oOOO0kdddlclk00OOOOOOOOOOOOOOOOOOOOkxo:.................\n";
        cout << "      .....  .;x00OOkkOOOOOOOOkkkOkOOOkxoccxOkooxxdoc;',cccc,,clllllcclcc:::cll:coddc;';ccc:,,cdkO0kdxdlclk00OkkkOOOOOOOOkkkOkOOOkxo:.................\n";
        cout << "             .;x000OOOOOOOOOOOkkkOOOOOkxdccdkxooxdcccc:lkxxkl:cc::llcldocc::cdo:clcccccdkxkxc:clldkxoddolok0O0OOOOOOOOOOOkkkOOOOOkxd:..               \n";
        cout << "              ;x0OOOkkOOOOOOOOOOOOOOOOkxdcclolccc::c;,:d0KK0d:;;c:;ccldocc::cdo:,;cc;,lkKKKOo;,:c:clcllccok0OOOkkOOOOOOOOOOOOOOOOkxo:.                \n";
        cout << "              ,x0OOOkkOOOOOOOOkkkOkOOOkxdccdkxoodc;;'';:cllc:;;;;;:cclolccc:coo:::::,,:ccllc:;,::lddoddolok00OOkOOOOOOOOOkkkOkOOOkxo:.                \n";
        cout << "              ,oxxxxxdxxxxxxxxxxxxxxxxdol::lxdclol::;;cc'..,cc:cc:c::cccc:c:ccc:cllo::l:'..;c::oddxolooc:cdxxxxxxxxxdxxxxxxxxxxxxdol;.                \n";
        cout << ",,,,,;,,,,,;,,:cccc:cc:ccccc::c::cccc::c:;:ccc::::::cccc;;;;:::c:;:::;:;;:;;;::;:::cc:cc;:;;:c::cccc::::;:cccc::c:ccccc::cc:::cc::c::;,,;,,;;,;,,,,,,;\n";
        cout << ":::::::;:;:c:;::;;;:::;:::;:;:::;::;;;:::::::;:;:c::::;;;:::;::::::::;:;:::::::;;;:::;:::;;;:c:;::;:;:::;:::;;;:c::::;;;:::;;;::::::;:;:c:;::;;;:::;:c\n";
        cout << "::clc;:ccc::lc:;:cc::clc;:ccc::lc:;:cc::cl:;:cc::clc:;:cc::clc::clc;:ccc::llc:;:cc::clc;:ccc::lc:;:cc::cl:;:cc::clc:;:cc::clc::clc;;:cc::lc:;:cc::clc;\n";
        cout << "cclllcclllccllcclllcclllcclllccllcclllcclllcclllclllcclllcclllcclllcclllcclollclllcclllcclllccllcclllcclllcclllclllcclllcclllcclllcclllcclllclllcclllc\n";
        cout << "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n";
        cout << "llcccc::cccccclocc:ccc:cc::cclc::ccccccccccccc:cccccllccccccc:cccccccccccccccllccccccccccccllc::ccc::::ccll::cclccccccccccc:::cccclccccccccccccccccccc\n";
        cout << ":;,;:;,,:::::;;:;,:::cc;,'';:cc;;;,;:;,,;;::::;,',:c:c:::,,,,;::::;,,,;;:::;::,,;;,,;::;::;;;,;:::c:;,',;cc:;;;;::,',;;::::;,';cc::::;,,,;:::::;,,,;;:\n";
        cout << "',,,;,,',;;,,,.'',,;;;:;..',,;,,;,.',''',;;,,,;,',,,;;,;;,'',;::;,''''',,;,'',,,;;,',,;;,,'.',,;;,;:,.'',;,,;;'.,,''';;;,,;,'',,,;;,;;,',;;::;,''''',;\n";
        cout << "..............................................................''...........................................................................''.........\n\n\n\n";

        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * C A S T L E   Z O N E * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
        Sleep(2700);
}

void OverWorld::PrintShopKeep()
{
    cout << "                              .. ...',,,,,,,,,,,,,,,,,'.. .,,'.                      .,'..                     \n";
    cout << "                          .'cc;'',,,,,,,,,,,,,,,,,,,,,,,,''lxOko:.                  .dOOkx:                    \n";
    cout << "                        .ck0d;',,,,,,,,,,,,,,,,,,,,,,,,,,,'',oKXX0d;.               .d000k,      .             \n";
    cout << "                      ,d0XXx,',,,,,,,,,,,,,,,,,,,,,,,,,,,,,'.:0XXXXXOl.             .x00k: .,'',col;.          \n";
    cout << "                    ,dKXXXKc.',,,,,,,,,,,,,,,,,,,,,,,,,,,,,'.:0XXXXXXX0o.           .,::,.  'coxxxxx:.         \n";
    cout << "                  .l0XXXXX0:.,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'.lKXXXXXXXXX0l.     .........    .,::::;.          \n";
    cout << "                 .xXXXXXXXKc.',,,,,,,,,,,,,,,,,,,,,,,,,,,,';lkXXXXXXXXXXXXk,   .,;;,;,,,,,'.   ..'''.  .''.    \n";
    cout << "                 'oKXXXXXXXx,',,,,,,,,,,,,,,,,,,,,,,,,,,,';kKXXXXXXXXXXX0dc,.   ..........  .;loddo:..lkOOx,   \n";
    cout << "                .',oKXXXXXXKx;',,,,,,,,,,,,,,,,,,,,,,,,,;oOXNXXXXXXXXXKd;',,,.    .,;::c:,..':oddd;.'dxlcokx'  \n";
    cout << "               .,,';xXXXXXXXXOl,',,,,,,,,,,,,,,,,,,,',:oOXXXXXXXXXXXX0l,,,,,,,.   ;OkldKXKOo;.'cdc..od;,''lk:  \n";
    cout << "              .,,,''oKXXXXXXXXXOoc;,'',,,,,,,,,',,;cokKXXXXXXXXXXXXXKo'',,,,,,,.  .lx::kOOOKOo'.c, ,xocxd,:xc  \n";
    cout << "             .',,,,.lKXXXXXXXXXXXXKOxoollcccllodxO0XXXXXXXXXXXXXXXXXk;',,,,,,,,,.  .oo:clloOKk:... :kddOd,ck:  \n";
    cout << "             .,,,,,.lKXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXKl'',,,,,,,,,'.  ;O0KKKXXKkc... ,xOOOc,ok;  \n";
    cout << "             .,,,,,'oKXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX0c',,,,,,,,,,,.   .,:d0KKOd, .. .:xkl,ckd.  \n";
    cout << "             .,,,,',xXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXKl'',,,,,,,,,,.    .  .;c:'  ..  .;ccokk;   \n";
    cout << "             .,,,,'c0XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx,',,,,,,,,,,.   .,,'.   ......  'okkd,    \n";
    cout << "             .,,,';kXXXXXXXXXXXXXXK0OkxxddddxxkO0KXXXXXXXXXXXXXXXXXXKl'',,,,,,,,,.   .,;;,'',,;;;;,'. .'.      \n";
    cout << "              .'':kXXXXXXXXXXX0xocc:c::cccccc:::ccloxOKXXXXXXXXXXXXXX0l'',,,,,,,'.   .;;;;;;;;;;;;;,.  .....   \n";
    cout << "               'l0XXXXXXXXX0o;,:codxkkkkkkkkkkkkxdoc::cokKXXXXXXXXXXXX0l,',,,,,,.    .,'',;;;;;;;;;;,',;;;;'   \n";
    cout << "               :0XXXXXXXXXKc .ckkkkkkkkkkkkkkkkkkkkkkxoc;,lOKXXXXXXXXXXKxc,',,,.    ,::,.';;,'',',,,,;;,,..    \n";
    cout << "               .l0XXXXXXXXd. :xkxloxkkkkkkkkdcldkkkkkkkkdc'',lOXXXXXXXXXXKOoc;.    .',,'',;;'.,cc::,'',.       \n";
    cout << "                 ;kXXXXXXO, .dkx:..ckkkkkkkx;..ckkkkkkkkkkx:...oKXXXXXXXXXXXKo.   .,;;;;;;;;,'...,;,.',.       \n";
    cout << "                  .:kXXXXo. ;xkd' .:kkkkkkko' .ckkkkkkkkkkko;. ;0XXXXXXXXXXOc.   .',,;,,;;;;,.      ....       \n";
    cout << "                    .;d0O; .okkd' .ckkkkkkko. .lkkkkkkkkkkko;. ;0XXXXXXXXOc.     .. ... ...',. .,;,'   ..      \n";
    cout << "                       .'. 'dkkx:.;oooxdodxd,.;dkkkkkkkkkkko;. ,OXXXXKOd;.       ..    .....   .clc,. .,,.     \n";
    cout << "                           'dkkkxl,.  .. ..:odxkkkkkkkkkkkkl'. ,OKOdc,.    ..';:loc.  .,::;,'. .,c:.  ';;'     \n";
    cout << "                           .:oxdc.          .cddllxkkkkkkkx,   .,'.       .cdxxxxxd:  .;:::::,..;:.  .,;;,.    \n";
    cout << "                             ...              ..  ;xkkkkkx:            ..  ,dxxxxxxo,  '::::,..,;'  .,;;;;'    \n";
    cout << "                              .                  .lkkkkkd,     ...   .',,.  .,;:::cc;. ..''.   .....,,,,;;,.   \n";
    cout << "                               .    .;c:..     .cxkkkxo;.    .,,.   .,;'','........        ...'',,'.....,;,.   \n";
    cout << "                                 .':dkkkxdl::clxkxdl;.      ....   .,;;. .,;,'....'''',,'...',;;;,......';,.   \n";
    cout << "                    .,:cc:,.       .',;:::::::;,'..      ......   .,;;;'  .,'......,;;;'......,;;;,,,;;'..,.   \n";
    cout << "                   'dkkkkkkd,                         .;oxxkxxdc.  .,;;,.  ';,,,'',;;;;,,'',,,;;;;;;;;;'  .    \n";
    cout << "                  .lkkkkkkkko.   ..'ldocc:::'  .'''.  :xkkkkkkkko.  ';;;'. .,;;;;;;;;;;;;;;;;;;;;;;;;;;,.      \n";
    cout << "                  .ckkkkkkkd,  ....lkkkkkkkkc..,;;,.  ,dkkkkkkkkd.  .;;;,.  ';'';;;;;;;;;;;;;;;;;;;;;;;,.      \n";
    cout << "                   .okkkkkx;  ..  .,,,;;,,,,. .,;;;,.  :kkkkkkkx:  .,;;;,.  co,,llc::;;;,,;;;;;;;;;;;;;,.      \n";
    cout << "                    .;cc:,.  .. .codddxxdddlc,..,;;;'  .:oxkkxd:.  ';;;;,.  ckloOOOkxdl,.,;;;;;;;;;;;;;,.      \n";
    cout << "                            ....dXXXXXXXXXXXX0c.',,;,'.   ..'..    .',;;,.  cOOO00000Oo,cxxo:;;;;;;;;;;,.      \n";
    cout << "                              .cKXXXXXXXXXXXXX0o,''..'.       ....   .',,.  cO0000000OkxO00kl;;;;;;;;;'.       \n";
    cout << "                              .oXXXXXXXXXXXXXXXXOo:'...',.   .';;,'.   ...  ;k0000000000Oxol;',;;;;;,.         \n";
    cout << "                               .oKXXXXXXXXXXXXOo:,'....,;.     .'''..        ,ldkkOOO000Oxoc'.'''...           \n";
    cout << "                           ....  ,d0XXXXXXXX0l.   ....                          ..',,,,,,,,'.                  \n";
    cout << "                         .,;;;;'.  .,cdxO00k;  .',;;;;,,'..                                                    \n";
    cout << "                        .;;;;;;;;,'..   ....   ';;;;;;;;;;;,,.                                                 \n";
    cout << "                        .;;;;;;;;;;;;,.        ';;;;;;;;;;;;;,.                                                \n";
    cout << "                         .....''''....          ..',,,,,,,''..                                                 \n\n\n";

    cout << "                        HELLO!  Could I interest you in my wares?                    \n";
}


void OverWorld::PrintGameWin()
{
    cout << "                     _|_|_|_|_|  _|    _|    _|_|    _|      _|  _|    _|      _|      _|    _|_|    _|    _|      _|      \n";
    cout << "                         _|      _|    _|  _|    _|  _|_|    _|  _|  _|          _|  _|    _|    _|  _|    _|      _|      \n";
    cout << "                         _|      _|_|_|_|  _|_|_|_|  _|  _|  _|  _|_|              _|      _|    _|  _|    _|      _|      \n";
    cout << "                         _|      _|    _|  _|    _|  _|    _|_|  _|  _|            _|      _|    _|  _|    _|              \n";
    cout << "                         _|      _|    _|  _|    _|  _|      _|  _|    _|          _|        _|_|      _|_|        _|      \n\n\n";

    cout << "                                   _|_|_|    _|    _|  _|_|_|_|_|        _|_|    _|    _|  _|_|_|      \n";
    cout << "                                   _|    _|  _|    _|      _|          _|    _|  _|    _|  _|    _|    \n";
    cout << "                                   _|_|_|    _|    _|      _|          _|    _|  _|    _|  _|_|_|      \n";
    cout << "                                   _|    _|  _|    _|      _|          _|    _|  _|    _|  _|    _|    \n";
    cout << "                                   _|_|_|      _|_|        _|            _|_|      _|_|    _|    _|    \n\n\n";

    cout << "                                  _|_|_|    _|_|_|    _|_|_|  _|      _|    _|_|_|  _|_|_|_|    _|_|_|    _|_|_|      \n";
    cout << "                                  _|    _|  _|    _|    _|    _|_|    _|  _|        _|        _|        _|            \n";
    cout << "                                  _|_|_|    _|_|_|      _|    _|  _|  _|  _|        _|_|_|      _|_|      _|_|        \n";
    cout << "                                  _|        _|    _|    _|    _|    _|_|  _|        _|              _|        _|      \n";
    cout << "                                  _|        _|    _|  _|_|_|  _|      _|    _|_|_|  _|_|_|_|  _|_|_|    _|_|_|        \n\n\n";

    cout << "               _|_|_|    _|_|_|      _|_|_|  _|      _|        _|_|    _|      _|    _|_|    _|_|_|_|_|  _|    _|  _|_|_|_|  _|_|_|   \n";
    cout << "                 _|    _|              _|    _|_|    _|      _|    _|  _|_|    _|  _|    _|      _|      _|    _|  _|        _|    _| \n";
    cout << "                 _|      _|_|          _|    _|  _|  _|      _|_|_|_|  _|  _|  _|  _|    _|      _|      _|_|_|_|  _|_|_|    _|_|_|   \n";
    cout << "                 _|          _|        _|    _|    _|_|      _|    _|  _|    _|_|  _|    _|      _|      _|    _|  _|        _|    _| \n";
    cout << "               _|_|_|  _|_|_|        _|_|_|  _|      _|      _|    _|  _|      _|    _|_|        _|      _|    _|  _|_|_|_|  _|    _| \n\n\n";

    cout << "                                            _|_|_|    _|_|      _|_|_|  _|_|_|_|_|  _|        _|_|_|_|      _|  \n";
    cout << "                                          _|        _|    _|  _|            _|      _|        _|            _|  \n";
    cout << "                                          _|        _|_|_|_|    _|_|        _|      _|        _|_|_|        _|  \n";
    cout << "                                          _|        _|    _|        _|      _|      _|        _|                \n";
    cout << "                                            _|_|_|  _|    _|  _|_|_|        _|      _|_|_|_|  _|_|_|_|      _|  \n\n";

    cout << "                                                                    ........                         \n";                                                                        
    cout << "                                                                .',ck000000Ol,,'.                    \n";                                                                        
    cout << "                                                           .:OKxccoxKXOxk0KXkolcoKXx,                \n";                                                                      
    cout << "                                                           .dNXOox0X0dlcclokKKkoxXWXo.               \n";                                                                        
    cout << "                                                          .;lkKXXNNXkccccccoKNNNNXKkc;.              \n";                                                                        
    cout << "                                                          'cclokNWWN0xlccldOXWWWXkolc:.              \n";                                                                       
    cout << "                                                          'ccclxXWWWWN0kOOKNWWWWKdlcc:.              \n";                                                                        
    cout << "                                                          ':lxOKNX0xd0KKKK0xdOKNNKOdc:.              \n";                                                                        
    cout << "                                                           .oKKK0Ox;,dOOOOk:,oO000K0l.               \n";                                                                        
    cout << "                                                           .oxc',okxdxdoddxxdkk:''ckl.               \n";                                                                        
    cout << "                                                          ;dkkxl,:dxkxc;:cdkkxd,,lxkkd;              \n";                                                                        
    cout << "                                                          .ckOOOx::ccoddoddddlcc;:xOOOk:.            \n";                                                                        
    cout << "                                                          .;:coolccclddddddolccclooc:;.              \n";                                                                        
    cout << "                                                             .;cccldkkOOOOOkxdcccc,.                 \n";                                                                        
    cout << "                                                              .'codxOOkxxxxxkOOxddc'                 \n";                                                                        
    cout << "                                                              .cKNNN0xoooookXNNNXl.                  \n";                                                                        
    cout << "                                                            ...ckKNWNNNXXXXNWWWXOl'..                \n";                                                                        
    cout << "                                                           ..,:cccd0XNWWMMWWWWXKklccc;..             \n";                                                                        
    cout << "                                                          .,:ccccccldKWMMMMWWXxllcccc::;.            \n";                                                                        
    cout << "                                                         ..,;:::::::cxO00000Okl;;::::::;.            \n";
    
}