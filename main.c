#include "monty.h"

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of strings representing command-line arguments.
 *
 * Description: The main function serves as the entry point for the program.
 *              It processes command-line arguments and executes the main logic.
 *              Returns: Always 0.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file_fonction(argv[1]);
	free_nodes_fonction();
	return (0);
}

/**
 * create_node_fonction - Creates a node.
 * @n: Number to be stored inside the node.
 * Return: On success, a pointer to the created node. Otherwise, NULL.
 */

stack_t *create_node_fonction(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		monty_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes_fonction - Frees memory allocated for nodes in the stack.
 *
 * Description: This function frees the memory allocated for all nodes in the stack.
 *              It is responsible for deallocating resources and preventing memory leaks.
 */

void free_nodes_fonction(void)
{
	stack_t *temporary_v;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temporary_v = head;
		head = head->next;
		free(temporary_v);
	}
}


/**
 * add_to_queue_fonction - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the opcode.
 *
 * Description: This function adds a new node to the queue.
 *              The line number (@ln) is used for error reporting and debugging purposes.
 */

void add_to_queue_fonction(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temporary_v;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temporary_v = head;
	while (temporary_v->next != NULL)
		temporary_v = temporary_v->next;

	temporary_v->next = *new_node;
	(*new_node)->prev = temporary_v;

}
