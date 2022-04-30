#ifndef INPUTCONFIG_H
#define INPUTCONFIG_H

class InputConfig
{
public:
    void UserInput(bool& menu);

    void PressEnterToContinue(bool& titleScreen);

    void GamePlayInputLogic(int& x, int& y, int width, int height) const;

    void StartMenuInputLogic(int& yMenu, int numMenuOptions, bool& select, bool& titleMenu);

    void CharSelectInputLogic(int& yCharSelect, const int numCharacters, bool& charSelect);



private:

    enum eInputs { STOP = 0, LEFT, RIGHT, UP, DOWN, RUN_LEFT, RUN_RIGHT, RUN_UP, RUN_DOWN, ENTER };
    eInputs userInput;
};

#endif