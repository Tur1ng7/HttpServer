#include "response.h"
#include <sstream>
using namespace std;


string generate_response(const HttpResponse& response){
    ostringstream response_stream;

    response_stream << "HTTP/1.1 " << response.status_code << " " << response.status_message << "\r\n";

    for(const auto& [key, value] : response.headers){
        response_stream << key << ": " << value << "\r\n";
    }
    
    response_stream << "\r\n";

    response_stream << response.body;

    return response_stream.str();
}
