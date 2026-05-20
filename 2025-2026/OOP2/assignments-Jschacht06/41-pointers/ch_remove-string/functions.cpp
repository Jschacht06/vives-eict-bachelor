#include "functions.h"
#include <iostream>

using namespace std;

std::string getString(string* arr, int size) {
    string result = "";
    
    
    for (int i = 0; i < size; i++) {
        
        result += *(arr + i); 
        
        
        if (i < size - 1) {
            result += " ";
        }
    }
    return result;
}

void removeString(string target, string* arr, int size) {
    string* readPtr = arr;        // Pointer to scan the array
    string* writePtr = arr;       // Pointer to write valid elements
    string* endPtr = arr + size;  // Pointer marking the end of the array

    //eerste keer doorgaan
    while (readPtr < endPtr) {
        
        if (*readPtr != target) {
            *writePtr = *readPtr; // Copy value from read location to write location
            writePtr++;           // Move write pointer forward
        }
        readPtr++; //read moet altijd vooruit gaan ongeacht de if statement
    }

    //2e keer doorgaan om de rest van de array op te vullen met '.'
    while (writePtr < endPtr) {
        *writePtr = ".";
        writePtr++;
    }
}