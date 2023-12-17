#include "monty.h"

/**
 * mul_nodes_fonction - Multiplies the top two elements of the stack_v.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Integer representing the line number of the opcode.
 *
 * Description: This function multiplies the values of the top two elements in the stack_v
 *              and replaces them with the result.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void mul_nodes_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	int sum;

	if (stack_v == NULL || *stack_v == NULL || (*stack_v)->next == NULL)
		more_monty_errors(8, line_number_v, "mul");

	(*stack_v) = (*stack_v)->next;
	sum = (*stack_v)->n * (*stack_v)->prev->n;
	(*stack_v)->n = sum;
	free((*stack_v)->prev);
	(*stack_v)->prev = NULL;
}


/**
 * mod_nodes_fonction - Computes the modulo of the second element on the stack_v by the top element.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Integer representing the line number of the opcode.
 *
 * Description: This function computes the modulo operation, finding the remainder when dividing
 *              the value of the second element in the stack_v by the top element.
 *              It replaces them with the result.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void mod_nodes_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	int sum;

	if (stack_v == NULL || *stack_v == NULL || (*stack_v)->next == NULL)

		more_monty_errors(8, line_number_v, "mod");


	if ((*stack_v)->n == 0)
		more_monty_errors(9, line_number_v);
	(*stack_v) = (*stack_v)->next;
	sum = (*stack_v)->n % (*stack_v)->prev->n;
	(*stack_v)->n = sum;
	free((*stack_v)->prev);
	(*stack_v)->prev = NULL;
}
