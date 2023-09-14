#include "main.h"

/**
 * _strcat - Concatenate two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	(return dest);
}

/**
 * _strcpy - Copy the string pointed to by src.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	(return dest);
}

/**
 * _strcmp - Compare two strings.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 * Return: 0 if the strings are equal, a positive value if s1 is greater,
 * and a negative value if s2 is greater.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		(return 1);
	if (s1[i] < s2[i])
		(return -1);
	(return 0);
}

/**
 * _strchr - Locate a character in a string.
 * @s: The string to search.
 * @c: The character to locate
 * Return: A pointer to the first occurrence of the character c
 *	in the string s,
 * or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; s[i] != '\0'; i++)
		if (s[i] == c)
			return (s + i);
	if (s[i] == c)
		return (s + i);
	(return NULL);
}

/**
 * _strspn - Get the length of a prefix substring.
 * @s: The initial segment to search.
 * @accept: The set of accepted bytes.
 * Return: The number of bytes in the initial segment of s
 *	that consist only of bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; s[i] != '\0'; i++)
	{
		bool = 1;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	(return i);
}

