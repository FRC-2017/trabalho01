#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int server(int client_socket) {
	while(1){
		int lenght;
		char* text;
		int verify_read;
		verify_read = read(client_socket, &lenght, sizeof(int));
		if(verify_read == 0) {
			return 0;
		}
		if(verify_read <0) {
			printf("deu ruim\n");
		}

		text = (char*) malloc(lenght * sizeof(char));
		verify_read = read(client_socket, text, lenght);
		printf("%s\n", text);
		
		free(text);

		if(!strcmp(text, "quit")) {
			return 1;
		}
	}
}