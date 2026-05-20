#include <iostream>
#include <fstream>
#include "WordCounter.h"

using namespace std;

void createSampleFile() {
    ofstream outfile("test.txt");
    outfile << "The quick brown fox jumps over the lazy dog." << endl;
    outfile.close();
}

int main() {
    
    createSampleFile();

    string filename;
    cout << "Enter a file: ";
    cin >> filename;

    WordCounter counter(filename);

    
    if (!counter.processFile()) {
        return 1;
    }

    cout << endl;
    counter.printReport();

    return 0;
}