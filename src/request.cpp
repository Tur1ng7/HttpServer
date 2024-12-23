#include "request.h"
#include <sstream>
#include <iostream>
using namespace std;

HttpRequest parse_request(const string& raw_request){
    HttpRequest request;
    istringstream stream(raw_request);
    string line;

    if(getline(stream, line)){
        istringstream line_stream(line);
        line_stream >> request.method >> request.path;
    }

    while(getline(stream, line) && line != "\r"){
        size_t colon = line.find(":");
        if(colon != string::npos){
            string key = line.substr(0, colon);
            string value = line.substr(colon + 2);
            request.headers[key] = value;
        }
    }

    if(request.headers.count("Content-Length")){
        int content_length = stoi(request.headers["Content-Length"]);
        string body(content_length, ' ');
        stream.read(&body[0], content_length);
        request.body = body;
    }
    
    return request;
}
