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

	bytes_read = read(client_socket, operation, 3);
	printf("Bytes readed: %d\n", (int)bytes_read);
	printf("Operation: %s\n", operation);
	bytes_read = read(client_socket, &first_number, sizeof(first_number));
	printf("Bytes readed: %d\n", (int)bytes_read);
	printf("First number: %d\n", first_number);
	bytes_read = read(client_socket, &second_number, sizeof(second_number));
	printf("Bytes readed: %d\n", (int)bytes_read);

	printf("Numbers: %d %d\n", first_number, second_number);

	return (first_number + second_number);
	return 0;
}