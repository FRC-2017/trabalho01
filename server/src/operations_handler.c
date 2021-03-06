#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "operations_handler.h"

int handle_operations(char* operation, int first_number, int second_number, int* success) {
	int result = -1;
	if(strcmp(operation, "ADD") == 0) {
		result = add(first_number, second_number, success);
	}
	else if(strcmp(operation, "SUB") == 0) {
		result = subtract(first_number, second_number, success);
	}
	else if(strcmp(operation,  "MUL") == 0) {
		result = multiply(first_number, second_number, success);
	}
	else if(strcmp(operation, "DIV") == 0) {
		result = divide(first_number, second_number, success);
	}
	else {
		printf("Operação inválida!\n");
		*success = ERROR;
	}

	return result;
}

int add(int first_number, int second_number, int* success) {
	if((first_number > 0) && (second_number > INT_MAX - first_number)) {
		printf("Ocorreu um overflow na adição!\nOperação cancelada.\n");
		*success = ERROR;
		return ERROR_OVERFLOW;
	}
	else if((first_number < 0) && (second_number < INT_MIN - first_number)) {
		printf("Ocorreu um underflow na adição!\nOperação cancelada.\n");
		*success = ERROR;
		return ERROR_UNDERFLOW;
	}

	int result = first_number + second_number;
	*success = SUCCESS;

	return result;
}

int subtract(int first_number, int second_number, int* success) {
	if((first_number > 0) && (second_number < ((INT_MIN + 1) + first_number)) ) {
		printf("Ocorreu um overflow na subtração!\nOperação cancelada.\n");
		*success = ERROR;
		return ERROR_OVERFLOW;
	} 
	else if((first_number < 0) && (second_number > ((INT_MAX + first_number) + 1)) ) {
		printf("Ocorreu um underflow na subtração!\nOperação cancelada.\n");
		*success = ERROR;
		return ERROR_UNDERFLOW;
	}

	int result = first_number - second_number;
	*success = SUCCESS;

	return result;
}

int multiply(int first_number, int second_number, int* success) {
	int same_sign;
	int first_module = module(first_number);
	int second_module = module(second_number);

	if( (first_number > 0 && second_number > 0) || (first_number < 0 && second_number < 0)) {
		same_sign = 1;
	}
	else {
		same_sign = 0;
	}

	if((first_number == -1) && (second_number == INT_MIN)) {
		printf("Ocorreu um overflow na multiplicação!\nOperação cancelada.\n");
		*success = ERROR;
		return ERROR_OVERFLOW;
	}
	else if((second_number == -1) && (first_number == INT_MIN)) {
		printf("Ocorreu um overflow na multiplicação!\nOperação cancelada.\n");
		*success = ERROR;
		return ERROR_OVERFLOW;
	}
	else if(first_module > INT_MAX / second_module) {
		*success = ERROR;

		if(same_sign){
			printf("Ocorreu um overflow na multiplicação!\nOperação cancelada.\n");
			return ERROR_OVERFLOW;
		}
		else {
			printf("Ocorreu um underflow na multiplicação!\nOperação cancelada.\n");
		return ERROR_UNDERFLOW;
		}
	}

	int result = first_number * second_number;
	*success = SUCCESS;

	return result;
}

int divide(int first_number, int second_number, int* success) {
	int result;
	if(second_number == 0) {
		printf("Divisão por 0!\n");
		*success = ERROR;
		return ERROR_DIVISION_BY_0;
	}
	else if((first_number % second_number) != 0) {
			printf("Divisão com resto diferente de 0. Mudando variáveis para double.\n");
			*success = WARNING;
			return WARNING_DIVISION_WITH_REMINDER;
	}
	else {
		result = first_number / second_number;
		*success = SUCCESS;
		return result;
	}
}

double division_with_reminder(int first_number, int second_number) {
	double result = (double) first_number / (double) second_number;

	return result;
}

int module(int number) {
	if(number > 0) {
		return number;
	}
	else {
		return -number;
	}
}