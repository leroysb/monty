#include "monty.h"

/**
 * _div - divides second top element by top element
 * @stack: stack to be evaluated
 * @lnum: line number
 */
void _div(stack_t **stack, unsigned int lnum)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lnum);
		status = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lnum);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, lnum);/*For top node*/
	(*stack)->n = result;
}
