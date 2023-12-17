#include "monty.h"


/**
 * add_to_stack_fonction - Adds a new node to the stack_v.
 * @n_node: Pointer to the new node to be added.
 * @ln_num: Integer representing the line number of the opcode.
 *
 * Description: This function creates a new node with the provided data and adds it to the top of the stack_v.
 *              The line number (@ln_num) is used for error reporting and debugging purposes.
 */

void add_to_stack_fonction(stack_t **n_node, __attribute__((unused))unsigned int ln_num)
{
	stack_t *tmp_v;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_node;
		return;
	}
	tmp_v = head;
	head = *n_node;
	head->next = tmp_v;
	tmp_v->prev = head;
}


/**
 * print_stack_fonction - Prints the elements of the stack_v.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Line number of the opcode.
 *
 * Description: This function prints the elements of the stack_v starting from the top.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void print_stack_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	stack_t *tmp_v;

	(void) line_number_v;
	if (stack_v == NULL)
		exit(EXIT_FAILURE);
	tmp_v = *stack_v;
	while (tmp_v != NULL)
	{
		printf("%d\n", tmp_v->n);
		tmp_v = tmp_v->next;
	}
}

/**
 * pop_top_fonction - Removes the top node from the stack_v.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Integer representing the line number of the opcode.
 *
 * Description: This function removes the top node from the stack_v.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void pop_top_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	stack_t *tmp_v;

	if (stack_v == NULL || *stack_v == NULL)
		more_monty_errors(7, line_number_v);

	tmp_v = *stack_v;
	*stack_v = tmp_v->next;
	if (*stack_v != NULL)
		(*stack_v)->prev = NULL;
	free(tmp_v);
}

/**
 * print_top_fonction - Prints the value of the top node in the stack_v.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Integer representing the line number of the opcode.
 *
 * Description: This function prints the value of the top node in the stack_v without removing it.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void print_top_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	if (stack_v == NULL || *stack_v == NULL)
		more_monty_errors(6, line_number_v);
	printf("%d\n", (*stack_v)->n);
}
