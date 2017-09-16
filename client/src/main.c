#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include "socket_client.h"

int main(int argc, char* argv[]) {
	int socket_fd;
	
	socket_fd = connect_to_server();

	if(socket_fd == -1) {
		printf("Erro na conexão.\n");
		return 1;
	}

	return talk_to_server(socket_fd);
}