#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "socket_client.h"
#include "expression_handler.h"

#define SERVER_PORT 8080

int main(int argc, char* argv[]) {
	struct sockaddr_in server;
	int socket_fd;
	int result = -1;
	int sucess = 1;
	char* expression = NULL;
	expression_values* values;
	int first_value;
	int second_value;

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
		expression = read_expression();
		values = get_values(expression);

		if(!values) {
			printf("Erro nos valores!\n");
			return 1;
		}
		
		send(socket_fd, values->operand, sizeof(values->operand), 0);
		send(socket_fd, &values->first_value, sizeof(first_value), 0);
		send(socket_fd, &values->second_value, sizeof(second_value), 0);

		recv(socket_fd, &sucess, sizeof(sucess), 0);
		recv(socket_fd, &result, sizeof(result), 0);
		if(sucess == 0) {
			printf("Resultado: %d\n", result);
		}
		else {
			printf("Ocorreu algum erro na operação!\n");
			print_error_code(result);
		}
	}

	return 0;
}