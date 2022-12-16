#include "monty.h"

/**
 * opcode - runs builtins
 * @stack: stack to be evaluated
 * @str: string to compare
 * @line_number: line number
 */
void opcode(stack_t **stack, char *str, unsigned int line_number)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
	status = EXIT_FAILURE;
}

