#include "monty.h"

/**
 * pint - print value at the top of the stack
 * @stack: stack given by main
 * @lnum: line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int lnum)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lnum);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}
