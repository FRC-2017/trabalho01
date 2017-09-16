#ifndef EXPRESSION_HANDLER_H
#define EXPRESSION_HANDLER_H

#define FIRST_VALUE 0
#define OPERAND 1
#define SECOND_VALUE 2
#define ASCII_0 48
#define ASCII_9 57
#define VALID 1
#define INVALID 0

typedef struct expression_values {
	int first_value;
	int second_value;
	char operand[4];
} expression_values;

char* read_expression();
expression_values* get_values(char* expression);
int valid_numbers(char* first_value, char* second_value);

#endif