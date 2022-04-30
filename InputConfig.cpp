#include "InputConfig.h"
#include <conio.h>
#include <windows.h>

using namespace std;

void InputConfig::UserInput(bool& menu)
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

void InputConfig::PressEnterToContinue(bool& titleScreen)
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


void InputConfig::GamePlayInputLogic(int& x, int& y, int width, int height) const
{
    switch (userInput)
    {
    case LEFT:
        if (x != 1) // lower limit is 0
        {
            x--;
            break;
        }
        else
        {
            x = x;
            break;
        }

    case RUN_LEFT:
        if (x > 5)
        {
            x -= 4;
            break;
        }
        else
        {
            x = 1;
            break;
        }
    case RIGHT:
        if (x != width - 2) // upper limit is width - 2 since last char is at width - 1 
        {
            x++;
            break;
        }
        else
        {
            x = x;
            break;
        }

    case RUN_RIGHT:
        if (x < width - 6)
        {
            x += 4;
            break;
        }
        else
        {
            x = width - 2;
            break;
        }
   


    case UP:
        if (y != 0) // upper limit is 0 for y
        {
            y--;
            break;
        }
        else {
            y = 0;
            break;
        }

    case RUN_UP:
        if (y > 1)
        {
            y -= 2;
            break;
        }
        else
        {
            y = 0;
            break;
        }

    case DOWN:
        if (y < height - 1)
        {
            y++;
            break;
        }
        else 
        {
            y = height - 1;
            break;
        }

    case RUN_DOWN:
        if (y < height - 2)
        {
            y += 2;
            break;
        }
        else
        {
            y = height - 1;
            break;
        }

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

        else 
        {
            yMenu = yMenu;
            break;
        }

    case DOWN:
        if (yMenu != numMenuOptions - 1)
        {
            yMenu++;
            break;
        }

        else 
        {
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

void InputConfig::CharSelectInputLogic(int& yCharSelect, const int numCharacters, bool& charSelect)
{
    switch (userInput)
    {
    case UP:
        if (yCharSelect != 0)
        {
            yCharSelect--;
            break;
        }

        else 
        {
            yCharSelect = yCharSelect;
            break;
        }

    case DOWN:
        if (yCharSelect != numCharacters - 1)
        {
            yCharSelect++;
            break;
        }

        else 
        {
            yCharSelect = yCharSelect;
            break;
        }

    case ENTER:
        charSelect = true;
        break;

    case STOP:
        yCharSelect = yCharSelect;
        break;
    default:
        break;
    }
}
