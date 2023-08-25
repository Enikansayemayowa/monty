#include "monty.h"
/*
 * main - main functions
 * @argc: argument count
 * @argv: argument vector
 * Return value
 */
int main(int argc, char *argv[])
{
	FILE *f;
	char *line = NULL;
	size_t len = MAX_LINE_LENGTH;
	/* ssize_t read;*/
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *opcode;
	int value;
	char *arg;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = malloc(len + 1);
	while (fgets(line, len, f))
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode == NULL)
		{
			continue;
		}
		else if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \n");
			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(f);
	free(line);
	return 0;
}
