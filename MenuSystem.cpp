#include "MenuSystem.h"
#include <iostream>
#include <limits>

using namespace std;

MenuSystem::MenuSystem(int initialSize) {
    arrayOps = new ArrayOperations(initialSize);
    arrayOps->initializeArray();
}

MenuSystem::~MenuSystem() {
    delete arrayOps;
}

void MenuSystem::run() {
    int choice;
    do {
        showMainMenu();
        cout << "Enter your choice (1-12): ";
        cin >> choice;
        
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        if(choice >= 1 && choice <= 11) {
            handleMainMenuChoice(choice);
        } else if(choice != 12) {
            cout << "Invalid choice! Please try again." << endl;
        }
        
    } while(choice != 12);
    
    cout << "Thank you for using Array Operations Program!" << endl;
}

void MenuSystem::showMainMenu() {
    cout << "\n=== ARRAY OPERATIONS MENU ===" << endl;
    cout << "1. Display Array" << endl;
    cout << "2. Insert Element" << endl;
    cout << "3. Delete Element" << endl;
    cout << "4. Reverse Array" << endl;
    cout << "5. Shift Operations" << endl;
    cout << "6. Find Element" << endl;
    cout << "7. Update Element" << endl;
    cout << "8. Sort Array" << endl;
    cout << "9. Resize Array" << endl;
    cout << "10. Reinitialize Array" << endl;
    cout << "11. Show Array Size" << endl;
    cout << "12. Exit" << endl;
    cout << "============================" << endl;
}

void MenuSystem::handleMainMenuChoice(int choice) {
    try {
        switch(choice) {
            case 1:
                arrayOps->displayArray();
                break;
                
            case 2: {
                int position, value;
                cout << "Enter position to insert (0-" << arrayOps->getSize() << "): ";
                cin >> position;
                cout << "Enter value to insert: ";
                cin >> value;
                arrayOps->insertElement(position, value);
                break;
            }
                
            case 3: {
                int position;
                cout << "Enter position to delete (0-" << arrayOps->getSize()-1 << "): ";
                cin >> position;
                arrayOps->deleteElement(position);
                break;
            }
                
            case 4:
                arrayOps->reverseArray();
                arrayOps->displayArray("Array after reversal");
                break;
                
            case 5:
                showShiftMenu();
                break;
                
            case 6: {
                int value;
                cout << "Enter value to find: ";
                cin >> value;
                arrayOps->findElement(value);
                break;
            }
                
            case 7: {
                int position, newValue;
                cout << "Enter position to update (0-" << arrayOps->getSize()-1 << "): ";
                cin >> position;
                cout << "Enter new value: ";
                cin >> newValue;
                arrayOps->updateElement(position, newValue);
                break;
            }
                
            case 8: {
                char order;
                cout << "Sort in (a)scending or (d)escending order? ";
                cin >> order;
                arrayOps->sortArray(order == 'a' || order == 'A');
                arrayOps->displayArray("Array after sorting");
                break;
            }
                
            case 9: {
                int newSize;
                cout << "Enter new array size: ";
                cin >> newSize;
                arrayOps->resizeArray(newSize);
                break;
            }
                
            case 10:
                arrayOps->initializeArray();
                cout << "Array reinitialized!" << endl;
                break;
                
            case 11:
                cout << "Current array size: " << arrayOps->getSize() << endl;
                break;
        }
    } catch(const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void MenuSystem::showShiftMenu() {
    int choice;
    cout << "\n=== SHIFT OPERATIONS ===" << endl;
    cout << "1. Left Shift" << endl;
    cout << "2. Right Shift" << endl;
    cout << "3. Circular Left Shift" << endl;
    cout << "4. Circular Right Shift" << endl;
    cout << "5. Back to Main Menu" << endl;
    cout << "========================" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;
    
    if(choice >= 1 && choice <= 4) {
        int shiftBy, startFrom;
        cout << "Enter number of shifts: ";
        cin >> shiftBy;
        cout << "Enter starting position (0 for beginning): ";
        cin >> startFrom;
        
        try {
            switch(choice) {
                case 1:
                    arrayOps->leftShift(shiftBy, startFrom);
                    break;
                case 2:
                    arrayOps->rightShift(shiftBy, startFrom);
                    break;
                case 3:
                    arrayOps->circularLeftShift(shiftBy, startFrom);
                    break;
                case 4:
                    arrayOps->circularRightShift(shiftBy, startFrom);
                    break;
            }
            arrayOps->displayArray("Array after shift");
        } catch(const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}
