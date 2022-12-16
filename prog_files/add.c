#include "monty.h"

/**
 * add -  adds the top two elements of the stack
 * @stack: stack to be evaluated
 * @lnum: line number
 */
void add(stack_t **stack, unsigned int lnum)
{

	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lnum);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, lnum);/*For top node*/
	(*stack)->n = result;
}
