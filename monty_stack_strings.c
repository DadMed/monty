#include "monty.h"ascii_v

/**
 * print_char_fonction - Prints the character represented by the top element's ascii_v value.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @line_number_v: Integer representing the line number of the opcode.
 *
 * Description: This function prints the character represented by the ascii_v value
 *              of the top element in the stack_v without removing it.
 *              The line number (@line_number_v) is used for error reporting and debugging purposes.
 */

void print_char_fonction(stack_t **stack_v, unsigned int line_number_v)
{
	int ascii_v;

	if (stack_v == NULL || *stack_v == NULL)
		monty_string_error(11, line_number_v);

	ascii_v = (*stack_v)->n;
	if (ascii_v < 0 || ascii_v > 127)
		monty_string_error(10, line_number_v);
	printf("%c\n", ascii_v);
}

/**
 * print_str_fonction - Prints the string represented by ASCII values on the stack_v.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @ln_v: Integer representing the line number of the opcode.
 *
 * Description: This function interprets the ASCII values on the stack_v as characters
 *              and prints the corresponding string without removing the elements.
 *              The line number (@ln_v) is used for error reporting and debugging purposes.
 */

void print_str_fonction(stack_t **stack_v, __attribute__((unused))unsigned int ln_v)
{
	int ascii_v;
	stack_t *temporary_v;

	if (stack_v == NULL || *stack_v == NULL)
	{
		printf("\n");
		return;
	}

	temporary_v = *stack_v;
	while (temporary_v != NULL)
	{
		ascii_v = temporary_v->n;
		if (ascii_v <= 0 || ascii_v > 127)
			break;
		printf("%c", ascii_v);
		temporary_v = temporary_v->next;
	}
	printf("\n");
}

/**
 * rotl_fonction - Rotates the first node of the stack_v to the bottom.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @ln_v: Integer representing the line number of the opcode.
 *
 * Description: This function rotates the first node of the stack_v to the bottom,
 *              preserving the order of other nodes.
 *              The line number (@ln_v) is used for error reporting and debugging purposes.
 */

void rotl_fonction(stack_t **stack_v, __attribute__((unused))unsigned int ln_v)
{
	stack_t *temporary_v;

	if (stack_v == NULL || *stack_v == NULL || (*stack_v)->next == NULL)
		return;

	temporary_v = *stack_v;
	while (temporary_v->next != NULL)
		temporary_v = temporary_v->next;

	temporary_v->next = *stack_v;
	(*stack_v)->prev = temporary_v;
	*stack_v = (*stack_v)->next;
	(*stack_v)->prev->next = NULL;
	(*stack_v)->prev = NULL;
}


/**
 * rotr_fonction - Rotates the last node of the stack_v to the top.
 * @stack_v: Pointer to a pointer pointing to the top node of the stack_v.
 * @ln_v: Integer representing the line number of the opcode.
 *
 * Description: This function rotates the last node of the stack_v to the top,
 *              preserving the order of other nodes.
 *              The line number (@ln_v) is used for error reporting and debugging purposes.
 */

void rotr_fonction(stack_t **stack_v, __attribute__((unused))unsigned int ln_v)
{
	stack_t *temporary_v;

	if (stack_v == NULL || *stack_v == NULL || (*stack_v)->next == NULL)
		return;

	temporary_v = *stack_v;

	while (temporary_v->next != NULL)
		temporary_v = temporary_v->next;

	temporary_v->next = *stack_v;
	temporary_v->prev->next = NULL;
	temporary_v->prev = NULL;
	(*stack_v)->prev = temporary_v;
	(*stack_v) = temporary_v;
}
