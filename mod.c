#include "monty.h"

/**
 * mod - computes the rest of the division of 2nd top element
 * by the top element of the stack
 * @stack: stack to be evaluated
 * @lnum: line number
 */
void mod(stack_t **stack, unsigned int lnum)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lnum);
		status = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lnum);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, lnum);/*For top node*/
	(*stack)->n = result;
}
