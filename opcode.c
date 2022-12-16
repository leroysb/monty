#include "monty.h"

/**
 * opcode - runs builtins
 * @stack: stack given by main
 * @str: string to compare
 * @lnum: line number
 */
void opcode(stack_t **stack, char *str, unsigned int lnum)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, lnum);
			return; /* if we found a match, run the function */
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lnum, str);
	status = EXIT_FAILURE;
}
