#include <iostream>
#include <fstream> //todo1
#include <vector> //todo2a
#include <map> //todo3

using namespace std;

//ToLower method for todo2b
string toLowerCase(string str){
    string lowerStr;
    for(char ch : str){
        lowerStr += tolower(ch);
    }
    return lowerStr;
}

//defining what a log message is for todo3
struct LogMessage {
    string message;
    int count;
};

//sorting log messages for todo3
vector<LogMessage> sortLogMessages(vector<LogMessage> logMessages){
    for(int i=0; i<logMessages.size(); i++){
        for(int j=i+1; j<logMessages.size(); j++){
            if(logMessages[i].count < logMessages[j].count){
                LogMessage temp = logMessages[i];
                logMessages[i] = logMessages[j];
                logMessages[j] = temp;
            }
        }
    }
    return logMessages;
}

int main(void){
    
    cout << "Welcome to the log file analyser!" << endl;



    //TODO1: ask user for filename
    //if file doesn't exist, print error with cerr and ask again

    ifstream serverFile;
    bool succes = false;

    while(!succes){
        string fileName;
        cout << "PLease enter the file name of the server log file: ";
        getline(cin, fileName);
        serverFile.open(fileName);
        if(serverFile.is_open()){
            succes = true;
        } else {
            cerr << "Error: File not found. Please enter the correct name." << endl;
        }
    }



    //TODO2a: read file line by line and collect info + total number of lines

    string line;
    vector<string> logLines;
    int totalLines = 0;

    while(getline(serverFile, line)){
        logLines.push_back(line);
        totalLines++;
    }

    cout << "The log file has been successfully read." << endl;
    cout << "The total amount of lines in the log file is: " << totalLines << endl;

    serverFile.close();



    //TODO2b: determin frequency count of each log type

    int totalErrors = 0;
    int totalWarnings = 0;
    int totalInfos = 0;

    for(auto logLine : logLines){
        string lowerLogLine = toLowerCase(logLine);
        if(lowerLogLine.find("error") != string::npos) totalErrors++;
        if(lowerLogLine.find("warning") != string::npos) totalWarnings++;
        if(lowerLogLine.find("info") != string::npos) totalInfos++;
    }

    cout << "The total amount of errors is: " << totalErrors << endl;
    cout << "The total amount of warnings is: " << totalWarnings << endl;
    cout << "The total amount of info messages is: " << totalInfos << endl;



    //TODO3: display top 3 most common log messages

    map<string, int> logMessages;

    for(auto logLine : logLines){
        string lowerLogLine = toLowerCase(logLine);
        size_t messageStart = lowerLogLine.find(": ");
        if(messageStart != string::npos){
            string message = lowerLogLine.substr(messageStart + 2);
            if(logMessages.find(message) == logMessages.end()){
                logMessages[message] = 1;
            } else {
                logMessages[message]++;
            }
        }
    }

    vector<LogMessage> sortedLogMessages;

    for(auto const &entry : logMessages){
        LogMessage logMessage;
        logMessage.message = entry.first;
        logMessage.count = entry.second;
        sortedLogMessages.push_back(logMessage);
    }

    sortedLogMessages = sortLogMessages(sortedLogMessages);
    cout << "The most frequent log messages are: " << endl;
    for(int i=0; i<3 && sortedLogMessages.size(); i++){
        cout << i + 1 << ": " << sortedLogMessages[i].message << " - " << sortedLogMessages[i].count << " times" << endl;
    }



    //TODO4: allow user to choose to only display a selected log type
    //keep asking until user enters 'q' to quit

    while(true){
        cout << "Enter 'y' to search for a specific log type or 'q' to exit the program: ";
        string userInput;
        getline(cin, userInput);
        if(toLowerCase(userInput) == "y"){
            cout << "Please enter the log type you want to search for: ";
            string searchType;
            getline(cin, searchType);
            searchType = toLowerCase(searchType);
            bool found = false;
            cout << "The log messages that match the search criteria are:" << endl;
            for(const string &storedLine :logLines){
                string lowerLine = toLowerCase(storedLine);
                if(lowerLine.find(searchType) != string::npos){
                    cout << storedLine << endl;
                    found = true;
                }
            }
            if(!found){
                cout << "No log messages found that match the search criteria." << endl;
            }

        } else if(toLowerCase(userInput) == "q"){
            cout << "Thank you for using loganalyser." << endl;
            return 0;
        } else {
            cout << "invalid input." << endl;
        }
    }

    return 0;
}