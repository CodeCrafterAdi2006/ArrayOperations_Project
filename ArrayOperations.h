#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stdexcept>

class ArrayOperations {
private:
    std::vector<int> arr;
    int size;

public:
    // Constructor
    ArrayOperations(int arraySize);
    
    // Core operations
    void initializeArray();
    void displayArray(const std::string& message = "Current Array");
    void insertElement(int position, int value);
    void deleteElement(int position);
    void reverseArray();
    void leftShift(int shiftBy, int startFrom = 0);
    void rightShift(int shiftBy, int startFrom = 0);
    void circularLeftShift(int shiftBy, int startFrom = 0);
    void circularRightShift(int shiftBy, int startFrom = 0);
    
    // Utility functions
    int getSize() const;
    bool isValidPosition(int position) const;
    void resizeArray(int newSize);
    
    // Additional operations
    void findElement(int value);
    void updateElement(int position, int newValue);
    void sortArray(bool ascending = true);
};

#endif
