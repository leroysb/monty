#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

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

#define INSTRUCTIONS { \
		{"push", push},\
		{"pall", pall},\
		{"pint", pint},\
		{"pop", pop},\
		{"swap", swap},\
		{NULL, NULL} \
	}

/**
* struct help - argument for the current opcode
* @data_struct: stack mode, stack (default) and queue
* @argument: the arguments of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

extern int status;

/* utils2 */
int is_digit(char *string);
int isnumber(char *str);

/* utils */
stack_t *queue_node(stack_t **stack, const int n);
stack_t *add_node(stack_t **stack, const int n);
size_t print_stack(const stack_t *stack);
void free_stack(stack_t *stack);
void opcode(stack_t **stack, char *str, unsigned int lnum);

void push(stack_t **stack, unsigned int lnum);
void pall(stack_t **stack, unsigned int lnum);
void pint(stack_t **stack, unsigned int lnum);
void pop(stack_t **stack, unsigned int lnum);
void swap(stack_t **stack, unsigned int lnum);

#endif /* MONTY_H */
