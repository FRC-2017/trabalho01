#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int server(int client_socket) {
	ssize_t bytes_recv;
	char operation[3] = {0};
	int first_number;
	int second_number;
	int result;


	while(1) {
		
		while((bytes_recv = recv(client_socket, operation, 3, 0)) <= 0);

		printf("Operation: %s\n", operation);
		bytes_recv = recv(client_socket, &first_number, sizeof(first_number), 0);

		if(bytes_recv <= 0) {
			printf("Nothing to recv!\n");
		}

		printf("First number: %d\n", first_number);
		bytes_recv = recv(client_socket, &second_number, sizeof(second_number), 0);

		if(bytes_recv <= 0) {
			printf("Nothing to recv!\n");
		}

		printf("Second number: %d\n", (int)second_number);

		result = first_number + second_number;
		send(client_socket, &result, sizeof(result), 0);
	}


	return (first_number + second_number);
}