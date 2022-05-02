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
    }

    else if (map == 1)        // start of Desert maps
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
        if (exitMapNorth)
        {
            map = 5;
        }
        else if (exitMapEast)
        {
            map = 2;
        }
    }

    else if (map == 4)             // shop
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
        if (exitMapWest)
        {
            map = 2;
        }
    }

    else if (map == 5)        // start of Sea Floor maps
    {
        SeaFloorOneSetup();
        PrintSeaFloor();
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
        if (exitMapWest)
        {
            map = 6;
        }
        else if (exitMapSouth)
        {
            map = 3;
        }
    }

    else if (map == 6)
    {
        SeaFloorTwoSetup();
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
    }

 

    else if (map == 7)
    {
       SeaFloorThreeSetup();
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
           map = 9;
       }
       else if(exitMapEast)
       {
           map = 6;
       }
    }

    else if (map == 8)
    {
        ShopTwoSetup();
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
            map = 6;
        }
    }

    else if (map == 9)
    {
       CastleOneSetup();
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
            map = 10;
        }
        else if (exitMapSouth)
        {
            map = 7;
        }
    }
    
    else if (map == 10)
    {
    CastleTwoSetup();
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


        if (exitMapNorth)
        {
            map = 11;
        }
        else if (exitMapSouth)
        {
            map = 9;
        }
    }
    }
    else if (map == 11)
    {
        CastleThreeSetup();
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
            map = 12;
        }
        else if (exitMapSouth)
        {
            map = 10;
        }
    }
    else if (map == 12)
    {
    system("cls");
    cout << "Sorry! The Princess is in another Castle...\n";
    Sleep(8000);

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
 // Map setups
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
//  map 0
void OverWorld::HomeSetup()
{
    exitMap = false;
    southOpen = true; // to map 1
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
//  map 1
void OverWorld::DesertOneSetup()
{
    exitMap = false;
    southOpen = true;// to map 2
    northOpen = true;// back to map 1
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
//  map 2
void OverWorld::DesertTwoSetup()
{
    exitMap = false;
    southOpen = false;
    northOpen = true; // back to map 2
    westOpen = true;  //to map 3
    eastOpen = true;  // to shop map 4
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
//  map 3
void OverWorld::DesertThreeSetup() 
{
    exitMap = false;
    southOpen = false;
    northOpen = true; // to Sea Floor map 5
    westOpen = false;
    eastOpen = true;  // back to map 2
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width - 2;
    yCoordinate = height / 2;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
}
//  map 4
void OverWorld::ShopOneSetup()
{
    exitMap = false;
    southOpen = false;
    northOpen = false;
    westOpen = true; // back to map 2
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = 1;
    yCoordinate = height / 2;
    saveXCoordinate = 8;
    saveYCoordinate = 8;
    shopKeepXCoordinate = width / 2;
    shopKeepYCoordinate = height / 2;
}
//  map 5
void OverWorld::SeaFloorOneSetup()
{
    exitMap = false;
    southOpen = true;  //back to map 3
    northOpen = false;
    westOpen = true;   // to map 6
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width / 2;
    yCoordinate = height;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
}
//  map 6
void OverWorld::SeaFloorTwoSetup()
{
    exitMap = false;
    southOpen = true; // to shop map 8
    northOpen = false;
    westOpen = true; // to map 7
    eastOpen = true; // back to map 5
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width - 2;
    yCoordinate = height / 2;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
}

// map 7
void OverWorld::SeaFloorThreeSetup()
{
    exitMap = false;
    southOpen = false;
    northOpen = true; // to Castle map 9
    westOpen = false;
    eastOpen = true; // back to map 6
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = width - 2;
    yCoordinate = height / 2;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
}
// map 8
void OverWorld::ShopTwoSetup()
{
    exitMap = false;
    southOpen = false;
    northOpen = true;  // back to map 6
    westOpen = false;
    eastOpen = false;
    exitMapNorth = false;
    exitMapSouth = false;
    exitMapEast = false;
    exitMapWest = false;
    xCoordinate = 1;
    yCoordinate = height / 2;
    saveXCoordinate = 8;
    saveYCoordinate = 8;
    shopKeepXCoordinate = width / 2;
    shopKeepYCoordinate = height / 2;
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
    xCoordinate = width / 2;
    yCoordinate = 0;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
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
    xCoordinate = width / 2;
    yCoordinate = 0;
    saveXCoordinate = 10;
    saveYCoordinate = 10;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
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
    xCoordinate = width / 2;
    yCoordinate = 0;
    saveXCoordinate = 0;
    saveYCoordinate = -1;
    shopKeepXCoordinate = 0;
    shopKeepYCoordinate = -1;
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
    cout << "lllcclllllccclcccclllccclllcclllcccllllcllllc:clllccllllc:cllcclolllccccccccodddxxlccclddoloolllcccc:clooolcccccc:cllooooolccc:clloollccccc:cllolllccc\n";
    Sleep(2700);
}
