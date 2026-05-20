#pragma once
#include <string>

class WordCounter {
private:
    std::string filePath;
    
    // Dynamic arrays
    std::string* uniqueWords;
    int* wordCounts;
    
    int capacity;       
    int uniqueCount;    
    int totalWords;     
    int totalSentences; 

    void resizeArrays();
    int findWordIndex(const std::string& word) const;
    void addWord(std::string word);
    std::string cleanWord(const std::string& raw) const;

public:
    WordCounter(const std::string& path);
    ~WordCounter(); 

    bool processFile();
    void printReport() const;
};