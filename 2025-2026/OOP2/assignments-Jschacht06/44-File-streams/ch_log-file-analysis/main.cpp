#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <map>      
#include <utility>
using namespace std;
int main(){
    string filename;
    
    cout << "Enter a filename: ";
    getline(cin, filename);
    transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
    ifstream input;
    input.open(filename);
    while (!input) {
        cout << "File not found. Enter a valid filename: ";
        getline(cin, filename);
        transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
        input.open(filename);
    }
    cout << "File opened successfully.\n" << endl;
    vector<string> logLines;
    while(getline(input, filename)){
        logLines.push_back(filename);
    }
    input.close();
    cout << "Total log entries: " << logLines.size() << endl;
    int total_errors = 0;
    int total_info = 0;
    int total_warning = 0;
    for(auto line : logLines){
        if (line.find("ERROR") != string::npos){
            total_errors++;
        } else if (line.find("INFO") != string::npos){
            total_info++;
        } else if (line.find("WARNING") != string::npos){
            total_warning++;
        }
    }

    cout << "Total ERROR entries: " << total_errors << endl;
    cout << "Total INFO entries: " << total_info << endl;
    cout << "Total WARNING entries: " << total_warning << "\n" << endl;

    cout << "Top 3 most common log messages: " << endl;

map<string, int> messageCount;

for (auto line : logLines) {
    size_t pos = line.find("] ");
    if (pos != string::npos) {
        string message = line.substr(pos + 2); 
        messageCount[message]++;
    }
}

vector<pair<string, int>> sortedMessages(messageCount.begin(), messageCount.end());

sort(sortedMessages.begin(), sortedMessages.end(),
     [](const pair<string, int>& a, const pair<string, int>& b) {
         return a.second > b.second; 
     });

cout << "Top 3 most common log messages:\n";
for (int i = 0; i < 3 && i < sortedMessages.size(); i++) {
    cout << i + 1 << ". " << sortedMessages[i].first
         << " (" << sortedMessages[i].second << " times)" << endl;
}


    return 0;
}