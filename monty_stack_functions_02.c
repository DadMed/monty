#include "monty.h"

/**
 * nop_fonction - Does nothing.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Integer representing the line number of the opcode.
 *
 * Description: This function serves as a no-operation (nop) and has no effect on the stack_v.
 *              It is included for alignment or placeholder purposes.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void  nop_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	(void)stack_v;
	(void)line_number_v;
}


/**
 * swap_nodes_fonction - Swaps the positions of the top two elements in the stack_v.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Integer representing the line number of the opcode.
 *
 * Description: This function swaps the positions of the top two elements in the stack_v.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void  swap_nodes_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	stack_t *temporary_v;

	if (stack_v == NULL || *stack_v == NULL || (*stack_v)->next == NULL)
		more_monty_errors(8, line_number_v, "swap");
	temporary_v = (*stack_v)->next;
	(*stack_v)->next = temporary_v->next;
	if (temporary_v->next != NULL)
		temporary_v->next->prev = *stack_v;
	temporary_v->next = *stack_v;
	(*stack_v)->prev = temporary_v;
	temporary_v->prev = NULL;
	*stack_v = temporary_v;
}

/**
 * add_nodes_fonction - Adds the top two elements of the stack_v.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Integer representing the line number of the opcode.
 *
 * Description: This function adds the values of the top two elements in the stack_v and replaces
 *              them with the result.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void add_nodes_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	int sum;

	if (stack_v == NULL || *stack_v == NULL || (*stack_v)->next == NULL)
		more_monty_errors(8, line_number_v, "add");

	(*stack_v) = (*stack_v)->next;
	sum = (*stack_v)->n + (*stack_v)->prev->n;
	(*stack_v)->n = sum;
	free((*stack_v)->prev);
	(*stack_v)->prev = NULL;
}


/**
 * sub_nodes_fonction - Subtracts the top element from the second element on the stack_v.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Integer representing the line number of the opcode.
 *
 * Description: This function subtracts the value of the top element from the second element in the stack_v
 *              and replaces them with the result.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void sub_nodes_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	int sum;

	if (stack_v == NULL || *stack_v == NULL || (*stack_v)->next == NULL)

		more_monty_errors(8, line_number_v, "sub");


	(*stack_v) = (*stack_v)->next;
	sum = (*stack_v)->n - (*stack_v)->prev->n;
	(*stack_v)->n = sum;
	free((*stack_v)->prev);
	(*stack_v)->prev = NULL;
}


/**
 * div_nodes_fonction - Divides the second element on the stack_v by the top element.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Integer representing the line number of the opcode.
 *
 * Description: This function divides the value of the second element in the stack_v by the top element
 *              and replaces them with the result.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void div_nodes_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	int sum;

	if (stack_v == NULL || *stack_v == NULL || (*stack_v)->next == NULL)
		more_monty_errors(8, line_number_v, "div");

	if ((*stack_v)->n == 0)
		more_monty_errors(9, line_number_v);
	(*stack_v) = (*stack_v)->next;
	sum = (*stack_v)->n / (*stack_v)->prev->n;
	(*stack_v)->n = sum;
	free((*stack_v)->prev);
	(*stack_v)->prev = NULL;
}
