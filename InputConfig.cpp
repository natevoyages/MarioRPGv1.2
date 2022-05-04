#include "InputConfig.h"
#include <conio.h>
#include <windows.h>

using namespace std;

InputConfig::InputConfig()
{
    stepCount = 0;
}

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
void InputConfig::UserInput(bool& menuOpen)
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
            menuOpen = true;
            break;

        }
    }
    else
    {
        userInput = STOP;
    }
}

void InputConfig::MenuInput()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            userInput = UP;
            break;

        case 's':
            userInput = DOWN;
            break;

        case 'z':
            userInput = ENTER;
            break;

        case 'x':
            userInput = BACK;
            break;

        case ' ':
            userInput = EXIT;
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

void InputConfig::StepCounter()
{
    if(userInput == LEFT || userInput == RIGHT || userInput == UP || userInput == DOWN)
    {
        stepCount++;  
    }

    else if(userInput == RUN_LEFT || userInput == RUN_RIGHT || userInput == RUN_UP || userInput == RUN_DOWN)
    {
        stepCount += 4;
    }
}

int InputConfig::GetStepCount()
{
    return stepCount;
}

void InputConfig::StepCountReset()
{
    stepCount = 0;
}

void InputConfig::OverWorldInputLogic(int& x, int& y, int width, int height, bool northOpen, bool southOpen, bool eastOpen, bool westOpen)
{
    switch (userInput)
    {
    case LEFT:
        if (westOpen) {
            if (x > 1 || (x == 1 && y == ( height / 2)) ) // lower limit is 0
            {
                x--;
                break;
            }
            else
            {
                x = x;
                break;
            }
        }
        else {
            if (x > 1) // lower limit is 0
            {
                x--;
                break;
            }
            else
            {
                x = x;
                break;
            }
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
        if (eastOpen) {
            if (x < width -2  || (x == width - 2 && y == (height / 2))) // lower limit is 0
            {
                x++;
                break;
            }
            else
            {
                x = x;
                break;
            }
        }
        else {

            if (x < width - 2) // upper limit is width - 2 since last char is at width - 1 
            {
                x++;
                break;
            }
            else
            {
                x = x;
                break;
            }
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
        if(northOpen) {
            if (y > 0 || (y == 0 && x == width / 2) || (y == 0 && x == (width / 2) + 1) )  // upper limit is 0 for y
            {
                y--;
                break;
            }
            else {
                y = y;
                break;
            }
        }
        else
        {
            if (y > 0) // upper limit is 0 for y
            {
                y--;
                break;
            }
            else {
                y = y;
                break;
            }
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
        if (southOpen) {
            if (y < height - 1 || (y == height - 1 && x == width / 2) || (y == height - 1 && x == (width / 2) + 1))  // upper limit is 0 for y
            {
                y++;
                break;
            }
            else {
                y = y;
                break;
            }
        }
        else {
            if (y < height - 1)
            {
                y++;
                break;
            }
            else
            {
                y = y;
                break;
            }
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
void InputConfig::MenuInputLogic(int& yMenu, int numMenuOptions, bool& select, bool& menuToggled)
{
    switch (userInput)
    {
    case UP:
        if (yMenu != 0 && !select)
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
        if (yMenu != numMenuOptions - 1 && !select)
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
        break;

    case BACK:
        select = false;
        break;

    case EXIT:
        menuToggled = false;
        break;

    case STOP:
        yMenu = yMenu;
        break;
    default:
        break;
    }
}


void InputConfig::BattleInputLogic(int& xMenu, int& yMenu, int& numXMenuOptions, int& numYMenuOptions, bool& select)
{
    select = false;
    switch (userInput)
    {
    case UP:
        if (yMenu != 0 && !select)
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
        if (yMenu != numYMenuOptions - 1 && !select)
        {
            yMenu++;
            break;
        }

        else
        {
            yMenu = yMenu;
            break;
        }
    case LEFT:
        if (yMenu != 0 && !select)
        {
            xMenu--;
            break;
        }

        else
        {
            xMenu = xMenu;
            break;
        }

    case RIGHT:
        if (xMenu != numXMenuOptions - 1 && !select)
        {
            xMenu++;
            break;
        }

        else
        {
            xMenu = xMenu;
            break;
        }

    case ENTER:
        select = true;
        break;

    case BACK:
        select = false;
        break;

    case STOP:
        yMenu = yMenu;
        break;
    default:
        break;
    }
}
