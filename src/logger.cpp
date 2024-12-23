#include "logger.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <mutex>
using namespace std;

mutex logMutex;

void logMessage(const string& message){
    lock_guard<mutex> lock(logMutex);

    time_t now = time(nullptr);
    string timestamp = ctime(&now);
    timestamp.pop_back();

    string logEntry = "[" + timestamp + "] " + message;

    cout << logEntry << endl;

    ofstream logFile("server.log", ios::app);
    if(logFile.is_open()){
        logFile << logEntry << endl;
    }
}
