#include "monty.h"

/**
 * _strcmp - compares strings
 * @opcode: a string to be compared
 * @list: a string to be compared
 * Return: 0
 */

int _strcmp(char *opcode, char *list)
{
	while (*list != '\0')
	{
		if (*list == ' ')
			list++;
		else if (*opcode == *list)
		{
			opcode++;
			list++;

			if (*opcode == '\0' && (*list == ' ' || *list == '\n'
						|| *list == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/**
 * nlfind - finds newline
 * @list: the string to find \n
 * Return: 1 || 0
 */

int nlfind(char *list)
{
	char *opcode = "\n";

	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;

			if (*opcode == '\0')
				return (1);
		}
		else
			list++;
	}
	return (0);
}

/**
 * pushInt - int for push opcode
 * @list: the content of the file
 * @ln: line number
 * Return: the number
 */

int pushInt(char *list, int ln)
{
	char *opcode = "push";

	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;

			if (*opcode == '\0')
			{
				while (*list)
				{
					if ((*list >= '0' && *list <= '9') ||
							*list == '-')
					{
						combFind(list, ln);
						return (atoi(list));
					}
					else if (*list == ' ')
						list++;
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", ln);
						exit(EXIT_FAILURE);
					}
				}
			}
		}
		else
			list++;
	}
	return (0);
}
/**
 * combFind - finds nonnumbers and number combinations
 * @list: the string
 * @ln: line number
 * Return: 1
 */
int combFind(char *list, int ln)
{
	int i = 0;

	while (list[i])
	{
		if (list[i] == '\0' || list[i] == '\n')
			break;
		if ((list[i] >= '0' && list[i] <= '9') || list[i] == ' ')
			i++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
/**
 * getLine - reads line from stdio and stores it in a buffer
 * @lineptr: pointer to buffer
 * @n: size of characters read
 * @stream: file to be read from
 *
 * Return: number of characters read
 */
ssize_t getLine(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = *n;
	int c;
	size_t i = 0;
	char *temp;

	if (lineptr == NULL || n == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		bufsize = 128;
		*lineptr = (char *)malloc(bufsize);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	else if (*n == 0)
	{
		return (-1);
	}

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (i == bufsize - 1)
		{
			bufsize *= 2;
			temp = (char *)realloc(*lineptr, bufsize);
			if (temp == NULL)
			{
				free(*lineptr);
				*lineptr = NULL;
				return (-1);
			}
			*lineptr = temp;
		}
		(*lineptr)[i++] = (char)c;
	}

	if (i > 0 || c == '\n')
	{
		(*lineptr)[i] = '\0';
		*n = bufsize;
		return (i);
	}
	return (-1);
}
