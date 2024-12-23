#include "server.h"
#include "socket.h"
#include "thread_pool.h"
#include <iostream>

using namespace std;

void start_server(int port){
    int server_fd = create_and_bind_socket(port);
    if (server_fd == -1){
        cerr << "Failed to create and bind the server\n";
        return;
    }

    start_listening(server_fd);
}

