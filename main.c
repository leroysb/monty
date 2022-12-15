#include "monty.h"

/**
 * error_usage - prints usage message and exits
 *
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - prints file error message and exits
 * @argv: argv given by main
 *
 * Return: nothing
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

int status = 0;
/* int getline(char **lineptr, size_t *n, FILE *stream); */

/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: amount of args
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int count = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while (getline(&buffer, &buf_len, file) != -1)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			count++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			count++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, count);
		count++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(status);
}
