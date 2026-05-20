#include "WordCounter.h"
#include <iostream>
#include <fstream>
#include <cctype> // for tolower,
#include <cstdlib> // for exit

using namespace std;

WordCounter::WordCounter(const std::string& path) 
    : filePath(path), capacity(10), uniqueCount(0), totalWords(0), totalSentences(0) 
{
    // Initialize dynamic arrays
    uniqueWords = new string[capacity];
    wordCounts = new int[capacity];
}

WordCounter::~WordCounter() {
    // Clean up memory
    delete[] uniqueWords;
    delete[] wordCounts;
}

void WordCounter::resizeArrays() {
    // double the capacity
    int newCapacity = capacity * 2;
    
    // allocate new arrays
    string* newWords = new string[newCapacity];
    int* newCounts = new int[newCapacity];

    // copy existing data
    for (int i = 0; i < uniqueCount; i++) {
        newWords[i] = uniqueWords[i];
        newCounts[i] = wordCounts[i];
    }

    // delete old arrays
    delete[] uniqueWords;
    delete[] wordCounts;

    // update pointers and capacity
    uniqueWords = newWords;
    wordCounts = newCounts;
    capacity = newCapacity;
}

int WordCounter::findWordIndex(const string& word) const {
    for (int i = 0; i < uniqueCount; i++) {
        if (uniqueWords[i] == word) {
            return i;
        }
    }
    return -1;
}

void WordCounter::addWord(string word) {
    totalWords++;
    
    // convert to lowercase
    for (size_t i = 0; i < word.length(); i++) {
        word[i] = tolower(word[i]);
    }

    // check if word exists
    int index = findWordIndex(word);
    
    if (index != -1) {
        // word exists, increment count
        wordCounts[index]++;
    } else {
        // new word
        if (uniqueCount == capacity) {
            resizeArrays();
        }
        uniqueWords[uniqueCount] = word;
        wordCounts[uniqueCount] = 1;
        uniqueCount++;
    }
}

bool WordCounter::processFile() {
    ifstream file(filePath);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file '" << filePath << "'" << endl;
        return false;
    }

    char ch;
    string currentWord = "";

    // read character by character
    while (file.get(ch)) {
        // check sentence ending
        if (ch == '.' || ch == '!' || ch == '?') {
            totalSentences++;
        }

        if (isalnum(ch)) {
            currentWord += ch;
        } else {
            if (!currentWord.empty()) {
                addWord(currentWord);
                currentWord = ""; 
            }
        }
    }
    if (!currentWord.empty()) {
        addWord(currentWord);
    }

    file.close();
    return true;
}

void WordCounter::printReport() const {
    cout << "Total words: " << totalWords << endl;
    cout << "\nWord frequency:" << endl;
    
    for (int i = 0; i < uniqueCount; i++) {
        cout << uniqueWords[i] << ": " << wordCounts[i] << endl;
    }

    cout << "\nTotal sentences: " << totalSentences << endl;
}