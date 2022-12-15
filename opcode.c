#include "monty.h"

/**
 * opcode - runs builtins
 * @stack: stack given by main
 * @str: string to compare
 * @count: number of lines
 *
 * Return: nothing
 */
void opcode(stack_t **stack, char *str, unsigned int count)
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
			op[i].f(stack, count);
			return; /* if we found a match, run the function */
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", count, str);
	status = EXIT_FAILURE;
}
