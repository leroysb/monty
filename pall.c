#include "monty.h"

/**
 * pall - prints all stack values
 * @stack: stack to be evaluated
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	print_stack(*stack);
}

