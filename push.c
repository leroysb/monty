#include "monty.h"

/**
 * push - push element to stack
 * @stack: stack to be evaluated
 * @lnum: line number
 */
void push(stack_t **stack, unsigned int lnum)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lnum);
		status = EXIT_FAILURE;
		return;
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			status = EXIT_FAILURE;
			return;
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			status = EXIT_FAILURE;
			return;
		}
	}
}

