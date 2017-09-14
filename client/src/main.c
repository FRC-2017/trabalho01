#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "socket_client.h"

#define SERVER_PORT 8080

int main(int argc, char* argv[]) {
	struct sockaddr_in server;
	int socket_fd;
	int first_integer = 5;
	int second_integer = 2;
	int result = -1;
	int sucess = 1;
	char operation[3] = "DIV";

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	if(connect(socket_fd, (struct sockaddr*)&server, sizeof(server)) < 0) {
		printf("Error on connect!\n");
		return -1;
	}

	printf("Client connected to server\n");

	while(1) {
		client();
		send(socket_fd, operation, sizeof(operation), 0);
		send(socket_fd, &first_integer, sizeof(first_integer), 0);
		send(socket_fd, &second_integer, sizeof(second_integer), 0);

		recv(socket_fd, &sucess, sizeof(sucess), 0);
		recv(socket_fd, &result, sizeof(result), 0);
		if(sucess == 0) {
			printf("Resultado: %d\n", result);
		}
		else {
			printf("Ocorreu algum erro na operação!\n");
		}
		sleep(5);
	}

	return 0;
}