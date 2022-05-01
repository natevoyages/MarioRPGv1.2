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
    saveXCoordinate =  0;
    saveYCoordinate = -1;
}

void OverWorld::SaveGame()
{
    ofstream save;
    save.open("save.txt");
    save << saveState[0];
}


void OverWorld::PrintOverWorld(char charCharacter,bool& play)
{
    OverWorldSetup(charCharacter);
    
    while (!newMap)
    {
        OverWorldPrintLogic();
        mapsInput.UserInput(menuToggled);
        mapsInput.GamePlayInputLogic(xCoordinate,yCoordinate, width, height);
        CollisonLogic();
        inGame.SetUpMenu();
        while (menuToggled)
        {
            inGame.PrintInGameMenu(menuToggled, notGameOver, newMap);
        }
    }
    play = notGameOver;
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
}

void OverWorld::OverWorldSetup(char charCharacter)
{
    newMap = false;
    xCoordinate = width / 2;
    yCoordinate = height - 1;
    saveXCoordinate = width / 6;  //Makes save icon invisible     saveXCoordinate = 0;
    saveYCoordinate = height - 7; //                              saveYCoordinate = -1;
    userCharacter = charCharacter;
}