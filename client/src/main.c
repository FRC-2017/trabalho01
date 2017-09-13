#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080

int main(int argc, char* argv[]) {
	struct sockaddr_in server;
	int socket_fd;
	int first_integer = 10;
	int second_integer = 12;
	int result = -1;
	char operation[3] = "ADD";

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	if(connect(socket_fd, (struct sockaddr*)&server, sizeof(server)) < 0) {
		printf("Error on bind!\n");
		return -1;
	}

	printf("Client connected to server\n");

	while(1) {
		send(socket_fd, operation, sizeof(operation), 0);
		send(socket_fd, &first_integer, sizeof(first_integer), 0);
		send(socket_fd, &second_integer, sizeof(second_integer), 0);

		recv(socket_fd, &result, sizeof(result), 0);
		printf("Resultado: %d\n", result);
		sleep(5);
	}

	return 0;
}