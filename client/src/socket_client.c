#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "socket_client.h"

// int connect_to_server() {

// }

void print_error_code(int code) {
	if(code == ERROR_DIVISION_BY_0) {
		printf("Erro de divisão por 0!\n");
	}
	else {
		printf("Erro desconhecido...\n");
	}
}

void client(){
}
