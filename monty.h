#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file_fonction(char *file_name);
int parse_line_fonction(char *buffer_v, int line_number, int format);
void read_file_fonction(FILE *);
int len_chars(FILE *);
void find_func_fonction(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node_fonction(int n);
void free_nodes_fonction(void);
void print_stack_fonction(stack_t **, unsigned int);
void add_to_stack_fonction(stack_t **, unsigned int);
void add_to_queue_fonction(stack_t **, unsigned int);

void call_fun_fonction(op_func, char *, char *, int, int);

void print_top_fonction(stack_t **, unsigned int);
void pop_top_fonction(stack_t **, unsigned int);
void nop_fonction(stack_t **, unsigned int);
void swap_nodes_fonction(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_nodes_fonction(stack_t **, unsigned int);
void sub_nodes_fonction(stack_t **, unsigned int);
void div_nodes_fonction(stack_t **, unsigned int);
void mul_nodes_fonction(stack_t **, unsigned int);
void mod_nodes_fonction(stack_t **, unsigned int);

/*String operations*/
void print_char_fonction(stack_t **, unsigned int);
void print_str_fonction(stack_t **, unsigned int);
void rotl_fonction(stack_t **, unsigned int);

/*Error hanlding*/
void monty_error(int monty_error_code, ...);
void more_monty_errors(int monty_error_code, ...);
void monty_string_error(int monty_error_code, ...);
void rotr_fonction(stack_t **, unsigned int);

#endif
