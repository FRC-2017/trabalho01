#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "socket_server.h"

#define SERVER_PORT 8080

int main (int argc, char* argv[]) {
	int socket_fd;
	int client_socket;
	int result;
	struct sockaddr_in name;
	socklen_t addr_size;

	socket_fd = socket(PF_INET, SOCK_STREAM, 0);
	name.sin_family = AF_INET;
	name.sin_port = htons(SERVER_PORT);
	name.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(socket_fd, (struct sockaddr*)&name, sizeof(name)) < 0) {
		printf("Error on bind\n");
		return 1;
	}

	listen(socket_fd, 10);

	printf("Listening to connections...\n");

	client_socket = accept(socket_fd, (struct sockaddr*)&name, &addr_size);

	if(client_socket < 0) {
		printf("Error on accept\n");
	}

	printf("connection received!\n");

	server(client_socket);
	return 0;
}