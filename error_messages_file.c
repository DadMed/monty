#include "monty.h"

/**
 * monty_error - Prints appropriate error messages based on the provided error code.
 * @monty_error_code: The error codes and their corresponding meanings are as follows:
 * (1) => The user did not provide any file or provided more than one file to the program.
 * (2) => The file provided cannot be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => Unable to allocate more memory using malloc.
 * (5) => The parameter passed to the "push" instruction is not an integer.
 * (6) => The stack is empty when executing the "pint" instruction.
 * (7) => The stack is empty when executing the "pop" instruction.
 * (8) => The stack is too short for the specified operation.
 */

void monty_error(int monty_error_code, ...)
{
	va_list argument_v;
	char *operation_v;
	int number_v;

	va_start(argument_v, monty_error_code);
	switch (monty_error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argument_v, char *));
			break;
		case 3:
			number_v = va_arg(argument_v, int);
			operation_v = va_arg(argument_v, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", number_v, operation_v);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argument_v, int));
			break;
		default:
			break;
	}
	free_nodes_fonction();
	exit(EXIT_FAILURE);
}

/**
 * more_monty_errors - Handles errors and prints appropriate messages based on the provided error code.
 * @monty_error_code: The error codes and their corresponding meanings are as follows:
 * (6) => The stack is empty when executing the "pint" instruction.
 * (7) => The stack is empty when executing the "pop" instruction.
 * (8) => The stack is too short for the specified operation.
 * (9) => Division by zero.
 */

void more_monty_errors(int monty_error_code, ...)
{
	va_list argument_v;
	char *operation_v;
	int number_v;

	va_start(argument_v, monty_error_code);
	switch (monty_error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argument_v, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argument_v, int));
			break;
		case 8:
			number_v = va_arg(argument_v, unsigned int);
			operation_v = va_arg(argument_v, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", number_v, operation_v);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argument_v, unsigned int));
			break;
		default:
			break;
	}
	free_nodes_fonction();
	exit(EXIT_FAILURE);
}

/**
 * monty_string_error - Handles errors and prints appropriate messages based on the provided error code.
 * @monty_error_code: The error codes and their corresponding meanings are as follows:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */

void monty_string_error(int monty_error_code, ...)
{
	va_list argument_v;
	int number_v;

	va_start(argument_v, monty_error_code);
	number_v = va_arg(argument_v, int);
	switch (monty_error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", number_v);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", number_v);
			break;
		default:
			break;
	}
	free_nodes_fonction();
	exit(EXIT_FAILURE);
}
