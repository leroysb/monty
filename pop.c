#include "monty.h"

/**
* pop - pops top element
* @stack: stack given by main
* @lnum: line number
*
* Return: void
*/
void pop(stack_t **stack, unsigned int lnum)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lnum);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}
