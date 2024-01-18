#include "monty.h"
#include <stdio.h>
/**
 * main - monty interperter
 * @ac: the number of arguments
 * @av: the arguments
 * Return: void
 */
int main(int ac, char *av[])
{
	stack_t *stack = NULL;
	static char *string[1000] = {NULL};
	int n = 0;
	FILE *fd;
	size_t bufsize = 1000;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	for (n = 0; getLine(&(string[n]), &bufsize, fd) > 0; n++)
		;
	executer(string, stack);
	freeList(string);
	fclose(fd);
	return (0);
}
/**
 * executer - executes opcodes
 * @string: contents of file
 * @stack: the list
 * Return: void
 */

void executer(char *string[], stack_t *stack)
{
	int ln, n, i;

	instruction_t st[] = {{"pall", pall},
		{"swap", swap},
		{"pop", pop},
		{"pint", pint},
		{"add", fAdd},
		{"sub", fSub},
		{"div", fDiv},
		{"mul", fMul},
		{"mod", fMod},
		{"pchar", pcharf},
		{"null", NULL}};

	for (ln = 1, n = 0; string[n + 1]; n++, ln++)
	{
		if (_strcmp("push", string[n]))
			push(&stack, ln, pushInt(string[n], ln));
		else if (_strcmp("nop", string[n]))
			;
		else
		{
			i = 0;
			while (!_strcmp(st[i].opcode, "null"))
			{
				if (_strcmp(st[i].opcode, string[n]))
				{
					st[i].f(&stack, ln);
					break;
				}
				i++;
			}
			if (_strcmp(st[i].opcode, "null") && !_strcmp(string[n],
						"\n"))
			{
				if (!nlfind(string[n]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	freeStack(stack);
}
