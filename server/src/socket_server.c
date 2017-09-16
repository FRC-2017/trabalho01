#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "socket_server.h"
#include "operations_handler.h"
void* server(void* client_socket) {
	int socket = *(int*)client_socket;
	ssize_t bytes_recv;
	char operation[4];
	int first_number;
	int second_number;
	int result;
	int success = 1;

	while(1) {
		
		while((bytes_recv = read(socket, operation, sizeof(operation))) <= 0);

		operation[4] = '\0';

		printf("Operation: %s\n", operation);
		bytes_recv = recv(socket, &first_number, sizeof(first_number), 0);

		printf("First number: %d\n", first_number);
		bytes_recv = recv(socket, &second_number, sizeof(second_number), 0);

		printf("Second number: %d\n", (int)second_number);

		result = handle_operations(operation, first_number, second_number, &success);
		send(socket, &success, sizeof(success), 0);
		send(socket, &result, sizeof(result), 0);
	}


	return 0;
}