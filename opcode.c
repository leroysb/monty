#include "monty.h"

/**
 * opcode - runs builtins
 * @stack: stack to be evaluated
 * @str: string to compare
 * @lnum: line number
 */
void opcode(stack_t **stack, char *str, unsigned int lnum)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, lnum);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lnum, str);
	status = EXIT_FAILURE;
}
