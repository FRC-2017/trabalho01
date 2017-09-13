#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void* server(void* client_socket) {
	int socket = *(int*)client_socket;
	ssize_t bytes_recv;
	char operation[4] = {0};
	int first_number;
	int second_number;
	int result;

	while(1) {
		
		while((bytes_recv = read(socket, operation, 3)) <= 0);
		
		operation[4] = '\0';

		printf("Operation: %s\n", operation);
		bytes_recv = recv(socket, &first_number, sizeof(first_number), 0);

		if(bytes_recv <= 0) {
			printf("Nothing to recv!\n");
		}

		printf("First number: %d\n", first_number);
		bytes_recv = recv(socket, &second_number, sizeof(second_number), 0);

		if(bytes_recv <= 0) {
			printf("Nothing to recv!\n");
		}

		printf("Second number: %d\n", (int)second_number);

		result = first_number + second_number;
		send(socket, &result, sizeof(result), 0);
	}


	return 0;
}