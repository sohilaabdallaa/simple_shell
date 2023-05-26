#include "main.h"
/**
 *_strcmp  - compares two strings
 * @stringone: first string to compare
 * @stringtwo: second string to compare
 *
 * Return: difference between strings
 */
int _strcmp(char *stringone, char *stringtwo)
{
	int k = 0, output;

	while (*(stringone + k) == *(stringtwo + k) && *(stringone + k) != '\0')
		k++;
	output = (*(stringone + k) - *(stringtwo + k));
	return (output);
}

/**
 * _strlen - returns the length of a string
 * @string: string passed
 *
 * Return: length of string passed
 */
int _strlen(char *string)
{
	int counting = 0;

	while (*string != '\0')
	{
		counting++;
		string++;
	}
	return (counting);
}

/**
 * _strncmp  - compares two strings up to number bytes
 * @stringone: first string to compare
 * @stringtwo: second string to compare
 * @n: number of bytes
 *
 * Return: difference between stringone and stringtwo
 */
int _strncmp(char *stringone, char *stringtwo, int n)
{
	int i;

	for (i = 0; stringone[i] && stringtwo[i] && i < n; i++)
	{
		if (stringone[i] != stringtwo[i])
			return (stringone[i] - stringtwo[i]);
	}
	return (0);
}

/**
 * _strdup - duplicates a string
 * @string: string to be duplicated
 *
 * Return: pointer to duplicate string
 */
char *_strdup(char *string)
{
	char *pointer;
	int m, n;

	if (string == NULL)
		return (NULL);
	n = _strlen(string);
	pointer = malloc(sizeof(char) * (n + 1));
	if (!pointer)
		return (NULL);
	for (m = 0; *string != '\0'; string++, m++)
		pointer[m] = *string;
	pointer[m++] = '\0';
	return (pointer);
}

/**
 * _strchr - locates a character in a string
 * @string: string to be checked
 * @chara: character to be located
 *
 * Return: pointer to first occurrence of
 * character or NULL if character not found
 */
char *_strchr(char *string, char chara)
{
	while (*string)
	{
		if (*string == chara)
			return (string);
		string++;
	}
	if (!chara)
		return (string);
	return (NULL);
}
