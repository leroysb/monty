#include "monty.h"

/**
 * pall - prints all stack elements
 * @stack: stack given by main
 * @lnum: line number
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int lnum __attribute__((unused)))
{
	print_stack(*stack);
}
