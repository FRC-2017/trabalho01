#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

void* server(void* client_socket);
int handle_operations(char* operation, int first_number, int second_number, int* sucess);
int add(int first_number, int second_number, int* sucess);
int subtract(int first_number, int second_number, int* sucess);
int multiply(int first_number, int second_number, int* sucess);
int divide(int first_number, int second_number, int* sucess);

#endif