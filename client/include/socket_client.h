#ifndef SOCKET_CLIENT_H
#define SOCKET_CLIENT_H

#define SUCCESS 0
#define ERROR 1
#define WARNING 2

#define ERROR_DIVISION_BY_0 470
#define ERROR_OVERFLOW 400
#define ERROR_UNDERFLOW 401

#define WARNING_DIVISION_WITH_REMINDER 500

int connect_to_server();
int talk_to_server(int socket_fd);
void print_error_code(int code);

#endif