#ifndef ROUTER_H
#define ROUTER_H

#include "request.h"
#include "response.h"
#include <functional>
#include <unordered_map>
#include <string>
using namespace std;


using RouteHandler = function<HttpResponse(const HttpRequest&)>;


void add_route(const string& path, RouteHandler handler);
HttpResponse handle_request(const HttpRequest& request);


#endif
