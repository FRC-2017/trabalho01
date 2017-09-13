#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#include "socket_server.h"

#define SERVER_PORT 8080

int main (int argc, char* argv[]) {
	int socket_fd;
	int client_socket;
	struct sockaddr_in name;
	socklen_t addr_size = sizeof(struct sockaddr_in);

	socket_fd = socket(PF_INET, SOCK_STREAM, 0);
	name.sin_family = AF_INET;
	name.sin_port = htons(SERVER_PORT);
	name.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(socket_fd, (struct sockaddr*)&name, sizeof(name)) < 0) {
		printf("Error on bind\n");
		return 1;
	}

	listen(socket_fd, 5);

	printf("Listening to connections...\n");

	while(1) {
		client_socket = accept(socket_fd, (struct sockaddr*)&name, &addr_size);
		if(client_socket < 0) {
			printf("Error on accept\n");
		}

		printf("connection received!\n");

		pthread_t connection_thread;

		if( pthread_create(&connection_thread, NULL, server, (void*) &client_socket) < 0) {
			printf("Error on thread create!\n");
			return -1;
		}

	}
	return 0;
}