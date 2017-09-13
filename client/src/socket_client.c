#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int client(){

	char legal[80];
	printf("Escreva a expressão\n");
	gets(legal);

	int lenght = strlen(legal);
	int firstValue=0, secondValue=0;
	int i = 0;

	char firstString[80];
	char operator[1];
	char secondString[80];

	operator[0] = ' ';

	while(operator[0] == ' '){
		if(legal[i] >= 48 && legal[i] <=57){
			firstString[i] = legal[i];	
		}

		if(legal[i] == '+'){
			operator[0] = legal[i];
		}
		i++;
	}

	int j=0;
	while(i<=lenght){
		if(legal[i] >= 48 && legal[i] <= 58){
			secondString[j] = legal[i];
			j++;
		}

		i++;
	}
		
	sscanf(firstString, "%d", &firstValue);
	sscanf(secondString, "%d", &secondValue);

	printf("%d\n", firstValue);
	printf("%c\n", operator[0]);
	printf("%d\n", secondValue);

	return 0;
}
