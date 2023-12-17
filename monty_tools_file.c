#include "monty.h"

/**
 * open_file_fonction - Opens a file.
 * @file_name_v: The file pathname to be opened.
 *
 * Description: This function opens a file specified by the given pathname (@file_name_v).
 *              It does not return any value.
 */


void open_file_fonction(char *file_name_v)
{
	FILE *fd_v = fopen(file_name_v, "r");

	if (file_name_v == NULL || fd_v == NULL)
		monty_error(2, file_name_v);

	read_file_fonction(fd_v);
	fclose(fd_v);
}


/**
 * read_file_fonction - Reads from a file.
 * @fd_v: Pointer to the file descriptor.
 *
 * Description: This function reads from a file specified by the given file descriptor (@fd_v).
 *              It does not return any specific value.
 */


void read_file_fonction(FILE *fd_v)
{
	int line_number_v, format_v = 0;
	char *buffer_v = NULL;
	size_t len = 0;

	for (line_number_v = 1; getline(&buffer_v, &len, fd_v) != -1; line_number_v++)
	{
		format_v = parse_line_fonction(buffer_v, line_number_v, format_v);
	}
	free(buffer_v);
}


/**
 * parse_line_fonction - Separates each line into tokens to determine
 * which function to call.
 * @buffer_v: Line from the file.
 * @line_number_v: Line number.
 * @format_v: Storage format. If 0, nodes will be entered as a stack.
 *            If 1, nodes will be entered as a queue.
 * Return: 0 if the opcode is for a stack, 1 if for a queue.
 */


int parse_line_fonction(char *buffer_v, int line_number_v, int format_v)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer_v == NULL)
		monty_error(4);

	opcode = strtok(buffer_v, delim);
	if (opcode == NULL)
		return (format_v);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func_fonction(opcode, value, line_number_v, format_v);
	return (format_v);
}

/**
 * find_func_fonction - Finds the appropriate function for the opcode.
 * @opcode: Opcode.
 * @value: Argument of the opcode.
 * @format_v: Storage format. If 0, nodes will be entered as a stack.
 *            If 1, nodes will be entered as a queue.
 * @ln_v: Line number.
 *
 * Description: This function finds and executes the appropriate function for the given opcode.
 *              The storage format is determined by the value of @format_v (0 for stack, 1 for queue).
 *              The line number (@ln_v) is used for error reporting and debugging purposes.
 */

void find_func_fonction(char *opcode, char *value, int ln_v, int format_v)
{
	int i;
	int flag;

	instruction_t func_list_v[] = {
		{"push", add_to_stack_fonction},
		{"pall", print_stack_fonction},
		{"pint", print_top_fonction},
		{"pop", pop_top_fonction},
		{"nop", nop_fonction},
		{"swap", swap_nodes_fonction},
		{"add", add_nodes_fonction},
		{"sub", sub_nodes_fonction},
		{"div", div_nodes_fonction},
		{"mul", mul_nodes_fonction},
		{"mod", mod_nodes_fonction},
		{"pchar", print_char_fonction},
		{"pstr", print_str_fonction},
		{"rotl", rotl_fonction},
		{"rotr", rotr_fonction},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list_v[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list_v[i].opcode) == 0)
		{
			call_fun_fonction(func_list_v[i].f, opcode, value, ln_v, format_v);
			flag = 0;
		}
	}
	if (flag == 1)
		monty_error(3, ln_v, opcode);
}


/**
 * call_fun_fonction - Calls the required function.
 * @func_v: Pointer to the function to be called.
 * @op_v: String representing the opcode.
 * @val_v: String representing a numeric value.
 * @ln_v: Line number for the instruction.
 * @format_v: Storage format specifier. If 0, nodes will be entered as a stack.
 *            If 1, nodes will be entered as a queue.
 *
 * Description: This function calls the specified function (@func_v) based on the provided opcode (@op_v).
 *              If the opcode requires a numeric value, it is represented by the string @val_v.
 *              The storage format is determined by the value of @format_v (0 for stack, 1 for queue).
 *              The line number (@ln_v) is used for error reporting and debugging purposes.
 */

void call_fun_fonction(op_func func_v, char *op_v, char *val_v, int ln_v, int format_v)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op_v, "push") == 0)
	{
		if (val_v != NULL && val_v[0] == '-')
		{
			val_v = val_v + 1;
			flag = -1;
		}
		if (val_v == NULL)
			monty_error(5, ln_v);
		for (i = 0; val_v[i] != '\0'; i++)
		{
			if (isdigit(val_v[i]) == 0)
				monty_error(5, ln_v);
		}
		node = create_node_fonction(atoi(val_v) * flag);
		if (format_v == 0)
			func_v(&node, ln_v);
		if (format_v == 1)
			add_to_queue_fonction(&node, ln_v);
	}
	else
		func_v(&head, ln_v);
}
