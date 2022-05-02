#include "OverWorld.h"



OverWorld::OverWorld()
{
    newMap = false;
    exitMap = false;
    exitMapSouth = false;
    exitMapNorth = false;
    exitMapEast = false;
    exitMapWest = false;
    menuToggled = false;
    notGameOver = true;
    xCoordinate = width / 2;
    yCoordinate = height - 1;
    saveXCoordinate =  0;
    saveYCoordinate = -1;
    map = 0;
}

void OverWorld::SaveGame()
{
    string saving[] = { "Saving.", "Saving..", "Saving...","Saving.", "Saving..", "Saving...",
        "Saving.", "Saving..", "Saving...", };
    ofstream save;
    save.open("save.dat");
    save << map << " "; // << userCharacter << " " << level << " " << power << " " ;
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


void OverWorld::PrintOverWorld(char charCharacter,bool& play)
{
    while (notGameOver)
    {
        HomeSetup(charCharacter);
        while (!exitMap)
        {
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.HomeInputLogic(xCoordinate, yCoordinate, width, height, bottomExitXCoordinateOne, bottomExitXCoordinateTwo);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
            }
        }
        map = 1;
        if (newMap)
        {
            SetUpMap(map);
        }

        play = notGameOver;
    }
}

void OverWorld::SetUpMap(int loadMap)
{
    map = loadMap;
    if (map == 0) 
    {
        HomeSetup();
        while (!exitMap)
        {
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.HomeInputLogic(xCoordinate, yCoordinate, width, height, bottomExitXCoordinateOne, bottomExitXCoordinateTwo);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
            }
        }
        map = 1;
        SetUpMap(map);
    }
    else if (map == 1)
    {
        DesertOneSetup();
        PrintDesert();
        while (!exitMap)
            {
                OverWorldPrintLogic();
                mapsInput.UserInput(menuToggled);
                mapsInput.NSExitInputLogic(xCoordinate, yCoordinate, width, height, bottomExitXCoordinateOne, bottomExitXCoordinateTwo, topExitXCoordinateOne, topExitXCoordinateTwo);
                CollisonLogic();
                inGame.SetUpMenu();
                while (menuToggled)
                {
                    inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
                }
            }

         if (exitMapSouth)
            {
              map = 2;
            }
         else if (exitMapNorth)
            {
                map = 0;
            }
         if (newMap)
         {
            SetUpMap(map);
         }
    }
    else if (map == 2)
    {

    }
    else if (map == 3)
    {

    }
    else if (map == 4)
    {

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
}

void OverWorld::OverWorldPrintLogic()
{
    system("cls");
    for (int i = 0; i < width; i++)
    {
        if (i == topExitXCoordinateOne || i == topExitXCoordinateTwo) //exit for map
        {
            cout << "_";
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
            if ( (i == 0 && j == leftExitYCoordinateOne) || (i == 0 && j == leftExitYCoordinateTwo) )
            {
                cout << "|";
            }
            else if (j == 0 || j == (width - 1) )
            {
                cout << "#";
            }

            else if (i == saveYCoordinate && j == saveXCoordinate)
            {
                cout << "S";
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
        cout << "\n";
    }

    for (int i = 0; i < width; i++) 
    {
        if (i == bottomExitXCoordinateOne || i == bottomExitXCoordinateTwo) //exit for map
        {
            cout << "_";
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
    else if ((xCoordinate == bottomExitXCoordinateOne && yCoordinate == height) || (xCoordinate == bottomExitXCoordinateTwo && yCoordinate == height))
    {
        newMap = true;
        exitMap = true;
        exitMapSouth = true;

    }
    else if ((xCoordinate == topExitXCoordinateOne && yCoordinate == 0) || (xCoordinate == topExitXCoordinateTwo && yCoordinate == 0))
    {
        newMap = true;
        exitMap = true;
        exitMapNorth = true;
    }

    else if ((xCoordinate == 0 && yCoordinate == leftExitYCoordinateOne) || (xCoordinate == 0 && yCoordinate == leftExitYCoordinateTwo))
    {
        newMap = true;
        exitMap = true;
        exitMapEast = true;
    }

    else if ((xCoordinate == width - 1 && yCoordinate == rightExitYCoordinateOne) || (xCoordinate == width - 1 && yCoordinate == rightExitYCoordinateTwo))
    {
        newMap = true;
        exitMap = true;
        exitMapWest = true;
    }
}

void OverWorld::HomeSetup(char charCharacter)  //used for newGame
{
    newMap = false;
    exitMap = false;
    exitMapSouth = false;
    exitMapNorth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width / 2;
    yCoordinate = height - 15;
    saveXCoordinate = width / 6;  //Makes save icon invisible     saveXCoordinate = 0;
    saveYCoordinate = height - 7; //                              saveYCoordinate = -1;
    bottomExitXCoordinateOne = width / 2; // fix me
    bottomExitXCoordinateTwo = (width / 2) + 1; // fix me
    userCharacter = charCharacter;
}

void OverWorld::HomeSetup()
{
    newMap = false;
    exitMap = false;
    exitMapSouth = false;
    exitMapNorth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width / 2;
    yCoordinate = height - 15;
    saveXCoordinate = width / 6;      
    saveYCoordinate = height - 7;                       
    bottomExitXCoordinateOne = width / 2; 
    bottomExitXCoordinateTwo = (width / 2) + 1; 
}

void OverWorld::PrintDesert()
{
    system("cls");
    {
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
}

void OverWorld::DesertOneSetup()
{
    newMap = false;
    exitMap = false;
    exitMapSouth = false;
    exitMapNorth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width / 2;
    yCoordinate = 0;
    saveXCoordinate = 500;
    saveYCoordinate = 500;
    bottomExitXCoordinateOne = width / 2;
    bottomExitXCoordinateTwo = (width / 2) + 1;
    topExitXCoordinateOne = width / 2;
    topExitXCoordinateTwo = (width / 2) + 1;
}
