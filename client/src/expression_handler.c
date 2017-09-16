#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "expression_handler.h"


char* read_expression() {
	char* message = (char*) malloc(sizeof(char));
	char* aux_pointer = (char*) malloc(sizeof(char));
	size_t string_size = 0;
	size_t position = 0;
	int read_char = 1;

	while(read_char) {
		read_char = getc(stdin);

		if(read_char == '\n' || read_char == '\0') {
			message[position] = '\0';
			return message;
		}

		if(string_size <= position) {
			string_size++;
			aux_pointer = realloc(message, string_size);

			if(!aux_pointer) {
				printf("Error on realloc!\n");
				free(message);
				return NULL;
			}

			message = aux_pointer;
		}
		message[position] = (char)read_char;
		position++;
	}

	return message;
}

expression_values* get_values(char* expression) {
	expression_values* values = (expression_values*) malloc(sizeof(expression_values));
	int lenght = strlen(expression);
	int state = FIRST_VALUE;
	size_t string_size = 0;
	char* first_value = (char*)malloc(sizeof(char));
	char* second_value = (char*)malloc(sizeof(char));
	int i = 0;

	while(state == FIRST_VALUE) {
		if(lenght < i) {
			return NULL;
		}

		if(expression[i] >= ASCII_0 && expression[i] <= ASCII_9) {
			string_size++;
			first_value = realloc(first_value, string_size);
			first_value[string_size - 1] = expression[i];
		}
		else if(expression[i] == '-' && string_size == 0) {
			string_size++;
			first_value = realloc(first_value, string_size);
			first_value[string_size - 1] = expression[i];
		}
		else if(i == 0){
			printf("Não foi encontrado um numero no inicio!\n");
			return NULL;
		}
		else {
			state = OPERAND;
			break;
		}

		i++;
	}

	first_value = realloc(first_value, string_size + 1);
	first_value[i] = '\0';

	while(state == OPERAND) {
		if(lenght < i) {
			return NULL;
		}

		if(expression[i] == '+') {
			strcpy(values->operand, "ADD");
			state = SECOND_VALUE;
		}
		else if(expression[i] == '-') {
			strcpy(values->operand, "SUB");
			state = SECOND_VALUE;
		}
		else if(expression[i] == '*') {
			strcpy(values->operand, "MUL");
			state = SECOND_VALUE;
		}
		else if(expression[i] == '/') {
			strcpy(values->operand, "DIV");
			state = SECOND_VALUE;
		}
		else if(expression[i] != ' '){
			printf("expressão invalida!\n");
			return NULL;
		}

		i++;
	}
	values->operand[4] = '\0';
	string_size = 0;

	while(state == SECOND_VALUE) {
		if(lenght < i) {
			printf("erro de tamanho\n");
			return NULL;
		}

		if(expression[i] >= ASCII_0 && expression[i] <= ASCII_9) {
			string_size++;
			second_value = realloc(second_value, string_size);
			second_value[string_size - 1] = expression[i];
		}
		else if(expression[i] == '-' && string_size == 0) {
			string_size++;
			second_value = realloc(second_value, string_size);
			second_value[string_size - 1] = expression[i];
		}
		else if(expression[i] == '\0') {
			break;
		}
		else if(expression[i] != ' ') {
			printf("caractere invalido após o operando!\n");
			return NULL;
		}

		i++;
	}

	second_value = realloc(second_value, string_size + 1);
	second_value[i] = '\0';

	if(valid_numbers(first_value, second_value)) {
		sscanf(first_value, "%d", &values->first_value);
		sscanf(second_value, "%d", &values->second_value);
		return values;
	}
	else {
		return NULL;
	}
}

int valid_numbers(char* first_value, char* second_value) {
	char maximum_int[12];
	char minimum_int[12];
	sprintf(maximum_int, "%d", INT_MAX);
	sprintf(minimum_int, "%d", INT_MIN);


	if(strlen(first_value) < strlen(maximum_int)) {
		if((strcmp(first_value, maximum_int) < 0) || (strcmp(first_value, minimum_int) > 0)) {
			return VALID;
		}
		else {
			printf("primeiro numero digitado inválido!\n");
			return INVALID;
		}
	}
	else {
		printf("primeiro numero digitado inválido!\n");
		return INVALID;
	}

	if(strlen(second_value) < strlen(maximum_int)){
		if((strcmp(second_value, maximum_int) < 0) || (strcmp(second_value, minimum_int) > 0)) {
			return VALID;
		}
		else {
			printf("Segundo numero digitado inválido!\n");
			return INVALID;
		}
	}
	else {
		printf("Segundo numero digitado inválido!\n");
		return INVALID;
	}
}