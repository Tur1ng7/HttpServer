#ifndef SOCKET_H
#define SOCKET_H

int create_and_bind_socket(int port);
void start_listening(int server_socket);
int accept_connection(int server_socket);

#endif
