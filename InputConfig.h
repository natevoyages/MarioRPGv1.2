#ifndef INPUTCONFIG_H
#define INPUTCONFIG_H

class InputConfig
{
public:
    InputConfig();

    void UserInput();
    //takes userInput if keyboard is pressed for directionals / run directionals
    //else stop is sent as input

    void UserInput(bool& menuOpen);
    //same as userInput but space triggers overWorld menu
    //z and x are used for select and back

    void MenuInput();
    //same as second userInput but only up and down are usable directions

    void PressEnterToContinue(bool& titleScreen);
    //exits title screen 

    void StepCounter();
    //base on input step counter increases walk = +1 run = +5

    int GetStepCount();
    // returns stepcount

    void SetStepCount(int steps);
    //retrieves steps from overworld class

    void StepCountReset();
    //resets step count

    void OverWorldInputLogic(int& x, int& y, int width, int height, bool northOpen, bool southOpen, bool eastOpen, bool westOpen);
    //determines what the user inputs mean to the x and y coordinates in the overworld 


    void StartMenuInputLogic(int& yMenu, int numMenuOptions, bool& select, bool& titleMenu);
    //determines what the user inputs mean in start menu 

    void CharSelectInputLogic(int& yCharSelect, const int numCharacters, bool& charSelect);
    //determines what the user inputs mean in character select


    void ShopMenuInputLogic(int& yMenu, int numMenuOptions, bool& select, bool& menuToggled);
    //determines what user input mean for y menu and selection

    void MenuInputLogic(int& yCharSelect, int numCharacters, bool& charSelect, bool& menuToggled);
    //determines what user input mean for y menu and selection for inGameMenu

    void BattleItemMenuInputLogic(int& yItemMenu, int numMenuOptions, bool& notExited, bool& selectedItem, bool& succesfullySlected, bool& itemSelected);
    //determines what user input mean for y menu and selection for battleItemMenu


    void ItemMenuInputLogic(int& yItemMenu, int numMenuOptions, bool& select, bool& open, bool& selectedItem, bool& itemUse);
    //determines what user input mean for y menu and selection for ItemMenu
  

    void BattleInputLogic(int& yMenu, int numMenuOptions, bool& select, bool& itemTabOpen);
    //determines what user input mean for y menu and selection for battleMenu

    void BattleItemMenuLogic(int& yMenu, int numItemOptions, bool& select, bool& itemTabOpen);
    //determines what user input mean for y menu and selection for battleMenu

    void OverWorldItemMenuLogic(int& yMenu, int numItemOptions, bool& select, bool& itemTabOpen);
    //same as userInput
    //z and x are used for select and back

    /*      Removede because of time constraints
    void AddStatPointLogic(int& yMenu, int numStats, bool& select, bool& statsOpen);
    */



private:
    //input directions 
    enum eInputs { STOP = 0, LEFT, RIGHT, UP, DOWN, RUN_LEFT, RUN_RIGHT, RUN_UP, RUN_DOWN, ENTER, BACK, EXIT };
    eInputs userInput;
    // tracks step count in between clasess
     int stepCount;
};

#endif
