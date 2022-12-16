#include "monty.h"

/**
 * pall - prints all stack values
 * @stack: stack to be evaluated
 * @lnum: line number
 */
void pall(stack_t **stack, unsigned int lnum __attribute__((unused)))
{
	print_stack(*stack);
}

