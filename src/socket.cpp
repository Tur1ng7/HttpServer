#include "socket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>


int create_and_bind_socket(int port){
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    return server_socket;
}

void start_listening(int server_socket){
    if (listen(server_socket, SOMAXCONN) == -1){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
}

int accept_connection(int server_socket){
    int client_socket = accept(server_socket, nullptr, nullptr);
    if (client_socket == -1){
        perror("Accept failed");
    }
    return client_socket;
}


