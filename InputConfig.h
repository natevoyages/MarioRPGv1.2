#ifndef INPUTCONFIG_H
#define INPUTCONFIG_H

class InputConfig
{
public:
    void UserInput();

    void UserInput(bool& menuOpen);

    void MenuInput();

    void PressEnterToContinue(bool& titleScreen);



    void OverWorldInputLogic(int& x, int& y, int width, int height, bool northOpen, bool southOpen, bool eastOpen, bool westOpen);

    void StartMenuInputLogic(int& yMenu, int numMenuOptions, bool& select, bool& titleMenu);

    void CharSelectInputLogic(int& yCharSelect, const int numCharacters, bool& charSelect);

    void MenuInputLogic(int& yCharSelect, int numCharacters, bool& charSelect, bool& menuToggled);



private:

    enum eInputs { STOP = 0, LEFT, RIGHT, UP, DOWN, RUN_LEFT, RUN_RIGHT, RUN_UP, RUN_DOWN, ENTER, BACK, EXIT };
    eInputs userInput;
};

#endif
