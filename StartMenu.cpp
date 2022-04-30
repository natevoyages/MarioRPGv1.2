#include "StartMenu.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>

using namespace std;

StartMenu::StartMenu()
{
    titleScreen = true;
    titleMenu = true;
    select = false;
    startNewGame = false;
    yMenu = 0;
    numOptions = 2;
    menuOptions[0] = "New Game ";   
    menuOptions[1] = "Quit     ";   
    menuOptions[2] = "Resume   ";    

    int numOptions = 2;
}

void StartMenu::TitlePrint() {

    cout << "    _/      _/                      _/                _/_/_/    _/_/_/      _/_/_/ \n";
    cout << "   _/_/  _/_/    _/_/_/  _/  _/_/        _/_/        _/    _/  _/    _/  _/        \n";
    cout << "  _/  _/  _/  _/    _/  _/_/      _/  _/    _/      _/_/_/    _/_/_/    _/  _/_/   \n";
    cout << " _/      _/  _/    _/  _/        _/  _/    _/      _/    _/  _/        _/    _/    \n";
    cout << "_/      _/    _/_/_/  _/        _/    _/_/        _/    _/  _/          _/_/_/     \n";

    cout << "\n         Press 'Space' to Start";
}

void StartMenu::PrintStartMenu()
{
    cout << "    _/      _/                      _/                _/_/_/    _/_/_/      _/_/_/ \n";
    cout << "   _/_/  _/_/    _/_/_/  _/  _/_/        _/_/        _/    _/  _/    _/  _/        \n";
    cout << "  _/  _/  _/  _/    _/  _/_/      _/  _/    _/      _/_/_/    _/_/_/    _/  _/_/   \n";
    cout << " _/      _/  _/    _/  _/        _/  _/    _/      _/    _/  _/        _/    _/    \n";
    cout << "_/      _/    _/_/_/  _/        _/    _/_/        _/    _/  _/          _/_/_/     \n\n";

    for (int i = 0; i < numOptions; i++) {
        cout << "         " << menuOptions[i];
        if (yMenu == i)
        {
            cout << "[*]\n";
        }
        else
        {
            cout << "[ ]\n";
        }

    }
    cout << "\n         Press 'Space' to Select";
}


void StartMenu::TitleMenu(bool& play, bool& startNewGame, bool& resumeGame)
{
    while (titleMenu)
    {
        system("cls"); 
        PrintStartMenu();
        input.UserInput();
        input.StartMenuInputLogic(yMenu, numOptions, select,titleMenu);
        if (yMenu == 0 && select)
        {
            startNewGame = true;
        }
        else if (yMenu == 1 && select) 
        {
            play = false;
        }

    }
}


void StartMenu::TitleScreen()
{
    while (titleScreen)
    {
        {
            system("cls");
            TitlePrint();
            input.PressEnter2Continue(titleScreen);
        }
    }
}