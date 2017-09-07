#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

int main (int argc, char* argv[]) {
	const char* const socket_name = argv[1];
	int socket_fd;
	struct sockaddr_un name;
	int quit;

	socket_fd = socket(PF_LOCAL, SOCK_STREAM, 0);
	name.sun_family = AF_LOCAL;
	strcpy(name.sun_path, socket_name);
	bind(socket_fd, &name, SUN_LEN(&name));
	listen(socket_fd, 10);
	return 0;
}