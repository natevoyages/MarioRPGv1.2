#include "Maps.h"
#include "InputConfig.h"

Maps::Maps()
{
    newMap = false;
    menuToggled = false;
    xCoordinate = width / 2;
    yCoordinate = height - 1;
}


void Maps::PrintMap()
{
    MapSetup();
    while (!newMap)
    {
        MapLogic();
        mapsInput.UserInput();
        mapsInput.GamePlayInputLogic(xCoordinate,yCoordinate, width, height);
        /*while (menuToggled)
        {
        
        }*/
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

void Maps::MapSetup()
{
    newMap = false;
    xCoordinate = width / 2;
    yCoordinate = height - 1;
    userCharacter = 'M';
}