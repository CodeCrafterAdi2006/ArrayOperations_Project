#include "MenuSystem.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== WELCOME TO ARRAY OPERATIONS PROGRAM ===" << endl;
    cout << "Created with Dev-C++" << endl;
    cout << "===========================================" << endl;
    
    int initialSize;
    cout << "Enter the initial size of the array: ";
    cin >> initialSize;
    
    if(initialSize <= 0) {
        cout << "Array size must be positive!" << endl;
        return 1;
    }
    
    try {
        MenuSystem menuSystem(initialSize);
        menuSystem.run();
    } catch(const exception& e) {
        cout << "Fatal error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
