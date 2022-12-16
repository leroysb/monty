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

/* stack_utils */
stack_t *queue_node(stack_t **stack, const int n);
stack_t *add_node(stack_t **stack, const int n);
size_t print_stack(const stack_t *stack);
void free_stack(stack_t *stack);

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

void opcode(stack_t **stack, char *str, unsigned int line_number);

#define INSTRUCTIONS { \
		{"push", push},\
		{"pall", pall},\
		{"pint", pint},\
		{"pop", pop},\
		{"swap", swap},\
		{"nop", nop},\
		{"div", _div},\
		{"mul", mul},\
		{"add", add},\
		{"sub", sub},\
		{"mod", mod},\
		{"pchar", pchar},\
		{"pstr", pstr},\
		{"rotl", rotl},\
		{"rotr", rotr},\
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

/* opcode_utils */
int is_digit(char *string);
int isnumber(char *str);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int lnum);
void swap(stack_t **stack, unsigned int lnum);
void pop(stack_t **stack, unsigned int lnum);
void nop(stack_t **stack, unsigned int lnum);
void _div(stack_t **stack, unsigned int lnum);
void add(stack_t **stack, unsigned int lnum);
void sub(stack_t **stack, unsigned int lnum);
void mul(stack_t **stack, unsigned int lnum);
void mod(stack_t **stack, unsigned int lnum);
void pchar(stack_t **stack, unsigned int lnum);
void pstr(stack_t **stack, unsigned int lnum);
void rotl(stack_t **stack, unsigned int lnum);
void rotr(stack_t **stack, unsigned int lnum);

#endif /* MONTY_H */
