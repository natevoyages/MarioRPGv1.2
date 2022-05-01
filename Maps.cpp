#include "Maps.h"
#include "InputConfig.h"
#include "InGameMenu.h"

Maps::Maps()
{
    newMap = false;
    menuToggled = false;
    xCoordinate = width / 2;
    yCoordinate = height - 1;
}


void Maps::PrintMap(char charCharacter)
{
    MapSetup(charCharacter);
    while (!newMap)
    {
        MapLogic();
        mapsInput.UserInput(menuToggled);
        mapsInput.GamePlayInputLogic(xCoordinate,yCoordinate, width, height);
        while (menuToggled)
        {
            inGame.PrintInGameMenu(menuToggled);
        }
    }
}

void Maps::MapLogic()
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

void Maps::MapSetup(char charCharacter)
{
    newMap = false;
    xCoordinate = width / 2;
    yCoordinate = height - 1;
    userCharacter = charCharacter;
}