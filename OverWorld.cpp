#include "OverWorld.h"
#include "InputConfig.h"
#include "InGameMenu.h"

OverWorld::OverWorld()
{
    newMap = false;
    menuToggled = false;
    notGameOver = true;
    xCoordinate = width / 2;
    yCoordinate = height - 1;
}


void OverWorld::PrintOverWorld(char charCharacter,bool& play)
{
    OverWorldSetup(charCharacter);
    
    while (!newMap)
    {
        OverWorldLogic();
        mapsInput.UserInput(menuToggled);
        mapsInput.GamePlayInputLogic(xCoordinate,yCoordinate, width, height);
        inGame.SetUpMenu();
        while (menuToggled)
        {
            inGame.PrintInGameMenu(menuToggled, notGameOver, newMap);
            
        }
    }
    play = notGameOver;
}

void OverWorld::OverWorldLogic()
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

void OverWorld::OverWorldSetup(char charCharacter)
{
    newMap = false;
    xCoordinate = width / 2;
    yCoordinate = height - 1;
    userCharacter = charCharacter;
}