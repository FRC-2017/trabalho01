#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "socket_client.h"

// int connect_to_server() {

// }

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
