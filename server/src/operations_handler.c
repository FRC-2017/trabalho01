#include <stdio.h>
#include <string.h>

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
	int result = first_number + second_number;
	*success = SUCCESS;

	return result;
}

int subtract(int first_number, int second_number, int* success) {
	int result = first_number - second_number;
	*success = SUCCESS;

	return result;
}

int multiply(int first_number, int second_number, int* success) {
	int result = first_number * second_number;
	*success = SUCCESS;

	return result;
}

int divide(int first_number, int second_number, int* success) {
	int result;
	if(second_number != 0) {
		result = first_number / second_number;
		*success = SUCCESS;
		return result;
	}
	else {
		printf("Divisão por 0!\n");
		*success = ERROR;
		return ERROR_DIVISION_BY_0;
	}
}
