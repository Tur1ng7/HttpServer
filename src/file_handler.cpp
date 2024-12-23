#include "file_handler.h"

bool fileExists(const string& path){
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}

string readFile(const string& path){
    ifstream file(path);
    if(!file.is_open()){
        throw runtime_error("Failed to open file: " + path);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}
