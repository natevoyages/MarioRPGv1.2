#ifndef INPUTCONFIG_H
#define INPUTCONFIG_H

class InputConfig
{
public:
    InputConfig();

    void UserInput();

    void UserInput(bool& menuOpen);

    void MenuInput();

    void PressEnterToContinue(bool& titleScreen);

    void StepCounter();

    int GetStepCount();

    void SetStepCount(int steps);

    void StepCountReset();

    void OverWorldInputLogic(int& x, int& y, int width, int height, bool northOpen, bool southOpen, bool eastOpen, bool westOpen);

    void StartMenuInputLogic(int& yMenu, int numMenuOptions, bool& select, bool& titleMenu);

    void CharSelectInputLogic(int& yCharSelect, const int numCharacters, bool& charSelect);

    void ShopMenuInputLogic(int& yMenu, int numMenuOptions, bool& select, bool& menuToggled);

    void MenuInputLogic(int& yCharSelect, int numCharacters, bool& charSelect, bool& menuToggled);

    void BattleItemMenuInputLogic(int& yItemMenu, int numMenuOptions, bool& notExited, bool& selectedItem, bool& succesfullySlected, bool& itemSelected);

    void ItemMenuInputLogic(int& yItemMenu, int numMenuOptions, bool& select, bool& open, bool& selectedItem, bool& itemUse);

  

    void BattleInputLogic(int& yMenu, int numMenuOptions, bool& select, bool& itemTabOpen);


    void BattleItemMenuLogic(int& yMenu, int numItemOptions, bool& select, bool& itemTabOpen);


    void OverWorldItemMenuLogic(int& yMenu, int numItemOptions, bool& select, bool& itemTabOpen);

    void AddStatPointLogic(int& yMenu, int numStats, bool& select, bool& statsOpen);



private:

    enum eInputs { STOP = 0, LEFT, RIGHT, UP, DOWN, RUN_LEFT, RUN_RIGHT, RUN_UP, RUN_DOWN, ENTER, BACK, EXIT };
    eInputs userInput;

     int stepCount;
};

#endif
