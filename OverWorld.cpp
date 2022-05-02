#include "OverWorld.h"
#include "InputConfig.h"
#include "InGameMenu.h"


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
    map = 0;
}

void OverWorld::Shop()
{
    system("cls");
    cout << "shop activated";
}

void OverWorld::SaveGame()
{
    string saving[] = { "Saving.", "Saving..", "Saving...","Saving.", "Saving..", "Saving...",
        "Saving.", "Saving..", "Saving...", };
    ofstream save;
    save.open("save.dat");
    save << map;
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
    if (!(xCoordinate == saveXCoordinate && yCoordinate == saveYCoordinate))
    {
        prevXCoordinate = xCoordinate;
        prevYCoordinate = yCoordinate;
    }
}


void OverWorld::PrintOverWorld(char charCharacter,bool& play , bool &notGAMEOVER)
{
        if (!exitMap)
        {
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
            }
        }
        else {
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
        else  if (!notGameOver)
        {
            notGAMEOVER = false;
            play = false;
        }
}


void OverWorld::SetUpMap()
{
    ifstream load;
    load.open("save.dat");
    if (!(load.fail())) {
        load >> map;
        load.close();
    }

    if (map == 0) 
    {
        HomeSetup();
        while (!exitMap)
        {
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
            }
        }
        map = 1;
        SetUpMap();
    }
    else if (map == 1)
    {
        PrintDesert();
        DesertOneSetup();
        while (!exitMap)
            {
                OverWorldPrintLogic();
                mapsInput.UserInput(menuToggled);
                mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
                characterTracker();
                CollisonLogic();
                inGame.SetUpMenu();
                while (menuToggled)
                {
                    inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
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

    }
    else if (map == 2)
    {
        DesertTwoSetup();
        while (!exitMap)
        {
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
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
    }
    else if (map == 3)
    {
        DesertThreeSetup();
        while (!exitMap)
        {
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
            }
        }

    }
    else if (map == 4)
    {
        ShopOneSetup();
        while (!exitMap)
        {
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.OverWorldInputLogic(xCoordinate, yCoordinate, width, height, northOpen, southOpen, eastOpen, westOpen);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
            }
        }
    }
    else if (map == 5)
    {

    }
    else if (map == 6)
    {
    }

    else if (map == 7)
    {

    }
    else if (map == 8)
    {

    }
    else if (map == 9)
    {

    }
    else if (map == 10)
    {

    }
    else if (map == 11)
    {

    }
    else if (map == 12)
    {

    }
    else if (map == 13)
    {

    }
    else if (map == 14) 
    {
        notGameOver = false;
    }
}

void OverWorld::OverWorldPrintLogic()
{
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
}

void OverWorld::CollisonLogic()
{
    if(xCoordinate == saveXCoordinate && yCoordinate == saveYCoordinate)
    {
        SaveGame();

    }

    if (xCoordinate == shopKeepXCoordinate && yCoordinate == shopKeepYCoordinate)
    {
        Shop();
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

void OverWorld::NewGameHomeSetup(char charCharacter)  //used for newGame
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
    yCoordinate = height - 15;
    saveXCoordinate = width / 6;  //Makes save icon invisible     saveXCoordinate = 0;
    saveYCoordinate = height - 7; //                              saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
    userCharacter = charCharacter;
}

void OverWorld::HomeSetup()
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
    yCoordinate = height - 1;
    saveXCoordinate = width / 6;      
    saveYCoordinate = height - 7; 
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
}

void OverWorld::DesertOneSetup()
{
    exitMap = false;
    southOpen = true;
    northOpen = true;
    westOpen = false;
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width / 2;
    yCoordinate = 0;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
}

void OverWorld::DesertTwoSetup()
{
    exitMap = false;
    southOpen = false;
    northOpen = true;
    westOpen = true;
    eastOpen = true;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width / 2;
    yCoordinate = 0;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
}

void OverWorld::DesertThreeSetup() 
{
    exitMap = false;
    southOpen = false;
    northOpen = true;
    westOpen = false;
    eastOpen = true;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width / 2;
    yCoordinate = 0;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
}

void OverWorld::ShopOneSetup()
{
    exitMap = false;
    southOpen = false;
    northOpen = false;
    westOpen = true;
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = 1;
    yCoordinate = height / 2;
    saveXCoordinate = width - 3;
    saveYCoordinate = 3;
    shopKeepXCoordinate = width / 2;
    shopKeepYCoordinate = height / 2;
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
