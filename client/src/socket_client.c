#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "socket_client.h"

struct OpValues {
	int firstValue;
	int secondValue;
	char operand[3];
};

struct OpValues handleString(char string[80], struct OpValues Values){
	int lenght = strlen(string);
	int i = 0;

	char firstString[80];
	char secondString[80];

	Values.operand[0] = ' ';

	while(Values.operand[0] == ' '){
		if(string[i] >= 48 && string[i] <=57){
			firstString[i] = string[i];	
		}

		//Não está tratando operadores inválidos
		if(string[i] == '+'){
			strcpy(Values.operand, "ADD");
		}
		if(string[i] == '-'){
			strcpy(Values.operand, "SUB");
		}
		if(string[i] == '*'){
			strcpy(Values.operand, "MUL");
		}
		if(string[i] == '/'){
			strcpy(Values.operand, "DIV");
		}
		i++;
	}

	int j=0;
	while(i<=lenght){
		if(string[i] >= 48 && string[i] <= 58){
			secondString[j] = string[i];
			j++;
		}

		i++;
	}
		
	sscanf(firstString, "%d", &Values.firstValue);
	sscanf(secondString, "%d", &Values.secondValue);

	return Values;
}

void* client(){

	char string[80];
	printf("Escreva a expressão\n");
	gets(string);

	struct OpValues Values;

	Values = handleString(string, Values);

	printf("%d\n", Values.firstValue);
	printf("%s\n", Values.operand);
	printf("%d\n", Values.secondValue);

}
