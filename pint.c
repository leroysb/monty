#include "monty.h"

/**
 * pint - print the top data
 * @stack: stack given by main
 * @count: number of lines
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int count)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}
