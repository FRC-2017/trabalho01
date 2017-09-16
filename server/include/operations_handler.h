#ifndef OPERATIONS_HANDLER_H
#define OPERATIONS_HANDLER_H

#define SUCCESS 0
#define ERROR 1
#define WARNING 2

#define ERROR_DIVISION_BY_0 470
#define ERROR_OVERFLOW 400
#define ERROR_UNDERFLOW 401

#define WARNING_DIVISION_WITH_REMINDER 500

int handle_operations(char* operation, int first_number, int second_number, int* sucess);
int add(int first_number, int second_number, int* sucess);
int subtract(int first_number, int second_number, int* sucess);
int multiply(int first_number, int second_number, int* sucess);
int divide(int first_number, int second_number, int* sucess);
double division_with_reminder(int first_number, int second_number);

#endif