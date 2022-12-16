#include "monty.h"

/**
 * sub - substracts top stack element from second
 * @stack: stack to be evaluated
 * @lnum: line number
 */
void sub(stack_t **stack, unsigned int lnum)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lnum);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, lnum);/*For top node*/
	(*stack)->n = result;
}
