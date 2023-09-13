#include "main.h"

/**
 * reverse_string - Reverses a given string.
 * @string: Input string to be reversed.
 * Return: No return value.
 */
void reverse_string(char *string)
{
	int length = 0, start = 0, end = 0;
	char *str, temp;

	/* Calculate the length of the string */
	while (length >= 0)
	{
		if (string[length] == '\0')
			break;
		length++;
	}
	str = string;

	/* Reverse the string */
	for (start = 0; start < (length - 1); start++)
	{
		for (end = start + 1; end > 0; end--)
		{
			temp = *(str + end);
			*(str + end) = *(str + (end - 1));
			*(str + (end - 1)) = temp;
		}
	}
}

