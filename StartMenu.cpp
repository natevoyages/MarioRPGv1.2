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
    continueGame = false;
    yMenu = 0;
    numOptions = 2;
    menuOptions[0] = "New Game ";   
    menuOptions[1] = "Quit     ";   
    menuOptions[2] = "Continue ";    

}

void StartMenu::TitlePrint() {
    cout << "\n\n\n\n\n";
    cout << "            _/      _/                      _/         \n";
    cout << "           _/_/  _/_/    _/_/_/  _/  _/_/        _/_/  \n";
    cout << "          _/  _/  _/  _/    _/  _/_/      _/  _/    _/\n";
    cout << "         _/      _/  _/    _/  _/        _/  _/    _/ \n";
    cout << "        _/      _/    _/_/_/  _/        _/    _/_/    \n\n";

    cout << "              _/_/_/    _/_/_/      _/_/_/ \n";
    cout << "             _/    _/  _/    _/  _/        \n";
    cout << "           _/_/_/    _/_/_/    _/  _/_/   \n";
    cout << "          _/    _/  _/        _/    _/    \n";
    cout << "         _/    _/  _/          _/_/_/     \n\n";

    cout << "\n         Press 'Space' to Start";
}

void StartMenu::PrintStartMenu()
{
    cout << "\n\n\n\n\n";
    cout << "            _/      _/                      _/         \n";
    cout << "           _/_/  _/_/    _/_/_/  _/  _/_/        _/_/  \n";
    cout << "          _/  _/  _/  _/    _/  _/_/      _/  _/    _/\n";
    cout << "         _/      _/  _/    _/  _/        _/  _/    _/ \n";
    cout << "        _/      _/    _/_/_/  _/        _/    _/_/    \n\n";

    cout << "              _/_/_/    _/_/_/      _/_/_/ \n";
    cout << "             _/    _/  _/    _/  _/        \n";
    cout << "           _/_/_/    _/_/_/    _/  _/_/   \n";
    cout << "          _/    _/  _/        _/    _/    \n";
    cout << "         _/    _/  _/          _/_/_/     \n\n";

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
    cout << "\n\n        'w' = UP     's' = DOWN       \n";
}


void StartMenu::TitleMenu(bool& play, bool& startNewGame)
{
    while (titleMenu)
    {
        Sleep(150);
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

void StartMenu::TitleMenu(bool& play, bool& startNewGame, bool& resumeGame)
{
    while (titleMenu)
    {
        Sleep(150);
        system("cls");
        PrintStartMenu();
        input.UserInput();
        input.StartMenuInputLogic(yMenu, numOptions, select, titleMenu);
        if (yMenu == 0 && select)
        {
            resumeGame = true;
        }
        else if (yMenu == 1 && select)
        {
            startNewGame = true;
        }
        else if (yMenu == 2 && select)
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
            Sleep(150);
            system("cls");
            TitlePrint();
            input.PressEnterToContinue(titleScreen);
        }
    }
}

void StartMenu::SetResumeStartMenu()
{
    numOptions = 3;
    menuOptions[0] = "Continue ";
    menuOptions[1] = "New Game ";
    menuOptions[2] = "Quit     ";
}