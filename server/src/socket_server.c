#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "socket_server.h"

void* server(void* client_socket) {
	int socket = *(int*)client_socket;
	ssize_t bytes_recv;
	char operation[4] = {0};
	int first_number;
	int second_number;
	int result;
	int sucess = 1;

	while(1) {
		
		while((bytes_recv = read(socket, operation, 3)) <= 0);

		operation[4] = '\0';

		printf("Operation: %s\n", operation);
		bytes_recv = recv(socket, &first_number, sizeof(first_number), 0);

		printf("First number: %d\n", first_number);
		bytes_recv = recv(socket, &second_number, sizeof(second_number), 0);

		printf("Second number: %d\n", (int)second_number);

		result = handle_operations(operation, first_number, second_number, &sucess);
		send(socket, &sucess, sizeof(sucess), 0);
		send(socket, &result, sizeof(result), 0);
	}


	return 0;
}

int handle_operations(char* operation, int first_number, int second_number, int* sucess) {
	int result = -1;
	if(strcmp(operation, "ADD") == 0) {
		result = add(first_number, second_number, sucess);
	}
	else if(strcmp(operation, "SUB") == 0) {
		result = subtract(first_number, second_number, sucess);
	}
	else if(strcmp(operation,  "MUL") == 0) {
		result = multiply(first_number, second_number, sucess);
	}
	else if(strcmp(operation, "DIV") == 0) {
		result = divide(first_number, second_number, sucess);
	}
	else {
		printf("Operação inválida!\n");
		*sucess = 1;
	}

	return result;
}

int add(int first_number, int second_number, int* sucess) {
	int result = first_number + second_number;
	*sucess = 0;

	return result;
}

int subtract(int first_number, int second_number, int* sucess) {
	int result = first_number - second_number;
	*sucess = 0;

	return result;
}

int multiply(int first_number, int second_number, int* sucess) {
	int result = first_number * second_number;
	*sucess = 0;

	return result;
}

int divide(int first_number, int second_number, int* sucess) {
	int result;
	if(second_number != 0) {
		result = first_number / second_number;
		*sucess = 0;
		return result;
	}
	else {
		printf("Divisão por 0!\n");
		*sucess = 1;
		return -1;
	}
}
