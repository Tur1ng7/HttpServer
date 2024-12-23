#include "router.h"
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;


static unordered_map<string, RouteHandler> routes;

void add_route(const string& path, RouteHandler handler){
    routes[path] = handler;
}

HttpResponse handle_request(const HttpRequest& request){
    if(routes.count(request.path)){
        return routes[request.path](request);
    }

    string file_path = "public" + request.path;
    ifstream file(file_path, ios::binary);

    if(file){
        ostringstream content_stream;
        content_stream << file.rdbuf();

        HttpResponse response;
        response.status_code = 200;
        response.status_message = "OK";
        response.headers = {
            {"Content-Type", "text/html"},
            {"Content-Length", to_string(content_stream.str().size())}
        };
        response.body = content_stream.str();
        return response;
    }

    HttpResponse response;
    response.status_code = 404;
    response.status_message = "Not Found";
    response.headers = {{"Content-Type", "text/plain"}};
    response.body = "404 Not Found";
    return response;
}
