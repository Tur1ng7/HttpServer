#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H


#include <string>
#include <fstream>
#include <sys/stat.h>
using namespace std;

bool fileExists(const string& path);

string readFile(const string& path);


#endif
