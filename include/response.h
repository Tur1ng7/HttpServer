#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <unordered_map>
using namespace std;


struct HttpResponse{
    int status_code;
    string status_message;
    unordered_map<string, string> headers;
    string body;
};

string generate_response(const HttpResponse& response);


#endif
