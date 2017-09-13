#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int server(int client_socket) {
	ssize_t bytes_read;
	char operation[3] = {0};
	int first_number;
	int second_number;
	int result;


	while(1) {
		bytes_read = read(client_socket, operation, 3);

		if(bytes_read <= 0) {
			printf("Nothing to read!\n");
			while((bytes_read = read(client_socket, operation, 3)) <= 0);
		}

		printf("Operation: %s\n", operation);
		bytes_read = read(client_socket, &first_number, sizeof(first_number));

		if(bytes_read <= 0) {
			printf("Nothing to read!\n");
		}

		printf("First number: %d\n", first_number);
		bytes_read = read(client_socket, &second_number, sizeof(second_number));

		if(bytes_read <= 0) {
			printf("Nothing to read!\n");
		}

		printf("Second number: %d\n", (int)second_number);

		result = first_number + second_number;
		send(client_socket, &result, sizeof(result), 0);
	}


	return (first_number + second_number);
}