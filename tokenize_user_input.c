#include "main.h"
/**
 * tokenize_user_input - creates an array of strings from given input
 * @lline: the input string to be tokenized
 *
 * Return: an array of strings
 */
char **tokenize_user_input(char *lline)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	size_t index = 0, flag = 0, i = 0, tokensize = 1;

	buf = _strdup(lline);
	if (!buf)
		return (isnull(buf));
	bufp = buf;
	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && flag == 0)
			tokensize++, flag = 1;
		else if (_strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	if (tokens == NULL)
		return (NULL);
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		{
			for (i = 0; i < index; i++)
				free(tokens[i]);
			free(tokens);
			free(buf);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = NULL;
	free(buf);
	return (tokens);
}
/**
 * isnull - used to free the given pointer.
 * @pointer: pointer to char array .
 * Return: if pointer is null
 */
char **isnull(char *pointer)
{
	char **ptr = NULL;

	if (pointer == NULL)
	{
		free(pointer);
		return (NULL);
	}
	return (ptr);
}
