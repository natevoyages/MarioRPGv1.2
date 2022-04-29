#include "InputConfig.h"
#include <conio.h>
#include <windows.h>

using namespace std;

void InputConfig::UserInput()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            userInput = LEFT;
            break;

        case 'A':
            userInput = RUN_LEFT;
            break;

        case 'd':
            userInput = RIGHT;
            break;

        case 'D':
            userInput = RUN_RIGHT;
            break;

        case 'w':
            userInput = UP;
            break;

        case 'W':
            userInput = RUN_UP;
            break;
        case 's':
            userInput = DOWN;
            break;

        case 'S':
            userInput = RUN_DOWN;
            break;

        case ' ':
            userInput = ENTER;
            break;

        }
    }
    else
    {
        userInput = STOP;
    }
}

void InputConfig::TitleScreenInput(bool& titleScreen)
{

    if (_kbhit())
    {
        switch (_getch())
        {
        case ' ':
            titleScreen = false;
            break;

        }
    }


}


void InputConfig::GamePlayInputLogic(int& x, int& y) const
{
    switch (userInput)
    {
    case LEFT:
        x--;
        break;

    case RUN_LEFT:
        x -= 4;
        break;

    case RIGHT:
        x++;
        break;

    case RUN_RIGHT:
        x += 4;
        break;


    case UP:
        y--;
        break;

    case RUN_UP:
        y -= 2;
        break;

    case DOWN:
        y++;
        break;

    case RUN_DOWN:
        y += 2;
        break;


    case STOP:
        x = x;
        y = y;
        break;
    default:
        break;

    }
}

void InputConfig::StartMenuInputLogic(int& yMenu, int numMenuOptions, bool& select, bool& titleMenu)
{
    switch (userInput)
    {
    case UP:
        if (yMenu != 0)
        {
            yMenu--;
            break;
        }

        else {
            yMenu = yMenu;
            break;
        }

    case DOWN:
        if (yMenu != numMenuOptions - 1)
        {
            yMenu++;
            break;
        }

        else {
            yMenu = yMenu;
            break;
        }

    case ENTER:
        select = true;
        titleMenu = false;
        break;

    case STOP:
        yMenu = yMenu;
        break;
    default:
        break;
    }
}
