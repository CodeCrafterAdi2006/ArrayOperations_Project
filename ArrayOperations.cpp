#include "ArrayOperations.h"
using namespace std;

ArrayOperations::ArrayOperations(int arraySize) : size(arraySize) {
    arr.resize(size, 0);
}

void ArrayOperations::initializeArray() {
    cout << "Enter " << size << " values:" << endl;
    for(int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void ArrayOperations::displayArray(const string& message) {
    cout << message << " = { ";
    for(int i = 0; i < size; i++) {
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << " }" << endl;
}

void ArrayOperations::insertElement(int position, int value) {
    if(position < 0 || position > size) {
        throw out_of_range("Invalid position for insertion");
    }
    
    arr.insert(arr.begin() + position, value);
    size++;
    cout << "Element " << value << " inserted at position " << position << endl;
}

void ArrayOperations::deleteElement(int position) {
    if(position < 0 || position >= size) {
        throw out_of_range("Invalid position for deletion");
    }
    
    int deletedValue = arr[position];
    arr.erase(arr.begin() + position);
    size--;
    cout << "Element " << deletedValue << " deleted from position " << position << endl;
}

void ArrayOperations::reverseArray() {
    std::reverse(arr.begin(), arr.end());
    cout << "Array reversed successfully!" << endl;
}

void ArrayOperations::leftShift(int shiftBy, int startFrom) {
    if(shiftBy <= 0) return;
    if(startFrom < 0 || startFrom >= size) startFrom = 0;
    
    int effectiveSize = size - startFrom;
    shiftBy = min(shiftBy, effectiveSize);
    
    for(int i = startFrom; i < size - shiftBy; i++) {
        arr[i] = arr[i + shiftBy];
    }
    
    for(int i = size - shiftBy; i < size; i++) {
        arr[i] = 0;
    }
    
    cout << "Left shifted by " << shiftBy << " starting from position " << startFrom << endl;
}

void ArrayOperations::rightShift(int shiftBy, int startFrom) {
    if(shiftBy <= 0) return;
    if(startFrom < 0 || startFrom >= size) startFrom = 0;
    
    int effectiveSize = size - startFrom;
    shiftBy = min(shiftBy, effectiveSize);
    
    for(int i = size - 1; i >= startFrom + shiftBy; i--) {
        arr[i] = arr[i - shiftBy];
    }
    
    for(int i = startFrom; i < startFrom + shiftBy; i++) {
        arr[i] = 0;
    }
    
    cout << "Right shifted by " << shiftBy << " starting from position " << startFrom << endl;
}

void ArrayOperations::circularLeftShift(int shiftBy, int startFrom) {
    if(shiftBy <= 0) return;
    if(startFrom < 0 || startFrom >= size) startFrom = 0;
    
    int effectiveSize = size - startFrom;
    shiftBy = shiftBy % effectiveSize;
    if(shiftBy == 0) return;
    
    vector<int> temp(shiftBy);
    for(int i = 0; i < shiftBy; i++) {
        temp[i] = arr[startFrom + i];
    }
    
    for(int i = startFrom; i < size - shiftBy; i++) {
        arr[i] = arr[i + shiftBy];
    }
    
    for(int i = 0; i < shiftBy; i++) {
        arr[size - shiftBy + i] = temp[i];
    }
    
    cout << "Circular left shifted by " << shiftBy << " starting from position " << startFrom << endl;
}

void ArrayOperations::circularRightShift(int shiftBy, int startFrom) {
    if(shiftBy <= 0) return;
    if(startFrom < 0 || startFrom >= size) startFrom = 0;
    
    int effectiveSize = size - startFrom;
    shiftBy = shiftBy % effectiveSize;
    if(shiftBy == 0) return;
    
    vector<int> temp(shiftBy);
    for(int i = 0; i < shiftBy; i++) {
        temp[i] = arr[size - shiftBy + i];
    }
    
    for(int i = size - 1; i >= startFrom + shiftBy; i--) {
        arr[i] = arr[i - shiftBy];
    }
    
    for(int i = 0; i < shiftBy; i++) {
        arr[startFrom + i] = temp[i];
    }
    
    cout << "Circular right shifted by " << shiftBy << " starting from position " << startFrom << endl;
}

int ArrayOperations::getSize() const {
    return size;
}

bool ArrayOperations::isValidPosition(int position) const {
    return position >= 0 && position < size;
}

void ArrayOperations::resizeArray(int newSize) {
    if(newSize <= 0) {
        throw invalid_argument("Array size must be positive");
    }
    
    arr.resize(newSize);
    if(newSize > size) {
        for(int i = size; i < newSize; i++) {
            arr[i] = 0;
        }
    }
    size = newSize;
    cout << "Array resized to " << newSize << " elements" << endl;
}

void ArrayOperations::findElement(int value) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == value) {
            cout << "Element " << value << " found at position " << i << endl;
            return;
        }
    }
    cout << "Element " << value << " not found in the array" << endl;
}

void ArrayOperations::updateElement(int position, int newValue) {
    if(position < 0 || position >= size) {
        throw out_of_range("Invalid position for update");
    }
    
    int oldValue = arr[position];
    arr[position] = newValue;
    cout << "Element at position " << position << " updated from " << oldValue << " to " << newValue << endl;
}

void ArrayOperations::sortArray(bool ascending) {
    if(ascending) {
        std::sort(arr.begin(), arr.end());
        cout << "Array sorted in ascending order" << endl;
    } else {
        std::sort(arr.begin(), arr.end(), std::greater<int>());
        cout << "Array sorted in descending order" << endl;
    }
}
