#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct OpValues {
	int firstValue;
	int secondValue;
	char operand[1];
};

struct OpValues handleString(char string[80], struct OpValues Values){
	int lenght = strlen(string);
	int i = 0;

	char firstString[80];
	char operator[1];
	char secondString[80];

	Values.operand[0] = ' ';

	while(Values.operand[0] == ' '){
		if(string[i] >= 48 && string[i] <=57){
			firstString[i] = string[i];	
		}

		//Não está tratando operadores inválidos
		if(string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/'){
			Values.operand[0] = string[i];
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

int client(){

	char string[80];
	printf("Escreva a expressão\n");
	gets(string);

	struct OpValues Values;

	Values = handleString(string, Values);

	printf("%d\n", Values.firstValue);
	printf("%c\n", Values.operand[0]);
	printf("%d\n", Values.secondValue);

	return 0;
}
