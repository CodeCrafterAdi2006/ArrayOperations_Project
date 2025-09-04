#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include "ArrayOperations.h"

class MenuSystem {
private:
    ArrayOperations* arrayOps;
    
    void showMainMenu();
    void handleMainMenuChoice(int choice);
    void showShiftMenu();
    void handleShiftMenuChoice(int choice);
    
public:
    MenuSystem(int initialSize);
    ~MenuSystem();
    void run();
};

#endif
