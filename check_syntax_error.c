#include "main.h"

/**
 * count_repeated - counts the repeated occurrences of a character
 *
 * @str: input string
 * @c: character to count
 * Return: count of repeated characters
 */
int count_repeated(const char *str, char c)
{
	int count = 0;

	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}

	return count;
}

/**
 * has_syntax_error - checks for syntax errors in the input
 *
 * @input: input string
 * Return: 1 if syntax error found, 0 otherwise
 */
int has_syntax_error(const char *input)
{
	int i = 0;

	while (input[i])
	{
		if (input[i] == ';' || input[i] == '|' || input[i] == '&')
		{
			if (input[i + 1] == input[i] && input[i + 2] == input[i])
				return 1;
		}
		i++;
	}

	return 0;
}

/**
 * print_syntax_error_msg - prints a syntax error message
 *
 * @datash: data structure
 * @input: input string
 * @index: index of the error
 */
void print_syntax_error_msg(data_shell *datash, const char *input, int index)
{
	char *error_msg = malloc(128);

	if (error_msg == NULL)
		return;

	snprintf(error_msg, 128, "%s: Syntax error near unexpected token '%c'\n", datash->av[0], input[index]);

	write(STDERR_FILENO, error_msg, _strlen(error_msg));
	free(error_msg);
}

/**
 * check_syntax_error - checks and prints syntax errors in the input
 *
 * @datash: data structure
 * @input: input string
 * Return: 1 if syntax error found, 0 otherwise
 */
int check_syntax_error(data_shell *datash, const char *input)
{
	if (has_syntax_error(input))
	{
		int i = 0;

		while (input[i])
		{
			if (input[i] == ';' || input[i] == '|' || input[i] == '&')
			{
				if (input[i + 1] == input[i] && input[i + 2] == input[i])
				{
					print_syntax_error_msg(datash, input, i);
					return 1;
				}
			}
			i++;
		}
	}

	return 0;
}

