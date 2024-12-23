#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <unordered_map>
using namespace std; 


struct HttpRequest{
    string method;
    string path;
    unordered_map<string, string> headers;
    string body;
};

HttpRequest parse_request(const string& raw_request);

#endif
