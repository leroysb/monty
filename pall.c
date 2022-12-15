#include "monty.h"

/**
 * pall - prints all stack elements
 * @stack: stack given by main
 * @count: number of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int count __attribute__((unused)))
{
	print_stack(*stack);
}
