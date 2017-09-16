#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "socket_client.h"
#include "expression_handler.h"

#define SERVER_PORT 8080

int connect_to_server() {
	struct sockaddr_in server;
	int socket_fd;
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	if(connect(socket_fd, (struct sockaddr*)&server, sizeof(server)) < 0) {
		printf("Error on connect!\n");
		return -1;
	}

	printf("Client connected to server\n");

	return socket_fd;
}

int talk_to_server(int socket_fd) {
	int result = -1;
	int success = 1;
	double division_result;
	char* expression = NULL;
	expression_values* values;
	int first_value;
	int second_value;

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

		recv(socket_fd, &success, sizeof(success), 0);
		recv(socket_fd, &result, sizeof(result), 0);
		if(success == SUCCESS) {
			printf("Resultado: %d\n", result);
		}
		else if(success == WARNING) {
			if(result == WARNING_DIVISION_WITH_REMINDER) {
				recv(socket_fd, &division_result, sizeof(division_result), 0);
				printf("Resultado: %.2f\n", division_result);
			}
		}
		else {
			printf("Ocorreu algum erro na operação!\n");
			print_error_code(result);
		}
	}

	return 0;
}

void print_error_code(int code) {
	switch(code) {
		case ERROR_DIVISION_BY_0:
			printf("Erro de divisão por 0!\n");
			return;

		case ERROR_OVERFLOW:
			printf("Ocorreu um overflow na operação!\n");
			return;

		case ERROR_UNDERFLOW:
			printf("Ocorreu um underflow na operação!\n");
			return;

		default:
			printf("Erro desconhecido!\n");
			return;
	}
}

void client(){
}
