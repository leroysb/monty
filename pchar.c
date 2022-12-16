#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: stack to be evaluated
 * @lnum: line number
 */
void pchar(stack_t **stack, unsigned int lnum)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lnum);
		status = EXIT_FAILURE;
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lnum);
		status = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (*stack)->n);
}
