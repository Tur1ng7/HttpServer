#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include "server.h"
#include "router.h"
#include "thread_pool.h"
#include "logger.h"
#include "socket.h"
#include "file_handler.h"
#include "request.h"
#include "response.h"

using namespace std;

void handle_client(int client_fd) {
    char buffer[1024];
    int bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        cerr << "Error reading from client socket" << endl;
        close(client_fd);
        return;
    }
    buffer[bytes_read] = '\0';  

    HttpRequest request = parse_request(buffer);

    HttpResponse response = handle_request(request);

    string response_str = generate_response(response);

    write(client_fd, response_str.c_str(), response_str.length());

    logMessage("Responded to client with status: " + to_string(response.status_code));

    close(client_fd);
}

int main() {
    // Initialize the server on port 8080 (you can customize the port here)
    int port = 8080;

    int server_fd = create_and_bind_socket(port);
    if (server_fd == -1) {
        cerr << "Failed to create and bind the server" << endl;
        return 1;
    }

    start_listening(server_fd);
    cout << "Server running on port " << port << "..." << endl;

    ThreadPool thread_pool;
    thread_pool.initialize(4);

    add_route("/", [](const HttpRequest& /*req*/) {
        HttpResponse res;
        res.status_code = 200;
        res.status_message = "OK";
        res.body = "<html><body><h1>Hello everyone, welcome to the HttpServer !</h1></body></html>";
        return res;
    });

    add_route("/hello", [](const HttpRequest& /*req*/) {
        HttpResponse res;
        res.status_code = 200;
        res.status_message = "OK";
        res.body = "<html><body><h1>Welcome to the /hello endpoint!</h1></body></html>";
        return res;
    });

    while (true) {
        int client_fd = accept_connection(server_fd);
        if (client_fd < 0) {
            cerr << "Error accepting client connection" << endl;
            continue;
        }

        logMessage("Client connected");

        thread_pool.enqueueTask([client_fd]() {
            handle_client(client_fd);
        });
    }

    thread_pool.shutdown();
    close(server_fd);

    return 0;
}
