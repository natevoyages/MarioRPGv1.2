#include "OverWorld.h"
#include "InputConfig.h"
#include "InGameMenu.h"


OverWorld::OverWorld()
{
    exitMap = false;
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


void OverWorld::PrintOverWorld(char charCharacter,bool& play)
{
    while (notGameOver)
    {
        HomeSetup(charCharacter);
        while (!exitMap)
        {
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.HomeInputLogic(xCoordinate, yCoordinate, width, height, bottomExitXCoordinateOne, bottomExitXCoordinateTwo, bottomExitYCoordinate);
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
        while (!exitMap)
        {
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.HomeInputLogic(xCoordinate, yCoordinate, width, height, bottomExitXCoordinateOne, bottomExitXCoordinateTwo, bottomExitYCoordinate);
            characterTracker();
            CollisonLogic();
            inGame.SetUpMenu();
            while (menuToggled)
            {
                inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
            }
        }
        SetUpMap(map);

        play = notGameOver;
    }
}

void OverWorld::SetUpMap(int map)
{
    if (map == 0) 
    {
        HomeSetup();
        while (!exitMap)
        {
            OverWorldPrintLogic();
            mapsInput.UserInput(menuToggled);
            mapsInput.HomeInputLogic(xCoordinate, yCoordinate, width, height, bottomExitXCoordinateOne, bottomExitXCoordinateTwo, bottomExitYCoordinate);
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
        while (!exitMap)
            {
                OverWorldPrintLogic();
                mapsInput.UserInput(menuToggled);
                mapsInput.HomeInputLogic(xCoordinate, yCoordinate, width, height, bottomExitXCoordinateOne, bottomExitXCoordinateTwo, bottomExitYCoordinate);
                characterTracker();
                CollisonLogic();
                inGame.SetUpMenu();
                while (menuToggled)
                {
                    inGame.PrintInGameMenu(menuToggled, notGameOver, exitMap);
                }
        }
        SetUpMap(map);
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
        cout << "#";
    }

    cout << "\n";

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {


            if (j == 0 || j == (width - 1))
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
        if (i == width / 2 || i == (width / 2) + 1) //exit for map
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
    else if ((xCoordinate == bottomExitXCoordinateOne && yCoordinate == bottomExitYCoordinate) || (xCoordinate == bottomExitXCoordinateTwo && yCoordinate == bottomExitYCoordinate))
    {
        exitMap = true;
        exitMapSouth = true;

    }
    else if ((xCoordinate == topExitXCoordinateOne && yCoordinate == topExitYCoordinate) || (xCoordinate == topExitXCoordinateTwo && yCoordinate == topExitYCoordinate))
    {
        exitMap = true;
        exitMapNorth = true;
    }

    else if ((xCoordinate == leftExitXCoordinate && yCoordinate == leftExitYCoordinateOne) || (xCoordinate == leftExitXCoordinate && yCoordinate == leftExitYCoordinateTwo))
    {
        exitMap = true;
        exitMapEast = true;
    }

    else if ((xCoordinate == rightExitXCoordinate && yCoordinate == rightExitYCoordinateOne) || (xCoordinate == rightExitXCoordinate && yCoordinate == rightExitYCoordinateTwo))
    {
        exitMap = true;
        exitMapWest = true;
    }
}

void OverWorld::HomeSetup(char charCharacter)  //used for newGame
{
    exitMap = false;
    xCoordinate = width / 2;
    yCoordinate = height - 15;
    saveXCoordinate = width / 6;  //Makes save icon invisible     saveXCoordinate = 0;
    saveYCoordinate = height - 7; //                              saveYCoordinate = -1;
    bottomExitXCoordinateOne = width / 2; // fix me
    bottomExitXCoordinateTwo = (width / 2) + 1; // fix me
    bottomExitYCoordinate = height;
    userCharacter = charCharacter;
}

void OverWorld::HomeSetup()
{
    exitMap = false;
    xCoordinate = width / 2;
    yCoordinate = height - 15;
    saveXCoordinate = width / 6;      
    saveYCoordinate = height - 7;                       
    bottomExitXCoordinateOne = width / 2; 
    bottomExitXCoordinateTwo = (width / 2) + 1; 
    bottomExitYCoordinate = height;
}

void OverWorld::DesertOneSetup()
{
    exitMap = false;
    xCoordinate = width / 2;
    yCoordinate = 0;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    bottomExitXCoordinateOne = width / 2;
    bottomExitXCoordinateTwo = (width / 2) + 1;
    bottomExitYCoordinate = height;
    topExitXCoordinateOne = width / 2;
    topExitXCoordinateTwo = (width / 2) + 1;
    topExitYCoordinate = -1;
}
